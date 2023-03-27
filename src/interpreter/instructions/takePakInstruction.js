import Instruction from "./utils/instruction.js";
import IdentifierNode from "mavka-parser/src/ast/IdentifierNode.js";

function doOperation(mavka, context, node) {
  const takeAsyncCell = new mavka.AsyncCell(mavka, async () => {
    const path = node.id instanceof IdentifierNode ? [node.id.name] : node.id.toFlatArray();

    let { name, result } = await mavka.loader.loadPak(context, path);

    context.set(node.as ? node.as.name : name, result);

    return result;
  });

  return new mavka.AwaitCell(mavka, takeAsyncCell);
}

class TakePakInstruction extends Instruction {
  /**
   * @param {Context} context
   * @param {TakeNode} node
   * @returns {*}
   */
  runSync(context, node) {
    return doOperation(this.mavka, context, node);
  }

  /**
   * @param {Context} context
   * @param {TakeNode} node
   * @returns {Promise<*>}
   */
  async runAsync(context, node) {
    return doOperation(this.mavka, context, node);
  }
}

export default TakePakInstruction;
