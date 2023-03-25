import Instruction from "./utils/instruction.js";

class ArrayDestructionInstruction extends Instruction {
  /**
   * @param {Context} context
   * @param {ArrayDestructionNode} node
   * @returns {*}
   */
  runSync(context, node) {
    this.mavka.fall(context, this.mavka.makeText(`Деструкція наразі недоступна.`));
  }

  /**
   * @param {Context} context
   * @param {ArrayDestructionNode} node
   * @returns {Promise<*>}
   */
  async runAsync(context, node) {
    this.mavka.fall(context, this.mavka.makeText(`Деструкція наразі недоступна.`));
  }
}

export default ArrayDestructionInstruction;
