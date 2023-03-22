import Instruction from "./utils/instruction.js";

class GetElementInstruction extends Instruction {
  /**
   * @param {Context} context
   * @param {GetElementNode} node
   * @returns {*}
   */
  runSync(context, node) {
    let left = this.mavka.runSync(context, node.left);
    let element = this.mavka.runSync(context, node.element);

    return left.getAt(context, element);
  }

  /**
   * @param {Context} context
   * @param {GetElementNode} node
   * @returns {Promise<*>}
   */
  async runAsync(context, node) {
    let left = await this.mavka.runAsync(context, node.left);
    let element = await this.mavka.runAsync(context, node.element);

    return left.getAt(context, element);
  }
}

export default GetElementInstruction;
