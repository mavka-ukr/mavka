import Instruction from "./utils/instruction.js";

class ArrayDestructionInstruction extends Instruction {
  /**
   * @param {Context} context
   * @param {ArrayDestructionNode} node
   * @returns {*}
   */
  runSync(context, node) {
    //
  }

  /**
   * @param {Context} context
   * @param {ArrayDestructionNode} node
   * @returns {Promise<*>}
   */
  async runAsync(context, node) {
    //
  }
}

export default ArrayDestructionInstruction;
