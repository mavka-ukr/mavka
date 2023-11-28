#!/usr/bin/env node

import Mavka from "../main.js";
import { DiiaParserSyntaxError } from "mavka-parser/src/utils/errors.js";
import process from "process";
import Scope from "../scope.js";
import { parse } from "mavka-parser";
import { processBody } from "../utils.js";
import fs from "fs";
import path from "path";
import { MavkaCompilationError } from "../error.js";
import { fileURLToPath } from "url";
import md5 from "md5";
import os from "os";
import axios from "axios";

process.removeAllListeners("warning");

const cwdPath = process.cwd();
const binPath = path.dirname(fileURLToPath(import.meta.url));

let command = process.argv[2];

let doCompile = false;

if (command === "версія") {
  console.log(Mavka.VERSION);
} else if (command === "допомога" || !command) {
  console.log(`
Використання:
  мавка <модуль> [...аргументи]
  мавка <команда> [...аргументи]

Доступні команди:
  мавка <модуль> — виконує модуль
  мавка виконати <модуль> — виконує модуль
  мавка версія — показує версію Мавки
  мавка допомога — друкує це повідолення
  `.trim());
} else {
  if (command === "запустити") {
    command = process.argv[3];
  }
  if (!fs.existsSync(`${cwdPath}/${command}`)) {
    console.error(`Модуль "${command}" не знайдено.`);
    process.exit(1);
  }

  try {
    const headLib = fs.readFileSync(`${binPath}/../lib/head.js`, "utf8");
    const stdLib = fs.readFileSync(`${binPath}/../lib/std.js`, "utf8");


    function printProgress(name, progress) {
      process.stdout.clearLine();
      process.stdout.cursorTo(0);
      process.stdout.write(`[ ${progress}% ] ${name}`);
    }

    function clearProgress() {
      process.stdout.clearLine();
      process.stdout.cursorTo(0);
    }

    const mavka = new Mavka({
      getBuiltinModuleCode: (name, di, options) => {
        if (fs.existsSync(`${binPath}/../modules/${name}.js`)) {
          return fs.readFileSync(`${binPath}/../modules/${name}.js`, "utf8");
        }
        throw new MavkaCompilationError(`Пак "${name}" не знайдено.`, di);
      },
      async getModuleCode(name, di, options) {
        const rootModuleDirname = options.rootModuleDirname;
        const modulePathParts = name.split(".");
        let moduleDirname = `${rootModuleDirname}/${modulePathParts.slice(0, modulePathParts.length - 1).join("/")}`;
        if (moduleDirname.endsWith("/")) {
          moduleDirname = moduleDirname.substring(0, moduleDirname.length - 1);
        }
        const modulePath = `${moduleDirname}/${modulePathParts[modulePathParts.length - 1]}.м`;
        if (fs.existsSync(modulePath)) {
          return [fs.readFileSync(modulePath, "utf8"), modulePath];
        } else {
          throw new MavkaCompilationError(`Модуль "${name}" не знайдено.`, di);
        }
      },
      async getRemoteModuleCode(name, version, di, options) {
        const userHomeDir = os.homedir();
        const dirUrl = `https://пак.укр/${name}/${version}`;
        const url = `https://хмарний.пак.укр/${name}/${version}/${name}.м`;
        const paksDir = `${userHomeDir}/.паки`;
        if (!fs.existsSync(paksDir)) {
          fs.mkdirSync(paksDir);
        }
        const dir = `${paksDir}/${md5(dirUrl)}`;
        if (!fs.existsSync(dir)) {
          fs.mkdirSync(dir);
        }
        const file = `${dir}/${name}.м`;
        if (!fs.existsSync(file)) {
          printProgress(url, 0);
          const result = await axios
            .get(url, {
              onDownloadProgress: (progressEvent) => {
                printProgress(url, Math.floor(progressEvent.progress * 100 || 0));
              },
              responseType: "text",
              headers: {
                "X-Mavka-Version": mavka.constructor.VERSION
              }
            })
            .then((r) => String(r.data))
            .catch((e) => {
              clearProgress();
              throw new MavkaCompilationError(`Помилка завантаження паку "${name}/${version}": ${e.message}`, di);
            });
          clearProgress();
          fs.writeFileSync(file, result);
          return [result, file];
        }
        return [fs.readFileSync(file, "utf8"), file];
      }
    });

    const scope = new Scope(mavka.globalScope);
    let code = fs.readFileSync(`${cwdPath}/${command}`, "utf8");

    if (code) {
      const programNode = parse(code, {
        path: `${cwdPath}/${command}`
      });

      const result = await mavka.compileProgramBody(scope, processBody(mavka, scope, programNode.body), {
        rootModuleDirname: cwdPath,
        currentModuleDirname: cwdPath
      });

      // console.log(result);
      // console.log("---------");

      const compiled = `
  ((async function () {
${headLib}
${stdLib}

try {
  ${result}
} catch (e) {
  if (e instanceof MavkaError) {
    if (e.di) {
      console.error(e.di[0] + ":" + e.di[1] + ":" + e.di[2] + ": " + mavka_to_pretty_string(e.value));
    } else {
      console.error(mavka_to_pretty_string(e.value));
    }
  } else {
    throw e;
  }
}
  })());
    `.trim();

      if (doCompile) {
        if (process.argv[4]) {
          fs.writeFileSync(process.argv[4], compiled);
        } else {
          fs.writeFileSync(`${cwdPath}/${command}.js`, compiled);
        }
      } else {
        eval(compiled);
      }
    }
  } catch (e) {
    if (e instanceof DiiaParserSyntaxError) {
      console.error(`${e.fileinfo.path}:${e.line}:${e.column}: ${e.msg}`);
    } else if (e instanceof MavkaCompilationError) {
      if (e.di) {
        console.error(`${e.di[0]}:${e.di[1]}:${e.di[2]}: ${e.message}`);
      } else {
        console.error(e.message);
      }
    } else {
      throw e;
    }
  }
}
