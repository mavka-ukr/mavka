import CallNode from "diia-parser/src/ast/CallNode.js";
import runArgs from "./args.js";

function runChainNode(context, chain) {
    const runSync = () => {
        let result = context;

        for (const node of chain.nodes) {
            if (typeof node === 'string') {
                result = result.get(node);
            } else if (node instanceof CallNode) {
                const args = runArgs(context, node.parameters);

                if (result) {
                    const fn = result.get(node.name);

                    result = fn.call(args);
                } else {
                    result = result.call(node.name, args);
                }
            }
        }

        return result;
    }

    const runAsync = async () => {
        let result = context;

        for (const node of chain.nodes) {
            if (typeof node === 'string') {
                result = result.get(node);
            } else if (node instanceof CallNode) {
                const args = await runArgs(context, node.parameters);

                if (result) {
                    const fn = result.get(node.name);

                    result = fn.call(args);
                } else {
                    result = result.call(node.name, args);
                }
            }
        }

        return result;
    }

    return context.vars.__async__ ? runAsync() : runSync();
}

export default runChainNode;
