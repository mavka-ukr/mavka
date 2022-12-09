import { StructureConstructorVal } from "../val/index.js";

function runStructureNode(context, node) {
    const structureConstructor = new StructureConstructorVal(context, node);

    context.set(node.name, structureConstructor);

    return structureConstructor;
}

export default runStructureNode;
