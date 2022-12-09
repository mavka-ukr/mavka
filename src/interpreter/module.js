import path from "path";
import { Context } from "./context/index.js";
import { parse } from "diia-parser";
import { run } from "./run/index.js";
import fs from "fs";

const modulesCache = {};

export async function loadModuleNext(globalContext, modulePath) {
    if (modulesCache[modulePath]) {
        return modulesCache[modulePath];
    }

    const rootDir = path.dirname(modulePath);

    const context = new Context(globalContext);
    context.set('__module_path__', modulePath);
    context.set('__module_root_path__', rootDir);
    context.set('__async__', true);

    const moduleCode = fs.readFileSync(modulePath).toString();
    const moduleAst = parse(moduleCode);

    const givenContext = new Context();
    context.set('__given_context__', givenContext);

    modulesCache[modulePath] = context;

    await run(context, moduleAst);

    return context;
}
