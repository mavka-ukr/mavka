#!/usr/bin/env node

import JejalykNodeModule from "jejalyk/node";
import JejalykVersion from "jejalyk/version";
import fs from "fs";
import process from "process";
import path from "path";
import os from "os";
import { Uint8ArrayReader, ZipReader } from "@zip.js/zip.js";
import axios from "axios";
import { fileURLToPath } from "url";
import mavkaVersion from "../mavkaVersion.js";
import readline from "readline";

const binPath = fileURLToPath(import.meta.url);
const binDirname = path.dirname(binPath);

process.removeAllListeners("warning");

function printProgress(name, progress) {
  readline.clearLine(process.stdout, 0);
  readline.cursorTo(process.stdout, 0);
  process.stdout.write(`[ ${progress}% ] ${name}`);
}

function clearProgress() {
  readline.clearLine(process.stdout, 0);
  readline.cursorTo(process.stdout, 0);
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
      --строгість={0,1} — рівень строгості
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

const loadedPaks = new Map();

global.mavka_compilation_options = {
  args: options.join(" "),
  std_code: `
js """
var м_друк = мДія(function друк(values) {
  console.log(...values.map((v) => мГарно(v)));
});
var м_вивести = мДія(function вивести(values) {
  process.stdout.write(...values.map((v) => мГарно(v)));
});
var м_показати_вітрину = мДія(function показати_вітрину() {});
var м_приховати_вітрину = мДія(function приховати_вітрину() {});
var м_тримати_вітрину = мДія(function тримати_вітрину() {});
"""

макет дія друк(...значення список) пусто
макет дія вивести(...значення список) пусто
макет дія показати_вітрину() пусто
макет дія приховати_вітрину() пусто
макет дія тримати_вітрину() пусто
`,
  main_module_path: inputFilePath,
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
    if (relative) {
      return {
        error: "",
        result: path.resolve(`${path.dirname(options.current_module_path)}/${parts.join("/")}.м`)
      };
    } else {
      const rootModulePath = options.root_module_path;
      const stdDirname = path.resolve(`${binDirname}/../бібліотека`);

      if (parts.length === 1) {
        if (fs.existsSync(path.resolve(`${path.dirname(rootModulePath)}/${parts[0]}.м`))) {
          return {
            error: "",
            result: path.resolve(`${path.dirname(rootModulePath)}/${parts[0]}.м`)
          };
        }
        if (loadedPaks.has(parts[0])) {
          const loaded_pak = loadedPaks.get(parts[0]);
          return {
            error: "",
            result: path.resolve(`${loaded_pak.path}/${parts[0]}.м`)
          };
        }
        if (fs.existsSync(path.resolve(`${stdDirname}/${parts[0]}.м`))) {
          return {
            error: "",
            result: path.resolve(`${stdDirname}/${parts[0]}.м`)
          };
        }
      } else {
        if (fs.existsSync(path.resolve(`${path.dirname(rootModulePath)}/${parts.join("/")}.м`))) {
          return {
            error: "",
            result: path.resolve(`${path.dirname(rootModulePath)}/${parts.join("/")}.м`)
          };
        }
        if (loadedPaks.has(parts[0])) {
          const loaded_pak = loadedPaks.get(parts[0]);
          return {
            error: "",
            result: path.resolve(`${loaded_pak.path}/${parts.join("/")}.м`)
          };
        }
      }
      return {
        error: `Модуль "${module}" не знайдено.`,
        result: ""
      };
    }
  },
  async get_module_code(relative, module, options) {
    const modulePathResult = await global.mavka_compilation_options.get_module_path(relative, module, options);
    if (modulePathResult.error) {
      return modulePathResult;
    }
    if (fs.existsSync(modulePathResult.result)) {
      return {
        error: "",
        result: fs.readFileSync(modulePathResult.result, "utf8"),
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
  async get_pak(name, version, as, options) {
    const userHomeDir = os.homedir();
    let pakRepository = "пак";
    let pakName = "";
    if (name.includes(":")) {
      const parts = name.split(":");
      if (parts[0].length) {
        pakRepository = parts[0];
      }
      if (parts[1].length) {
        pakName = parts[1];
      }
    } else {
      pakName = name;
    }
    if (!pakName) {
      return {
        error: `Невірна назва паку.`,
        result: ""
      };
    }
    if (loadedPaks.has(pakName)) {
      const loaded_pak = loadedPaks.get(pakName);
      const loaded_pak_major_version = loaded_pak.version.split(".")[0];
      const pak_major_version = version.split(".")[0];
      if (loaded_pak_major_version !== pak_major_version) {
        return {
          error: `Пак "${pakName}" "${version}" вже завантажено з версією "${loaded_pak.version}".`,
          result: ""
        };
      }
      const loaded_pak_minor_version = loaded_pak.version.split(".")[1];
      const pak_minor_version = version.split(".")[1];
      if (loaded_pak_minor_version < pak_minor_version) {
        return {
          error: `Пак "${pakName}" "${version}" вже завантажено з версією "${loaded_pak.version}".`,
          result: ""
        };
      }
      return {
        error: "",
        result: ""
      };
    }
    let repositoriesText = "пак=https://завантажити.пак.укр/{NAME}-{VERSION}.zip";
    if (!fs.existsSync(`${userHomeDir}/.паки`)) {
      fs.mkdirSync(`${userHomeDir}/.паки`);
    }
    if (!fs.existsSync(`${userHomeDir}/.паки/${pakRepository}`)) {
      fs.mkdirSync(`${userHomeDir}/.паки/${pakRepository}`);
    }
    if (fs.existsSync(`${binDirname}/репозиторії`)) {
      repositoriesText = fs.readFileSync(`${binDirname}/репозиторії`, "utf8");
    }
    const pakDirname = `${userHomeDir}/.паки/${pakRepository}/${pakName}/${version}`;
    if (!fs.existsSync(pakDirname)) {
      const repositories = repositoriesText.split("\n")
        .map((line) => line.trim())
        .filter((line) => line.length && !line.startsWith(";;"))
        .map((line) => line.split("="))
        .map((line) => ({ name: line[0], url: line[1] }));
      const repository = repositories.find((repository) => repository.name === pakRepository);
      if (!repository) {
        return {
          error: `Репозиторій "${pakRepository}" не знайдено.`,
          result: ""
        };
      }
      const url = repository.url.replaceAll("{NAME}", pakName).replaceAll("{VERSION}", version);
      printProgress(`${name} ${version}`, 0);
      let error;
      await axios
        .get(url, {
          onDownloadProgress: (progressEvent) => {
            printProgress(`${name} ${version}`, Math.floor(progressEvent.progress * 100 || 0));
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
          error = `Помилка завантаження паку "${name}" "${version}": ${e.message}`;
        });
      clearProgress();
      if (error) {
        return {
          error,
          result: ""
        };
      }
    }
    loadedPaks.set(pakName, { version, path: `${userHomeDir}/.паки/${pakRepository}/${pakName}/${version}` });
    return {
      error: "",
      result: ""
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
      if (compilationResult.error.line) {
        console.error(`${compilationResult.error.path}:${compilationResult.error.line}:${compilationResult.error.column}: ${compilationResult.error.message}`);
      } else {
        console.error(`${compilationResult.error.path}: ${compilationResult.error.message}`);
      }
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