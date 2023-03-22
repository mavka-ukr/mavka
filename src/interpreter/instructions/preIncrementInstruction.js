import Instruction from "./utils/instruction.js";

class PreIncrementInstruction extends Instruction {
  /**
   * @param {Context} context
   * @param {PreIncrementNode} node
   * @returns {*}
   */
  runSync(context, node) {
    //
  }

  /**
   * @param {Context} context
   * @param {PreIncrementNode} node
   * @returns {Promise<*>}
   */
  async runAsync(context, node) {
    //
  }
}

export default PreIncrementInstruction;
