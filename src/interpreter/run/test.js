import { runNode } from "./index.js";

function runTestNode(context, node) {
    const left = runNode(context, node.left);
    const right = runNode(context, node.right);

    return ({
        '==': () => left.equals(right),
        '!=': () => left.notEquals(right),
        '>': () => left.greaterThan(right),
        '<': () => left.lesserThan(right),
        '>=': () => left.greaterThanOrEquals(right),
        '<=': () => left.lesserThanOrEquals(right),
    }[node.operation])();
}

export default runTestNode;
