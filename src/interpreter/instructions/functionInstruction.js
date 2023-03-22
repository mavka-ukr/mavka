import Instruction from "./utils/instruction.js";

class FunctionInstruction extends Instruction {
  /**
   * @param {Context} context
   * @param {FunctionNode} node
   * @returns {*}
   */
  runSync(context, node) {
    return new this.mavka.FunctionCell(this.mavka, context, node);
  }

  /**
   * @param {Context} context
   * @param {FunctionNode} node
   * @returns {Promise<*>}
   */
  async runAsync(context, node) {
    return new this.mavka.FunctionCell(this.mavka, context, node);
  }
}

export default FunctionInstruction;
