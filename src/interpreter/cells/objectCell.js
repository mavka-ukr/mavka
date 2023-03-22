import { Cell } from "./utils/cell.js";

class ObjectCell extends Cell {
  /**
   * @param {Mavka} mavka
   * @param {Object} properties
   */
  constructor(mavka, properties = {}) {
    super(
      mavka,
      "<обʼєкт>",
      properties,
      {},
      null,
      mavka.objectStructureCellInstance
    );
  }

  asText(context) {
    const properties = Object.entries(this.properties)
      .map(([k, v]) => `${k}=${v.asText(context).asJsValue(context)}`)
      .join(", ");

    return this.mavka.toCell(`${this.name}(${properties})`);
  }

  asJsValue(context) {
    const jsObject = {};

    Object.entries(this.properties)
      .forEach(([k, v]) => {
        if (this.get("__оминати_пустоту_конвертуючи__").asBoolean(context).asJsValue(context)) {
          if (this.mavka.isEmpty(v)) {
            return;
          }
        }

        jsObject[k] = v.asJsValue(context);
      });

    return jsObject;
  }
}

export default ObjectCell;
