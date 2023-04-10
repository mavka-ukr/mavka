import Instruction from "./utils/instruction.js";

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
    } else {
      this.mavka.fall(context, this.mavka.makeText("\"js\" приймає лише текст."));
    }

    const prevGetMavka = this.mavka.global.getMavka;
    const prevGetContext = this.mavka.global.getContext;

    this.mavka.global.getMavka = () => this.mavka;
    this.mavka.global.getContext = () => context;

    const loadExtensionAsyncCell = new this.mavka.AsyncCell(this.mavka, async () => {
      await this.mavka.import(context, value);

      this.mavka.global.getMavka = prevGetMavka;
      this.mavka.global.getContext = prevGetContext;

      return this.mavka.empty;
    });

    return new this.mavka.AwaitCell(this.mavka, loadExtensionAsyncCell);
  }
}

export default EvalInstruction;
