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
        return `mavka_add(${left}, ${right}, ${debugInfoVarName})`;
      case "-":
        return `mavka_sub(${left}, ${right}, ${debugInfoVarName})`;
      case "*":
        return `mavka_mul(${left}, ${right}, ${debugInfoVarName})`;
      case "/":
        return `mavka_div(${left}, ${right}, ${debugInfoVarName})`;
      case "%":
        return `mavka_mod(${left}, ${right}, ${debugInfoVarName})`;
      case "//":
        return `mavka_divDiv(${left}, ${right}, ${debugInfoVarName})`;
      case "**":
        return `mavka_pow(${left}, ${right}, ${debugInfoVarName})`;
      default:
        throw new Error(`BUG: Unknown operation ${node.operation}`);
    }
  }
}

export default ArithmeticInstruction;
