import Instruction from "./utils/instruction.js";

class BreakInstruction extends Instruction {
  /**
   * @param {Context} context
   * @param {BreakNode} node
   * @returns {*}
   */
  runSync(context, node) {
    this.mavka.throw(context, `"зупинити" наразі недоступно.`);
  }

  /**
   * @param {Context} context
   * @param {BreakNode} node
   * @returns {Promise<*>}
   */
  async runAsync(context, node) {
    this.mavka.throw(context, `"зупинити" наразі недоступно.`);
  }
}

export default BreakInstruction;
