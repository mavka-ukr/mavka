#!/usr/bin/env node

import clone from "git-clone/promise.js";
import fs from "fs";

const command = process.argv[2];

if (command === "додати") {
  const name = process.argv[3];
  const repo = process.argv[4];

  if (repo) {
    console.log(`Додаємо "${name}" з ${repo}...`);

    const path = `.паки/${name}`;

    fs.rmSync(path, { recursive: true, force: true });

    await clone(repo, path);

    console.log(`"${name}" додано.`);
  } else {
    console.log("пак додати <назва> <репозиторій>");
  }
} else if (command === "видалити") {
  const name = process.argv[3];

  console.log("пак видалити <назва>");
} else {
  console.log(`
Використання:
  пак <команда> [...аргументи]

Доступні команди:
  пак додати <назва> <репозиторій> — додає пак з git-репозиторію
  пак видалити <назва> — видаляє пак
  `.trim());
}
