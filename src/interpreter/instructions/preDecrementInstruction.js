import Instruction from "./utils/instruction.js";

class PreDecrementInstruction extends Instruction {
  /**
   * @param {Context} context
   * @param {PreDecrementNode} node
   * @returns {*}
   */
  runSync(context, node) {
    this.mavka.throw(context, `Декремент наразі недоступний.`);
  }

  /**
   * @param {Context} context
   * @param {PreDecrementNode} node
   * @returns {Promise<*>}
   */
  async runAsync(context, node) {
    this.mavka.throw(context, `Декремент наразі недоступний.`);
  }
}

export default PreDecrementInstruction;
