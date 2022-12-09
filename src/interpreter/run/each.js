import { run, runNode } from "./index.js";

function runEachNode(context, node) {
    const iterator = runNode(context, node.iterator);

    let result = null;

    for (const element of iterator) {
        context.set(node.name, element);

        result = run(context, node.body);
    }

    context.set(node.name, undefined);

    return result;
}

export default runEachNode;
