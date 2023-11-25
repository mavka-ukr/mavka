import Instruction from "./instruction.js";
import { processBody } from "../utils.js";

class IfInstruction extends Instruction {
  /**
   * @param {Scope} scope
   * @param {IfNode} node
   * @param {object} options
   * @returns {*}
   */
  async compile(scope, node, options) {
    const value = await this.mavka.compileNode(scope, node.value);
    const body = await this.mavka.compileBody(scope, processBody(this.mavka, scope, node.body, options), options);
    const elseBody = node.elseBody ? await this.mavka.compileBody(scope, processBody(this.mavka, scope, node.elseBody, options), options) : "";

    return `
if (${value}) {
  ${body}
}${elseBody ? " else {\n" + elseBody + "\n}" : ""}
`.trim();
  }
}

export default IfInstruction;
