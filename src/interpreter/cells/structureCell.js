import { Cell } from "./utils/cell.js";
import { runParams } from "../../std/tools.js";

class StructureCell extends Cell {
  /**
   * @param {Mavka} mavka
   * @param {Context} context
   * @param {StructureNode} node
   */
  constructor(mavka, context, node) {
    super(mavka, "<структура>");

    this.context = context;
    this.node = node;

    this.defaultValues = {};

    if (this.node.parent) {
      this.parent = this.mavka.runSync(context, node.parent, { forceSync: true });
    } else {
      this.parent = this.mavka.objectStructureCellInstance;
    }
  }

  doCall(context, args) {
    const cell = new this.mavka.Cell(
      this.mavka,
      this.node.name.name,
      {},
      {},
      null,
      this
    );

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
    if (this.parent) {
      params = [...params, ...this.parent.getParams()];
    }
    return params;
  }

  asText(context) {
    let value = `<структура ${this.node.name.name}`;

    if (this.prototype) {
      value = `${value} є ${this.prototype.node.name.name}`;
    }

    value += ">";

    return this.mavka.toCell(value);
  }
}

export default StructureCell;
