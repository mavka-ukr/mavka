import Instruction from "./instruction.js";

class ContinueInstruction extends Instruction {
  /**
   * @param {Scope} scope
   * @param {ContinueNode} node
   * @returns {*}
   */
  async compile(scope, node) {
    return "continue";
  }
}

export default ContinueInstruction;
