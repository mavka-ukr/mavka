#!/usr/bin/env node

import process from "process";
import path from "path";
import { fileURLToPath } from "url";
import os from "os";
import fs from "fs";
import axios from "axios";
import { Uint8ArrayReader, ZipReader } from "@zip.js/zip.js";
import { spawn } from "child_process";
import semver from "semver";
import mavkaVersion from "../mavkaVersion.js";

console.log("Тимчасово недоступно.");
process.exit(1);

function printProgress(name, progress) {
  process.stdout.clearLine(0);
  process.stdout.cursorTo(0);
  process.stdout.write(`[ ${progress}% ] ${name}`);
}

function clearProgress() {
  process.stdout.clearLine(0);
  process.stdout.cursorTo(0);
}

const cwdPath = process.cwd();
const binPath = path.dirname(fileURLToPath(import.meta.url));
const userHomeDir = os.homedir();
const paksDirname = `${userHomeDir}/.паки`;
let command = process.argv[2] || "";

if (!command) {
  console.log(`
Використання:
  пак <назва> [...аргументи]
  пак <команда> [...аргументи]

Доступні команди:
  пак <назва> — виконати пак
  пак завантажити <назва> — завантажити пак
  `.trim());
  process.exit(0);
}

if (!fs.existsSync(paksDirname)) {
  fs.mkdirSync(paksDirname);
}

let commandParts;
let pakName;
let pakVersion;
let pakPath;

if (command === "завантажити") {
  command = process.argv[3];
  commandParts = command.split("/");
  pakName = commandParts[0];
  pakVersion = commandParts[1];
  pakPath = `${paksDirname}/${pakName}`;
  if (!fs.existsSync(pakPath)) {
    fs.mkdirSync(pakPath);
  }

  if (!pakVersion) {
    const response = await axios.get(`https://пак.укр/${pakName}/last-version.txt`)
      .catch((e) => {
        console.error(`Помилка отримання версії паку "${pakName}": ${e.message}`);
        process.exit(1);
      });
    pakVersion = response.data;
    const pakVersionPath = `${pakPath}/${pakVersion}`;
    if (fs.existsSync(pakVersionPath)) {
      console.error(`Пак "${pakName}/${pakVersion}" вже існує.`);
      process.exit(1);
    } else {
      await downloadVersion(pakVersion);
      console.log(`Пак "${pakName}/${pakVersion}" завантажено.`);
      process.exit(0);
    }
  }
} else {
  commandParts = command.split("/");
  pakName = commandParts[0];
  pakVersion = commandParts[1];
  pakPath = `${paksDirname}/${pakName}`;
  if (!fs.existsSync(pakPath)) {
    fs.mkdirSync(pakPath);
  }

  if (!pakVersion) {
    const versions = fs.readdirSync(pakPath);
    const latest = versions.sort((a, b) => {
      if (semver.gt(a, b)) {
        return 1;
      }
      if (semver.lt(a, b)) {
        return -1;
      }
      return 0;
    });
    pakVersion = latest[latest.length - 1];
    if (!pakVersion) {
      const response = await axios.get(`https://пак.укр/${pakName}/last-version.txt`)
        .catch((e) => {
          console.error(`Помилка отримання версії паку "${pakName}": ${e.message}`);
          process.exit(1);
        });
      pakVersion = response.data;
    }
  }
}

if (!pakVersion) {
  console.error(`Помилка: не вказано версію паку "${pakName}"!`);
  process.exit(1);
}

async function downloadVersion(pakVersion) {
  const url = `https://завантажити.пак.укр/${pakName}-${pakVersion}.zip`;
  const pakVersionPath = `${pakPath}/${pakVersion}`;

  printProgress(`${pakName}/${pakVersion}`, 0);
  const r = await axios
    .get(url, {
      onDownloadProgress: (progressEvent) => {
        printProgress(`${pakName}/${pakVersion}`, Math.floor(progressEvent.progress * 100 || 0));
      },
      responseType: "arraybuffer",
      headers: {
        "X-Mavka-Version": mavkaVersion
      }
    }).catch((e) => {
      clearProgress();
      console.error(`Помилка завантаження паку "${pakName}/${pakVersion}": ${e.message}`);
      process.exit(1);
    });
  fs.mkdirSync(pakVersionPath, { recursive: true });
  const zipFileReader = new Uint8ArrayReader(new Uint8Array(r.data));
  const zipReader = new ZipReader(zipFileReader);
  const entries = await zipReader.getEntries();
  for (const entry of entries) {
    const entryStream = new TransformStream();
    const entryArrayBufferPromise = new Response(entryStream.readable).arrayBuffer();
    await entry.getData(entryStream.writable);
    const fileName = entry.filename;
    const fileArrayBuffer = await entryArrayBufferPromise;
    fs.writeFileSync(`${pakVersionPath}/${fileName}`, Buffer.from(fileArrayBuffer));
  }
  await zipReader.close();
  clearProgress();
}

const pakVersionPath = `${pakPath}/${pakVersion}`;

if (!fs.existsSync(pakVersionPath)) {
  await downloadVersion(pakVersion);
}

let modulePath = `${pakVersionPath}/запуск.м`;
if (fs.existsSync(modulePath)) {
} else {
  modulePath = `${pakVersionPath}/старт.м`;
  if (!fs.existsSync(modulePath)) {
    console.error(`Неможливо запустити пак "${pakName}/${pakVersion}": модуль "старт.м" не знайдено.`);
    process.exit(1);
  }
}
spawn("mavka", [modulePath, ...process.argv.slice(3)], { stdio: "inherit" });

