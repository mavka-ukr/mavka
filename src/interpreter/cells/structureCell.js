import { Cell } from "./cell.js";
import { runParams } from "./utils.js";

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

    // prototype
    this.set("назва", this.node.name.name);
    this.set("прототип", new this.mavka.Cell(this.mavka, this.mavka.Cell.DEFAULT_NAME));

    this.superMethods = [];

    // set parent prototype
    if (node.parent) {
      this.parent = this.mavka.runSync(context, node.parent, { forceSync: true });

      if (!(this.parent instanceof StructureCell)) {
        throw "fuck";
      }

      this.get("прототип").set(Cell.PROTOTYPE_PROPERTY_NAME, this.parent.get("прототип"));
      this.set(Cell.PROTOTYPE_PROPERTY_NAME, this.parent);
    } else {
      this.get("прототип").set(Cell.PROTOTYPE_PROPERTY_NAME, this.mavka.objectCell.get("прототип"));
      this.set(Cell.PROTOTYPE_PROPERTY_NAME, this.mavka.objectCell);
    }

    this.get("прототип").set("структура", this);

    // fill prototype with methods
    for (const method of this.node.methods) {
      const diia = new this.mavka.DiiaCell(this.mavka, context, method);
      diia.superValue = this.get("прототип").get(Cell.PROTOTYPE_PROPERTY_NAME);
      this.superMethods.push(diia);
      this.get("прототип").set(method.name.name, diia);
    }
  }

  set(name, value) {
    if (name === Cell.PROTOTYPE_PROPERTY_NAME) {
      for (const superMethod of this.superMethods) {
        superMethod.superValue = value;
      }
    }

    super.set(name, value);
  }

  call(context, args) {
    const cell = new this.mavka.Cell(this.mavka, this.node.name.name);
    cell.set(Cell.PROTOTYPE_PROPERTY_NAME, this.get("прототип"));

    let params = this.getParams();
    runParams(this.mavka, context, cell, params, [], this.defaultValues);

    const createFn = this.get("прототип").get("створити");
    if (!this.mavka.isEmpty(createFn)) {
      createFn.call(context, args, { meValue: cell });
    } else {
      runParams(this.mavka, context, cell, params, args, this.defaultValues);
    }

    const afterCreateFn = this.get("прототип").get("створено");
    if (!this.mavka.isEmpty(afterCreateFn)) {
      afterCreateFn.call(context, args, { meValue: cell });
    }

    return cell;
  }

  getParams() {
    let params = this.node.params;
    if (this.parent) {
      params = [...this.parent.getParams(), ...params];
    }
    return params;
  }

  asString() {
    let value = `структура ${this.node.name.name}`;

    if (this.parent) {
      value = `${value} є ${this.parent.node.name.name}`;
    }

    return this.mavka.toCell(value);
  }
}

export class ListConstructorCell extends Cell {
  /**
   * @param {Mavka} mavka
   * @param {Context} context
   */
  constructor(mavka, context) {
    super(mavka, "Список", context);

    this.context = context;
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
