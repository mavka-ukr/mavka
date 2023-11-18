import Instruction from "./instruction.js";

class AsInstruction extends Instruction {
  /**
   * @param {Scope} scope
   * @param {AsNode} node
   * @returns {*}
   */
  async compile(scope, node) {
    const debugInfoVarName = this.mavka.putDebugInfoVarName(node);

    const left = await this.mavka.compileNode(scope, node.left);
    const right = await this.mavka.compileNode(scope, node.right);

    return `as(${left}, ${right}, ${debugInfoVarName})`;
  }
}

export default AsInstruction;
