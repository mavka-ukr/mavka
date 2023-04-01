import Instruction from "./utils/instruction.js";
import FileStructureCell from "../../library/fileStructureCell.js";

function doEval(code, mavka, context) {
  eval(code);
}

let extId = 0;

class EvalInstruction extends Instruction {
  /**
   * @param {Context} context
   * @param {EvalNode} node
   * @returns {*}
   */
  runSync(context, node) {
    this.mavka.fall(context, this.mavka.makeText("Не можна виконувати \"js\" в звичайному контексті."));
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
      this.mavka.fall(context, this.mavka.makeText("\"js\" приймає лише текст або файл."));
    }

    const prevGetMavka = this.mavka.global.getMavka;
    const prevGetContext = this.mavka.global.getContext;

    this.mavka.global.getMavka = () => this.mavka;
    this.mavka.global.getContext = () => context;

    const loadExtensionAsyncCell = new this.mavka.AsyncCell(this.mavka, async () => {
      extId++;

      const wrappedCode = `
mavka.global.EXTENSION_EVAL_ASYNC_${extId} = async function() {
  ${value}
}
      `;

      doEval(wrappedCode, this.mavka, context);

      const result = await this.mavka.global[`EXTENSION_EVAL_ASYNC_${extId}`]();
      delete this.mavka.global[`EXTENSION_EVAL_ASYNC_${extId}`];

      this.mavka.global.getMavka = prevGetMavka;
      this.mavka.global.getContext = prevGetContext;

      return this.mavka.toCell(result);
    });

    return new this.mavka.AwaitCell(this.mavka, loadExtensionAsyncCell);
  }
}

export default EvalInstruction;
