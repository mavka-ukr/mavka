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

let command = process.argv[2] || "";

const helpMessage = `
Використання:
  джеджалик [...опції] <вхід.м> [вихід.м]
  джеджалик [...опції] <команда> [...аргументи]

Доступні команди:
  джеджалик компілювати <вхід.м> [вихід.м] — компілювати модуль
  джеджалик версія — показує версію Джеджалика
  джеджалик допомога — друкує це повідолення
`.trim();

if (!command) {
  console.log(helpMessage);
  process.exit(0);
} else if (command === "версія") {
  console.log(JejalykVersion);
  process.exit(0);
} else if (command === "допомога") {
  console.log(helpMessage);
  process.exit(0);
}

let code;

if (fs.existsSync(command)) {
  code = fs.readFileSync(command, "utf8");
} else {
  console.error(`Модуль "${command}" не знайдено.`);
  process.exit(1);
}

global.mavka_compilation_options = {
  args: "",
  std_code: `
js """
var м_друк = мДія("друк", [], function(args) {
  console.log(...Object.values(args));
});
"""

макет дія друк(...значення) ніщо
`,
  root_module_path: path.resolve(command),
  current_module_path: path.resolve(command),
  async get_module_name(relative, module, options) {
    const parts = module.split(".");
    return parts[parts.length - 1];
  },
  async get_module_path(relative, module, options) {
    const parts = module.split(".");
    const rootModulePath = relative ? options.current_module_path : options.root_module_path;
    return path.resolve(`${path.dirname(rootModulePath)}/${parts.join("/")}.м`);
  },
  async get_module_code(relative, module, options) {
    const modulePath = await global.mavka_compilation_options.get_module_path(relative, module, options);
    if (fs.existsSync(modulePath)) {
      return fs.readFileSync(modulePath, "utf8");
    } else {
      throw new Error(`Модуль "${module}" не знайдено.`);
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
          return rest[rest.length - 1];
        } else {
          return name;
        }
      } else {
        if (rest.length) {
          return rest[rest.length - 1];
        } else {
          return version;
        }
      }
    } else {
      return name;
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
          return path.resolve(`${paksDirname}/${name}/${version}/${rest.join("/")}.м`);
        }
        return path.resolve(`${paksDirname}/${name}/${version}/${name}.м`);
      }
    }
    return path.resolve(`${binDirname}/../вп/${module}.м`);
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
                "X-Mavka-Version": "lol"
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
        if (!fs.existsSync(modulePath)) {
          throw new Error(`Пак "${module}" не знайдено.`);
        }
        return fs.readFileSync(modulePath, "utf8");
      }
    }
    if (!fs.existsSync(modulePath)) {
      throw new Error(`Пак "${module}" не знайдено.`);
    }
    return fs.readFileSync(modulePath, "utf8");
  }
};

JejalykNodeModule().then(async (jejalyk) => {
  let compilationResult;
  try {
    compilationResult = await jejalyk.compile(code);
  } catch (e) {
    if (typeof e === "number") {
      console.log(jejalyk.getExceptionMessage(e).toString());
    } else {
      console.error(e);
    }
    process.exit(1);
  }
  if (compilationResult.error) {
    console.error(compilationResult.error.message);
    process.exit(1);
  }
  console.log(compilationResult.result);
});