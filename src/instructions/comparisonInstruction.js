import Instruction from "./instruction.js";

class ComparisonInstruction extends Instruction {
  /**
   * @param {Scope} scope
   * @param {ComparisonNode} node
   * @returns {*}
   */
  async compile(scope, node) {
    const debugInfoVarName = this.mavka.putDebugInfoVarName(node);

    const left = await this.mavka.compileNode(scope, node.left);
    const right = await this.mavka.compileNode(scope, node.right);
    switch (node.operation) {
      case "рівно":
      case "==":
        return `mavka_compare_eq(${left}, ${right}, ${debugInfoVarName})`;

      case "не рівно":
      case "!=":
        return `!mavka_compare_eq(${left}, ${right}, ${debugInfoVarName})`;

      case "менше":
      case "<":
        return `mavka_compare_lt(${left}, ${right}, ${debugInfoVarName})`;

      case "більше":
      case ">":
        return `mavka_compare_gt(${left}, ${right}, ${debugInfoVarName})`;

      case "не більше":
      case "<=":
        return `mavka_compare_le(${left}, ${right}, ${debugInfoVarName})`;

      case "не менше":
      case ">=":
        return `mavka_compare_ge(${left}, ${right}, ${debugInfoVarName})`;

      case "є":
        return `mavka_compare_is(${left}, ${right}, ${debugInfoVarName})`;

      case "не є":
        return `mavka_compare_is_not(${left}, ${right}, ${debugInfoVarName})`;

      case "містить":
        return `mavka_compare_contains(${left}, ${right}, ${debugInfoVarName})`;

      case "не містить":
        return `mavka_compare_not_contains(${left}, ${right}, ${debugInfoVarName})`;

      default:
        throw new Error(`Unknown comparison operation: ${node.operation}`);
    }
  }
}

export default ComparisonInstruction;
