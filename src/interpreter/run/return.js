import { ReturnValue, runNode } from "./index.js";

function runReturnNode(context, node) {
    return new ReturnValue(runNode(context, node.value));
}

export default runReturnNode;
