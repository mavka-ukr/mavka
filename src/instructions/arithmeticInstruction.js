import Instruction from "./instruction.js";

class ArithmeticInstruction extends Instruction {
  /**
   * @param {Scope} scope
   * @param {ArithmeticNode} node
   * @returns {*}
   */
  async compile(scope, node) {
    const debugInfoVarName = this.mavka.putDebugInfoVarName(node);

    const left = await this.mavka.compileNode(scope, node.left);
    const right = await this.mavka.compileNode(scope, node.right);

    switch (node.operation) {
      case "+":
        return `add(${left}, ${right}, ${debugInfoVarName})`;
      case "-":
        return `sub(${left}, ${right}, ${debugInfoVarName})`;
      case "*":
        return `mul(${left}, ${right}, ${debugInfoVarName})`;
      case "/":
        return `div(${left}, ${right}, ${debugInfoVarName})`;
      case "%":
        return `mod(${left}, ${right}, ${debugInfoVarName})`;
      case "//":
        return `divDiv(${left}, ${right}, ${debugInfoVarName})`;
      case "**":
        return `pow(${left}, ${right}, ${debugInfoVarName})`;
      case "^":
        return `bitXor(${left}, ${right}, ${debugInfoVarName})`;
      default:
        throw new Error(`BUG: Unknown operation ${node.operation}`);
    }
  }
}

export default ArithmeticInstruction;
