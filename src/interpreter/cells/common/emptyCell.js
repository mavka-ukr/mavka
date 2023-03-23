import { Cell } from "./cell.js";

class EmptyCell extends Cell {
  /**
   * @param {Mavka} mavka
   */
  constructor(mavka) {
    super(mavka, "пусто");

    this.properties["виконати_додавання"] = this.mavka.tools.fn(
      (args, context) => {
        if (!args[0]) {
          throw "no value provided.";
        }

        return args[0].asNumber(context);
      },
      { jsArgs: false }
    );
    this.properties["виконати_віднімання"] = this.mavka.tools.fn(
      (args, context) => {
        if (!args[0]) {
          throw "no value provided.";
        }

        return args[0].asNumber(context).negative(context);
      },
      { jsArgs: false }
    );
    this.properties["виконати_множення"] = this.mavka.tools.fn(
      (args) => {
        if (!args[0]) {
          throw "no value provided.";
        }

        return this.mavka.makeNumber(0);
      },
      { jsArgs: false }
    );
    this.properties["виконати_ділення"] = this.mavka.tools.fn(
      (args) => {
        if (!args[0]) {
          throw "no value provided.";
        }

        return this.mavka.makeNumber(0);
      },
      { jsArgs: false }
    );
    this.properties["виконати_ділення_за_модулем_остача"] = this.mavka.tools.fn(
      (args) => {
        if (!args[0]) {
          throw "no value provided.";
        }

        return this.mavka.makeNumber(0);
      },
      { jsArgs: false }
    );
    this.properties["виконати_ділення_за_модулем_частка"] = this.mavka.tools.fn(
      (args) => {
        if (!args[0]) {
          throw "no value provided.";
        }

        return this.mavka.makeNumber(0);
      },
      { jsArgs: false }
    );
    this.properties["виконати_піднесення_до_степеня"] = this.mavka.tools.fn(
      (args) => {
        if (!args[0]) {
          throw "no value provided.";
        }

        return this.mavka.makeNumber(0);
      },
      { jsArgs: false }
    );
    this.properties["виконати_виняткову_дизʼюнкцію"] = this.mavka.tools.fn(
      (args, context) => {
        if (!args[0]) {
          throw "no value provided.";
        }

        return args[0].asNumber(context);
      },
      { jsArgs: false }
    );

    this.properties["виконати_перетворення_на_текст"] = this.mavka.tools.fn(
      () => {
        return this.mavka.makeText("пусто");
      },
      { jsArgs: false }
    );
    this.properties["виконати_перетворення_на_число"] = this.mavka.tools.fn(
      () => this.mavka.makeNumber(0),
      { jsArgs: false }
    );
    this.properties["виконати_перетворення_на_логічне"] = this.mavka.tools.fn(
      () => this.mavka.noCellInstance,
      { jsArgs: false }
    );

    // ==
    this.properties["виконати_порівняння_чи_рівно"] = this.mavka.tools.fn(
      (args) => {
        if (!args[0]) {
          throw "no value provided.";
        }

        return args[0] === this.mavka.emptyCellInstance
          ? this.mavka.yesCellInstance
          : this.mavka.noCellInstance;
      },
      { jsArgs: false }
    );
    // !=
    this.properties["виконати_порівняння_чи_не_рівно"] = this.mavka.tools.fn(
      (args) => {
        if (!args[0]) {
          throw "no value provided.";
        }

        return args[0] !== this.mavka.emptyCellInstance
          ? this.mavka.yesCellInstance
          : this.mavka.noCellInstance;
      },
      { jsArgs: false }
    );
    // <
    this.properties["виконати_порівняння_чи_менше"] = this.mavka.tools.fn(
      (args, context) => {
        if (!args[0]) {
          throw "no value provided.";
        }

        const compJsValue = args[0].asNumber(context).asJsValue(context);

        return 0 < compJsValue
          ? this.mavka.yesCellInstance
          : this.mavka.noCellInstance;
      },
      { jsArgs: false }
    );
    // >=
    this.properties["виконати_порівняння_чи_не_менше"] = this.mavka.tools.fn(
      (args, context) => {
        if (!args[0]) {
          throw "no value provided.";
        }

        const compJsValue = args[0].asNumber(context).asJsValue(context);

        return 0 >= compJsValue
          ? this.mavka.yesCellInstance
          : this.mavka.noCellInstance;
      },
      { jsArgs: false }
    );
    // >
    this.properties["виконати_порівняння_чи_більше"] = this.mavka.tools.fn(
      (args, context) => {
        if (!args[0]) {
          throw "no value provided.";
        }

        const compJsValue = args[0].asNumber(context).asJsValue(context);

        return 0 > compJsValue
          ? this.mavka.yesCellInstance
          : this.mavka.noCellInstance;
      },
      { jsArgs: false }
    );
    // <=
    this.properties["виконати_порівняння_чи_не_більше"] = this.mavka.tools.fn(
      (args, context) => {
        if (!args[0]) {
          throw "no value provided.";
        }

        const compJsValue = args[0].asNumber(context).asJsValue(context);

        return 0 <= compJsValue
          ? this.mavka.yesCellInstance
          : this.mavka.noCellInstance;
      },
      { jsArgs: false }
    );
  }

  asText(context) {
    return this.mavka.makeText("пусто");
  }

  isInstanceOf(context, value) {
    if (value === this.mavka.emptyCellInstance) {
      return this.mavka.yesCellInstance;
    }

    return this.mavka.noCellInstance;
  }
}

export default EmptyCell;
