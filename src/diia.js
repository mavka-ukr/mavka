#!/usr/bin/env node

import fs from "fs";
import { runProgram } from "./interpreter/index.js";
import "./interpreter/std.js";

const cwdPath = process.cwd();

let filename = process.argv[2];

export const modules = {};

if (filename && filename !== 'допомога') {
    if (!filename.endsWith('.дія')) {
        filename = `${filename}.дія`;
    }

    fs.readFile(filename, async (error, data) => {
        if (error) {
            console.error(`Не вдалось прочитати файл "${filename}".`);
            return;
        }

        const code = data.toString();

        await runProgram(code, `${cwdPath}/${filename}`);
    });
} else {
    console.log('дія :файл:');
}
