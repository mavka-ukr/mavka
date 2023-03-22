import Instruction from "./utils/instruction.js";

class PreDecrementInstruction extends Instruction {
  /**
   * @param {Context} context
   * @param {PreDecrementNode} node
   * @returns {*}
   */
  runSync(context, node) {
    //
  }

  /**
   * @param {Context} context
   * @param {PreDecrementNode} node
   * @returns {Promise<*>}
   */
  async runAsync(context, node) {
    //
  }
}

export default PreDecrementInstruction;
