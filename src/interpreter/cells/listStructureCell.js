import StructureCell from "./common/structureCell.js";

class ListStructureCell extends StructureCell {
  /**
   * @param {Mavka} mavka
   */
  constructor(mavka) {
    super(mavka, "список");

    this.properties["виконати_виклик"] = this.mavka.makeProxyFunction((args) => {
      return this.mavka.makeList(Object.values(args));
    });

    this.setMethod("виконати_перетворення_на_текст", (args, context, options) => {
      const values = options.meValue.meta.values
        .map((v) => {
          if (this.mavka.isText(v)) {
            return `"${v.asText(context).asJsValue(context)}"`;
          }
          return v.asText(context).asJsValue(context);
        })
        .join(", ");

      return this.mavka.toCell(`[${values}]`);
    });

    this.setMethod("виконати_отримання_елемента", (args, context, options) => {
      const index = Object.values(args)[0].asJsValue(context);

      return this.mavka.toCell(options.meValue.meta.values[index]);
    });
    this.setMethod("виконати_присвоєння_елемента", (args, context, options) => {
      const index = Object.values(args)[0].asJsValue(context);
      const value = Object.values(args)[1];

      options.meValue.meta.values[index] = value;

      return value;
    });

    this.setMethod("довжина", (args, context, options) => {
      return this.mavka.makeNumber(options.meValue.meta.values.length);
    });
    this.setMethod("додати", (args, context, options) => {
      return this.mavka.makeNumber(options.meValue.meta.values.push(Object.values(args)[0]));
    });
    this.setMethod("забрати", (args, context, options) => {
      return options.meValue.meta.values.pop();
    });
    this.setMethod("сортувати", (args, context, options) => {
      let fn = Object.values(args)[0];
      if (!fn) {
        fn = this.mavka.makeProxyFunction((args) => {
          return this.mavka.makeNumber(args[0].asJsValue(context) - args[1].asJsValue(context));
        });
      }

      return this.mavka.makeList(options.meValue.meta.values.sort(
        (a, b) => fn.doCall(context, [a, b]).asJsValue(context)
      ));
    });
    this.setMethod("фільтрувати", (args, context, options) => {
      let fn = Object.values(args)[0];
      if (!fn) {
        fn = this.mavka.empty;
      }

      return this.mavka.makeList(options.meValue.meta.values.filter(
        (a) => fn.doCall(context, [a]).asJsValue(context)
      ));
    });
    this.setMethod("знайти", (args, context, options) => {
      let fn = Object.values(args)[0];
      if (!fn) {
        fn = this.mavka.empty;
      }

      return options.meValue.meta.values.find(
        (a) => fn.doCall(context, [a]).asJsValue(context)
      );
    });
    this.setMethod("знайти_позицію", (args, context, options) => {
      let fn = Object.values(args)[0];
      if (!fn) {
        fn = this.mavka.empty;
      }

      return this.mavka.makeNumber(options.meValue.meta.values.findIndex(
        (a) => fn.doCall(context, [a]).asJsValue(context)
      ));
    });
    this.setMethod("перетворити", (args, context, options) => {
      let fn = Object.values(args)[0];
      if (!fn) {
        fn = this.mavka.empty;
      }

      return this.mavka.makeList(options.meValue.meta.values.map(
        (a, b) => fn.doCall(context, [a, b])
      ));
    });
    this.setMethod("заповнити", (args, context, options) => {
      let value = Object.values(args)[0];
      if (!value) {
        value = this.mavka.empty;
      }

      options.meValue.meta.values.fill(value);

      return options.meValue;
    });
    this.setMethod("злити", (args, context, options) => {
      let value = Object.values(args)[0];
      if (!value) {
        value = this.mavka.empty;
      }

      if (!this.mavka.isList(value)) {
        this.mavka.fall(context, this.mavka.makeText("Злиття можливе тільки зі списком."));
      }

      return this.mavka.makeList(options.meValue.meta.values.concat(value.meta.values));
    });
    this.setMethod("зʼєднати", (args, context, options) => {
      let delimiter = Object.values(args)[0];
      if (!delimiter) {
        delimiter = "";
      } else {
        delimiter = args[0].asJsValue(context);
      }

      return this.mavka.makeText(options.meValue.meta.values.map((element) => element.asJsValue(context)).join(delimiter));
    });
    this.setMethod("обернути", (args, context, options) => {
      return this.mavka.makeList(options.meValue.meta.values.reverse());
    });
    this.setMethod("зрізати", (args, context, options) => {
      let start = Object.values(args)[0];
      if (!start) {
        start = this.mavka.empty;
      }
      let end = Object.values(args)[1];
      if (!start) {
        end = this.mavka.empty;
      }

      return this.mavka.makeList(options.meValue.meta.values.slice(start.asJsValue(context), end.asJsValue(context)));
    });
    this.setMethod("скоротити", (args, context, options) => {
      let fn = Object.values(args)[0];
      if (!fn) {
        fn = this.mavka.empty;
      }
      let initialValue = Object.values(args)[1];
      if (!fn) {
        fn = this.mavka.empty;
      }

      return options.meValue.meta.values.reduce(
        (a, b, c, d) => fn.doCall(context, [a, b, c, d]),
        initialValue
      );
    });
    this.setMethod("позиція", (args, context, options) => {
      if (!args[0]) {
        return this.mavka.makeNumber(-1);
      } else {
        return this.mavka.makeNumber(
          options.meValue.meta.values.findIndex((value) => args[0].doCompareEquals(context, value) === this.mavka.yes)
        );
      }
    });
  }

  static createInstance(mavka) {
    return new ListStructureCell(mavka);
  }
}

export default ListStructureCell;
