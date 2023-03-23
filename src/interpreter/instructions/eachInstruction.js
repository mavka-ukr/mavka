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

    for (const item of iterator) {
      if (node.keyName) {
        context.set(node.keyName.name, item.key);
      }
      context.set(node.name.name, item.value);

      result = this.mavka.run(context, node.body);
    }

    if (node.keyName) {
      context.delete(node.keyName.name);
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

    for (const item of iterator) {
      if (node.keyName) {
        context.set(node.keyName.name, item.key);
      }
      context.set(node.name.name, item.value);

      result = await this.mavka.run(context, node.body);
    }

    if (node.keyName) {
      context.delete(node.keyName.name);
    }
    context.delete(node.name.name);

    return result;
  }
}

export default EachInstruction;
