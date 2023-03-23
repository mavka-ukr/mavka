import Instruction from "./utils/instruction.js";
import { convertParamNodes } from "./utils/params.js";

function doOperation(mavka, context, node) {
  const parameters = convertParamNodes(mavka, context, node.params);

  return new mavka.makeDiia(
    "функція",
    parameters,
    mavka.LightContext,
    context,
    node.async,
    node.body,
    mavka.functionStructureCellInstance
  );
}

class FunctionInstruction extends Instruction {
  /**
   * @param {Context} context
   * @param {FunctionNode} node
   * @returns {*}
   */
  runSync(context, node) {
    return doOperation(this.mavka, context, node);
  }

  /**
   * @param {Context} context
   * @param {FunctionNode} node
   * @returns {Promise<*>}
   */
  async runAsync(context, node) {
    return doOperation(this.mavka, context, node);
  }
}

export default FunctionInstruction;
