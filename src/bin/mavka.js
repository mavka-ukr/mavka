#!/usr/bin/env node

import Mavka from "../main.js";
import { makePrintDiiaCell, makeReadDiiaCell } from "../std/io.js";
import promptSync from "prompt-sync";
import {
  makeLoadExtensionDiiaCell,
  makeLoadExtensionFromFileDiiaCell,
  makeLoadExtensionFromNetworkDiiaCell
} from "../std/extensions.js";
import { getBinPathSync } from "get-bin-path";
import { DiiaParserSyntaxError } from "mavka-parser/src/utils/errors.js";

const fs = (await import("fs")).default;
const jsPath = (await import("path")).default;

process.removeAllListeners("warning");

const cwdPath = process.cwd();

let filename = process.argv[2];

function buildGlobalContext(mavka) {
  return new mavka.Context(mavka, null, {
    "друк": makePrintDiiaCell(mavka),
    "читати": makeReadDiiaCell(mavka),

    "підключити_розширення_з_файлу": makeLoadExtensionFromFileDiiaCell(mavka),
    "підключити_розширення_з_мережі": makeLoadExtensionFromNetworkDiiaCell(mavka),
    "підключити_розширення": makeLoadExtensionDiiaCell(mavka)
  });
}

function buildLoader(mavka) {
  return new mavka.FileLoader(mavka);
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

  const context = new mavka.Context(mavka);
  context.set("__шлях_до_папки_кореневого_модуля__", mavka.makeText(cwdPath));
  context.set("__шлях_до_кореневого_модуля__", mavka.makeText(`${cwdPath}/${filename}`));
  context.set("__шлях_до_папки_модуля__", mavka.makeText(cwdPath));
  context.set("__шлях_до_модуля__", mavka.makeText(`${cwdPath}/${filename}`));

  const binPath = getBinPathSync();
  if (binPath && false) {
    const stdCode = fs.readFileSync(`${jsPath.dirname(jsPath.dirname(jsPath.dirname(binPath)))}/node_modules/mavka-teka/тека.м`).toString();

    mavka.context.setAsync(true);
    await mavka.eval(stdCode);
    mavka.context.setAsync(false);
  }

  const path = filename.substring(0, filename.length - 2).split(".");

  try {
    await mavka.loader.load(context, path, false);
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
  console.log("мавка :файл");
}
