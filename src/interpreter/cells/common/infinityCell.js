import { Cell } from "./cell.js";

/**
 * Infinity cell.
 */
class InfinityCell extends Cell {
  /**
   * @param {Mavka} mavka
   * @param {*} jsValue
   */
  constructor(mavka, jsValue) {
    super(
      mavka,
      "Нескінченність",
      {},
      null,
      () => jsValue,
      null,
      {}
    );

    this.properties["виконати_перетворення_на_текст"] = this.mavka.makeProxyFunction(() => {
      return this.mavka.makeText("Нескінченність");
    });
    this.properties["виконати_перетворення_на_число"] = this.mavka.makeProxyFunction(() => {
      return this;
    });
    this.properties["виконати_перетворення_на_логічне"] = this.mavka.makeProxyFunction(() => {
      return this.mavka.no;
    });

    this.properties["виконати_додавання"] = this.mavka.makeProxyFunction(() => {
      return this;
    });
    this.properties["виконати_віднімання"] = this.mavka.makeProxyFunction(() => {
      return this;
    });
    this.properties["виконати_множення"] = this.mavka.makeProxyFunction(() => {
      return this;
    });
    this.properties["виконати_ділення"] = this.mavka.makeProxyFunction(() => {
      return this;
    });
    this.properties["виконати_ділення_за_модулем_остача"] = this.mavka.makeProxyFunction(() => {
      return this;
    });
    this.properties["виконати_ділення_за_модулем_частка"] = this.mavka.makeProxyFunction(() => {
      return this;
    });
    this.properties["виконати_піднесення_до_степеня"] = this.mavka.makeProxyFunction(() => {
      return this;
    });
    this.properties["виконати_виняткову_дизʼюнкцію"] = this.mavka.makeProxyFunction(() => {
      return this;
    });

    this.properties["виконати_порівняння_чи_рівно"] = this.mavka.makeProxyFunction(() => {
      return this.mavka.no;
    });
    this.properties["виконати_порівняння_чи_не_рівно"] = this.mavka.makeProxyFunction(() => {
      return this.mavka.yes;
    });
    this.properties["виконати_порівняння_чи_менше"] = this.mavka.makeProxyFunction(() => {
      return this.mavka.infinity;
    });
    this.properties["виконати_порівняння_чи_не_менше"] = this.mavka.makeProxyFunction(() => {
      return this.mavka.infinity;
    });
    this.properties["виконати_порівняння_чи_більше"] = this.mavka.makeProxyFunction(() => {
      return this.mavka.infinity;
    });
    this.properties["виконати_порівняння_чи_не_більше"] = this.mavka.makeProxyFunction(() => {
      return this.mavka.infinity;
    });
  }

  get(context, name) {
    if (name in this.properties) {
      return this.properties[name];
    }

    this.mavka.fall(context, this.mavka.makeText("Неможливо отримувати значення з Нескінченність."));
  }

  set(context, name, value) {
    this.mavka.fall(context, this.mavka.makeText("Неможливо встановлювати значення в Нескінченність."));
  }

  doCall(context, args, options = {}) {
    this.mavka.fall(context, this.mavka.makeText("Неможливо викликати Нескінченність."));
  }

  asText(context) {
    return this.mavka.makeText("Нескінченність");
  }

  isInstanceOf(value) {
    return this.mavka.isNaN(value);
  }
}

export default InfinityCell;
