import { LambdaVal } from "../val/index.js";

function runLambdaNode(context, node) {
    return new LambdaVal(context, node);
}

export default runLambdaNode;
