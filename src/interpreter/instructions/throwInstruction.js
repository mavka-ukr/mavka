import Instruction from "./instruction.js";

export class ThrowValue {
  /**
   * @param {Context|Cell} context
   * @param {*} value
   */
  constructor(context, value) {
    this.context = context;
    this.value = value;
  }
}

class ThrowInstruction extends Instruction {
  /**
   * @param {Context} context
   * @param {ThrowNode} node
   * @returns {*}
   */
  runSync(context, node) {
    throw new ThrowValue(context, this.mavka.runSync(context, node.value));
  }

  /**
   * @param {Context} context
   * @param {ThrowNode} node
   * @returns {Promise<*>}
   */
  async runAsync(context, node) {
    throw new ThrowValue(context, await this.mavka.runAsync(context, node.value));
  }
}

export default ThrowInstruction;
