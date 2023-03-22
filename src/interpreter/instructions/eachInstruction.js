import Instruction from "./utils/instruction.js";

class EachInstruction extends Instruction {
  /**
   * @param {Context} context
   * @param {EachNode} node
   * @returns {*}
   */
  runSync(context, node) {
    const iterator = this.mavka.runSync(context, node.iterator);

    let result = null;

    for (const element of iterator) {
      context.set(node.name.name, element);

      result = this.mavka.run(context, node.body);
    }

    context.delete(node.name.name);

    return result;
  }

  /**
   * @param {Context} context
   * @param {EachNode} node
   * @returns {Promise<*>}
   */
  async runAsync(context, node) {
    const iterator = await this.mavka.runAsync(context, node.iterator);

    let result = null;

    for (const element of iterator) {
      context.set(node.name.name, element);

      result = await this.mavka.run(context, node.body);
    }

    context.delete(node.name.name);

    return result;
  }
}

export default EachInstruction;
