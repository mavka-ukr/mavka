import Instruction from "./instruction.js";

class IdentifiersChainInstruction extends Instruction {
  /**
   * @param {Context} context
   * @param {IdentifiersChainNode} node
   * @returns {*}
   */
  runSync(context, node) {
    let value = this.mavka.runSync(node.left);
    if (!value) {
      // todo: throw
      value = this.mavka.emptyCellInstance;
    }

    return value.get(node.right.name);
  }

  /**
   * @param {Context} context
   * @param {IdentifiersChainNode} node
   * @returns {Promise<*>}
   */
  async runAsync(context, node) {
    let value = await this.mavka.runAsync(node.left);
    if (!value) {
      // todo: throw
      value = this.mavka.emptyCellInstance;
    }

    return value.get(node.right.name);
  }
}

export default IdentifiersChainInstruction;
