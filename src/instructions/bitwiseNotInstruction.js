import Instruction from "./instruction.js";

class BitwiseNotInstruction extends Instruction {
  /**
   * @param {Scope} scope
   * @param {BitwiseNotNode} node
   * @returns {*}
   */
  async compile(scope, node) {
    const debugInfoVarName = this.mavka.putDebugInfoVarName(node);

    const value = await this.mavka.compileNode(scope, node.value);

    return `bitXor(${value}, ${debugInfoVarName})`;
  }
}

export default BitwiseNotInstruction;
