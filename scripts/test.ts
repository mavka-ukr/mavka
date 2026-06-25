#!/home/prykhozhdenko/.local/share/nvm/v26.0.0/bin/node

import fs from "fs";
import pathModule from 'path';
import process from "process";
import { type IMavkaFS, Mavka } from "../external/js/mavka.ts";

const wasmBuffer = fs.readFileSync('./будування/0.125.7/васм64/готове/мавка.wasm');

const mavkaFS: IMavkaFS = {
  readFileSync(path) {
    // console.log("readFileSync", path)
    return fs.readFileSync(path);
  },
  checkIfExistsAndIsFile(path) {
    // console.log("checkIfExistsAndIsFile", path)
    try {
      return fs.statSync(path).isFile();
    } catch (e) {
      return false;
    }
  },
  getAbsolutePath(path) {
    // console.log("getAbsolutePath", path)
    return pathModule.resolve(path);
  }
};
const mavka = new Mavka(mavkaFS, wasmBuffer, {
  cwd: () => process.cwd(),
  print: (color, value) => process.stdout.write(value),
  readlineSync: (prefix) => {
    process.stdout.write(prefix);

    return fs.readFileSync(0, 'utf8');
  }
});

await mavka.instantiate();

mavka.run([...process.argv.slice(2)])