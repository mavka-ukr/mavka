import Instruction from "./instruction.js";
import { processBody } from "../utils.js";

class WhileInstruction extends Instruction {
  /**
   * @param {Scope} scope
   * @param {WhileNode} node
   * @param {object} options
   * @returns {*}
   */
  async compile(scope, node, options) {
    const value = await this.mavka.compileNode(scope, node.value);
    const body = await this.mavka.compileBody(scope, await processBody(this.mavka, scope, node.body, {
      ...options,
      loop: true
    }), {
      ...options,
      loop: true
    });

    return `while (${value}) {
  ${body}
}`;
  }
}

export default WhileInstruction;
