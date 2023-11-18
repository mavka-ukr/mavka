import Instruction from "./instruction.js";

class BooleanInstruction extends Instruction {
  /**
   * @param {Scope} scope
   * @param {BooleanNode} node
   * @returns {*}
   */
  async compile(scope, node) {
    return `${node.value ? "true" : "false"}`;
  }
}

export default BooleanInstruction;
