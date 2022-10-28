import path from "path";
import fs from "fs";
import { parse } from "diia-parser";
import Context, { ModuleContext } from "./context.js";

const modulesCache = {};

export function loadModule(globalContext, modulePath, onBeforeRun) {
    if (modulesCache[modulePath]) {
        return modulesCache[modulePath];
    }

    const rootDir = path.dirname(modulePath);

    const context = new Context(globalContext);
    context.set('__шлях_до_модуля', modulePath);
    context.set('__кореневий_шлях_до_модуля', rootDir);

    const moduleCode = fs.readFileSync(modulePath).toString();
    const moduleAst = parse(moduleCode);

    modulesCache[modulePath] = context;

    const moduleContext = new ModuleContext();
    context.set('__moduleContext', moduleContext);

    if (onBeforeRun) {
        onBeforeRun(context);
    }

    context.run(moduleAst);

    return context;
}
