import Instruction from "./utils/instruction.js";

class TypeValueInstruction extends Instruction {
  /**
   * @param {Context} context
   * @param {TypeValueNode} node
   * @returns {*}
   */
  runSync(context, node) {
    //
  }

  /**
   * @param {Context} context
   * @param {TypeValueNode} node
   * @returns {Promise<*>}
   */
  async runAsync(context, node) {
    //
  }
}

export default TypeValueInstruction;
