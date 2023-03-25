import StructureCell from "./common/structureCell.js";

class NumberStructureCell extends StructureCell {
  /**
   * @param {Mavka} mavka
   */
  constructor(mavka) {
    super(mavka, "число");

    this.properties["виконати_виклик"] = this.mavka.makeProxyFunction((args, context) => {
        if (Array.isArray(args) && args.length) {
          return args[0].asNumber(context);
        }

        return this.mavka.toCell(0);
      }
    );

    this.setMethod("виконати_перетворення_на_текст", (args, context, options) => {
      return this.mavka.makeText(String(options.meValue.asJsValue(context)));
    });
    this.setMethod("виконати_перетворення_на_число", (args, context, options) => {
      return options.meValue;
    });
    this.setMethod("виконати_перетворення_на_логічне", (args, context, options) => {
      return options.meValue.asJsValue(context) ? this.mavka.yes : this.mavka.no;
    });

    this.setMethod("виконати_додавання", (args, context, options) => {
      let value = args[0];
      if (!value) {
        value = this.mavka.empty;
      }

      if (this.mavka.isText(value)) {
        return this.mavka.makeText(options.meValue.asText(context).asJsValue(context) + value.asJsValue(context));
      }

      return this.mavka.makeNumber(options.meValue.asJsValue(context) + value.asNumber(context).asJsValue(context));
    });
    this.setMethod("виконати_віднімання", (args, context, options) => {
      let value = args[0];
      if (!value) {
        value = this.mavka.empty;
      }

      return this.mavka.makeNumber(options.meValue.asJsValue(context) - value.asNumber(context).asJsValue(context));
    });
    this.setMethod("виконати_множення", (args, context, options) => {
      let value = args[0];
      if (!value) {
        value = this.mavka.empty;
      }

      return this.mavka.makeNumber(options.meValue.asJsValue(context) * value.asNumber(context).asJsValue(context));
    });
    this.setMethod("виконати_ділення", (args, context, options) => {
      let value = args[0];
      if (!value) {
        value = this.mavka.empty;
      }

      return this.mavka.makeNumber(options.meValue.asJsValue(context) / value.asNumber(context).asJsValue(context));
    });
    this.setMethod("виконати_ділення_за_модулем_остача", (args, context, options) => {
      let value = args[0];
      if (!value) {
        value = this.mavka.empty;
      }

      return this.mavka.makeNumber(options.meValue.asJsValue(context) % value.asNumber(context).asJsValue(context));
    });
    this.setMethod("виконати_ділення_за_модулем_частка", (args, context, options) => {
      let value = args[0];
      if (!value) {
        value = this.mavka.empty;
      }

      return this.mavka.makeNumber(Math.floor(options.meValue.asJsValue(context) / value.asNumber(context).asJsValue(context)));
    });
    this.setMethod("виконати_піднесення_до_степеня", (args, context, options) => {
      let value = args[0];
      if (!value) {
        value = this.mavka.empty;
      }

      return this.mavka.makeNumber(Math.pow(options.meValue.asJsValue(context), value.asNumber(context).asJsValue(context)));
    });
    this.setMethod("виконати_виняткову_дизʼюнкцію", (args, context, options) => {
      let value = args[0];
      if (!value) {
        value = this.mavka.empty;
      }

      return this.mavka.makeNumber(options.meValue.asJsValue(context) ^ value.asNumber(context).asJsValue(context));
    });

    this.setMethod("виконати_порівняння_чи_рівно", (args, context, options) => {
      let value = args[0];
      if (!value) {
        value = this.mavka.empty;
      }

      if (!this.mavka.isNumber(value)) {
        return this.mavka.no;
      }

      const meJsValue = options.meValue.asJsValue(context);
      const compJsValue = value.asJsValue(context);

      return meJsValue === compJsValue
        ? this.mavka.yes
        : this.mavka.no;
    });
    this.setMethod("виконати_порівняння_чи_не_рівно", (args, context, options) => {
      let value = args[0];
      if (!value) {
        value = this.mavka.empty;
      }

      if (!this.mavka.isNumber(value)) {
        return this.mavka.yes;
      }

      const meJsValue = options.meValue.asJsValue(context);
      const compJsValue = value.asJsValue(context);

      return meJsValue === compJsValue
        ? this.mavka.no
        : this.mavka.yes;
    });
    this.setMethod("виконати_порівняння_чи_менше", (args, context, options) => {
      let value = args[0];
      if (!value) {
        value = this.mavka.empty;
      }

      const meJsValue = options.meValue.asJsValue(context);
      const compJsValue = value.asNumber(context).asJsValue(context);

      return meJsValue < compJsValue
        ? this.mavka.yes
        : this.mavka.no;
    });
    this.setMethod("виконати_порівняння_чи_не_менше", (args, context, options) => {
      let value = args[0];
      if (!value) {
        value = this.mavka.empty;
      }

      const meJsValue = options.meValue.asJsValue(context);
      const compJsValue = value.asNumber(context).asJsValue(context);

      return meJsValue >= compJsValue
        ? this.mavka.yes
        : this.mavka.no;
    });
    this.setMethod("виконати_порівняння_чи_більше", (args, context, options) => {
      let value = args[0];
      if (!value) {
        value = this.mavka.empty;
      }

      const meJsValue = options.meValue.asJsValue(context);
      const compJsValue = value.asNumber(context).asJsValue(context);

      return meJsValue > compJsValue
        ? this.mavka.yes
        : this.mavka.no;
    });
    this.setMethod("виконати_порівняння_чи_не_більше", (args, context, options) => {
      let value = args[0];
      if (!value) {
        value = this.mavka.empty;
      }

      const meJsValue = options.meValue.asJsValue(context);
      const compJsValue = value.asNumber(context).asJsValue(context);

      return meJsValue <= compJsValue
        ? this.mavka.yes
        : this.mavka.no;
    });
  }

  static createInstance(mavka) {
    return new NumberStructureCell(mavka);
  }
}

export default NumberStructureCell;
