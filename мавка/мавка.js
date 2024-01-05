#!/usr/bin/env node

import process from "process";
import path from "path";
import { spawn } from "child_process";
import mavkaVersion from "../mavkaVersion.js";
import fs from "fs";
import { run } from "../run.js";

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
  console.log(mavkaVersion);
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

  const tempFilename = path.resolve(`${new Date().getTime().toString()}_${Math.round(Math.random() * 1000)}.js`);

  spawn(`jejalyk`, [...options, modulePath, tempFilename], { stdio: "inherit" })
    .on("exit", async function() {
      if (fs.existsSync(tempFilename)) {
        const code = fs.readFileSync(tempFilename, "utf8");
        fs.unlinkSync(tempFilename);

        await run(`var run = async function() {
${code}
};
run()`);

      }
    });
}
