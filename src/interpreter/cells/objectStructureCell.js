import StructureCell from "./common/structureCell.js";
import { fillParameters } from "../../std/tools.js";

class ObjectStructureCell extends StructureCell {
  /**
   * @param {Mavka} mavka
   * @param {string} name
   * @param {Record<string, Cell>} properties
   * @param {StructureCell|null} parent
   * @param {{ name: string, defaultValue: Cell|undefined }[]} parameters
   * @param {Record<string, Method>} methods
   */
  constructor(mavka,
              name,
              properties = {},
              parent = null,
              parameters = [],
              methods = {}) {
    super(mavka, name, properties, parent, parameters, methods);

    this.properties["виконати_виклик"] = this.mavka.makeProxyFunction(
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
      }
    );
  }

  static createInstance(mavka) {
    return new ObjectStructureCell(mavka, "обʼєкт", {}, null, [], {
      "виконати_перетворення_на_текст": mavka.makeMethod(
        "виконати_перетворення_на_текст",
        (args, callContext, options) => {
          const properties = options.meValue.structure.getAllParameters()
            .map((p) => [p.name, options.meValue.get(callContext, p.name)])
            .map(([k, v]) => `${k}=${v.asText(callContext).asJsValue(callContext)}`)
            .join(", ");

          return mavka.toCell(`${options.meValue.name}(${properties})`);
        }
      ),
      "виконати_перетворення_на_число": mavka.makeMethod(
        "виконати_перетворення_на_число",
        (args, callContext, options) => {
          return options.meValue.asText(callContext).asNumber(callContext);
        }
      ),
      "виконати_перетворення_на_логічне": mavka.makeMethod(
        "виконати_перетворення_на_логічне",
        () => {
          return mavka.yesCellInstance;
        }
      )
    });
  }
}

export default ObjectStructureCell;
