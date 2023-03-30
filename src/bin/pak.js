#!/usr/bin/env node

import { pakAddFromRepoUrl } from "mavka-pak";

const command = process.argv[2];

if (command === "додати") {
  const name = process.argv[3];
  const repoUrl = process.argv[4];

  if (repoUrl) {
    console.log(`Додаємо "${name}" з ${repoUrl}...`);

    await pakAddFromRepoUrl(name, repoUrl, process.cwd());

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
