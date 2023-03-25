import Instruction from "./utils/instruction.js";

class PreDecrementInstruction extends Instruction {
  /**
   * @param {Context} context
   * @param {PreDecrementNode} node
   * @returns {*}
   */
  runSync(context, node) {
    this.mavka.fall(context, this.mavka.makeText(`Декремент наразі недоступний.`));
  }

  /**
   * @param {Context} context
   * @param {PreDecrementNode} node
   * @returns {Promise<*>}
   */
  async runAsync(context, node) {
    this.mavka.fall(context, this.mavka.makeText(`Декремент наразі недоступний.`));
  }
}

export default PreDecrementInstruction;
