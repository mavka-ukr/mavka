import Instruction from "./instruction.js";
import IdentifierNode from "mavka-parser/src/ast/IdentifierNode.js";

class TakeInstruction extends Instruction {
  commonRun(context, node) {
    return new this.mavka.WaitCell(this.mavka, new this.mavka.AsyncCell(this.mavka, async () => {
      const path = node.id instanceof IdentifierNode ? [node.id.name] : node.id.toFlatArray();

      let { name, result } = await this.mavka.loader.load(context, path, node.pak, node.relative);

      if (node.star && !node.as) {
        console.log("not implemented");
      } else {
        context.set(node.as ? node.as : name, result);
      }

      return result;
    }));
  }

  /**
   * @param {Context} context
   * @param {TakeNode} node
   * @returns {*}
   */
  runSync(context, node) {
    return this.commonRun(context, node);
  }

  /**
   * @param {Context} context
   * @param {TakeNode} node
   * @returns {Promise<*>}
   */
  async runAsync(context, node) {
    return this.commonRun(context, node);
  }
}

export default TakeInstruction;
