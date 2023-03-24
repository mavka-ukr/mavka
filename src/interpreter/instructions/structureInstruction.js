import Instruction from "./utils/instruction.js";
import { convertParamNodes } from "./utils/params.js";
import Method from "../cells/common/method.js";

function doOperation(mavka, context, node) {
  const parentStructureCell = node.parent
    ? mavka.runSync(context, node.parent, { forceSync: true })
    : mavka.objectStructureCellInstance;

  const parameters = convertParamNodes(mavka, context, node.params);

  const methods = {};
  for (const nodeMethod of node.methods) {
    const method = new Method(
      nodeMethod.name.name,
      parameters,
      nodeMethod.body,
      nodeMethod.async,
      context
    );

    methods[method.name] = method;
  }

  const structureCell = new mavka.ObjectStructureCell(
    mavka,
    node.name.name,
    {},
    parentStructureCell,
    parameters,
    methods
  );

  context.set(node.name.name, structureCell);

  return structureCell;
}

class StructureInstruction extends Instruction {
  /**
   * @param {Context} context
   * @param {StructureNode} node
   * @returns {*}
   */
  runSync(context, node) {
    return doOperation(this.mavka, context, node);
  }

  /**
   * @param {Context} context
   * @param {StructureNode} node
   * @returns {Promise<*>}
   */
  async runAsync(context, node) {
    return doOperation(this.mavka, context, node);
  }
}

export default StructureInstruction;
