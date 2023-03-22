import Instruction from "./utils/instruction.js";

class BreakInstruction extends Instruction {
  /**
   * @param {Context} context
   * @param {BreakNode} node
   * @returns {*}
   */
  runSync(context, node) {
    //
  }

  /**
   * @param {Context} context
   * @param {BreakNode} node
   * @returns {Promise<*>}
   */
  async runAsync(context, node) {
    //
  }
}

export default BreakInstruction;
