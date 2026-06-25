type адреса = bigint;
type адреса_п8 = bigint;
type адреса_адреса_п8 = bigint;
type адреса_природне = bigint;
type адреса_ціле = bigint;
type природне = bigint;
type р64 = number;
type ц64 = bigint;
type п64 = bigint;
type ц32 = number;

export const КолірВиводуСтандартний = 0;
export const КолірВиводуЧервоний = 1;
export const КолірВиводуЗелений = 2;
export const КолірВиводуСиній = 3;
export const КолірВиводуЖовтий = 4;

export type КолірВиводу = typeof КолірВиводуСтандартний
  | typeof КолірВиводуЧервоний
  | typeof КолірВиводуЗелений
  | typeof КолірВиводуСиній
  | typeof КолірВиводуЖовтий;

export type TMavkaOptions = {
  cwd: () => string;
  print: (color: КолірВиводу, value: string) => void;
  readline: (prefix: string, callback: (value: string, end: boolean) => void) => void;
  readlineSync: (prefix: string) => string;
  exit: (code: number) => void;
};

export interface IMavkaFS {
  readFileSync(path: string): Uint8Array | false;
  checkIfExistsAndIsFile(path: string): boolean;
  getAbsolutePath(path: string): string;
}

export class Mavka {
  protected fs: IMavkaFS;
  protected wasmBuffer: BufferSource;
  protected options: TMavkaOptions;

  protected instance: WebAssembly.Instance | null = null;
  private utf8Decoder = new TextDecoder('utf-8');
  private textEncoder = new TextEncoder();

  constructor(
    fs: IMavkaFS,
    wasmBuffer: BufferSource,
    options: TMavkaOptions
  ) {
    this.fs = fs;
    this.wasmBuffer = wasmBuffer;
    this.options = options;
  }

  private getExports() {
    if (!this.instance) {
      throw new Error("Not instantiated!");
    }

    return this.instance.exports as Record<string, any> & { memory: WebAssembly.Memory };
  }

  private getMemoryBuffer() {
    return this.getExports().memory.buffer;
  }

  mapFn<F>(ptr: bigint): F {
    const exports = this.getExports();
    const table = exports.__indirect_function_table || exports.table;
    return table.get(ptr) as F;
  }

  malloc(size: bigint): bigint {
    return this.getExports().пристрій_мавки_виділити(size);
  }

  realloc(value: bigint, size: bigint): bigint {
    return this.getExports().пристрій_мавки_перевиділити(value, size);
  }

  free(value: bigint): void {
    this.getExports().пристрій_мавки_звільнити(value);
  }

  extractString(ptr: bigint, size: bigint): string {
    const byteBuffer = new Uint8Array(this.getMemoryBuffer(), Number(ptr), Number(size));
    return this.utf8Decoder.decode(byteBuffer);
  }

  sharePtrs(ptrs: bigint[]): [bigint, bigint] {
    const elementCount = ptrs.length;
    const byteSize = BigInt(elementCount * 8);
    const arrayPtr = this.malloc(byteSize);

    const wasmMemoryView = new BigInt64Array(this.getMemoryBuffer(), Number(arrayPtr), elementCount);
    wasmMemoryView.set(ptrs);

    return [arrayPtr, byteSize];
  }

  shareString(str: string): [bigint, bigint] {
    const encodedString = this.textEncoder.encode(str);
    const size = BigInt(encodedString.length);
    const sizeWithNull = size + 1n;

    const ptr = this.malloc(sizeWithNull);

    const wasmMemoryView = new Uint8Array(this.getMemoryBuffer(), Number(ptr), Number(sizeWithNull));

    wasmMemoryView.set(encodedString);
    wasmMemoryView[Number(size)] = 0;

    return [ptr, size];
  }

  storeU64(value: bigint, ptr: bigint): void {
    const wasmMemoryView = new BigUint64Array(this.getMemoryBuffer(), Number(ptr), 1);
    wasmMemoryView[0] = value;
  }

  storePtr(value: bigint, ptr: bigint): void {
    this.storeU64(value, ptr);
  }

  storeBufferPtr(buf: Uint8Array, ptr: bigint): void {
    const size = BigInt(buf.byteLength);
    const bufPtr = this.malloc(size);

    const wasmDataView = new Uint8Array(this.getMemoryBuffer(), Number(bufPtr), buf.byteLength);
    wasmDataView.set(buf);

    this.storePtr(bufPtr, ptr);
  }

  storeString(value: string, dataPtr: bigint, lenPtr: bigint) {
    const [ptr, size] = this.shareString(value);

    this.storePtr(ptr, dataPtr);
    this.storeU64(size, lenPtr);
  }

  private handleConversion(значення: any, вихід_даних: адреса_адреса_п8, вихід_розміру: адреса_природне): boolean {
    const strval = String(значення).replace(/[eE]/g, "е");
    this.storeString(strval, вихід_даних, вихід_розміру);
    return true;
  }

  async instantiate(): Promise<void> {
    const env = {
      fmod: (a: number, b: number) => a % b,
      пристрій_мавки_читати_ю8: (дані_перед: адреса_п8, розмір_перед: природне, вихід_даних: адреса_адреса_п8, вихід_розміру: адреса_природне, вихід_кінець_файлу: адреса_природне, дозволити_історію: природне) => {
        const prefix = this.extractString(дані_перед, розмір_перед);
        const line = this.options.readlineSync(prefix);
        this.storeString(line, вихід_даних, вихід_розміру);
        this.storeU64(0n, вихід_кінець_файлу);
        return true;
      },
      пристрій_мавки_читати_ю8_асинхронно: (дані_перед: адреса_п8, розмір_перед: природне, обробник: адреса, аргумент: адреса, дозволити_історію: природне) => {
        const prefix = this.extractString(дані_перед, розмір_перед);
        const callback = this.mapFn<(дані: адреса_п8, розмір: природне, кінець_файлу: природне, аргумент: адреса) => void>(обробник);

        this.options.readline(prefix, (value, end) => {
          if (end) {
            callback(0n, 0n, 1n, аргумент);
          } else {
            const [ptr, size] = this.shareString(value);
            callback(ptr, size, 0n, аргумент);
          }
        });
      },
      пристрій_мавки_вивести_ю8: (колір: природне, дані: адреса_п8, розмір: природне) => {
        this.options.print(Number(колір) as КолірВиводу, this.extractString(дані, розмір));
      },
      пристрій_мавки_вивести_шлях: (колір: природне, дані: адреса_п8, розмір: природне) => {
        this.options.print(Number(колір) as КолірВиводу, this.extractString(дані, розмір));
      },
      пристрій_мавки_перетворити_р64_в_ю8: (значення: р64, вихід_даних: адреса_адреса_п8, вихід_розміру: адреса_природне, вихід_розміру_експоненти: адреса_ціле) => {
        return this.handleConversion(значення, вихід_даних, вихід_розміру);
      },
      пристрій_мавки_перетворити_ц64_в_ю8: (значення: ц64, вихід_даних: адреса_адреса_п8, вихід_розміру: адреса_природне) => {
        return this.handleConversion(значення, вихід_даних, вихід_розміру);
      },
      пристрій_мавки_перетворити_п64_в_ю8: (значення: п64, вихід_даних: адреса_адреса_п8, вихід_розміру: адреса_природне) => {
        return this.handleConversion(значення, вихід_даних, вихід_розміру);
      },
      пристрій_мавки_піднести_до_степеня_р64: (значення: р64, степінь: р64) => {
        return значення ** степінь;
      },
      пристрій_мавки_вийти: (код_виходу: ц32) => {
        this.options.exit(код_виходу);
      },
      пристрій_мавки_прочитати_файл: (дані_шляху: адреса_п8, розмір_шляху: природне, вихід_даних: адреса_адреса_п8, вихід_розміру: адреса_природне) => {
        const path = this.extractString(дані_шляху, розмір_шляху);
        const buf = this.fs.readFileSync(path);
        if (!buf) {
          return false;
        }
        this.storeBufferPtr(buf, вихід_даних);
        this.storeU64(BigInt(buf.byteLength), вихід_розміру);
        return true;
      },
      пристрій_мавки_перевірити_чи_шлях_існує_і_є_файлом: (дані_шляху: адреса_п8, розмір_шляху: природне) => {
        return this.fs.checkIfExistsAndIsFile(this.extractString(дані_шляху, розмір_шляху));
      },
      пристрій_мавки_отримати_абсолютний_шлях: (дані_шляху: адреса_п8, розмір_шляху: природне, вихід_даних: адреса_адреса_п8, вихід_розміру: адреса_природне) => {
        const path = this.extractString(дані_шляху, розмір_шляху);
        const absPath = this.fs.getAbsolutePath(path);
        this.storeString(absPath, вихід_даних, вихід_розміру);
        return true;
      },
      пристрій_мавки_отримати_поточний_шлях_процесу: (вихід_даних: адреса_адреса_п8, вихід_розміру: адреса_природне) => {
        const cwd = this.options.cwd();
        this.storeString(cwd, вихід_даних, вихід_розміру);
        return true;
      },
    } as const;

    const envProxy = new Proxy(env, {
      get(target, prop) {
        if (prop in target) {
          return target[prop as keyof typeof target];
        }
        return () => {
          throw new Error(`"${String(prop)}" не втілено для WASM! Допоможіть втілити!`);
        };
      }
    });

    const { instance } = await WebAssembly.instantiate(this.wasmBuffer, {
      env: envProxy
    });

    this.instance = instance;
  }

  run(args: string[]): ц32 {
    const exports = this.getExports();

    const аргументи = args.map((arg) => {
      if (typeof arg !== "string") {
        throw new Error("args must be strings!");
      }
      return this.shareString(arg)[0];
    });

    const [ptr] = this.sharePtrs(аргументи);

    return exports.wasmMain(args.length, ptr);
  }
}