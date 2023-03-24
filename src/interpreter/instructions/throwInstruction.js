import Instruction from "./utils/instruction.js";

export class ThrowValue {
  /**
   * @param {Context} context
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
    return this.mavka.throw(context, this.mavka.runSync(context, node.value));
  }

  /**
   * @param {Context} context
   * @param {ThrowNode} node
   * @returns {Promise<*>}
   */
  async runAsync(context, node) {
    return this.mavka.throw(context, await this.mavka.runAsync(context, node.value));
  }
}

export default ThrowInstruction;
