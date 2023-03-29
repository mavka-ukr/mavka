#!/usr/bin/env node

import Mavka from "../main.js";
import promptSync from "@kant2002/prompt-sync";
import { DiiaParserSyntaxError } from "mavka-parser/src/utils/errors.js";
import FileLoader from "../loaders/fileLoader.js";

const fs = (await import("fs")).default;
const jsPath = (await import("path")).default;

process.removeAllListeners("warning");

const cwdPath = process.cwd();

let filename = process.argv[2];

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


if (filename && filename !== "допомога") {
  if (!filename.endsWith(".м")) {
    filename = `${filename}.м`;
  }

  const mavka = new Mavka({
    buildGlobalContext,
    buildLoader,
    buildExternal
  });

  const context = new mavka.Context(mavka, mavka.context);

  const path = filename.substring(0, filename.length - 2).split(".");

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
    await mavka.loader.loadModule(context, path, false);
  } catch (e) {
    if (e instanceof DiiaParserSyntaxError) {
      console.error(`Не вдалось зловити: ${e.message}`);
    } else if (e instanceof mavka.ThrowValue) {
      console.error(`Не вдалось зловити: ${e.value.asText(context).asJsValue(context)}`);
    } else {
      throw e;
    }
  }
} else {
  console.log("мавка <модуль>");
}
