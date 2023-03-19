#!/usr/bin/env node

import Mavka from "../main.js";
import FileLoader from "../loaders/fileLoader.js";
import { makePrintDiiaCell, makeReadDiiaCell } from "../std/io.js";
import promptSync from "prompt-sync";
import { makeToNumberDiiaCell } from "../std/casts.js";
import {
  makeLoadExtensionDiiaCell,
  makeLoadExtensionFromFileDiiaCell,
  makeLoadExtensionFromNetworkDiiaCell
} from "../std/extensions.js";
import { makeRangeDiiaCell } from "../std/ranges.js";
import { makeGetJsonDiiaCell } from "../std/network.js";
import { getBinPathSync } from "get-bin-path";

const fs = (await import("fs")).default;
const jsPath = (await import("path")).default;

process.removeAllListeners("warning");

const cwdPath = process.cwd();

let filename = process.argv[2];

function buildGlobalContext(mavka) {
  const context = new mavka.Context(mavka, null, {
    "друк": makePrintDiiaCell(mavka),
    "читати": makeReadDiiaCell(mavka),

    "до_числа": makeToNumberDiiaCell(mavka),

    "підключити_розширення_з_файлу": makeLoadExtensionFromFileDiiaCell(mavka),
    "підключити_розширення_з_мережі": makeLoadExtensionFromNetworkDiiaCell(mavka),
    "підключити_розширення": makeLoadExtensionDiiaCell(mavka),

    "діапазон": makeRangeDiiaCell(mavka),

    "отримати_джсон": makeGetJsonDiiaCell(mavka, null),

    "global": mavka.toCell(global)
  });

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

  const context = new mavka.Context(mavka);
  context.set("__шлях_до_папки_кореневого_модуля__", cwdPath);
  context.set("__шлях_до_кореневого_модуля__", `${cwdPath}/${filename}`);
  context.set("__шлях_до_папки_модуля__", cwdPath);
  context.set("__шлях_до_модуля__", `${cwdPath}/${filename}`);

  const stdCode = fs.readFileSync(`${jsPath.dirname(jsPath.dirname(jsPath.dirname(getBinPathSync())))}/node_modules/mavka-teka/тека.м`).toString();

  mavka.context.setAsync(true);
  await mavka.eval(stdCode);
  mavka.context.setAsync(false);

  const path = filename.substring(0, filename.length - 2).split(".");

  try {
    await mavka.loader.load(context, path, false);
  } catch (e) {
    if (e instanceof Error) {
      console.error(e.message);
    } else if (typeof e === "string") {
      console.error(e);
    } else if (e instanceof mavka.ThrowValue) {
      const cell = mavka.toCell(e.value);
      console.error(`Не вдалось зловити: ${cell.asString().asJsString()}`);
    } else {
      console.log(e);
    }
  }
} else {
  console.log("мавка :файл");
}
