import StructureCell from "./common/structureCell.js";

class DictionaryStructureCell extends StructureCell {
  /**
   * @param {Mavka} mavka
   */
  constructor(mavka) {
    super(mavka, "словник");

    this.properties["виконати_виклик"] = this.mavka.makeProxyFunction((args, context) => {
      const items = new Map();

      if (Array.isArray(args)) {
        for (const k of args) {
          if (mavka.isBasic(k)) {
            items.set(k.asJsValue(context), this.mavka.empty);
          } else {
            items.set(k, this.mavka.empty);
          }
        }
      } else {
        for (const [k, v] of Object.entries(args)) {
          items.set(k, v);
        }
      }

      return this.mavka.makeDictionary(items);
    });

    this.setMethod("виконати_отримання", (args, context, options) => {
      let index = Object.values(args)[0];

      if (this.mavka.isBasic(index)) {
        index = index.asJsValue(context);
      }

      return this.mavka.toCell(options.meValue.meta.items.get(index));
    });
    this.setMethod("виконати_присвоєння", (args, context, options) => {
      let key = args[0];
      let value = args[1];
      if (!key) {
        key = this.mavka.empty;
      }
      if (!value) {
        value = this.mavka.empty;
      }

      if (this.mavka.isBasic(key)) {
        key = key.asJsValue(context);
      }

      options.meValue.meta.items.set(key, value);

      return value;
    });

    this.setMethod("виконати_перетворення_на_текст", (args, context, options) => {
      const items = [...options.meValue.meta.items.entries()]
        .map(([k, v]) => {
          let kt = this.mavka.toCell(k).asText(context).asJsValue(context);
          let vt = v.asText(context).asJsValue(context);

          if (this.mavka.isText(this.mavka.toCell(kt))) {
            kt = `"${kt}"`;
          }
          if (this.mavka.isText(v)) {
            vt = `"${vt}"`;
          }

          return `${kt}=${vt}`;
        })
        .join(", ");

      return this.mavka.toCell(`(${items})`);
    });

    this.setMethod("виконати_отримання_елемента", (args, context, options) => {
      let index = Object.values(args)[0];

      if (this.mavka.isBasic(index)) {
        index = index.asJsValue(context);
      }

      return this.mavka.toCell(options.meValue.meta.items.get(index));
    });
    this.setMethod("виконати_присвоєння_елемента", (args, context, options) => {
      let key = args[0];
      let value = args[1];
      if (!key) {
        key = this.mavka.empty;
      }
      if (!value) {
        value = this.mavka.empty;
      }

      if (this.mavka.isBasic(key)) {
        key = key.asJsValue(context);
      }

      options.meValue.meta.items.set(key, value);

      return value;
    });

    this.setMethod("покласти", (args, context, options) => {
      let key = args[0];
      let value = args[1];
      if (!key) {
        key = this.mavka.empty;
      }
      if (!value) {
        value = this.mavka.empty;
      }

      if (this.mavka.isBasic(key)) {
        key = key.asJsValue(context);
      }

      options.meValue.meta.items.set(key, value);

      return value;
    });
    this.setMethod("отримати", (args, context, options) => {
      let key = Object.values(args)[0];

      if (this.mavka.isBasic(key)) {
        key = key.asJsValue(context);
      }

      return options.meValue.meta.items.get(key);
    });
    this.setMethod("вилучити", (args, context, options) => {
      let key = Object.values(args)[0];

      if (this.mavka.isBasic(key)) {
        key = key.asJsValue(context);
      }

      return this.mavka.toCell(options.meValue.meta.items.delete(key));
    });
    this.setMethod("розмір", (args, context, options) => {
      return this.mavka.makeNumber(options.meValue.meta.items.size);
    });
    this.setMethod("очистити", (args, context, options) => {
      options.meValue.meta.items.clear();

      return this.mavka.empty;
    });
    this.setMethod("ключі", (args, context, options) => {
      return new mavka.Cell(
        this.mavka,
        "ітератор",
        {},
        null,
        () => [...options.meValue.meta.items.keys()].map((k) => this.mavka.toCell(k).asJsValue(context)),
        function* () {
          let i = 0;
          for (const key of options.meValue.meta.items.keys()) {
            yield { key: i, value: mavka.toCell(key) };
            i++;
          }
        },
        null
      );
    });
    this.setMethod("значення", (args, context, options) => {
      return new mavka.Cell(
        this.mavka,
        "ітератор",
        {},
        null,
        () => [...options.meValue.meta.items.values()].map((v) => v.asJsValue(context)),
        function* () {
          let i = 0;
          for (const value of options.meValue.meta.items.values()) {
            yield { key: i, value };
            i++;
          }
        },
        null
      );
    });

    this.setMethod("виконати_порівняння_чи_містить", (args, context, options) => {
      let key = Object.values(args)[0];

      if (this.mavka.isBasic(key)) {
        key = key.asJsValue(context);
      }

      return this.mavka.toCell(options.meValue.meta.items.has(key));
    });
    this.setMethod("виконати_порівняння_чи_не_містить", (args, context, options) => {
      let key = Object.values(args)[0];

      if (this.mavka.isBasic(key)) {
        key = key.asJsValue(context);
      }

      return this.mavka.toCell(!options.meValue.meta.items.has(key));
    });
  }

  static createInstance(mavka) {
    return new DictionaryStructureCell(mavka);
  }
}

export default DictionaryStructureCell;
