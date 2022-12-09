#!/usr/bin/env node

import "./interpreter/std.js";
import { runProgram } from "./interpreter/program.js";

const cwdPath = process.cwd();

let filename = process.argv[2];

if (filename && filename !== 'допомога') {
    if (!filename.endsWith('.дія')) {
        filename = `${filename}.дія`;
    }

    await runProgram(`${cwdPath}/${filename}`);
} else {
    console.log('дія :файл');
}
