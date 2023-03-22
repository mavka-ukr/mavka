import Instruction from "./utils/instruction.js";

class NotInstruction extends Instruction {
  /**
   * @param {Context} context
   * @param {NotNode} node
   * @returns {*}
   */
  runSync(context, node) {
    const value = this.mavka.runSync(context, node.value);

    return value.asBoolean(context).not();
  }

  /**
   * @param {Context} context
   * @param {NotNode} node
   * @returns {Promise<*>}
   */
  async runAsync(context, node) {
    const value = await this.mavka.runAsync(context, node.value);

    return value.asBoolean(context).not();
  }
}

export default NotInstruction;
