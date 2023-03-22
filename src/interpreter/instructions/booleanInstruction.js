import Instruction from "./utils/instruction.js";

class BooleanInstruction extends Instruction {
  /**
   * @param {Context} context
   * @param {BooleanNode} node
   * @returns {*}
   */
  runSync(context, node) {
    return this.mavka.toCell(node.value);
  }

  /**
   * @param {Context} context
   * @param {BooleanNode} node
   * @returns {Promise<*>}
   */
  async runAsync(context, node) {
    return this.mavka.toCell(node.value);
  }
}

export default BooleanInstruction;
