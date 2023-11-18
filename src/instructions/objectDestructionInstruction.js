import Instruction from "./instruction.js";

class ObjectDestructionInstruction extends Instruction {
  /**
   * @param {Scope} scope
   * @param {ObjectDestructionNode} node
   * @returns {*}
   */
  async compile(scope, node) {
  }
}

export default ObjectDestructionInstruction;
