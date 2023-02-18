import Instruction from "./instruction.js";

class ChainInstruction extends Instruction {
  /**
   * @param {Context} context
   * @param {ChainNode} node
   * @returns {*}
   */
  runSync(context, node) {
    let value = this.mavka.runSync(context, node.left);
    if (!value) {
      // todo: throw
      value = this.mavka.emptyCellInstance;
    }

    return value.get(node.right.name);
  }

  /**
   * @param {Context} context
   * @param {ChainNode} node
   * @returns {Promise<*>}
   */
  async runAsync(context, node) {
    let value = await this.mavka.runAsync(context, node.left);
    if (!value) {
      // todo: throw
      value = this.mavka.emptyCellInstance;
    }
    // console.log(value);

    return value.get(node.right.name);
  }
}

export default ChainInstruction;
