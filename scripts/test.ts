#!/home/prykhozhdenko/.local/share/nvm/v26.0.0/bin/node

import fs from "node:fs";
import pathModule from 'node:path';
import process from "node:process";
import * as readline from 'node:readline';
import {
  type IMavkaFS,
  Mavka,
  КолірВиводуЖовтий,
  КолірВиводуЗелений,
  КолірВиводуСиній,
  КолірВиводуСтандартний,
  КолірВиводуЧервоний,
} from "../external/js/mavka.ts";

const wasmBuffer = fs.readFileSync('./будування/0.125.7/васм64/готове/мавка.wasm');

let rl: readline.Interface | null = null;
let readlineCallback: ((value: string, end: boolean) => void) | null = null;

function getInterface(): readline.Interface {
  if (rl) return rl;

  rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
  });

  rl.on('close', () => {
    rl = null;
    if (readlineCallback) {
      const cb = readlineCallback;
      readlineCallback = null;
      cb("", true);
    }
  });

  return rl;
}

const mavkaFS: IMavkaFS = {
  readFileSync(path) {
    try {
      return fs.readFileSync(path);
    } catch {
      return false;
    }
  },
  checkIfExistsAndIsFile(path) {
    try {
      return fs.statSync(path).isFile();
    } catch {
      return false;
    }
  },
  getAbsolutePath(path) {
    return pathModule.resolve(path);
  }
};

const colorsMap = {
  [КолірВиводуСтандартний]: '\x1b[0m',
  [КолірВиводуЧервоний]: '\x1b[31m',
  [КолірВиводуЗелений]: '\x1b[32m',
  [КолірВиводуЖовтий]: '\x1b[33m',
  [КолірВиводуСиній]: '\x1b[34m',
} as const;

const mavka = new Mavka(mavkaFS, wasmBuffer, {
  cwd: () => process.cwd(),
  print: (color, value) => {
    const selectedColor = colorsMap[color] || colorsMap[КолірВиводуСтандартний];
    process.stdout.write(`${selectedColor}${value}${colorsMap[КолірВиводуСтандартний]}`);
  },
  readlineSync: (prefix) => {
    if (rl) {
      rl.close();
    }
    process.stdout.write(prefix);
    return fs.readFileSync(0, 'utf8').replace(/\r?\n$/, '');
  },
  readline: (prefix, callback) => {
    readlineCallback = callback;
    getInterface().question(prefix, (value) => {
      readlineCallback = null;
      callback(value, false);
    });
  },
  exit: (code) => {
    if (rl) {
      rl.close();
    }
    process.exit(code);
  }
});

await mavka.instantiate();

mavka.run(process.argv.slice(1));