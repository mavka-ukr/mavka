import Instruction from "./utils/instruction.js";

class ObjectDestructionInstruction extends Instruction {
  /**
   * @param {Context} context
   * @param {ObjectDestructionNode} node
   * @returns {*}
   */
  runSync(context, node) {
    this.mavka.throw(context, `Деструкція наразі недоступна.`);
  }

  /**
   * @param {Context} context
   * @param {ObjectDestructionNode} node
   * @returns {Promise<*>}
   */
  async runAsync(context, node) {
    this.mavka.throw(context, `Деструкція наразі недоступна.`);
  }
}

export default ObjectDestructionInstruction;
