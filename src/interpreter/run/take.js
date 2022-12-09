import { loadModule } from "../module.js";
import { AsyncVal, ModuleVal, WaitVal } from "../val/index.js";

function runTakeNode(context, node) {
    const rootPath = context.get('__module_root_path__');

    return new WaitVal(new AsyncVal(new Promise(async (resolve) => {
        let moduleName = node.name;

        let loadedContext;

        if (node.pak) {
            loadedContext = await loadModule(globalContext, `${rootPath}/.паки/${moduleName}/${moduleName}.дія`);
        } else {
            loadedContext = await loadModule(globalContext, `${rootPath}/${moduleName}.дія`);
        }

        const givenContext = loadedContext.get('__given_context__');

        if (node.chain) {
            let k = node.chain.identifiers[0];

            let value = givenContext.get(k);

            for (k of node.chain.identifiers.slice(1)) {
                value = value.get(k);
            }

            context.set(k, value);

            resolve(value);
        } else {
            const module = new ModuleVal(moduleName, givenContext);

            context.set(node.name, module);

            resolve(module);
        }
    })));
}

export default runTakeNode;
