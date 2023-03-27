import Instruction from "./utils/instruction.js";

function doOperation(mavka, context, node) {
  const takeAsyncCell = new mavka.AsyncCell(mavka, async () => {
    let { name, result } = await mavka.loader.loadRemote(context, node.url);

    // todo: handle as prop
    context.set(node.as ? node.as.name : name, result);

    return result;
  });

  return new mavka.AwaitCell(mavka, takeAsyncCell);
}

class TakeRemoteInstruction extends Instruction {
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

export default TakeRemoteInstruction;
