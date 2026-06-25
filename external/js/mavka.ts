
type адреса_п8 = bigint;
type адреса_адреса_п8 = bigint;
type адреса_природне = bigint;
type адреса_ціле = bigint;
type природне = bigint;
type р64 = number;
type ц64 = bigint;
type п64 = bigint;
type ц32 = number;



function setStringToWasm64Memory(instance: WebAssembly.Instance, jsString: string, outptr: bigint) {
  const memory = instance.exports.memory;

  const encoder = new TextEncoder();
  const stringBytes = encoder.encode(jsString);
  const sizeWithNull = stringBytes.length + 1;

  const stringPtrBigInt = instance.exports.пристрій_мавки_виділити_сиру_памʼять(BigInt(sizeWithNull));

  const safeStringPtr = Number(stringPtrBigInt);
  const stringBuffer = new Uint8Array(memory.buffer, safeStringPtr, sizeWithNull);
  stringBuffer.set(stringBytes);
  stringBuffer[stringBytes.length] = 0; // Додаємо '\0' наприкінці рядка

  const safeOutstr = Number(outptr);
  const outstrView = new BigUint64Array(memory.buffer, safeOutstr, 1);

  outstrView[0] = stringPtrBigInt;
}

function shareStringWithWasm(instance: WebAssembly.Instance, str: string) {
  const encoder = new TextEncoder();
  const encodedString = encoder.encode(str);
  const size = BigInt(encodedString.length);
  const sizeWithNull = size + 1n;

  const ptr = instance.exports.пристрій_мавки_виділити_сиру_памʼять(sizeWithNull);

  const memoryBuffer = instance.exports.memory.buffer;
  const wasmMemoryView = new Uint8Array(memoryBuffer, Number(ptr), Number(sizeWithNull));

  wasmMemoryView.set(encodedString);
  wasmMemoryView[Number(size)] = 0;

  return { ptr, size: sizeWithNull };
}

function jsArrayToCArray64(instance: WebAssembly.Instance, jsArray: адреса_п8[]) {
  const elementCount = jsArray.length;

  const byteSize = BigInt(elementCount * 8);

  const arrayPtr = instance.exports.пристрій_мавки_виділити_сиру_памʼять(byteSize);

  const memoryBuffer = instance.exports.memory.buffer;

  const wasmMemoryView = new BigInt64Array(
    memoryBuffer,
    Number(arrayPtr),
    elementCount
  );

  wasmMemoryView.set(jsArray.map(BigInt));

  return { ptr: arrayPtr, size: byteSize };
}

export type MavkaPrintNoColor = 0;
export type MavkaPrintColorRed = 1;
export type TMavkaPrintColor = MavkaPrintNoColor | MavkaPrintColorRed;

export type TMavkaOptions = {
  cwd: () => string;
  print: (color: TMavkaPrintColor, value: string) => void;
  readlineSync: (prefix: string) => string;
};

export interface IMavkaFS {
  readFileSync(path: string): Uint8Array | false;
  checkIfExistsAndIsFile(path: string): boolean;
  getAbsolutePath(path: string): string;
}

export class Mavka {
  protected fs: IMavkaFS;
  protected wasmBuffer: BufferSource;
  protected instance: WebAssembly.Instance | null;
  protected options: TMavkaOptions;

  constructor(fs: IMavkaFS, wasmBuffer: BufferSource, options: TMavkaOptions) {
    this.fs = fs;
    this.wasmBuffer = wasmBuffer;
    this.instance = null;
    this.options = options;
  }

  extractString(ptr: bigint, size: bigint) {
    if (!this.instance) {
      throw new Error("Not instantiated!");
    }

    const memory = this.instance.exports.memory;
    const safePtr = Number(ptr);
    const safeSize = Number(size);
    const byteBuffer = new Uint8Array(memory.buffer, safePtr, safeSize);
    const decoder = new TextDecoder('utf-8');
    return decoder.decode(byteBuffer);
  }

  shareString(str: string) {
    if (!this.instance) {
      throw new Error("Not instantiated!");
    }

    const encoder = new TextEncoder();
    const encodedString = encoder.encode(str);
    const size = BigInt(encodedString.length);
    const sizeWithNull = size + 1n;

    const ptr = this.instance.exports.пристрій_мавки_виділити_сиру_памʼять(sizeWithNull);

    const memoryBuffer = this.instance.exports.memory.buffer;
    const wasmMemoryView = new Uint8Array(memoryBuffer, Number(ptr), Number(sizeWithNull));

    wasmMemoryView.set(encodedString);
    wasmMemoryView[Number(size)] = 0;

    return { ptr, size };
  }

  writeBuffer(buf: Uint8Array, ptr: bigint) {
    if (!this.instance) {
      throw new Error("Not instantiated!");
    }

    const memoryBuffer = this.instance.exports.memory.buffer;
    const wasmMemoryView = new Uint8Array(
      memoryBuffer,
      Number(ptr),
      buf.byteLength
    );

    // Node.js Buffer can be passed directly to .set()
    wasmMemoryView.set(buf);
  }

  writeBufferPtr(buf: Uint8Array, ptr: bigint) {
    if (!this.instance) {
      throw new Error("Not instantiated!");
    }

    const size = BigInt(buf.byteLength);
    const bufPtr = this.instance.exports.пристрій_мавки_виділити_сиру_памʼять(size);

    const memoryBuffer = this.instance.exports.memory.buffer;

    // 1. Copy the Uint8Array data into the newly allocated space
    const wasmDataView = new Uint8Array(memoryBuffer, Number(bufPtr), buf.byteLength);
    wasmDataView.set(buf);

    // 2. Write the 64-bit pointer address into the target location
    const wasmPtrView = new BigUint64Array(memoryBuffer, Number(ptr), 1);
    wasmPtrView[0] = bufPtr;
  }

  writePtr(value: bigint, ptr: bigint) {
    if (!this.instance) {
      throw new Error("Not instantiated!");
    }

    const memoryBuffer = this.instance.exports.memory.buffer;

    const wasmMemoryView = new BigUint64Array(
      memoryBuffer,
      Number(ptr),
      1
    );

    wasmMemoryView[0] = value;
  }

  writeU64(value: bigint, ptr: bigint) {
    if (!this.instance) {
      throw new Error("Not instantiated!");
    }

    const memoryBuffer = this.instance.exports.memory.buffer;

    const wasmMemoryView = new BigUint64Array(
      memoryBuffer,
      Number(ptr),
      1
    );

    wasmMemoryView[0] = value;
  }

  async instantiate() {
    const env = {
      fmod: (a: number, b: number) => a % b,
      пристрій_мавки_читати_ю8: (дані_перед: адреса_п8, розмір_перед: природне, вихід_даних: адреса_адреса_п8, вихід_розміру: адреса_природне, вихід_кінець_файлу: адреса_природне, дозволити_історію: природне) => {
        const prefix = this.extractString(дані_перед, розмір_перед);
        const line = this.options.readlineSync(prefix)
        const { ptr, size } = this.shareString(line);
        this.writePtr(ptr, вихід_даних);
        this.writeU64(size, вихід_розміру);
        this.writeU64(0n, вихід_кінець_файлу);
        return true;
      },
      пристрій_мавки_вивести_ю8: (колір: природне, дані: адреса_п8, розмір: природне) => {
        this.options.print(Number(колір) as TMavkaPrintColor, this.extractString(дані, розмір))
      },
      пристрій_мавки_вивести_шлях: (колір: природне, дані: адреса_п8, розмір: природне) => {
        this.options.print(Number(колір) as TMavkaPrintColor, this.extractString(дані, розмір))
      },
      пристрій_мавки_перетворити_р64_в_ю8: (значення: р64, вихід_даних: адреса_адреса_п8, вихід_розміру: адреса_природне, вихід_розміру_експоненти: адреса_ціле) => {
        console.log("пристрій_мавки_перетворити_р64_в_ю8");
        return false;
      },
      пристрій_мавки_перетворити_ц64_в_ю8: (значення: ц64, вихід_даних: адреса_адреса_п8, вихід_розміру: адреса_природне) => {
        console.log("пристрій_мавки_перетворити_ц64_в_ю8");
        return false;
      },
      пристрій_мавки_перетворити_п64_в_ю8: (значення: п64, вихід_даних: адреса_адреса_п8, вихід_розміру: адреса_природне) => {
        console.log("пристрій_мавки_перетворити_п64_в_ю8");
        return false;
      },
      пристрій_мавки_піднести_до_степеня_р64: (значення: р64, степінь: р64) => {
        return значення ** степінь;
      },
      пристрій_мавки_вийти: (код_виходу: ц32) => {
        console.log("пристрій_мавки_вийти");
        return false;
      },
      пристрій_мавки_прочитати_файл: (дані_шляху: адреса_п8, розмір_шляху: природне, вихід_даних: адреса_адреса_п8, вихід_розміру: адреса_природне) => {
        const path = this.extractString(дані_шляху, розмір_шляху);
        const buf = this.fs.readFileSync(path);
        if (!buf) {
          return false;
        }
        this.writeBufferPtr(buf, вихід_даних);
        this.writeU64(BigInt(buf.byteLength), вихід_розміру);
        return true;
      },
      пристрій_мавки_перевірити_чи_шлях_існує_і_є_файлом: (дані_шляху: адреса_п8, розмір_шляху: природне) => {
        return this.fs.checkIfExistsAndIsFile(this.extractString(дані_шляху, розмір_шляху));
      },
      пристрій_мавки_отримати_абсолютний_шлях: (дані_шляху: адреса_п8, розмір_шляху: природне, вихід_даних: адреса_адреса_п8, вихід_розміру: адреса_природне) => {
        const path = this.extractString(дані_шляху, розмір_шляху);
        const absPath = this.fs.getAbsolutePath(path);
        const { ptr, size } = this.shareString(absPath);
        this.writePtr(ptr, вихід_даних);
        this.writeU64(size, вихід_розміру);
        return true;
      },
      пристрій_мавки_отримати_поточний_шлях_процесу: (вихід_даних: адреса_адреса_п8, вихід_розміру: адреса_природне) => {
        const cwd = this.options.cwd();
        const { ptr, size } = this.shareString(cwd);
        this.writePtr(ptr, вихід_даних);
        this.writeU64(size, вихід_розміру);
        return true;
      },
    } as const;

    const envProxy = new Proxy(env, {
      get(target, prop) {
        if (prop in target) {
          return target[prop];
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
    if (!this.instance) {
      throw new Error("Not instantiated!");
    }

    const аргументи: адреса_п8[] = [];

    const setArg = (index: number, value: string) => {
      const { ptr } = shareStringWithWasm(this.instance!, value);
      аргументи[index] = ptr;
    }

    setArg(0, "/home/prykhozhdenko/Projects/Mavka/mavka/external/js/mavka.ts");

    for (let i = 0; i < args.length; i++) {
      if (typeof args[i] != "string") {
        throw new Error("args must be strings!");
      }

      setArg(i + 1, args[i]);
    }

    const { ptr } = jsArrayToCArray64(this.instance, аргументи);

    return this.instance.exports.xmain(args.length + 1, ptr);
  }
}