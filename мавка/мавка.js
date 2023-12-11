#!/usr/bin/env node

import process from "process";
import path from "path";
import { exec } from "child_process";
import { run } from "../run.js";
import Mavka from "../main.js";

process.removeAllListeners("warning");

let command = process.argv[2] || "";

const helpMessage = `
Використання:
  мавка [...опції] <модуль.м> [...аргументи]
  мавка [...опції] <команда> [...аргументи]

Доступні команди:
  мавка <модуль.м> — виконує модуль
  мавка джеджалик - запускає джеджалик
  мавка пак - запускає пак
  мавка версія — показує версію Мавки
  мавка допомога — друкує це повідолення
`.trim();

if (!command) {
  console.log(helpMessage);
  process.exit(0);
} else if (command === "версія") {
  console.log(Mavka.VERSION);
  process.exit(0);
} else if (command === "допомога") {
  console.log(helpMessage);
  process.exit(0);
}

const modulePath = path.resolve(command);

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

