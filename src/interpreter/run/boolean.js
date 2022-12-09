import { BooleanVal } from "../val/index.js";

function runBooleanNode(context, node) {
    return new BooleanVal(node.value);
}

export default runBooleanNode;
