#!/usr/bin/env node

import clone from "git-clone/promise.js";
import fs from "fs";

const command = process.argv[2];

if (command === 'додати') {
    const repo = process.argv[3];
    const name = process.argv[4];

    if (name) {
        console.log(`Додаємо "${name}" з ${repo}...`);

        const path = `.паки/${name}`;

        fs.rmSync(path, { recursive: true, force: true });

        await clone(repo, path);

        console.log(`"${name}" додано.`);
    } else {
        console.log('пак додати :репозиторій :назва')
    }
} else if (command === 'створити') {
    const name = process.argv[3];

    console.log('пак створити :назва');
} else if (command === 'ініт') {
    const name = process.argv[3];

    console.log('пак ініт :назва');
} else {
    console.log('пак (додати,створити,ініт)')
}
