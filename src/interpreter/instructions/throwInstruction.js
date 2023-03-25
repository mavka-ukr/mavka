import Instruction from "./utils/instruction.js";

export class ThrowValue {
  /**
   * @param {Context} context
   * @param {Cell} value
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
    this.mavka.fall(context, this.mavka.runSync(context, node.value));
  }

  /**
   * @param {Context} context
   * @param {ThrowNode} node
   * @returns {Promise<*>}
   */
  async runAsync(context, node) {
    this.mavka.fall(context, await this.mavka.runAsync(context, node.value));
  }
}

export default ThrowInstruction;
