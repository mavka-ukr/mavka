#!/usr/bin/env node

import JejalykNodeModule from "jejalyk/node";
import JejalykVersion from "jejalyk/version";
import fs from "fs";
import process from "process";
import path from "path";
import semver from "semver";
import os from "os";
import { Uint8ArrayReader, ZipReader } from "@zip.js/zip.js";
import axios from "axios";
import { fileURLToPath } from "url";
import mavkaVersion from "../mavkaVersion.js";

const binPath = fileURLToPath(import.meta.url);
const binDirname = path.dirname(binPath);

process.removeAllListeners("warning");

function printProgress(name, progress) {
  process.stdout.clearLine(0);
  process.stdout.cursorTo(0);
  process.stdout.write(`[ ${progress}% ] ${name}`);
}

function clearProgress() {
  process.stdout.clearLine(0);
  process.stdout.cursorTo(0);
}

const options = [];
let command = "";
const rest = [];
for (let i = 2; i < process.argv.length; i++) {
  const arg = process.argv[i];
  if (arg.startsWith("-")) {
    options.push(arg);
  } else {
    command = arg;
    if (["версія", "допомога"].includes(command)) {
      rest.push(...process.argv.slice(i + 1));
    } else {
      rest.push(...process.argv.slice(i));
    }
    break;
  }
}
if (!command) {
  command = "допомога";
}

const helpMessage = `
Використання:
  джеджалик [...опції] <вхід.м> [вихід.js]
  джеджалик [...опції] <команда> [...аргументи]

Доступні команди:
  <модуль.м> — компілювати модуль
    Опції:
      --інфо-викликів={0,1} — додати інформацію про виклики (для відлагодження)
      --розширення={0,1} — дозволити JS-розширення

  джеджалик версія — показати версію Джеджалика
    Опції: немає

  джеджалик допомога — показати це повідолення
    Опції: немає
`.trim();

if (command === "допомога") {
  console.log(helpMessage);
  process.exit(0);
} else if (command === "версія") {
  console.log(JejalykVersion);
  process.exit(0);
}

const inputFile = rest[0];
if (!inputFile) {
  console.error(helpMessage);
  process.exit(1);
}
const inputFilePath = path.resolve(inputFile);

let code;
if (fs.existsSync(inputFilePath)) {
  code = fs.readFileSync(inputFilePath, "utf8");
} else {
  console.error(`Модуль "${inputFilePath}" не знайдено.`);
  process.exit(1);
}

global.mavka_compilation_options = {
  args: options.join(" "),
  std_code: `
js """
var м_друк = мДія("друк", [], function(args) {
  console.log(__мГТкс__(...Object.values(args)));
});
"""

макет дія друк(...значення) ніщо
`,
  root_module_path: inputFilePath,
  current_module_path: inputFilePath,
  async get_module_name(relative, module, options) {
    const parts = module.split(".");
    return {
      error: "",
      result: parts[parts.length - 1],
      builtin: false
    };
  },
  async get_module_path(relative, module, options) {
    const parts = module.split(".");
    const rootModulePath = relative ? options.current_module_path : options.root_module_path;
    return {
      error: "",
      result: path.resolve(`${path.dirname(rootModulePath)}/${parts.join("/")}.м`),
      builtin: false
    };
  },
  async get_module_code(relative, module, options) {
    const modulePath = await global.mavka_compilation_options.get_module_path(relative, module, options);
    if (fs.existsSync(modulePath.result)) {
      return {
        error: "",
        result: fs.readFileSync(modulePath.result, "utf8"),
        builtin: false
      };
    } else {
      return {
        error: `Модуль "${module}" не знайдено.`,
        result: "",
        builtin: false
      };
    }
  },
  async get_remote_module_name(module, options) {
    const parts = module.split("/");
    const name = parts[0];
    const version = parts[1];
    const rest = parts.slice(2);
    if (version) {
      if (semver.valid(version)) {
        if (rest.length) {
          return {
            error: "",
            result: rest[rest.length - 1],
            builtin: false
          };
        } else {
          return {
            error: "",
            result: name,
            builtin: false
          };
        }
      } else {
        if (rest.length) {
          return {
            error: "",
            result: rest[rest.length - 1],
            builtin: true
          };
        } else {
          return {
            error: "",
            result: version,
            builtin: true
          };
        }
      }
    } else {
      return {
        error: "",
        result: name,
        builtin: true
      };
    }
  },
  async get_remote_module_path(module, options) {
    const parts = module.split("/");
    const name = parts[0];
    const version = parts[1];
    if (version) {
      if (semver.valid(version)) {
        const rest = parts.slice(2);
        const userHomeDir = os.homedir();
        const paksDirname = `${userHomeDir}/.паки`;
        if (rest.length) {
          return {
            error: "",
            result: path.resolve(`${paksDirname}/${name}/${version}/${rest.join("/")}.м`),
            builtin: false
          };
        }
        return {
          error: "",
          result: path.resolve(`${paksDirname}/${name}/${version}/${name}.м`),
          builtin: false
        };
      }
    }
    return {
      error: "",
      result: path.resolve(`${binDirname}/../вп/${module}.м`),
      builtin: true
    };
  },
  async get_remote_module_code(module, options) {
    const parts = module.split("/");
    const name = parts[0];
    const version = parts[1];
    const modulePath = await global.mavka_compilation_options.get_remote_module_path(module, options);
    if (version) {
      if (semver.valid(version)) {
        const url = `https://завантажити.пак.укр/${name}-${version}.zip`;
        const userHomeDir = os.homedir();
        const paksDirname = `${userHomeDir}/.паки`;
        const pakDirname = `${paksDirname}/${name}/${version}`;
        if (!fs.existsSync(pakDirname)) {
          printProgress(`${name}/${version}`, 0);
          await axios
            .get(url, {
              onDownloadProgress: (progressEvent) => {
                printProgress(`${name}/${version}`, Math.floor(progressEvent.progress * 100 || 0));
              },
              responseType: "arraybuffer",
              headers: {
                "X-Mavka-Version": mavkaVersion
              }
            })
            .then(async (r) => {
              fs.mkdirSync(pakDirname, { recursive: true });
              const zipFileReader = new Uint8ArrayReader(new Uint8Array(r.data));
              const zipReader = new ZipReader(zipFileReader);
              const entries = await zipReader.getEntries();
              for (const entry of entries) {
                const entryStream = new TransformStream();
                const entryArrayBufferPromise = new Response(entryStream.readable).arrayBuffer();
                await entry.getData(entryStream.writable);
                const fileName = entry.filename;
                const fileArrayBuffer = await entryArrayBufferPromise;
                fs.writeFileSync(`${pakDirname}/${fileName}`, Buffer.from(fileArrayBuffer));
              }
              await zipReader.close();
            })
            .catch((e) => {
              clearProgress();
              throw new Error(`Помилка завантаження паку "${name}/${version}": ${e.message}`);
            });
          clearProgress();
        }
        if (!fs.existsSync(modulePath.result)) {
          return {
            error: `Пак "${module}" не знайдено.`,
            result: "",
            builtin: false
          };
        }
        return {
          error: "",
          result: fs.readFileSync(modulePath.result, "utf8"),
          builtin: false
        };
      }
    }
    if (!fs.existsSync(modulePath.result)) {
      return {
        error: `Пак "${module}" не знайдено.`,
        result: "",
        builtin: true
      };
    }
    return {
      error: "",
      result: fs.readFileSync(modulePath.result, "utf8"),
      builtin: true
    };
  }
};

if (code.trim().length) {
  JejalykNodeModule().then(async (jejalyk) => {
    let compilationResult;
    try {
      compilationResult = await jejalyk.compile(code);
    } catch (e) {
      if (typeof e === "number") {
        console.error(jejalyk.getExceptionMessage(e).toString());
      } else {
        console.error(e);
      }
      process.exit(1);
    }
    if (compilationResult.error) {
      console.error(compilationResult.error.message);
      process.exit(1);
    }
    const outputFile = rest[1];
    if (outputFile) {
      fs.writeFileSync(outputFile, compilationResult.result);
    } else {
      console.log(compilationResult.result);
    }
  });
}