import Instruction from "./utils/instruction.js";

function doOperation(mavka, context, node) {
  const takeAsyncCell = new mavka.AsyncCell(mavka, async () => {
    const buffer = await mavka.loader.loadFile(context, node.name);

    const value = this.mavka.makeText(buffer.toString());

    context.set(node.as.name, value);

    return value;
  });

  return new mavka.AwaitCell(mavka, takeAsyncCell);
}

class TakeFileInstruction extends Instruction {
  /**
   * @param {Context} context
   * @param {TakeFileNode} node
   * @returns {*}
   */
  runSync(context, node) {
    this.mavka.fall(context, this.mavka.makeText("Не можна брати файли в звичайному контексті."));
  }

  /**
   * @param {Context} context
   * @param {TakeFileNode} node
   * @returns {Promise<*>}
   */
  async runAsync(context, node) {
    return doOperation(this.mavka, context, node);
  }
}

export default TakeFileInstruction;
