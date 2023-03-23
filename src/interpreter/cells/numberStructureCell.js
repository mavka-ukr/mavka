import { Cell } from "./utils/cell.js";

class NumberStructureCell extends Cell {
  /**
   * @param {Mavka} mavka
   */
  constructor(mavka) {
    super(mavka, "<структура число>");

    this.methods["виконати_виклик"] = this.mavka.tools.fn(
      (args, context) => {
        if (Array.isArray(args) && args.length) {
          return args[0].asNumber(context);
        }

        return this.mavka.toCell(0);
      },
      { jsArgs: false }
    );

    this.methods["виконати_додавання"] = this.mavka.tools.fn(
      ([value], context, options) => this.mavka.toCell(options.meValue.asJsValue(context) + value.asNumber(context).asJsValue(context)),
      { jsArgs: false }
    );
    this.methods["виконати_віднімання"] = this.mavka.tools.fn(
      ([value], context, options) => this.mavka.toCell(options.meValue.asJsValue(context) - value.asNumber(context).asJsValue(context)),
      { jsArgs: false }
    );
    this.methods["виконати_множення"] = this.mavka.tools.fn(
      ([value], context, options) => this.mavka.toCell(options.meValue.asJsValue(context) * value.asNumber(context).asJsValue(context)),
      { jsArgs: false }
    );
    this.methods["виконати_ділення"] = this.mavka.tools.fn(
      ([value], context, options) => this.mavka.toCell(options.meValue.asJsValue(context) / value.asNumber(context).asJsValue(context)),
      { jsArgs: false }
    );
    this.methods["виконати_ділення_за_модулем_остача"] = this.mavka.tools.fn(
      ([value], context, options) => this.mavka.toCell(options.meValue.asJsValue(context) % value.asNumber(context).asJsValue(context)),
      { jsArgs: false }
    );
    this.methods["виконати_ділення_за_модулем_частка"] = this.mavka.tools.fn(
      ([value], context, options) => this.mavka.toCell(Math.floor(options.meValue.asJsValue(context) / value.asNumber(context).asJsValue(context))),
      { jsArgs: false }
    );
    this.methods["виконати_піднесення_до_степеня"] = this.mavka.tools.fn(
      ([value], context, options) => this.mavka.toCell(Math.pow(options.meValue.asJsValue(context), value.asNumber(context).asJsValue(context))),
      { jsArgs: false }
    );
    this.methods["виконати_виняткову_дизʼюнкцію"] = this.mavka.tools.fn(
      ([value], context, options) => this.mavka.toCell(options.meValue.asJsValue(context) ^ value.asNumber(context).asJsValue(context)),
      { jsArgs: false }
    );

    this.methods["виконати_перетворення_на_текст"] = this.mavka.tools.fn(
      (args, context, options) =>
        this.mavka.toCell(String(options.meValue.asJsValue(context))),
      { jsArgs: false }
    );
    this.methods["виконати_перетворення_на_число"] = this.mavka.tools.fn(
      (args, context, options) => options.meValue,
      { jsArgs: false }
    );
    this.methods["виконати_перетворення_на_логічне"] = this.mavka.tools.fn(
      (args, context, options) =>
        options.meValue.asJsValue(context) ? this.mavka.trueCellInstance : this.mavka.falseCellInstance,
      { jsArgs: false }
    );
  }
}

export default NumberStructureCell;
