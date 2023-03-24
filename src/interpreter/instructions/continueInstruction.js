import Instruction from "./utils/instruction.js";

class ContinueInstruction extends Instruction {
  /**
   * @param {Context} context
   * @param {ContinueNode} node
   * @returns {*}
   */
  runSync(context, node) {
    this.mavka.throw(context, `"продовжити" наразі недоступно.`);
  }

  /**
   * @param {Context} context
   * @param {ContinueNode} node
   * @returns {Promise<*>}
   */
  async runAsync(context, node) {
    this.mavka.throw(context, `"продовжити" наразі недоступно.`);
  }
}

export default ContinueInstruction;
