import {
    httpGet,
    loadExtensionFileFnVal,
    printFnVal,
    rangeFnVal,
    readInputFnVal,
    toNumberFnVal,
    toStringFnVal
} from "./std.js";
import { Context } from "./context/index.js";
import { loadModule } from "./module.js";

global.globalContext = new Context();

globalContext.set('друк', printFnVal);
globalContext.set('діапазон', rangeFnVal);
globalContext.set('підключити_файл_розширення', loadExtensionFileFnVal);
globalContext.set('отримати', httpGet);
globalContext.set('читати', readInputFnVal);
globalContext.set('до_числа', toNumberFnVal);
globalContext.set('до_рядка', toStringFnVal);

export function runProgram(path) {
    return loadModule(globalContext, path, (context) => {
        globalContext.set('__module_path__', context.get('__module_path__'));
        globalContext.set('__module_root_path__', context.get('__module_root_path__'));
    });
}
