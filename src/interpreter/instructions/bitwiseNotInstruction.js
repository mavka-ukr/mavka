import Instruction from "./utils/instruction.js";

class BitwiseNotInstruction extends Instruction {
  /**
   * @param {Context} context
   * @param {NotNode} node
   * @returns {*}
   */
  runSync(context, node) {
    const value = this.mavka.runSync(context, node.value);

    return value.asNumber(context).bitNot(context);
  }

  /**
   * @param {Context} context
   * @param {NotNode} node
   * @returns {Promise<*>}
   */
  async runAsync(context, node) {
    const value = await this.mavka.runAsync(context, node.value);

    return value.asNumber(context).bitNot(context);
  }
}

export default BitwiseNotInstruction;
