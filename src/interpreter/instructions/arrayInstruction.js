import Instruction from "./utils/instruction.js";

class ArrayInstruction extends Instruction {
  /**
   * @param {Context} context
   * @param {ArrayNode} node
   * @returns {*}
   */
  runSync(context, node) {
    const values = node.elements.map((el) => this.mavka.runSync(context, el));

    return this.mavka.makeList(values);
  }

  /**
   * @param {Context} context
   * @param {ArrayNode} node
   * @returns {Promise<*>}
   */
  async runAsync(context, node) {
    const values = await Promise.all(node.elements.map((el) => this.mavka.runAsync(context, el)));

    return this.mavka.makeList(values);
  }
}

export default ArrayInstruction;
