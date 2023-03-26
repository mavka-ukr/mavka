import StructureCell from "../interpreter/cells/common/structureCell.js";

class RangeStructureCell extends StructureCell {
  static instance = null;

  /**
   * @param {Mavka} mavka
   */
  constructor(mavka) {
    super(mavka, "діапазон");

    this.properties["виконати_виклик"] = this.mavka.makeProxyFunction(
      (args, context) => {
        let from = 0;
        let to = 0;
        let step = 1;

        if (Array.isArray(args) && args.length) {
          if (args.length === 1) {
            to = args[0].asNumber(context).asJsValue(context);
          } else if (args.length === 2) {
            from = args[0].asNumber(context).asJsValue(context);
            to = args[1].asNumber(context).asJsValue(context);
          } else if (args.length >= 3) {
            from = args[0].asNumber(context).asJsValue(context);
            to = args[1].asNumber(context).asJsValue(context);
            step = args[2].asNumber(context).asJsValue(context);
          }
        }

        const mavka = this.mavka;

        return new this.mavka.Cell(
          this.mavka,
          `діапазон(${from}, ${to}, ${step})`,
          {},
          RangeStructureCell.getInstance(mavka),
          () => {
            return null;
          },
          function* () {
            for (let i = from, key = 0; i < to; i += step, key++) {
              yield { key, value: mavka.makeNumber(i) };
            }
          }
        );
      }
    );
  }

  static getInstance(mavka) {
    if (!RangeStructureCell.instance) {
      RangeStructureCell.instance = new RangeStructureCell(mavka);
    }
    return RangeStructureCell.instance;
  }
}

export default RangeStructureCell;
