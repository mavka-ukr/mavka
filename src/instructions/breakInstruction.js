import Instruction from "./instruction.js";

class BreakInstruction extends Instruction {
  /**
   * @param {Scope} scope
   * @param {BreakNode} node
   * @returns {*}
   */
  async compile(scope, node) {
    return "break";
  }
}

export default BreakInstruction;
