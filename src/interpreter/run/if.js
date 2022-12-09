import { run, runNode, runNodeAsync } from "./index.js";

function runIfNode(context, node) {
    const runSync = () => {
        const expressionResult = runNode(context, node.expression);

        if (expressionResult.asJsBoolean()) {
            return run(context, node.body);
        } else {
            return run(context, node.elseBody);
        }
    }

    const runAsync = async () => {
        let expressionResult = await runNodeAsync(context, node.expression);

        if (expressionResult.asBoolean().asJsBoolean()) {
            return run(context, node.body);
        } else {
            return run(context, node.elseBody);
        }
    }

    return context.vars.__async__ ? runAsync() : runSync();
}

export default runIfNode;
