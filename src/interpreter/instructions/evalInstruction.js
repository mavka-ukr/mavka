import Instruction from "./utils/instruction.js";
import FileStructureCell from "../../library/fileStructureCell.js";

let extId = 0;

class EvalInstruction extends Instruction {
  /**
   * @param {Context} context
   * @param {EvalNode} node
   * @returns {*}
   */
  runSync(context, node) {
    this.mavka.fall(context, this.mavka.makeText("Не можна виконувати \"eval\" в звичайному контексті."));
  }

  /**
   * @param {Context} context
   * @param {EvalNode} node
   * @returns {Promise<*>}
   */
  async runAsync(context, node) {
    let value = await this.mavka.runAsync(context, node.value);

    if (this.mavka.isText(value)) {
      value = value.meta.value;
    } else if (value.isInstanceOf(FileStructureCell.getInstance(this.mavka))) {
      value = value.meta.buffer.toString();
    } else {
      this.mavka.fall(context, this.mavka.makeText("\"eval\" приймає лише текст або файл."));
    }


    const mavka = this.mavka;

    const getContext = () => context;
    const getMavka = () => this.mavka;

    const loadExtensionAsyncCell = new this.mavka.AsyncCell(this.mavka, async () => {
      extId++;

      const wrappedCode = `
mavka.global.EXTENSION_EVAL_ASYNC_${extId} = async function() {
  ${value}
}
      `;

      eval(wrappedCode);

      const result = await this.mavka.global[`EXTENSION_EVAL_ASYNC_${extId}`]();
      delete this.mavka.global[`EXTENSION_EVAL_ASYNC_${extId}`];

      return this.mavka.toCell(result);
    });

    return new this.mavka.AwaitCell(this.mavka, loadExtensionAsyncCell);
  }
}

export default EvalInstruction;
