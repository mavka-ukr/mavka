import Instruction from "./instruction.js";

class NegativeInstruction extends Instruction {
  /**
   * @param {Context} context
   * @param {NegativeNode} node
   * @returns {*}
   */
  runSync(context, node) {
    const value = this.mavka.runSync(context, node.value);

    return new this.mavka.NumberCell(this.mavka, -(value.asNumber().asJsValue()));
  }

  /**
   * @param {Context} context
   * @param {NegativeNode} node
   * @returns {Promise<*>}
   */
  async runAsync(context, node) {
    const value = await this.mavka.runAsync(context, node.value);

    return new this.mavka.NumberCell(this.mavka, -(value.asNumber().asJsValue()));
  }
}

export default NegativeInstruction;
