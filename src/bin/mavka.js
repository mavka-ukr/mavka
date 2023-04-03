#!/usr/bin/env node

import Mavka from "../main.js";
import promptSync from "@kant2002/prompt-sync";
import { DiiaParserSyntaxError } from "mavka-parser/src/utils/errors.js";
import FileLoader from "../loaders/fileLoader.js";

const fs = (await import("fs")).default;
const jsPath = (await import("path")).default;

process.removeAllListeners("warning");

const cwdPath = process.cwd();

let command = process.argv[2];

function buildGlobalContext(mavka) {
  let extId = 0;

  const context = new mavka.Context(mavka, null, {
    "друк": mavka.makeProxyFunction((args, context) => {
      console.log(
        ...args
          .map((arg) => {
            return arg.asText(context).asJsValue(context);
          })
      );

      return mavka.empty;
    }),
    "читати": mavka.makeProxyFunction((args, context) => {
      const ask = Object.values(args).length ? args[0].asText(context).asJsValue() : undefined;

      return mavka.makeText(mavka.external.promptSync({ sigint: true, encoding: "windows-1251" })(ask));
    }),

    "підключити_розширення_з_файлу": mavka.makeProxyFunction((args, context) => {
      const path = mavka.toCell(args[0]).asText(context).asJsValue(context);
      const moduleDirname = context.get("__шлях_до_папки_модуля__").asJsValue(context);

      mavka.global.getContext = () => context;

      const loadExtensionAsyncCell = new mavka.AsyncCell(mavka, async () => {
        return mavka.toCell(await import(`${moduleDirname}/${path}`));
      });

      return new mavka.AwaitCell(mavka, loadExtensionAsyncCell);
    }),
    "підключити_розширення_з_мережі": mavka.makeProxyFunction((args, context) => {
      const url = mavka.toCell(args[0]).asText(context).asJsValue(context);

      mavka.global.getContext = () => context;

      const loadExtensionAsyncCell = new mavka.AsyncCell(mavka, async () => {
        const body = await (await fetch(url)).text();

        extId++;

        const wrappedCode = `
mavka.global.EXTENSION_EVAL_ASYNC_${extId} = async () => {
  ${body}
}
      `;

        eval(wrappedCode);

        const result = await mavka.global[`EXTENSION_EVAL_ASYNC_${extId}`]();
        delete mavka.global[`EXTENSION_EVAL_ASYNC_${extId}`];

        return mavka.toCell(result);
      });

      return new mavka.AwaitCell(mavka, loadExtensionAsyncCell);
    }),
    "підключити_розширення": mavka.makeProxyFunction((args, context) => {
      const code = mavka.toCell(args[0]).asText(context).asJsValue(context);

      mavka.global.getContext = () => context;

      const loadExtensionAsyncCell = new mavka.AsyncCell(mavka, async () => {
        extId++;

        const wrappedCode = `
mavka.global.EXTENSION_EVAL_ASYNC_${extId} = async () => {
  ${code}
}
      `;

        eval(wrappedCode);

        const result = await mavka.global[`EXTENSION_EVAL_ASYNC_${extId}`]();
        delete mavka.global[`EXTENSION_EVAL_ASYNC_${extId}`];

        return mavka.toCell(result);
      });

      return new mavka.AwaitCell(mavka, loadExtensionAsyncCell);
    })
  });

  context.set("__шлях_до_папки_кореневого_модуля__", mavka.makeText(cwdPath));
  context.set("__шлях_до_папки_модуля__", mavka.makeText(cwdPath));
  context.set("__шлях_до_папки_паків__", mavka.makeText(`${cwdPath}/.паки`));

  return context;
}

function buildLoader(mavka) {
  return new FileLoader(mavka);
}

function buildExternal(mavka) {
  return {
    promptSync
  };
}

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

  if (!command.endsWith(".м")) {
    command = `${command}.м`;
  }

  const mavka = new Mavka({
    buildGlobalContext,
    buildLoader,
    buildExternal
  });

  const context = new mavka.Context(mavka, mavka.context);

  const path = command.substring(0, command.length - 2).split(".");

  function printProgress(name, progress) {
    process.stdout.clearLine();
    process.stdout.cursorTo(0);
    process.stdout.write(`[ ${progress}% ] ${name}`);
  }

  function clearProgress() {
    process.stdout.clearLine();
    process.stdout.cursorTo(0);
  }

  mavka.events.on("module::load::remote::start", ({ url }) => {
    printProgress(url, 0);
  });
  mavka.events.on("module::load::remote::progress", ({ url, progress }) => {
    printProgress(url, progress);
  });
  mavka.events.on("module::load::remote::stop", () => {
    clearProgress();
  });
  mavka.events.on("module::load::remote::failed", () => {
    clearProgress();
  });

  try {
    const startupModulePath = new URL('../startup-modules/', import.meta.url).pathname.substring(1);
    const startupModuleFiles = fs.readdirSync(startupModulePath)
      .map(filename => jsPath.join(startupModulePath, filename));

    for (const modulePath of startupModuleFiles) {
      mavka.context = await mavka.loader.loadStartupModule(context, modulePath);
    }

    await mavka.loader.loadModuleFromFile(mavka.context, command);

  } catch (e) {
    if (e instanceof DiiaParserSyntaxError) {
      console.error(`Не вдалось зловити: ${e.message}`);
    } else if (e instanceof mavka.ThrowValue) {
      console.error(`Не вдалось зловити: ${e.value.asText(context).asJsValue(context)}`);
    } else {
      throw e;
    }
  }
}
