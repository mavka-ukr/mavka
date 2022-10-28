import { loadModule } from "./module.js";
import { resolve } from "import-meta-resolve";
import path from "path";

const currPath = new URL(await resolve("./", import.meta.url)).pathname;
const rootPath = path.dirname(path.dirname(currPath));

function buildGlobalContext() {
    const globalContext = loadModule(null, `${rootPath}/сб/глобальний_контекст.дія`, (context) => {
        global.globalContext = context;

        context.set('global', global);
    });

    globalContext.set('фс', loadModule(globalContext, `${rootPath}/сб/файлова_система.дія`));
    globalContext.set('М', loadModule(globalContext, `${rootPath}/сб/математика.дія`));
    globalContext.set('jsNew', (fn, parameters) => new fn(...parameters));

    return globalContext;
}

const globalContext = buildGlobalContext();

export function runProgram(code, path) {
    return loadModule(globalContext, path);
}
