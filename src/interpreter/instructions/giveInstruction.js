import Instruction from "./utils/instruction.js";
import { lastIdentifierName, resolveIdentifier } from "./utils/chain.js";

class GiveInstruction extends Instruction {
  /**
   * @param {Context} context
   * @param {GiveNode} node
   * @returns {*}
   */
  runSync(context, node) {
    const name = lastIdentifierName(node.as) || lastIdentifierName(node.id);
    const value = resolveIdentifier(this.mavka, context, context, node.id);

    context.give(name, value);

    return node;
  }

  /**
   * @param {Context} context
   * @param {GiveNode} node
   * @returns {Promise<*>}
   */
  async runAsync(context, node) {
    const name = lastIdentifierName(node.as) || lastIdentifierName(node.id);
    const value = resolveIdentifier(this.mavka, context, context, node.id);

    context.give(name, value);

    return node;
  }
}

export default GiveInstruction;
