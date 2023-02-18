import Instruction from "./instruction.js";

class WhileInstruction extends Instruction {
  /**
   * @param {Context} context
   * @param {WhileNode} node
   * @returns {*}
   */
  runSync(context, node) {
    let result = null;

    while (this.mavka.runSync(context, node.value).asBoolean().asJsValue()) {
      result = this.mavka.run(context, node.body);
    }

    return result;
  }

  /**
   * @param {Context} context
   * @param {WhileNode} node
   * @returns {Promise<*>}
   */
  async runAsync(context, node) {
    let result = null;
    
    while ((await this.mavka.runSync(context, node.value)).asBoolean().asJsValue()) {
      result = await this.mavka.run(context, node.body);
    }

    return result;
  }
}

export default WhileInstruction;
