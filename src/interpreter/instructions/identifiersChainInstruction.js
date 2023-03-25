import Instruction from "./utils/instruction.js";

class IdentifiersChainInstruction extends Instruction {
  /**
   * @param {Context} context
   * @param {IdentifiersChainNode} node
   * @returns {*}
   */
  runSync(context, node) {
    let value = this.mavka.runSync(context, node.left);
    if (!value) {
      value = this.mavka.empty;
    }

    return value.get(context, node.right.name);
  }

  /**
   * @param {Context} context
   * @param {IdentifiersChainNode} node
   * @returns {Promise<*>}
   */
  async runAsync(context, node) {
    let value = await this.mavka.runAsync(context, node.left);
    if (!value) {
      value = this.mavka.empty;
    }

    return value.get(context, node.right.name);
  }
}

export default IdentifiersChainInstruction;
