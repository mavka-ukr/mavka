import Instruction from "./instruction.js";

class ArrayDestructionInstruction extends Instruction {
  /**
   * @param {Scope} scope
   * @param {ArrayDestructionNode} node
   * @returns {*}
   */
  async compile(scope, node) {
  }
}

export default ArrayDestructionInstruction;
