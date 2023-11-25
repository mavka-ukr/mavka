#!/usr/bin/env node

import Mavka from "../main.js";
import { DiiaParserSyntaxError } from "mavka-parser/src/utils/errors.js";
import process from "process";
import Scope from "../scope.js";
import { parse } from "mavka-parser";
import { processBody } from "../utils.js";
import { getBinPath } from "get-bin-path";
import fs from "fs";
import path from "path";
import { MavkaCompilationError } from "../error.js";

process.removeAllListeners("warning");

const cwdPath = process.cwd();
const binPath = await getBinPath();

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
    const headLib = fs.readFileSync(`${path.dirname(binPath)}/../lib/head.js`, "utf8");
    const stdLib = fs.readFileSync(`${path.dirname(binPath)}/../lib/std.js`, "utf8");

    const mavka = new Mavka({
      hasBuiltinModuleCode: (name) => {
        return fs.existsSync(`${path.dirname(binPath)}/../modules/${name}.js`);
      },
      getBuiltinModuleCode: (name) => {
        return fs.readFileSync(`${path.dirname(binPath)}/../modules/${name}.js`, "utf8");
      },
      printProgress(name, progress) {
        process.stdout.clearLine();
        process.stdout.cursorTo(0);
        process.stdout.write(`[ ${progress}% ] ${name}`);
      },
      clearProgress() {
        process.stdout.clearLine();
        process.stdout.cursorTo(0);
      },
    });

    const scope = new Scope(mavka.globalScope);
    const code = fs.readFileSync(`${cwdPath}/${command}`, "utf8");
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
