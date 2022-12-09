import { runNode, runNodeAsync } from "./index.js";

function runAssignNode(context, node) {
    const runSync = () => {
        let val = context;

        for (const id of node.id.identifiers.slice(0, -1)) {
            val = val.get(id);
        }

        const value = runNode(context, node.value);

        val.set(node.id.identifiers[node.id.identifiers.length - 1], value);

        return value;
    }

    const runAsync = async () => {
        let val = context;

        for (const id of node.id.identifiers.slice(0, -1)) {
            val = val.get(id);
        }

        let value = await runNodeAsync(context, node.value);

        val.set(node.id.identifiers[node.id.identifiers.length - 1], value);

        return value;
    }

    return context.vars.__async__ ? runAsync() : runSync();
}

export default runAssignNode;
