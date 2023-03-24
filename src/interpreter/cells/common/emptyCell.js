import { Cell } from "./cell.js";

class EmptyCell extends Cell {
  /**
   * @param {Mavka} mavka
   */
  constructor(mavka) {
    super(mavka, "пусто");

    this.properties["виконати_додавання"] = this.mavka.makeProxyFunction((args, context) => {
      let value = args[0];
      if (!value) {
        value = this.mavka.emptyCellInstance;
      }

      return value.asNumber(context);
    });
    this.properties["виконати_віднімання"] = this.mavka.makeProxyFunction((args, context) => {
      let value = args[0];
      if (!value) {
        value = this.mavka.emptyCellInstance;
      }

      return value.asNumber(context).negative(context);
    });
    this.properties["виконати_множення"] = this.mavka.makeProxyFunction((args) => {
      let value = args[0];
      if (!value) {
        value = this.mavka.emptyCellInstance;
      }

      return this.mavka.makeNumber(0);
    });
    this.properties["виконати_ділення"] = this.mavka.makeProxyFunction((args) => {
      let value = args[0];
      if (!value) {
        value = this.mavka.emptyCellInstance;
      }

      return this.mavka.makeNumber(0);
    });
    this.properties["виконати_ділення_за_модулем_остача"] = this.mavka.makeProxyFunction((args) => {
      let value = args[0];
      if (!value) {
        value = this.mavka.emptyCellInstance;
      }

      return this.mavka.makeNumber(0);
    });
    this.properties["виконати_ділення_за_модулем_частка"] = this.mavka.makeProxyFunction((args) => {
      let value = args[0];
      if (!value) {
        value = this.mavka.emptyCellInstance;
      }

      return this.mavka.makeNumber(0);
    });
    this.properties["виконати_піднесення_до_степеня"] = this.mavka.makeProxyFunction((args) => {
      let value = args[0];
      if (!value) {
        value = this.mavka.emptyCellInstance;
      }

      return this.mavka.makeNumber(0);
    });
    this.properties["виконати_виняткову_дизʼюнкцію"] = this.mavka.makeProxyFunction((args, context) => {
      let value = args[0];
      if (!value) {
        value = this.mavka.emptyCellInstance;
      }

      return value.asNumber(context);
    });

    this.properties["виконати_перетворення_на_текст"] = this.mavka.makeProxyFunction(() => {
      return this.mavka.makeText("пусто");
    });
    this.properties["виконати_перетворення_на_число"] = this.mavka.makeProxyFunction(() => {
      return this.mavka.makeNumber(0);
    });
    this.properties["виконати_перетворення_на_логічне"] = this.mavka.makeProxyFunction(() => {
      return this.mavka.noCellInstance;
    });

    this.properties["виконати_порівняння_чи_рівно"] = this.mavka.makeProxyFunction((args) => {
      let value = args[0];
      if (!value) {
        value = this.mavka.emptyCellInstance;
      }

      return value === this.mavka.emptyCellInstance
        ? this.mavka.yesCellInstance
        : this.mavka.noCellInstance;
    });
    this.properties["виконати_порівняння_чи_не_рівно"] = this.mavka.makeProxyFunction((args) => {
      let value = args[0];
      if (!value) {
        value = this.mavka.emptyCellInstance;
      }

      return value !== this.mavka.emptyCellInstance
        ? this.mavka.yesCellInstance
        : this.mavka.noCellInstance;
    });
    this.properties["виконати_порівняння_чи_менше"] = this.mavka.makeProxyFunction((args, context) => {
      let value = args[0];
      if (!value) {
        value = this.mavka.emptyCellInstance;
      }

      const compJsValue = value.asNumber(context).asJsValue(context);

      return 0 < compJsValue
        ? this.mavka.yesCellInstance
        : this.mavka.noCellInstance;
    });
    this.properties["виконати_порівняння_чи_не_менше"] = this.mavka.makeProxyFunction((args, context) => {
      let value = args[0];
      if (!value) {
        value = this.mavka.emptyCellInstance;
      }

      const compJsValue = value.asNumber(context).asJsValue(context);

      return 0 >= compJsValue
        ? this.mavka.yesCellInstance
        : this.mavka.noCellInstance;
    });
    this.properties["виконати_порівняння_чи_більше"] = this.mavka.makeProxyFunction((args, context) => {
      let value = args[0];
      if (!value) {
        value = this.mavka.emptyCellInstance;
      }

      const compJsValue = value.asNumber(context).asJsValue(context);

      return 0 > compJsValue
        ? this.mavka.yesCellInstance
        : this.mavka.noCellInstance;
    });
    this.properties["виконати_порівняння_чи_не_більше"] = this.mavka.makeProxyFunction((args, context) => {
      let value = args[0];
      if (!value) {
        value = this.mavka.emptyCellInstance;
      }

      const compJsValue = value.asNumber(context).asJsValue(context);

      return 0 <= compJsValue
        ? this.mavka.yesCellInstance
        : this.mavka.noCellInstance;
    });
  }

  doCall(context, args, options = {}) {
    return this.mavka.throw(context, "Неможливо викликати пустоту.");
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
