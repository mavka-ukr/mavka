#!/usr/bin/env node

import process from "process";
import path from "path";
import { exec, spawn } from "child_process";
import { run } from "../run.js";
import version from "../version.js";

process.removeAllListeners("warning");

const options = [];
let command = "";
const rest = [];
for (let i = 2; i < process.argv.length; i++) {
  const arg = process.argv[i];
  if (arg.startsWith("-")) {
    options.push(arg);
  } else {
    command = arg;
    if (["джеджалик", "пак", "версія", "допомога"].includes(command)) {
      rest.push(...process.argv.slice(i + 1));
    } else {
      rest.push(...process.argv.slice(i));
    }
    break;
  }
}
if (!command) {
  command = "допомога";
}

const helpMessage = `
Використання:
  мавка [...опції] <модуль.м> [...аргументи]
  мавка [...опції] <команда> [...аргументи]

Доступні команди:
  <модуль.м> — виконати модуль
    Опції: ті самі, що і у Джеджалика

  джеджалик - запустити Джеджалик
    Опції: немає

  пак - запустити Пак
    Опції: немає

  версія — показати версію Мавки
    Опції: немає

  допомога — показати це повідолення
    Опції: немає
`.trim();

if (command === "допомога") {
  console.log(helpMessage);
  process.exit(0);
} else if (command === "версія") {
  console.log(version);
  process.exit(0);
} else if (command === "джеджалик") {
  spawn("jejalyk", [...rest], { stdio: "inherit" });
} else if (command === "пак") {
  spawn("pak", [...rest], { stdio: "inherit" });
} else {
  const inputFile = rest[0];
  if (!inputFile) {
    console.error(helpMessage);
    process.exit(1);
  }
  const modulePath = path.resolve(inputFile);

  exec(`jejalyk ${modulePath}`, async function(error, stdout, stderr) {
    if (error) {
      process.stdout.write(stderr);
      process.exit(1);
    }

    if (stderr) {
      process.stdout.write(stderr);
      process.exit(1);
    }

    await run(`
(async function() {
  try {
    ${stdout}
  } catch (e) {
    console.error(String(e));
  }
})()
`);
  });
}
