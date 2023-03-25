import Instruction from "./utils/instruction.js";

class ObjectDestructionInstruction extends Instruction {
  /**
   * @param {Context} context
   * @param {ObjectDestructionNode} node
   * @returns {*}
   */
  runSync(context, node) {
    this.mavka.fall(context, this.mavka.makeText(`Деструкція наразі недоступна.`));
  }

  /**
   * @param {Context} context
   * @param {ObjectDestructionNode} node
   * @returns {Promise<*>}
   */
  async runAsync(context, node) {
    this.mavka.fall(context, this.mavka.makeText(`Деструкція наразі недоступна.`));
  }
}

export default ObjectDestructionInstruction;
