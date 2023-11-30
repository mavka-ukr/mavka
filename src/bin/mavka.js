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
import axios from "axios";
import promptSync from "@kant2002/prompt-sync";
import { cleanEval } from "../cleanEval.js";
import repl from "repl";
import { buildVars } from "../builders.js";
import { Uint8ArrayReader, ZipReader } from "@zip.js/zip.js";
import os from "os";

global.mavka_read = promptSync;
process.removeAllListeners("warning");

process.on("unhandledRejection", (e) => {
  throw e;
});

function printProgress(name, progress) {
  process.stdout.clearLine(0);
  process.stdout.cursorTo(0);
  process.stdout.write(`[ ${progress}% ] ${name}`);
}

function clearProgress() {
  process.stdout.clearLine(0);
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
  async getModulePath(relative, parts, di, options) {
    const rootModulePath = relative ? options.currentModulePath : options.rootModulePath;
    return `${path.dirname(rootModulePath)}/${parts.join("/")}.м`;
  },
  async getModuleName(relative, parts, di, options) {
    return parts[parts.length - 1];
  },
  async getModuleCode(relative, modulePathParts, di, options) {
    const name = modulePathParts.join(".");
    const modulePath = await this.getModulePath(relative, modulePathParts, di, options);
    if (fs.existsSync(modulePath)) {
      return fs.readFileSync(modulePath, "utf8");
    } else {
      throw new MavkaCompilationError(`Модуль "${name}" не знайдено.`, di);
    }
  },
  async getBuiltinModuleCode([name], di, options) {
    if (fs.existsSync(`${binPath}/../modules/${name}.js`)) {
      return fs.readFileSync(`${binPath}/../modules/${name}.js`, "utf8");
    }
    throw new MavkaCompilationError(`Пак "${name}" не знайдено.`, di);
  },
  async getRemoteModuleName(parts, di, options) {
    const name = parts[0];
    const rest = parts.slice(2);
    const userHomeDir = os.homedir();
    const paksDirname = `${userHomeDir}/.паки`;
    if (rest.length) {
      return rest[rest.length - 1];
    }
    return name;
  },
  async getRemoteModulePakPath(parts, di, options) {
    const name = parts[0];
    const version = parts[1];
    const userHomeDir = os.homedir();
    const paksDirname = `${userHomeDir}/.паки`;
    return `${paksDirname}/${name}/${version}`;
  },
  async getRemoteModulePath(parts, di, options) {
    const name = parts[0];
    const version = parts[1];
    const rest = parts.slice(2);
    const userHomeDir = os.homedir();
    const paksDirname = `${userHomeDir}/.паки`;
    if (rest.length) {
      return `${paksDirname}/${name}/${version}/${rest.join("/")}.м`;
    }
    return `${paksDirname}/${name}/${version}/${name}.м`;
  },
  async getRemoteModuleCode(parts, di, options) {
    const name = parts[0];
    const version = parts[1];
    const url = `https://завантажити.пак.укр/${name}-${version}.zip`;
    const modulePath = await this.getRemoteModulePath(parts, di, options);
    const pakDirname = await this.getRemoteModulePakPath(parts, di, options);
    if (!fs.existsSync(pakDirname)) {
      printProgress(`${name}/${version}`, 0);
      await axios
        .get(url, {
          onDownloadProgress: (progressEvent) => {
            printProgress(`${name}/${version}`, Math.floor(progressEvent.progress * 100 || 0));
          },
          responseType: "arraybuffer",
          headers: {
            "X-Mavka-Version": mavka.constructor.VERSION
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
          throw new MavkaCompilationError(`Помилка завантаження паку "${name}/${version}": ${e.message}`, di);
        });
      clearProgress();
    }
    if (!fs.existsSync(modulePath)) {
      throw new MavkaCompilationError(`Модуль "${parts.join("/")}" не знайдено.`, di);
    }
    return fs.readFileSync(modulePath, "utf8");
  }
});
const scope = new Scope(mavka.globalScope);

try {
  const programNode = parse(code, {
    path: `${cwdPath}/${command}`
  });

  const result = await mavka.compileProgramBody(scope, await processBody(mavka, scope, programNode.body), {
    rootModulePath: `${cwdPath}/${command}`,
    currentModulePath: `${cwdPath}/${command}`
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
      const node = await processBody(mavka, tempScope, programNode.body)[0];
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
        callback(null, `${e.fileinfo.path}:${e.line}:${e.column}: ${e.msg}`);
      } else if (e instanceof MavkaCompilationError) {
        if (e.di) {
          callback(null, `${e.di[0]}:${e.di[1]}:${e.di[2]}: ${e.message}`);
        } else {
          callback(null, e.message);
        }
      } else {
        callback(null, String(e));
      }
    }
  }

  repl.start({ prompt: ": ", eval: evalRepl });
}