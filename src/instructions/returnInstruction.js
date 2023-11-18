import Instruction from "./instruction.js";

class ReturnInstruction extends Instruction {
  /**
   * @param {Scope} scope
   * @param {ReturnNode} node
   * @returns {*}
   */
  async compile(scope, node) {
    const value = await this.mavka.compileNode(scope, node.value);
    return `return ${value}`;
  }
}

export default ReturnInstruction;
