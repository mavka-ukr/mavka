import { DiiaVal } from "../val/index.js";

function runDiiaNode(context, node) {
    const diia = new DiiaVal(context, node);

    context.set(node.name, diia);

    return diia;
}

export default runDiiaNode;
