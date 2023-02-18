#!/usr/bin/env node --no-warnings

import Mavka from "../main.js";
import FileLoader from "../loaders/fileLoader.js";
import { makePrintDiiaCell, makeReadDiiaCell } from "../std/io.js";
import promptSync from "prompt-sync";
import { makeToNumberDiiaCell } from "../std/casts.js";
import { makeLoadExtensionFromFileDiiaCell, makeLoadExtensionFromNetworkDiiaCell } from "../std/extensions.js";
import { makeRangeDiiaCell } from "../std/ranges.js";
import { ThrowValue } from "../interpreter/instructions/throwInstruction.js";
import { makeGetJsonDiiaCell } from "../std/network.js";
import { ListConstructorCell } from "../interpreter/cells/structureCell.js";

const cwdPath = process.cwd();

let filename = process.argv[2];

function buildGlobalContext(mavka) {
  const context = new mavka.Context(mavka, null, {
    "друк": makePrintDiiaCell(mavka),
    "читати": makeReadDiiaCell(mavka),
    "до_числа": makeToNumberDiiaCell(mavka),
    "підключити_розширення_з_файлу": makeLoadExtensionFromFileDiiaCell(mavka),
    "підключити_розширення_з_мережі": makeLoadExtensionFromNetworkDiiaCell(mavka),
    "діапазон": makeRangeDiiaCell(mavka),
    "отримати_джсон": makeGetJsonDiiaCell(mavka, null),
    "Список": new ListConstructorCell(mavka, null)
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
  if (!filename.endsWith(".дія")) {
    filename = `${filename}.дія`;
  }

  const mavka = new Mavka({
    buildGlobalContext,
    buildLoader,
    buildExternal
  });

  const context = new mavka.Context(mavka);
  context.set("__module_dirname__", cwdPath);
  context.set("__module_path__", `${cwdPath}/${filename}`);

  const name = filename.substring(0, filename.length - 4);

  try {
    await mavka.loader.load(context, name, false);
  } catch (e) {
    if (e instanceof Error) {
      console.error(e.message);
    } else if (typeof e === "string") {
      console.error(e);
    } else if (e instanceof ThrowValue) {
      const cell = mavka.toCell(e.value);
      console.error(`Не вдалось зловити "${cell.asString().asJsString()}"`);
    } else {
      console.log(e);
    }
  }
} else {
  console.log("дія :файл");
}
