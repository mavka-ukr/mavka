import Instruction from "./instruction.js";

class TypeValueSingleInstruction extends Instruction {
  /**
   * @param {Scope} scope
   * @param {TypeValueSingleNode} node
   * @returns {*}
   */
  async compile(scope, node) {
    return await this.mavka.compileNode(scope, node.value);
  }
}

export default TypeValueSingleInstruction;
