import fs from "fs";
import process from "process";

function getStringFromWasm(instance, ptr, size) {
  const memory = instance.exports.memory;
  const safePtr = Number(ptr);
  const safeSize = Number(size);
  const byteBuffer = new Uint8Array(memory.buffer, safePtr, safeSize);
  const decoder = new TextDecoder('utf-8');
  return decoder.decode(byteBuffer);
}

function mallocStringToWasm64(instance, jsString) {
  const encoder = new TextEncoder();
  const stringBytes = encoder.encode(jsString);
  const size = stringBytes.length;

  if (!instance.exports.пристрій_мавки_виділити_сиру_памʼять) {
    throw new Error("WASM модуль не експортує функцію виділення пам'яті (наприклад, malloc)!");
  }

  const ptrBigInt = instance.exports.пристрій_мавки_виділити_сиру_памʼять(BigInt(size));

  const safePtr = Number(ptrBigInt);

  const memory = instance.exports.memory;
  const wasmBuffer = new Uint8Array(memory.buffer, safePtr, size);
  wasmBuffer.set(stringBytes);

  return {
    ptr: ptrBigInt,
    size: BigInt(size)
  };
}

function setStringToWasm64Memory(instance, jsString, outstrBigInt) {
  const memory = instance.exports.memory;

  const encoder = new TextEncoder();
  const stringBytes = encoder.encode(jsString);
  const sizeWithNull = stringBytes.length + 1;

  const stringPtrBigInt = instance.exports.malloc(BigInt(sizeWithNull));
  allocatedStringPtr = stringPtrBigInt; // Зберігаємо для майбутнього free()

  const safeStringPtr = Number(stringPtrBigInt);
  const stringBuffer = new Uint8Array(memory.buffer, safeStringPtr, sizeWithNull);
  stringBuffer.set(stringBytes);
  stringBuffer[stringBytes.length] = 0; // Додаємо '\0' наприкінці рядка

  const safeOutstr = Number(outstrBigInt);
  const outstrView = new BigUint64Array(memory.buffer, safeOutstr, 1);

  outstrView[0] = stringPtrBigInt;
}

async function loadNodeWasm() {
  const wasmBuffer = fs.readFileSync('./будування/0.125.7/васм64/готове/мавка.wasm');

  const { instance } = await WebAssembly.instantiate(wasmBuffer, {
    env: {
      fmod: (a, b) => a % b,
      пристрій_мавки_читати_ю8: () => false,
      пристрій_мавки_вивести_ю8: (color, data, size) => process.stdout.write(getStringFromWasm(instance, data, size)),
      пристрій_мавки_перетворити_р64_в_ю8: () => console.log("пристрій_мавки_перетворити_р64_в_ю8") && false,
      пристрій_мавки_перетворити_ц64_в_ю8: () => console.log("пристрій_мавки_перетворити_ц64_в_ю8") && false,
      пристрій_мавки_перетворити_п64_в_ю8: () => console.log("пристрій_мавки_перетворити_п64_в_ю8") && false,
      пристрій_мавки_піднести_до_степеня_р64: (value) => Math.pow(value),
      пристрій_мавки_вийти: (value) => console.log("пристрій_мавки_вийти") && false,
      пристрій_мавки_вивести_шлях: (value) => console.log("пристрій_мавки_вивести_шлях") && false,
      пристрій_мавки_прочитати_файл: (value) => console.log("пристрій_мавки_прочитати_файл") && false,
      пристрій_мавки_перевірити_чи_шлях_існує_і_є_файлом: (value) => console.log("пристрій_мавки_перевірити_чи_шлях_існує_і_є_файлом") && false,
      пристрій_мавки_отримати_абсолютний_шлях: (value) => console.log("пристрій_мавки_отримати_абсолютний_шлях") && false,
      бібліотека_мавки_видалити: (value) => console.log("бібліотека_мавки_видалити") && false,
      бібліотека_мавки_дописати_файл: (value) => console.log("бібліотека_мавки_дописати_файл") && false,
      бібліотека_мавки_записати_файл: (value) => console.log("бібліотека_мавки_записати_файл") && false,
      бібліотека_мавки_прочитати_файл: (value) => console.log("бібліотека_мавки_прочитати_файл") && false,
      бібліотека_мавки_створити_папку: (value) => console.log("бібліотека_мавки_створити_папку") && false,
      бібліотека_мавки_виконати_аргументи: (value) => console.log("бібліотека_мавки_виконати_аргументи") && false,
      бібліотека_мавки_виконати: (value) => console.log("бібліотека_мавки_виконати") && false,
      пристрій_мавки_отримати_поточний_шлях_процесу: (value) => console.log("пристрій_мавки_отримати_поточний_шлях_процесу") && false,
    }
  });

  const result = instance.exports.почати(0n, 0n);

  console.log(result);
}

loadNodeWasm();