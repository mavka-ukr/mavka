import Instruction from "./instruction.js";

class TernaryInstruction extends Instruction {
  /**
   * @param {Context} context
   * @param {TernaryNode} node
   * @returns {*}
   */
  runSync(context, node) {
    const value = this.mavka.runSync(context, node.value);

    if (value.asBoolean().asJsValue()) {
      return this.mavka.runSync(context, node.positiveValue);
    } else {
      return this.mavka.runSync(context, node.negativeValue);
    }
  }

  /**
   * @param {Context} context
   * @param {TernaryNode} node
   * @returns {Promise<*>}
   */
  async runAsync(context, node) {
    let value = await this.mavka.runAsync(context, node.value);

    if (value.asBoolean().asJsValue()) {
      return await this.mavka.runAsync(context, node.positiveValue);
    } else {
      return await this.mavka.runAsync(context, node.negativeValue);
    }
  }
}

export default TernaryInstruction;
