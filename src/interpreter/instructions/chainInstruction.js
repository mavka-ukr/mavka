import Instruction from "./utils/instruction.js";

class ChainInstruction extends Instruction {
  /**
   * @param {Context} context
   * @param {ChainNode} node
   * @returns {*}
   */
  runSync(context, node) {
    let value = this.mavka.runSync(context, node.left);
    if (!value) {
      // todo: fall
      value = this.mavka.empty;
    }

    return value.get(context, node.right.name);
  }

  /**
   * @param {Context} context
   * @param {ChainNode} node
   * @returns {Promise<*>}
   */
  async runAsync(context, node) {
    let value = await this.mavka.runAsync(context, node.left);
    if (!value) {
      // todo: fall
      value = this.mavka.empty;
    }

    return value.get(context, node.right.name);
  }
}

export default ChainInstruction;
