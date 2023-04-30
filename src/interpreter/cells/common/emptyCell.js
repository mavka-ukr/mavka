import { Cell } from "./cell.js";

/**
 * Empty cell.
 */
class EmptyCell extends Cell {
  /**
   * @param {Mavka} mavka
   * @param {*} jsValue
   */
  constructor(mavka, jsValue) {
    super(
      mavka,
      "пусто",
      {},
      null,
      () => jsValue,
      null,
      {}
    );

    this.properties["виконати_перетворення_на_текст"] = this.mavka.makeProxyFunction(() => {
      return this.mavka.makeText("пусто");
    });
    this.properties["виконати_перетворення_на_число"] = this.mavka.makeProxyFunction((args, context) => {
      this.mavka.fall(context, this.mavka.makeText("Неможливо перетворити \"пусто\" в число"));
    });
    this.properties["виконати_перетворення_на_логічне"] = this.mavka.makeProxyFunction(() => {
      return this.mavka.no;
    });

    this.properties["виконати_додавання"] = this.mavka.makeProxyFunction((args, context) => {
      this.mavka.fall(context, this.mavka.makeText("Неможливо виконати операцію \"+\" з типом \"пусто\""));
    });
    this.properties["виконати_віднімання"] = this.mavka.makeProxyFunction((args, context) => {
      this.mavka.fall(context, this.mavka.makeText("Неможливо виконати операцію \"-\" з типом \"пусто\""));
    });
    this.properties["виконати_множення"] = this.mavka.makeProxyFunction((args, context) => {
      this.mavka.fall(context, this.mavka.makeText("Неможливо виконати операцію \"*\" з типом \"пусто\""));
    });
    this.properties["виконати_ділення"] = this.mavka.makeProxyFunction((args, context) => {
      this.mavka.fall(context, this.mavka.makeText("Неможливо виконати операцію \"/\" з типом \"пусто\""));
    });
    this.properties["виконати_ділення_за_модулем_остача"] = this.mavka.makeProxyFunction((args, context) => {
      this.mavka.fall(context, this.mavka.makeText("Неможливо виконати операцію \"%\" з типом \"пусто\""));
    });
    this.properties["виконати_ділення_за_модулем_частка"] = this.mavka.makeProxyFunction((args, context) => {
      this.mavka.fall(context, this.mavka.makeText("Неможливо виконати операцію \"//\" з типом \"пусто\""));
    });
    this.properties["виконати_піднесення_до_степеня"] = this.mavka.makeProxyFunction((args, context) => {
      this.mavka.fall(context, this.mavka.makeText("Неможливо виконати операцію \"**\" з типом \"пусто\""));
    });
    this.properties["виконати_виняткову_дизʼюнкцію"] = this.mavka.makeProxyFunction((args, context) => {
      let value = args[0];
      if (!value) {
        value = this.mavka.empty;
      }

      return value.asNumber(context);
    });

    this.properties["виконати_порівняння_чи_рівно"] = this.mavka.makeProxyFunction((args) => {
      let value = args[0];
      if (!value) {
        value = this.mavka.empty;
      }

      return this.mavka.isEmpty(value)
        ? this.mavka.yes
        : this.mavka.no;
    });
    this.properties["виконати_порівняння_чи_не_рівно"] = this.mavka.makeProxyFunction((args) => {
      let value = args[0];
      if (!value) {
        value = this.mavka.empty;
      }

      return !this.mavka.isEmpty(value)
        ? this.mavka.yes
        : this.mavka.no;
    });
    this.properties["виконати_порівняння_чи_менше"] = this.mavka.makeProxyFunction((args, context) => {
      this.mavka.fall(context, this.mavka.makeText("Неможливо виконати операцію \"чи_менше\" з типом \"пусто\""));
    });
    this.properties["виконати_порівняння_чи_не_менше"] = this.mavka.makeProxyFunction((args, context) => {
      this.mavka.fall(context, this.mavka.makeText("Неможливо виконати операцію \"чи_не_менше\" з типом \"пусто\""));
    });
    this.properties["виконати_порівняння_чи_більше"] = this.mavka.makeProxyFunction((args, context) => {
      this.mavka.fall(context, this.mavka.makeText("Неможливо виконати операцію \"чи_більше\" з типом \"пусто\""));
    });
    this.properties["виконати_порівняння_чи_не_більше"] = this.mavka.makeProxyFunction((args, context) => {
      this.mavka.fall(context, this.mavka.makeText("Неможливо виконати операцію \"чи_не_більше\" з типом \"пусто\""));
    });
  }

  get(context, name) {
    if (name in this.properties) {
      return this.properties[name];
    }

    this.mavka.fall(context, this.mavka.makeText("Неможливо отримувати значення з пустоти."));
  }

  set(context, name, value) {
    this.mavka.fall(context, this.mavka.makeText("Неможливо встановлювати значення в пустоту."));
  }

  doCall(context, args, options = {}) {
    this.mavka.fall(context, this.mavka.makeText("Неможливо викликати пустоту."));
  }

  asText(context) {
    return this.mavka.makeText("пусто");
  }

  isInstanceOf(value) {
    return this.mavka.isEmpty(value);
  }
}

export default EmptyCell;
