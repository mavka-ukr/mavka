import Instruction from "./instruction.js";

class NumberInstruction extends Instruction {
  /**
   * @param {Scope} scope
   * @param {NumberNode} node
   * @returns {*}
   */
  async compile(scope, node) {
    return `${node.value}`;
  }
}

export default NumberInstruction;
