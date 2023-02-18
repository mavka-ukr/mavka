import Instruction from "./instruction.js";

class NumberInstruction extends Instruction {
  /**
   * @param {Context} context
   * @param {NumberNode} node
   * @returns {*}
   */
  runSync(context, node) {
    return new this.mavka.NumberCell(this.mavka, node.value);
  }

  /**
   * @param {Context} context
   * @param {NumberNode} node
   * @returns {Promise<*>}
   */
  async runAsync(context, node) {
    return new this.mavka.NumberCell(this.mavka, node.value);
  }
}

export default NumberInstruction;
