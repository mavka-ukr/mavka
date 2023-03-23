import Instruction from "./utils/instruction.js";
import { convertParamNodes } from "./utils/params.js";

function doOperation(mavka, context, node) {
  const parameters = convertParamNodes(mavka, context, node.params);

  return new mavka.makeDiia(
    "",
    parameters,
    mavka.Context,
    context,
    node.async,
    node.body,
    mavka.anonymousDiiaStructureCellInstance
  );
}

class AnonymousDiiaInstruction extends Instruction {
  /**
   * @param {Context} context
   * @param {AnonymousDiiaNode} node
   * @returns {*}
   */
  runSync(context, node) {
    return doOperation(this.mavka, context, node);
  }

  /**
   * @param {Context} context
   * @param {AnonymousDiiaNode} node
   * @returns {Promise<*>}
   */
  async runAsync(context, node) {
    return doOperation(this.mavka, context, node);
  }
}

export default AnonymousDiiaInstruction;
