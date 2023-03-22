import Instruction from "./utils/instruction.js";

class NegativeInstruction extends Instruction {
  /**
   * @param {Context} context
   * @param {NegativeNode} node
   * @returns {*}
   */
  runSync(context, node) {
    const value = this.mavka.runSync(context, node.value);

    return value.asNumber(context).negative();
  }

  /**
   * @param {Context} context
   * @param {NegativeNode} node
   * @returns {Promise<*>}
   */
  async runAsync(context, node) {
    const value = await this.mavka.runAsync(context, node.value);

    return value.asNumber(context).negative();
  }
}

export default NegativeInstruction;
