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

    this.setMethod("виконати_додавання", (args, context, options) => {
      if (!args[0]) {
        throw "no value provided.";
      }

      return this.mavka.toCell(options.meValue.asJsValue(context) + args[0].asNumber(context).asJsValue(context));
    });
    this.setMethod("виконати_віднімання", (args, context, options) => {
      if (!args[0]) {
        throw "no value provided.";
      }

      return this.mavka.toCell(options.meValue.asJsValue(context) - args[0].asNumber(context).asJsValue(context));
    });
    this.setMethod("виконати_множення", (args, context, options) => {
      if (!args[0]) {
        throw "no value provided.";
      }

      return this.mavka.toCell(options.meValue.asJsValue(context) * args[0].asNumber(context).asJsValue(context));
    });
    this.setMethod("виконати_ділення", (args, context, options) => {
      if (!args[0]) {
        throw "no value provided.";
      }

      return this.mavka.toCell(options.meValue.asJsValue(context) / args[0].asNumber(context).asJsValue(context));
    });
    this.setMethod("виконати_ділення_за_модулем_остача", (args, context, options) => {
      if (!args[0]) {
        throw "no value provided.";
      }

      return this.mavka.toCell(options.meValue.asJsValue(context) % args[0].asNumber(context).asJsValue(context));
    });
    this.setMethod("виконати_ділення_за_модулем_частка", (args, context, options) => {
      if (!args[0]) {
        throw "no value provided.";
      }

      return this.mavka.toCell(Math.floor(options.meValue.asJsValue(context) / args[0].asNumber(context).asJsValue(context)));
    });
    this.setMethod("виконати_піднесення_до_степеня", (args, context, options) => {
      if (!args[0]) {
        throw "no value provided.";
      }

      return this.mavka.toCell(Math.pow(options.meValue.asJsValue(context), args[0].asNumber(context).asJsValue(context)));
    });
    this.setMethod("виконати_виняткову_дизʼюнкцію", (args, context, options) => {
      if (!args[0]) {
        throw "no value provided.";
      }

      return this.mavka.toCell(options.meValue.asJsValue(context) ^ args[0].asNumber(context).asJsValue(context));
    });

    this.setMethod("виконати_перетворення_на_текст", (args, context, options) => {
      return this.mavka.toCell(String(options.meValue.asJsValue(context)));
    });
    this.setMethod("виконати_перетворення_на_число", (args, context, options) => {
      return options.meValue;
    });
    this.setMethod("виконати_перетворення_на_логічне", (args, context, options) => {
      return options.meValue.asJsValue(context) ? this.mavka.yesCellInstance : this.mavka.noCellInstance;
    });

    // ==
    this.setMethod("виконати_порівняння_чи_рівно", (args, context, options) => {
      if (!args[0]) {
        throw "no value provided.";
      }

      if (!args[0].isInstanceOf(context, options.meValue.structure).asJsValue(context)) {
        return this.mavka.noCellInstance;
      }

      const meJsValue = options.meValue.asJsValue(context);
      const compJsValue = args[0].asJsValue(context);

      return meJsValue === compJsValue
        ? this.mavka.yesCellInstance
        : this.mavka.noCellInstance;
    });
    // !=
    this.setMethod("виконати_порівняння_чи_не_рівно", (args, context, options) => {
      if (!args[0]) {
        throw "no value provided.";
      }

      if (!args[0].isInstanceOf(context, options.meValue.structure).asJsValue(context)) {
        return this.mavka.yesCellInstance;
      }

      const meJsValue = options.meValue.asJsValue(context);
      const compJsValue = args[0].asJsValue(context);

      return meJsValue === compJsValue
        ? this.mavka.noCellInstance
        : this.mavka.yesCellInstance;
    });
    // <
    this.setMethod("виконати_порівняння_чи_менше", (args, context, options) => {
      if (!args[0]) {
        throw "no value provided.";
      }

      const meJsValue = options.meValue.asJsValue(context);
      const compJsValue = args[0].asNumber(context).asJsValue(context);

      return meJsValue < compJsValue
        ? this.mavka.yesCellInstance
        : this.mavka.noCellInstance;
    });
    // >=
    this.setMethod("виконати_порівняння_чи_не_менше", (args, context, options) => {
      if (!args[0]) {
        throw "no value provided.";
      }

      const meJsValue = options.meValue.asJsValue(context);
      const compJsValue = args[0].asNumber(context).asJsValue(context);

      return meJsValue >= compJsValue
        ? this.mavka.yesCellInstance
        : this.mavka.noCellInstance;
    });
    // >
    this.setMethod("виконати_порівняння_чи_більше", (args, context, options) => {
      if (!args[0]) {
        throw "no value provided.";
      }

      const meJsValue = options.meValue.asJsValue(context);
      const compJsValue = args[0].asNumber(context).asJsValue(context);

      return meJsValue > compJsValue
        ? this.mavka.yesCellInstance
        : this.mavka.noCellInstance;
    });
    // <=
    this.setMethod("виконати_порівняння_чи_не_більше", (args, context, options) => {
      if (!args[0]) {
        throw "no value provided.";
      }

      const meJsValue = options.meValue.asJsValue(context);
      const compJsValue = args[0].asNumber(context).asJsValue(context);

      return meJsValue <= compJsValue
        ? this.mavka.yesCellInstance
        : this.mavka.noCellInstance;
    });
  }

  static createInstance(mavka) {
    return new NumberStructureCell(mavka);
  }
}

export default NumberStructureCell;
