import StructureCell from "./common/structureCell.js";

class DiiaStructureCell extends StructureCell {
  /**
   * @param {Mavka} mavka
   */
  constructor(mavka) {
    super(mavka, "дія");

    // todo: complete
    this.methods["виконати_додавання"] = this.mavka.tools.fn(
      (args, context, options) => {
        if (!args[0]) {
          throw "no value provided.";
        }

        return this.mavka.toCell(options.meValue.asJsValue(context) + args[0].asNumber(context).asJsValue(context));
      },
      { jsArgs: false }
    );
    // todo: complete
    this.methods["виконати_віднімання"] = this.mavka.tools.fn(
      (args, context, options) => {
        if (!args[0]) {
          throw "no value provided.";
        }

        return this.mavka.toCell(options.meValue.asJsValue(context) - args[0].asNumber(context).asJsValue(context));
      },
      { jsArgs: false }
    );
    // todo: complete
    this.methods["виконати_множення"] = this.mavka.tools.fn(
      (args, context, options) => {
        if (!args[0]) {
          throw "no value provided.";
        }

        return this.mavka.toCell(options.meValue.asJsValue(context) * args[0].asNumber(context).asJsValue(context));
      },
      { jsArgs: false }
    );
    // todo: complete
    this.methods["виконати_ділення"] = this.mavka.tools.fn(
      (args, context, options) => {
        if (!args[0]) {
          throw "no value provided.";
        }

        return this.mavka.toCell(options.meValue.asJsValue(context) / args[0].asNumber(context).asJsValue(context));
      },
      { jsArgs: false }
    );
    // todo: complete
    this.methods["виконати_ділення_за_модулем_остача"] = this.mavka.tools.fn(
      (args, context, options) => {
        if (!args[0]) {
          throw "no value provided.";
        }

        return this.mavka.toCell(options.meValue.asJsValue(context) % args[0].asNumber(context).asJsValue(context));
      },
      { jsArgs: false }
    );
    // todo: complete
    this.methods["виконати_ділення_за_модулем_частка"] = this.mavka.tools.fn(
      (args, context, options) => {
        if (!args[0]) {
          throw "no value provided.";
        }

        return this.mavka.toCell(Math.floor(options.meValue.asJsValue(context) / args[0].asNumber(context).asJsValue(context)));
      },
      { jsArgs: false }
    );
    // todo: complete
    this.methods["виконати_піднесення_до_степеня"] = this.mavka.tools.fn(
      (args, context, options) => {
        if (!args[0]) {
          throw "no value provided.";
        }

        return this.mavka.toCell(Math.pow(options.meValue.asJsValue(context), args[0].asNumber(context).asJsValue(context)));
      },
      { jsArgs: false }
    );
    // todo: complete
    this.methods["виконати_виняткову_дизʼюнкцію"] = this.mavka.tools.fn(
      (args, context, options) => {
        if (!args[0]) {
          throw "no value provided.";
        }

        return this.mavka.toCell(options.meValue.asJsValue(context) ^ args[0].asNumber(context).asJsValue(context));
      },
      { jsArgs: false }
    );

    this.methods["виконати_перетворення_на_текст"] = this.mavka.tools.fn(
      (args, context, options) => {
        let value = "<";
        if (options.meValue.isAsync) {
          value = `${value}тривала `;
        }
        value = `${value}дія ${options.meValue.name}>`;
        return this.mavka.toCell(value);
      },
      { jsArgs: false }
    );
    // todo: complete
    this.methods["виконати_перетворення_на_число"] = this.mavka.tools.fn(
      (args, context, options) => options.meValue,
      { jsArgs: false }
    );
    // todo: complete
    this.methods["виконати_перетворення_на_логічне"] = this.mavka.tools.fn(
      (args, context, options) =>
        options.meValue.asJsValue(context) ? this.mavka.yesCellInstance : this.mavka.noCellInstance,
      { jsArgs: false }
    );

    // todo: complete
    // ==
    this.methods["виконати_порівняння_чи_рівно"] = this.mavka.tools.fn(
      (args, context, options) => {
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
      },
      { jsArgs: false }
    );
    // todo: complete
    // !=
    this.methods["виконати_порівняння_чи_не_рівно"] = this.mavka.tools.fn(
      (args, context, options) => {
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
      },
      { jsArgs: false }
    );
    // todo: complete
    // <
    this.methods["виконати_порівняння_чи_менше"] = this.mavka.tools.fn(
      (args, context, options) => {
        if (!args[0]) {
          throw "no value provided.";
        }

        const meJsValue = options.meValue.asJsValue(context);
        const compJsValue = args[0].asNumber(context).asJsValue(context);

        return meJsValue < compJsValue
          ? this.mavka.yesCellInstance
          : this.mavka.noCellInstance;
      },
      { jsArgs: false }
    );
    // todo: complete
    // >=
    this.methods["виконати_порівняння_чи_не_менше"] = this.mavka.tools.fn(
      (args, context, options) => {
        if (!args[0]) {
          throw "no value provided.";
        }

        const meJsValue = options.meValue.asJsValue(context);
        const compJsValue = args[0].asNumber(context).asJsValue(context);

        return meJsValue >= compJsValue
          ? this.mavka.yesCellInstance
          : this.mavka.noCellInstance;
      },
      { jsArgs: false }
    );
    // todo: complete
    // >
    this.methods["виконати_порівняння_чи_більше"] = this.mavka.tools.fn(
      (args, context, options) => {
        if (!args[0]) {
          throw "no value provided.";
        }

        const meJsValue = options.meValue.asJsValue(context);
        const compJsValue = args[0].asNumber(context).asJsValue(context);

        return meJsValue > compJsValue
          ? this.mavka.yesCellInstance
          : this.mavka.noCellInstance;
      },
      { jsArgs: false }
    );
    // todo: complete
    // <=
    this.methods["виконати_порівняння_чи_не_більше"] = this.mavka.tools.fn(
      (args, context, options) => {
        if (!args[0]) {
          throw "no value provided.";
        }

        const meJsValue = options.meValue.asJsValue(context);
        const compJsValue = args[0].asNumber(context).asJsValue(context);

        return meJsValue <= compJsValue
          ? this.mavka.yesCellInstance
          : this.mavka.noCellInstance;
      },
      { jsArgs: false }
    );
  }
}

export default DiiaStructureCell;
