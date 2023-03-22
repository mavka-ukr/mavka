import Instruction from "./utils/instruction.js";

class DictionaryInstruction extends Instruction {
  /**
   * @param {Context} context
   * @param {DictionaryNode} node
   * @returns {*}
   */
  runSync(context, node) {
    const args = {};

    for (const [k, v] of Object.entries(node.args)) {
      args[k] = this.mavka.runSync(context, v);
    }

    return this.mavka.dictionaryStructureCellInstance.doCall(context, args);
  }

  /**
   * @param {Context} context
   * @param {DictionaryNode} node
   * @returns {Promise<*>}
   */
  async runAsync(context, node) {
    const args = {};

    for (const [k, v] of Object.entries(node.args)) {
      args[k] = await this.mavka.runAsync(context, v);
    }

    return this.mavka.dictionaryStructureCellInstance.doCall(context, args);
  }
}

export default DictionaryInstruction;
