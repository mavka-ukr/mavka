import StructureCell from "./common/structureCell.js";

class BooleanStructureCell extends StructureCell {
  /**
   * @param {Mavka} mavka
   */
  constructor(mavka) {
    super(mavka, "логічне");

    this.properties["виконати_виклик"] = this.mavka.makeProxyFunction(
      (args, context) => {
        if (Array.isArray(args) && args.length) {
          return args[0].asBoolean(context);
        }

        return this.mavka.no;
      }
    );

    this.setMethod("виконати_перетворення_на_текст", (args, context, options) => {
      return options.meValue.asJsValue(context)
        ? this.mavka.toCell("так")
        : this.mavka.toCell("ні");
    });
    this.setMethod("виконати_перетворення_на_число", (args, context, options) => {
      return options.meValue.asJsValue(context)
        ? this.mavka.makeNumber(1)
        : this.mavka.makeNumber(0);
    });
    this.setMethod("виконати_перетворення_на_логічне", (args, context, options) => {
      return options.meValue;
    });

    this.setMethod("виконати_додавання", (args, context, options) => {
      let value = args[0];
      if (!value) {
        value = this.mavka.empty;
      }

      return options.meValue.asNumber(context).doAdd(context, value);
    });
    this.setMethod("виконати_віднімання", (args, context, options) => {
      let value = args[0];
      if (!value) {
        value = this.mavka.empty;
      }

      return options.meValue.asNumber(context).doSub(context, value);
    });
    this.setMethod("виконати_множення", (args, context, options) => {
      let value = args[0];
      if (!value) {
        value = this.mavka.empty;
      }

      return options.meValue.asNumber(context).doMul(context, value);
    });
    this.setMethod("виконати_ділення", (args, context, options) => {
      let value = args[0];
      if (!value) {
        value = this.mavka.empty;
      }

      return options.meValue.asNumber(context).doDiv(context, value);
    });
    this.setMethod("виконати_ділення_за_модулем_остача", (args, context, options) => {
      let value = args[0];
      if (!value) {
        value = this.mavka.empty;
      }

      return options.meValue.asNumber(context).doDivMod(context, value);
    });
    this.setMethod("виконати_ділення_за_модулем_частка", (args, context, options) => {
      let value = args[0];
      if (!value) {
        value = this.mavka.empty;
      }

      return options.meValue.asNumber(context).doDivFloor(context, value);
    });
    this.setMethod("виконати_піднесення_до_степеня", (args, context, options) => {
      let value = args[0];
      if (!value) {
        value = this.mavka.empty;
      }

      return options.meValue.asNumber(context).doPow(context, value);
    });
    this.setMethod("виконати_виняткову_дизʼюнкцію", (args, context, options) => {
      let value = args[0];
      if (!value) {
        value = this.mavka.empty;
      }

      return options.meValue.asNumber(context).doXor(context, value);
    });

    this.setMethod("виконати_порівняння_чи_рівно", (args, context, options) => {
      let value = args[0];
      if (!value) {
        value = this.mavka.empty;
      }

      return options.meValue === value
        ? this.mavka.yes
        : this.mavka.no;
    });
    this.setMethod("виконати_порівняння_чи_не_рівно", (args, context, options) => {
      let value = args[0];
      if (!value) {
        value = this.mavka.empty;
      }

      return options.meValue === value
        ? this.mavka.no
        : this.mavka.yes;
    });
    this.setMethod("виконати_порівняння_чи_менше", (args, context, options) => {
      let value = args[0];
      if (!value) {
        value = this.mavka.empty;
      }

      return options.meValue.asNumber(context).doCompareLesserThan(context, value);
    });
    this.setMethod("виконати_порівняння_чи_не_менше", (args, context, options) => {
      let value = args[0];
      if (!value) {
        value = this.mavka.empty;
      }

      return options.meValue.asNumber(context).doCompareGreaterThanOrEquals(context, value);
    });
    this.setMethod("виконати_порівняння_чи_більше", (args, context, options) => {
      let value = args[0];
      if (!value) {
        value = this.mavka.empty;
      }

      return options.meValue.asNumber(context).doCompareGreaterThan(context, value);
    });
    this.setMethod("виконати_порівняння_чи_не_більше", (args, context, options) => {
      let value = args[0];
      if (!value) {
        value = this.mavka.empty;
      }

      return options.meValue.asNumber(context).doCompareLesserThanOrEquals(context, value);
    });
  }

  static createInstance(mavka) {
    return new BooleanStructureCell(mavka);
  }
}

export default BooleanStructureCell;
