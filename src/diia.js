#!/usr/bin/env node

import fs from "fs";
import { run } from "./interpreter.js";

let filename = process.argv[2];

if (filename) {
    if (!filename.endsWith('.дія')) {
        filename = `${filename}.дія`;
    }

    fs.readFile(filename, (error, data) => {
        if (error) {
            console.error(`Не вдалось прочитати файл "${filename}".`);
            return;
        }

        const code = data.toString();

        run(code);
    });
} else {
    console.log('дія [файл]');
}
