import Instruction from "./instruction.js";
import Scope from "../scope.js";
import { buildDiia, buildStructureMethod } from "../builders.js";
import { varname } from "../utils.js";

class DiiaInstruction extends Instruction {
  /**
   * @param {Scope} scope
   * @param {DiiaNode} node
   * @returns {*}
   */
  async compile(scope, node) {
    const diiaScope = new Scope(scope);

    if (node.structure) {
      diiaScope.vars.set("я", true);
      const compiledDiia = await buildStructureMethod(this.mavka, node.structure, node.name, diiaScope, node.async, node.params, node.body);
      return `${varname(node.structure)}.__m_methods__["${node.name}"] = ${compiledDiia}`.trim();
    }

    const compiledDiia = await buildDiia(this.mavka, node.name, diiaScope, node.async, node.params, node.body);
    return `${varname(node.name)} = ${compiledDiia}`;
  }
}

export default DiiaInstruction;
