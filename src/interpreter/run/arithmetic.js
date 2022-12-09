import { runNode, runNodeAsync } from "./index.js";

function runArithmeticNode(context, node) {
    const runSync = () => {
        const left = runNode(context, node.left);
        const right = runNode(context, node.right);

        return ({
            '+': () => left.plus(right),
            '-': () => left.minus(right),
            '*': () => left.multiply(right),
            '/': () => left.divide(right),
        }[node.operation])();
    }

    const runAsync = async () => {
        const left = await runNodeAsync(context, node.left);
        const right = await runNodeAsync(context, node.right);

        return ({
            '+': () => left.plus(right),
            '-': () => left.minus(right),
            '*': () => left.multiply(right),
            '/': () => left.divide(right),
        }[node.operation])();
    }

    return context.vars.__async__ ? runAsync() : runSync();
}

export default runArithmeticNode;
