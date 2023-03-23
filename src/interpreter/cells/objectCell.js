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
      mavka.objectStructureCellInstance
    );
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
