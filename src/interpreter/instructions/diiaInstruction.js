import Instruction from "./utils/instruction.js";
import { ThrowValue } from "./throwInstruction.js";
import { convertParamNodes } from "./utils/params.js";

function doOperation(mavka, context, node) {
  const parameters = convertParamNodes(mavka, context, node.params);

  const diia = mavka.makeDiia(
    node.name.name,
    parameters,
    mavka.Context,
    context,
    node.async,
    node.body,
    mavka.diiaStructureCellInstance
  );

  if (node.structure) {
    const cell = mavka.runSync(context, node.structure, { forceSync: true });

    if (cell instanceof mavka.ObjectStructureCell) {
      cell.methods[node.name.name] = diia;
    } else {
      throw new ThrowValue(context, `Не вдалось встановити дію "${node.structure.name}.${node.name.name}".`);
    }
  } else {
    context.set(node.name.name, diia);
  }

  return diia;
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
