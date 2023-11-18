import Instruction from "./instruction.js";

class PositiveInstruction extends Instruction {
  /**
   * @param {Scope} scope
   * @param {PositiveNode} node
   * @returns {*}
   */
  async compile(scope, node) {
    const debugInfoVarName = this.mavka.putDebugInfoVarName(node);

    const value = await this.mavka.compileNode(scope, node.value);

    return `positive(${value}, ${debugInfoVarName})`;
  }
}

export default PositiveInstruction;
