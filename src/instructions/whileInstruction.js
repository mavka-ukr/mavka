import Instruction from "./instruction.js";
import { processBody } from "../utils.js";

class WhileInstruction extends Instruction {
  /**
   * @param {Scope} scope
   * @param {WhileNode} node
   * @returns {*}
   */
  async compile(scope, node) {
    const value = await this.mavka.compileNode(scope, node.value);
    const body = await this.mavka.compileBody(scope, processBody(this.mavka, scope, node.body));

    return `while (${value}) {
  ${body}
}`;
  }
}

export default WhileInstruction;
