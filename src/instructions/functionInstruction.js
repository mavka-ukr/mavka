import Instruction from "./instruction.js";
import Scope from "../scope.js";
import { buildDiia } from "../builders.js";

class FunctionInstruction extends Instruction {
  /**
   * @param {Scope} scope
   * @param {FunctionNode} node
   * @returns {*}
   */
  async compile(scope, node) {
    const diiaScope = new Scope(scope);

    return await buildDiia(this.mavka, "functionDiia", diiaScope, node.async, node.params, node.body);
  }
}

export default FunctionInstruction;
