import { runNode } from "./index.js";
import { WaitVal } from "../val/index.js";

function runWaitChainNode(context, node) {
    return new WaitVal(runNode(context, node.chain));
}

export default runWaitChainNode;
