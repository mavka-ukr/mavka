import Instruction from "./utils/instruction.js";
import { lastIdentifierName, resolveIdentifier } from "./utils/chain.js";

class GiveInstruction extends Instruction {
  /**
   * @param {Context} context
   * @param {GiveNode} node
   * @returns {*}
   */
  runSync(context, node) {
    this.mavka.fall(context, this.mavka.makeText("Не можна давати в звичайному контексті."));
  }

  /**
   * @param {Context} context
   * @param {GiveNode} node
   * @returns {Promise<*>}
   */
  async runAsync(context, node) {
    for (const nodeElement of node.elements) {
      const name = lastIdentifierName(nodeElement.as) || lastIdentifierName(nodeElement.id);
      const value = resolveIdentifier(this.mavka, context, context, nodeElement.id);

      context.give(name, value);
    }

    return node;
  }
}

export default GiveInstruction;
