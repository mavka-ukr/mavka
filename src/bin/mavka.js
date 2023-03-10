#!/usr/bin/env node

process.removeAllListeners("warning");

import Mavka from "../main.js";
import FileLoader from "../loaders/fileLoader.js";
import { makePrintDiiaCell, makeReadDiiaCell } from "../std/io.js";
import promptSync from "prompt-sync";
import { makeToNumberDiiaCell } from "../std/casts.js";
import { makeLoadExtensionFromFileDiiaCell, makeLoadExtensionFromNetworkDiiaCell } from "../std/extensions.js";
import { makeRangeDiiaCell } from "../std/ranges.js";
import { makeGetJsonDiiaCell } from "../std/network.js";
import { ListConstructorCell, ObjectConstructorCell } from "../interpreter/cells/structureCell.js";

const cwdPath = process.cwd();

let filename = process.argv[2];

function buildGlobalContext(mavka) {
  const context = new mavka.Context(mavka, null, {
    "Об'єкт": new ObjectConstructorCell(mavka),
    "Список": new ListConstructorCell(mavka, null),
    "друк": makePrintDiiaCell(mavka),
    "читати": makeReadDiiaCell(mavka),
    "до_числа": makeToNumberDiiaCell(mavka),
    "підключити_розширення_з_файлу": makeLoadExtensionFromFileDiiaCell(mavka),
    "підключити_розширення_з_мережі": makeLoadExtensionFromNetworkDiiaCell(mavka),
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
  context.set("__root_module_dirname__", cwdPath);
  context.set("__root_module_path__", `${cwdPath}/${filename}`);
  context.set("__module_dirname__", cwdPath);
  context.set("__module_path__", `${cwdPath}/${filename}`);

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
