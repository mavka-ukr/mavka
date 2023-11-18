import Instruction from "./instruction.js";
import Scope from "../scope.js";
import { processBody, varname } from "../utils.js";

class ModuleInstruction extends Instruction {
  /**
   * @param {Scope} scope
   * @param {ModuleNode} node
   * @returns {*}
   */
  async compile(scope, node) {
    const moduleScope = new Scope(scope);
    const body = await this.mavka.compileModuleBody(moduleScope, processBody(this.mavka, moduleScope, node.body));
    return `${varname(node.name)} = (await (async function() {
  var moduleValue = {
    __m_name__: "${node.name}",
    __m_type__: "module",
    __m_props__: Object.create(null),
  };
  await (async function() {
    ${body}
  })();
  return moduleValue;
})())`;
  }
}

export default ModuleInstruction;
