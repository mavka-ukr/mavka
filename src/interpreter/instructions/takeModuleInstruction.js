import Instruction from "./utils/instruction.js";
import IdentifierNode from "mavka-parser/src/ast/IdentifierNode.js";

function doOperation(mavka, context, node) {
  const takeAsyncCell = new mavka.AsyncCell(mavka, async () => {
    const path = node.id instanceof IdentifierNode ? [node.id.name] : node.id.toFlatArray();

    let { name, result } = await mavka.loader.loadModule(context, path, node.absolute);

    if (node.star && !node.as) {
      console.log("not implemented");
    } else {
      context.set(node.as ? node.as.name : name, result);
    }

    return result;
  });

  return new mavka.AwaitCell(mavka, takeAsyncCell);
}

class TakeModuleInstruction extends Instruction {
  /**
   * @param {Context} context
   * @param {TakeModuleNode} node
   * @returns {*}
   */
  runSync(context, node) {
    this.mavka.fall(context, this.mavka.makeText("Не можна брати модулі в звичайному контексті."));
  }

  /**
   * @param {Context} context
   * @param {TakeModuleNode} node
   * @returns {Promise<*>}
   */
  async runAsync(context, node) {
    return doOperation(this.mavka, context, node);
  }
}

export default TakeModuleInstruction;
