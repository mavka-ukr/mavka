import Instruction from "./utils/instruction.js";
import FileStructureCell from "../../library/fileStructureCell.js";

function doOperation(mavka, context, node) {
  const takeAsyncCell = new mavka.AsyncCell(mavka, async () => {
    const buffer = await mavka.loader.loadFile(context, node.name);

    const value = new mavka.Cell(
      mavka,
      "Файл",
      {
        "текст": mavka.makeProxyFunction(() => {
          return mavka.makeText(buffer.toString());
        })
      },
      FileStructureCell.getInstance(mavka),
      () => buffer,
      null,
      {
        buffer
      }
    );

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
