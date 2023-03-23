import Instruction from "./utils/instruction.js";

class DictionaryInstruction extends Instruction {
  /**
   * @param {Context} context
   * @param {DictionaryNode} node
   * @returns {*}
   */
  runSync(context, node) {
    const items = {};

    for (const [k, v] of Object.entries(node.args)) {
      items[k] = this.mavka.runSync(context, v);
    }

    return this.mavka.dictionaryStructureCellInstance.doCall(context, items);
  }

  /**
   * @param {Context} context
   * @param {DictionaryNode} node
   * @returns {Promise<*>}
   */
  async runAsync(context, node) {
    const items = {};

    for (const [k, v] of Object.entries(node.args)) {
      items[k] = await this.mavka.runAsync(context, v);
    }

    return this.mavka.dictionaryStructureCellInstance.doCall(context, items);
  }
}

export default DictionaryInstruction;
