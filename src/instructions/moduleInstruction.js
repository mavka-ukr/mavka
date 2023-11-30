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
    const body = await this.mavka.compileModuleBody(moduleScope, await processBody(this.mavka, moduleScope, node.body));
    return `${varname(node.name)} = await (async function() {
  var moduleValue = mavka_module("${node.name}");
  await (async function() {
    ${body}
  })();
  return moduleValue;
})()`;
  }
}

export default ModuleInstruction;
