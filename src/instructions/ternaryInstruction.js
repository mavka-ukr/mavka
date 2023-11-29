import Instruction from "./instruction.js";

class TernaryInstruction extends Instruction {
  /**
   * @param {Scope} scope
   * @param {TernaryNode} node
   * @returns {*}
   */
  async compile(scope, node) {
    const value = await this.mavka.compileNode(scope, node.value);
    const positiveValue = await this.mavka.compileNode(scope, node.positiveValue);
    const negativeValue = await this.mavka.compileNode(scope, node.negativeValue);

    return `(mavka_to_boolean(${value}) ? (${positiveValue}) : (${negativeValue}))`;
  }
}

export default TernaryInstruction;
