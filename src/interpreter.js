import { parse } from "diia-parser";
import Context from "./context.js";
import fs from "fs";
import path from "path";
import { resolve } from 'import-meta-resolve';
import promptSync from "prompt-sync";

const prompt = promptSync({ sigint: true });

const currDir = await resolve("./", import.meta.url);
const rootDir = path.dirname(new URL(currDir).pathname);

async function loadModule(path) {
    return new Promise((resolve) => {
        fs.readFile(path, (error, data) => {
            const code = data.toString();

            const modAst = parse(code);
            const modContext = new Context();

            modContext.run(modAst);

            resolve(modContext);
        });
    });
}

async function loadGlobalContext() {
    function readinput(question) {
        return prompt(question);
    }

    return new Promise((resolve) => {
        fs.readFile(rootDir + '/сб/глобальний_контекст.дія', async (error, data) => {
            const code = data.toString();

            const globalAst = parse(code);
            const globalContext = new Context();

            globalContext.functions['читати'] = readinput;
            globalContext.vars['фс'] = await loadModule(rootDir + '/сб/фс.дія');

            globalContext.run(globalAst);

            resolve(globalContext);
        });
    });
}

export async function run(code) {
    const globalContext = await loadGlobalContext();
    const mainAst = parse(code);
    const mainContext = new Context(globalContext);
    await mainContext.run(mainAst);
}
