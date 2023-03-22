import Instruction from "./utils/instruction.js";

class ObjectDestructionInstruction extends Instruction {
  /**
   * @param {Context} context
   * @param {ObjectDestructionNode} node
   * @returns {*}
   */
  runSync(context, node) {
    //
  }

  /**
   * @param {Context} context
   * @param {ObjectDestructionNode} node
   * @returns {Promise<*>}
   */
  async runAsync(context, node) {
    //
  }
}

export default ObjectDestructionInstruction;
