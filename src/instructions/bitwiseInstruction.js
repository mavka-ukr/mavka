import Instruction from "./instruction.js";

class BitwiseInstruction extends Instruction {
  /**
   * @param {Scope} scope
   * @param {BitwiseNode} node
   * @returns {*}
   */
  async compile(scope, node) {
    const debugInfoVarName = this.mavka.putDebugInfoVarName(node);

    const left = await this.mavka.compileNode(scope, node.left);
    const right = await this.mavka.compileNode(scope, node.right);

    switch (node.operation) {
      case "<<":
        return `shiftLeft(${left}, ${right}, ${debugInfoVarName})`;
      case ">>":
        return `shiftRight(${left}, ${right}, ${debugInfoVarName})`;
      case "&":
        return `bitAnd(${left}, ${right}, ${debugInfoVarName})`;
      case "|":
        return `bitOr(${left}, ${right}, ${debugInfoVarName})`;
      case "^":
        return `bitXor(${left}, ${right}, ${debugInfoVarName})`;
      default:
        throw new Error(`BUG: Unknown operation ${node.operation}`);
    }
  }
}

export default BitwiseInstruction;
