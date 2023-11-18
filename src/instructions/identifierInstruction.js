import Instruction from "./instruction.js";
import { varname } from "../utils.js";
import { MavkaCompilationError } from "../error.js";

class IdentifierInstruction extends Instruction {
  /**
   * @param {Scope} scope
   * @param {IdentifierNode} node
   * @returns {*}
   */
  async compile(scope, node) {
    const debugInfoVarName = this.mavka.putDebugInfoVarName(node);
    const debugInfoVar = this.mavka.debugInfoVarNames.get(debugInfoVarName);

    if (!scope.has(node.name)) {
      throw new MavkaCompilationError(`Субʼєкт "${node.name}" не визначено.`, debugInfoVar);
    }
    return `${varname(node.name)}`;
  }
}

export default IdentifierInstruction;
