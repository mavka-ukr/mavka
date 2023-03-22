import Instruction from "./utils/instruction.js";
import { lastIdentifierName, resolveIdentifier } from "./utils/chain.js";

class GiveInstruction extends Instruction {
  /**
   * @param {Context} context
   * @param {GiveNode} node
   * @returns {*}
   */
  runSync(context, node) {
    const id = node.id;

    const giveContext = context.get("__give_context__");

    if (giveContext) {
      giveContext.set(lastIdentifierName(node.as) || lastIdentifierName(id), resolveIdentifier(this.mavka, context, id));
    }

    return node;
  }

  /**
   * @param {Context} context
   * @param {GiveNode} node
   * @returns {Promise<*>}
   */
  async runAsync(context, node) {
    const id = node.id;

    const giveContext = context.get("__give_context__");

    if (giveContext) {
      giveContext.set(lastIdentifierName(node.as) || lastIdentifierName(id), resolveIdentifier(this.mavka, context, id));
    }

    return node;
  }
}

export default GiveInstruction;
