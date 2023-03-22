import Instruction from "./utils/instruction.js";

class PositiveInstruction extends Instruction {
  /**
   * @param {Context} context
   * @param {PositiveNode} node
   * @returns {*}
   */
  runSync(context, node) {
    const value = this.mavka.runSync(context, node.value);

    return value.asNumber(context).positive();
  }

  /**
   * @param {Context} context
   * @param {PositiveNode} node
   * @returns {Promise<*>}
   */
  async runAsync(context, node) {
    const value = await this.mavka.runAsync(context, node.value);

    return value.asNumber(context).positive();
  }
}

export default PositiveInstruction;
