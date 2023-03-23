import StructureCell from "./common/structureCell.js";
import { fillParameters } from "../../std/tools.js";

class ObjectStructureCell extends StructureCell {
  /**
   * @param {Mavka} mavka
   * @param {string} name
   * @param {Record<string, Cell>} properties
   * @param {StructureCell|null} parent
   * @param {{ name: string, defaultValue: Cell|undefined }[]} parameters
   * @param {Record<string, Cell>} methods
   */
  constructor(mavka,
              name,
              properties = {},
              parent = null,
              parameters = [],
              methods = {}) {
    super(mavka, name, properties, parent, parameters, methods);

    this.properties["виконати_виклик"] = this.mavka.tools.fn(
      (args, callContext) => {
        const objectCell = new this.mavka.Cell(
          this.mavka,
          this.name,
          {},
          this
        );

        fillParameters(
          this.mavka,
          callContext,
          objectCell,
          this.getAllParameters(),
          args
        );

        return objectCell;
      },
      { jsArgs: false }
    );
  }
}

export default ObjectStructureCell;
