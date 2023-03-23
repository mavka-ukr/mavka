import Instruction from "./utils/instruction.js";

class NumberInstruction extends Instruction {
  /**
   * @param {Context} context
   * @param {NumberNode} node
   * @returns {*}
   */
  runSync(context, node) {
    return this.mavka.makeNumber(node.value);
  }

  /**
   * @param {Context} context
   * @param {NumberNode} node
   * @returns {Promise<*>}
   */
  async runAsync(context, node) {
    return this.mavka.makeNumber(node.value);
  }
}

export default NumberInstruction;
