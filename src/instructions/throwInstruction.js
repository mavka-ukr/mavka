import Instruction from "./instruction.js";

class ThrowInstruction extends Instruction {
  /**
   * @param {Scope} scope
   * @param {ThrowNode} node
   * @returns {*}
   */
  async compile(scope, node) {
    const debugInfoVarName = this.mavka.putDebugInfoVarName(node);
    const value = await this.mavka.compileNode(scope, node.value);
    return `throw new MavkaError(${value}, ${debugInfoVarName});`;
  }
}

export default ThrowInstruction;
