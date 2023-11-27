import Instruction from "./instruction.js";
import Scope from "../scope.js";
import { buildDiia } from "../builders.js";

class AnonymousDiiaInstruction extends Instruction {
  /**
   * @param {Scope} scope
   * @param {AnonymousDiiaNode} node
   * @returns {*}
   */
  async compile(scope, node) {
    const diiaScope = new Scope(scope);

    return await buildDiia(this.mavka, null, diiaScope, node.async, node.params, node.body);
  }
}

export default AnonymousDiiaInstruction;
