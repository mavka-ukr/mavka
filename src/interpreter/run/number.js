import { NumberVal } from "../val/index.js";

function runNumberNode(context, node) {
    return new NumberVal(node.value);
}

export default runNumberNode;
