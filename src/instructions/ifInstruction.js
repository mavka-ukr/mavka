import Instruction from "./instruction.js";
import { processBody } from "../utils.js";

class IfInstruction extends Instruction {
  /**
   * @param {Scope} scope
   * @param {IfNode} node
   * @returns {*}
   */
  async compile(scope, node) {
    const value = await this.mavka.compileNode(scope, node.value);
    const body = await this.mavka.compileBody(scope, processBody(this.mavka, scope, node.body));
    const elseBody = node.elseBody ? await this.mavka.compileBody(scope, processBody(this.mavka, scope, node.elseBody)) : "";

    return `
if (${value}) {
  ${body}
}${elseBody ? " else {\n" + elseBody + "\n}" : ""}
`.trim();
  }
}

export default IfInstruction;
