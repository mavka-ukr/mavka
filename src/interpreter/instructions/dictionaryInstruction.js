import Instruction from "./utils/instruction.js";

class DictionaryInstruction extends Instruction {
  /**
   * @param {Context} context
   * @param {DictionaryNode} node
   * @returns {*}
   */
  runSync(context, node) {
    const items = new Map();

    for (const [k, v] of Object.entries(node.args)) {
      items.set(k, this.mavka.runSync(context, v));
    }

    return this.mavka.makeDictionary(items);
  }

  /**
   * @param {Context} context
   * @param {DictionaryNode} node
   * @returns {Promise<*>}
   */
  async runAsync(context, node) {
    const items = new Map();

    for (const [k, v] of Object.entries(node.args)) {
      items.set(k, await this.mavka.runAsync(context, v));
    }

    return this.mavka.makeDictionary(items);
  }
}

export default DictionaryInstruction;
