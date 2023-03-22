import Instruction from "./utils/instruction.js";

class ContinueInstruction extends Instruction {
  /**
   * @param {Context} context
   * @param {ContinueNode} node
   * @returns {*}
   */
  runSync(context, node) {
    //
  }

  /**
   * @param {Context} context
   * @param {ContinueNode} node
   * @returns {Promise<*>}
   */
  async runAsync(context, node) {
    //
  }
}

export default ContinueInstruction;
