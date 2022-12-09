import { runNode, runNodeAsync } from "./index.js";

function runArgs(context, args) {
    const runSync = () => {
        if (Array.isArray(args)) {
            return args.map((node) => runNode(context, node));
        } else {
            args = { ...args };

            for (const [k, v] of Object.entries(args)) {
                args[k] = runNode(context, v);
            }

            return args;
        }
    }

    const runAsync = async () => {
        if (Array.isArray(args)) {
            return await Promise.all(args.map((node) => runNodeAsync(context, node)));
        } else {
            args = { ...args };

            for (const [k, v] of Object.entries(args)) {
                args[k] = await runNodeAsync(context, v);
            }

            return args;
        }
    }

    return context.vars.__async__ ? runAsync() : runSync();
}

export default runArgs;
