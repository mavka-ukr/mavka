import Instruction from "./utils/instruction.js";
import { convertParamNodes } from "./utils/params.js";
import Method from "../cells/common/method.js";

function doOperation(mavka, context, node) {
  const parameters = convertParamNodes(mavka, context, node.params);

  if (node.structure) {
    const method = new Method(
      node.name.name,
      parameters,
      node.body,
      node.async,
      context
    );

    const cell = mavka.runSync(context, node.structure, { forceSync: true });

    if (cell instanceof mavka.ObjectStructureCell) {
      cell.methods[node.name.name] = method;
    } else {
      mavka.throw(context, `Не вдалось встановити дію "${node.structure.name}.${node.name.name}".`);
    }
  } else {
    const diia = mavka.makeDiia(
      node.name.name,
      parameters,
      mavka.Context,
      context,
      node.async,
      node.body,
      mavka.diiaStructureCellInstance
    );

    context.set(node.name.name, diia);
  }

  return mavka.emptyCellInstance;
}

class DiiaInstruction extends Instruction {
  /**
   * @param {Context} context
   * @param {DiiaNode} node
   * @returns {*}
   */
  runSync(context, node) {
    return doOperation(this.mavka, context, node);
  }

  /**
   * @param {Context} context
   * @param {DiiaNode} node
   * @returns {Promise<*>}
   */
  async runAsync(context, node) {
    return doOperation(this.mavka, context, node);
  }
}

export default DiiaInstruction;
