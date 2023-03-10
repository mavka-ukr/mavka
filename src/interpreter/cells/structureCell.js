import { Cell } from "./cell.js";
import { runParams } from "../../std/tools.js";

export class StructureCell extends Cell {
  /**
   * @param {Mavka} mavka
   * @param {Context} context
   * @param {StructureNode} node
   */
  constructor(mavka, context, node) {
    super(mavka, "Структура");

    this.context = context;
    this.node = node;

    this.defaultValues = {};

    if (this.node.parent) {
      this.prototype = this.mavka.runSync(context, node.parent, { forceSync: true });
    }
  }

  call(context, args) {
    const cell = new this.mavka.Cell(this.mavka, this.node.name.name, {}, {}, this);

    let params = this.getParams();
    runParams(this.mavka, context, cell, params, [], this.defaultValues);

    // const createFn = this.get("прототип").get("створити");
    // if (!this.mavka.isEmpty(createFn)) {
    //   createFn.call(context, args, { meValue: cell });
    // } else {
    runParams(this.mavka, context, cell, params, args, this.defaultValues);
    // }
    //
    // const afterCreateFn = this.get("прототип").get("створено");
    // if (!this.mavka.isEmpty(afterCreateFn)) {
    //   afterCreateFn.call(context, args, { meValue: cell });
    // }

    return cell;
  }

  getParams() {
    let params = this.node.params;
    if (this.prototype) {
      params = [...params, ...this.prototype.getParams()];
    }
    return params;
  }

  getMethods() {
    let methods = this.methods;
    if (this.prototype) {
      methods = { ...methods, ...this.prototype.getMethods() };
    }
    return methods;
  }

  asString() {
    let value = `структура ${this.node.name.name}`;

    if (this.prototype) {
      value = `${value} є ${this.prototype.node.name.name}`;
    }

    return this.mavka.toCell(value);
  }
}

export class ListConstructorCell extends Cell {
  /**
   * @param {Mavka} mavka
   */
  constructor(mavka) {
    super(mavka, "Список");
  }

  call(context, args) {
    const values = [];

    for (const arg of args) {
      values.push(arg);
    }

    return new this.mavka.ListCell(this.mavka, values);
  }

  asString() {
    return this.mavka.toCell(`структура Список`);
  }
}

export class ObjectConstructorCell extends Cell {
  /**
   * @param {Mavka} mavka
   */
  constructor(mavka) {
    super(mavka, "Об'єкт");
  }

  call(context, args, options = {}) {
    const cell = new this.mavka.Cell(this.mavka, this.name, {}, this);
    if (Array.isArray(args)) {
      // todo: maybe return new list instead?
      args.forEach((v, k) => {
        cell.set(k, v);
      });
    } else {
      Object.entries(args).forEach(([k, v]) => {
        cell.set(k, v);
      });
    }
    return cell;
  }

  asString() {
    return this.mavka.toCell(`структура Об'єкт`);
  }
}
