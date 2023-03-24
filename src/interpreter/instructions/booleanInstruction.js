import Instruction from "./utils/instruction.js";

class BooleanInstruction extends Instruction {
  /**
   * @param {Context} context
   * @param {BooleanNode} node
   * @returns {*}
   */
  runSync(context, node) {
    return node.value ? this.mavka.yesCellInstance : this.mavka.noCellInstance;
  }

  /**
   * @param {Context} context
   * @param {BooleanNode} node
   * @returns {Promise<*>}
   */
  async runAsync(context, node) {
    return node.value ? this.mavka.yesCellInstance : this.mavka.noCellInstance;
  }
}

export default BooleanInstruction;
