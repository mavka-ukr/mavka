import { loadModule } from "./module.js";
import { resolve } from "import-meta-resolve";
import path from "path";
import axios from "axios";

const currPath = new URL(await resolve("./", import.meta.url)).pathname;
const rootPath = path.dirname(path.dirname(currPath));

class DiiaPromise extends Promise {
    тоді(дія) {
        return this.then(дія);
    }
}

function diia_fetch(url, query) {
    return new DiiaPromise((resolve, reject) => {
        axios(url, {
            query,
        }).then((r) => r.data)
            .then(resolve)
            .catch(reject);
    });
}

function diia_promise(promise) {
    return new DiiaPromise((resolve, reject) => {
        promise
            .then(resolve)
            .catch(reject);
    });
}

function buildGlobalContext() {
    const globalContext = loadModule(null, `${rootPath}/сб/глобальний_контекст.дія`, (context) => {
        global.globalContext = context;

        context.set('global', global);
    });

    globalContext.set('фс', loadModule(globalContext, `${rootPath}/сб/файлова_система.дія`));
    globalContext.set('М', loadModule(globalContext, `${rootPath}/сб/математика.дія`));
    globalContext.set('jsNew', (fn, ...parameters) => new fn(...parameters));
    globalContext.set('отримати', diia_fetch);
    globalContext.set('проміс', diia_promise);

    return globalContext;
}

const globalContext = buildGlobalContext();

export function runProgram(code, path) {
    return loadModule(globalContext, path);
}
