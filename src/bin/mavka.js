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
import promptSync from "@kant2002/prompt-sync";
import { cleanEval } from "../cleanEval.js";
import repl from "repl";
import { buildVars } from "../builders.js";

global.mavka_read = promptSync;
process.removeAllListeners("warning");

process.on("unhandledRejection", (e) => {
  throw e;
});

function printProgress(name, progress) {
  process.stdout.clearLine();
  process.stdout.cursorTo(0);
  process.stdout.write(`[ ${progress}% ] ${name}`);
}

function clearProgress() {
  process.stdout.clearLine();
  process.stdout.cursorTo(0);
}

const cwdPath = process.cwd();
const binPath = path.dirname(fileURLToPath(import.meta.url));
let command = process.argv[2] || "";
let replMode = false;
let code = "";

const headLib = fs.readFileSync(`${binPath}/../lib/head.js`, "utf8");
const comparisonLib = fs.readFileSync(`${binPath}/../lib/comparison.js`, "utf8");
const arithmeticLib = fs.readFileSync(`${binPath}/../lib/arithmetic.js`, "utf8");
const getsetLib = fs.readFileSync(`${binPath}/../lib/getset.js`, "utf8");
const callLib = fs.readFileSync(`${binPath}/../lib/call.js`, "utf8");
const diiaLib = fs.readFileSync(`${binPath}/../lib/diia.js`, "utf8");
const structureLib = fs.readFileSync(`${binPath}/../lib/structure.js`, "utf8");
const moduleLib = fs.readFileSync(`${binPath}/../lib/module.js`, "utf8");
const stdLib = fs.readFileSync(`${binPath}/../lib/std.js`, "utf8");

if (!command) {
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
  process.exit(0);
} else if (command === "версія") {
  console.log(Mavka.VERSION);
  process.exit(0);
} else if (command === "допомога") {
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
  process.exit(0);
}

if (command === "запустити") {
  command = process.argv[3];
}
if (!replMode) {
  if (fs.existsSync(`${cwdPath}/${command}`)) {
    code = fs.readFileSync(`${cwdPath}/${command}`, "utf8");
  } else {
    console.error(`Модуль "${command}" не знайдено.`);
    process.exit(1);
  }
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

try {
  const programNode = parse(code, {
    path: `${cwdPath}/${command}`
  });

  const result = await mavka.compileProgramBody(scope, processBody(mavka, scope, programNode.body), {
    rootModuleDirname: cwdPath,
    currentModuleDirname: cwdPath
  });

  // console.log(result);
  // console.log("---------");

  const name = command.substring(0, command.length - 2);

  const compiled = `((async function () {
${headLib}
${comparisonLib}
${arithmeticLib}
${getsetLib}
${callLib}
${diiaLib}
${structureLib}
${moduleLib}
${stdLib}

try {
  var moduleValue = mavka_module("${name}");
  ${result}
  global.__mavka_eval__ = function (code) {
    return eval(code);
  }
} catch (e) {
  if (e instanceof MavkaError) {
    if (e.di) {
      console.error(e.di[0] + ":" + e.di[1] + ":" + e.di[2] + ": " + mavka_to_pretty_string(e.value));
    } else {
      console.error(mavka_to_pretty_string(e.value));
    }
  } else {
    console.error(String(e));
  }
}
})());`.trim();

  cleanEval(compiled);
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
    console.error(String(e));
  }
}

if (replMode) {
  async function evalRepl(uInput, context, filename, callback) {
    try {
      const programNode = parse(uInput);
      const tempScope = new Scope(scope);
      for (const [k, v] of scope.vars.entries()) {
        tempScope.vars.set(k, v);
      }
      const node = processBody(mavka, tempScope, programNode.body)[0];
      const compiledNode = await mavka.compileNode(tempScope, node);
      global.__mavka_eval__(`
${await buildVars(tempScope)}
$друк([${compiledNode}])
`.trim());
      callback(null);
      for (const [k, v] of tempScope.vars.entries()) {
        scope.vars.set(k, v);
      }
    } catch (e) {
      if (e instanceof DiiaParserSyntaxError) {
        callback(null,`${e.fileinfo.path}:${e.line}:${e.column}: ${e.msg}`);
      } else if (e instanceof MavkaCompilationError) {
        if (e.di) {
          callback(null,`${e.di[0]}:${e.di[1]}:${e.di[2]}: ${e.message}`);
        } else {
          callback(null,e.message);
        }
      } else {
        callback(null, String(e));
      }
    }
  }

  repl.start({ prompt: ": ", eval: evalRepl });
}