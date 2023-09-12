import Instruction from "./utils/instruction.js";

class TypeValueSingleInstruction extends Instruction {
  /**
   * @param {Context} context
   * @param {TypeValueSingleNode} node
   * @returns {*}
   */
  runSync(context, node) {
    //
  }

  /**
   * @param {Context} context
   * @param {TypeValueSingleNode} node
   * @returns {Promise<*>}
   */
  async runAsync(context, node) {
    //
  }
}

export default TypeValueSingleInstruction;
