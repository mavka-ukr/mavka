import { parse } from "diia-parser";
import Context from "./context.js";
import fs from "fs";
import path from "path";
import { resolve } from 'import-meta-resolve';
import promptSync from "prompt-sync";

class DiiaArray extends Array {
    constructor(...args) {
        super(...args);
    }

    toString() {
        return 'масив(' + this.map((v) => v.toString()).join(', ') + ')';
    }
}

class DiiaObject {
    constructor(args) {
        Object.assign(this, args)
    }
}

global.DiiaArray = DiiaArray;
global.DiiaObject = DiiaObject;

const prompt = promptSync({ sigint: true });

const currDir = await resolve("./", import.meta.url);
const rootDir = path.dirname(new URL(currDir).pathname);

async function loadModule(path, parent) {
    return new Promise((resolve) => {
        fs.readFile(path, (error, data) => {
            const code = data.toString();

            const modAst = parse(code);
            const modContext = new Context(parent);

            modContext.run(modAst);

            resolve(modContext);
        });
    });
}

function* makeRangeIterator(start = 0, end = Infinity, step = 1) {
    let iterationCount = 0;
    for (let i = start; i < end; i += step) {
        iterationCount++;
        yield i;
    }
    return iterationCount;
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
            globalContext.functions['діапазон'] = makeRangeIterator;
            globalContext.functions['jsNew'] = (fn, parameters) => new fn(...parameters);
            globalContext.vars['фс'] = await loadModule(rootDir + '/сб/файлова_система.дія', globalContext);
            globalContext.vars['М'] = await loadModule(rootDir + '/сб/математика.дія', globalContext);

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
