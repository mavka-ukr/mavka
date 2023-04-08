import StructureCell from "./common/structureCell.js";

class TextStructureCell extends StructureCell {
  /**
   * @param {Mavka} mavka
   */
  constructor(mavka) {
    super(mavka, "текст");

    this.properties["виконати_виклик"] = this.mavka.makeProxyFunction(
      (args, context) => {
        if (Array.isArray(args) && args.length) {
          return args[0].asText(context);
        }

        return this.mavka.toCell("");
      }
    );

    this.setMethod("виконати_перетворення_на_текст", (args, context, options) => {
      return options.meValue;
    });
    this.setMethod("виконати_перетворення_на_число", (args, context, options) => {
      return this.mavka.makeNumber(Number(options.meValue.asJsValue(context)));
    });
    this.setMethod("виконати_перетворення_на_логічне", (args, context, options) => {
      return options.meValue.asJsValue(context)
        ? this.mavka.yes
        : this.mavka.no;
    });

    this.setMethod("виконати_додавання", (args, context, options) => {
      let value = args[0];
      if (!value) {
        value = this.mavka.empty;
      }

      return this.mavka.makeText(options.meValue.asJsValue(context) + value.asText(context).asJsValue(context));
    });
    this.setMethod("виконати_віднімання", (args, context, options) => {
      let value = args[0];
      if (!value) {
        value = this.mavka.empty;
      }

      return options.meValue.asNumber(context).doSub(context, value);
    });
    this.setMethod("виконати_множення", (args, context, options) => {
      let value = args[0];
      if (!value) {
        value = this.mavka.empty;
      }

      return options.meValue.asNumber(context).doMul(context, value);
    });
    this.setMethod("виконати_ділення", (args, context, options) => {
      let value = args[0];
      if (!value) {
        value = this.mavka.empty;
      }

      return options.meValue.asNumber(context).doDiv(context, value);
    });
    this.setMethod("виконати_ділення_за_модулем_остача", (args, context, options) => {
      let value = args[0];
      if (!value) {
        value = this.mavka.empty;
      }

      return options.meValue.asNumber(context).doDivMod(context, value);
    });
    this.setMethod("виконати_ділення_за_модулем_частка", (args, context, options) => {
      let value = args[0];
      if (!value) {
        value = this.mavka.empty;
      }

      return options.meValue.asNumber(context).doDivFloor(context, value);
    });
    this.setMethod("виконати_піднесення_до_степеня", (args, context, options) => {
      let value = args[0];
      if (!value) {
        value = this.mavka.empty;
      }

      return options.meValue.asNumber(context).doPow(context, value);
    });
    this.setMethod("виконати_виняткову_дизʼюнкцію", (args, context, options) => {
      let value = args[0];
      if (!value) {
        value = this.mavka.empty;
      }

      return options.meValue.asNumber(context).doXor(context, value);
    });

    this.setMethod("виконати_порівняння_чи_рівно", (args, context, options) => {
      let value = args[0];
      if (!value) {
        value = this.mavka.empty;
      }

      if (!this.mavka.isText(value)) {
        return this.mavka.no;
      }

      return options.meValue.properties.value === value.properties.value
        ? this.mavka.yes
        : this.mavka.no;
    });
    this.setMethod("виконати_порівняння_чи_не_рівно", (args, context, options) => {
      let value = args[0];
      if (!value) {
        value = this.mavka.empty;
      }

      if (!this.mavka.isText(value)) {
        return this.mavka.yes;
      }

      return options.meValue.properties.value === value.properties.value
        ? this.mavka.no
        : this.mavka.yes;
    });
    this.setMethod("виконати_порівняння_чи_менше", (args, context, options) => {
      let value = args[0];
      if (!value) {
        value = this.mavka.empty;
      }

      return options.meValue.asNumber(context).doCompareLesserThan(context, value);
    });
    this.setMethod("виконати_порівняння_чи_не_менше", (args, context, options) => {
      let value = args[0];
      if (!value) {
        value = this.mavka.empty;
      }

      return options.meValue.asNumber(context).doCompareGreaterThanOrEquals(context, value);
    });
    this.setMethod("виконати_порівняння_чи_більше", (args, context, options) => {
      let value = args[0];
      if (!value) {
        value = this.mavka.empty;
      }

      return options.meValue.asNumber(context).doCompareGreaterThan(context, value);
    });
    this.setMethod("виконати_порівняння_чи_не_більше", (args, context, options) => {
      let value = args[0];
      if (!value) {
        value = this.mavka.empty;
      }

      return options.meValue.asNumber(context).doCompareLesserThanOrEquals(context, value);
    });
    this.setMethod("довжина", (args, context, options) => {
      return this.mavka.toCell(options.meValue.asJsValue(context).length);
    });
    this.setMethod("виконати_отримання_елемента", (args, context, options) => {
      let index = Object.values(args)[0];

      try {
        if (this.mavka.isEmpty(index) || typeof index === "undefined") {
          this.mavka.fall(context, this.mavka.makeText("Очікується, що ʼпозиціяʼ не є пусто."));
        }

        index = index.asNumber(context).asJsValue(context);

        if (index < 0) {
          this.mavka.fall(context, this.mavka.makeText("Очікується, що ʼпозиціяʼ є не менше 0."));
        }
      } catch (e) {
        if (e instanceof TypeError) {
          this.mavka.fall(context, this.mavka.makeText("Не вдалось перетворити параметр ʼпозиціяʼ у число."));
        } else {
          throw e;
        }
      }

      return this.mavka.toCell(options.meValue.meta.value[index]);
    });
    this.setMethod("символ", (args, context, options) => {
      let index = args[0];

      try {
        if (this.mavka.isEmpty(index) || typeof index === "undefined") {
          this.mavka.fall(context, this.mavka.makeText("Очікується, що ʼпозиціяʼ не є пусто."));
        }

        index = index.asNumber(context).asJsValue(context);

        if (index < 0) {
          this.mavka.fall(context, this.mavka.makeText("Очікується, що ʼпозиціяʼ є не менше 0."));
        }
      } catch (e) {
        if (e instanceof TypeError) {
          this.mavka.fall(context, this.mavka.makeText("Не вдалось перетворити параметр ʼпозиціяʼ у число."));
        } else {
          throw e;
        }
      }

      return this.mavka.toCell(options.meValue.meta.value.charAt(index));
    });
    this.setMethod("код_символу", (args, context, options) => {
      let index = args[0];

      try {
        if (this.mavka.isEmpty(index) || typeof index === "undefined") {
          this.mavka.fall(context, this.mavka.makeText("Очікується, що ʼпозиціяʼ не є пусто."));
        }

        index = index.asNumber(context).asJsValue(context);

        if (index < 0) {
          this.mavka.fall(context, this.mavka.makeText("Очікується, що ʼпозиціяʼ є не менше 0."));
        }
      } catch (e) {
        if (e instanceof TypeError) {
          this.mavka.fall(context, this.mavka.makeText("Не вдалось перетворити параметр ʼпозиціяʼ у число."));
        } else {
          throw e;
        }
      }

      return this.mavka.toCell(options.meValue.meta.value.charCodeAt(index));
    });
    this.setMethod("позиція", (args, context, options) => {
      let searchString = args[0];

      try {
        if (this.mavka.isEmpty(searchString) || typeof searchString === "undefined") {
          this.mavka.fall(context, this.mavka.makeText("Очікується, що ʼзначенняʼ не є пусто."));
        }

        searchString = searchString.asText(context).asJsValue(context);
      } catch (e) {
        if (e instanceof TypeError) {
          this.mavka.fall(context, this.mavka.makeText("Не вдалось перетворити параметр ʼзначенняʼ у текст."));
        } else {
          throw e;
        }
      }

      return this.mavka.toCell(options.meValue.meta.value.indexOf(searchString));
    });
    this.setMethod("повторити", (args, context, options) => {
      let count = args[0];


      try {
        if (this.mavka.isEmpty(count) || typeof count === "undefined") {
          this.mavka.fall(context, this.mavka.makeText("Очікується, що ʼкількістьʼ не є пусто."));
        }

        count = count.asNumber(context).asJsValue(context);

        if (Number.isNaN(count)) {
          throw new TypeError("Expected `count` to not be NaN");
        }

        if (count < 0) {
          this.mavka.fall(context, this.mavka.makeText("Очікується, що ʼкількістьʼ є не менше 0."));
        }
      } catch (e) {
        if (e instanceof TypeError) {
          this.mavka.fall(context, this.mavka.makeText("Не вдалось перетворити параметр ʼкількістьʼ у число."));
        } else {
          throw e;
        }
      }

      if (count < 0) {
        this.mavka.fall(context, this.mavka.makeText("Очікується, що кількість не меншою від 0."));
      }

      return this.mavka.toCell(options.meValue.meta.value.repeat(count));
    });
    this.setMethod("замінити_перше", (args, context, options) => {
      let [pattern, replacement] = args;

      try {
        if (this.mavka.isEmpty(pattern) || typeof pattern === "undefined") {
          this.mavka.fall(context, this.mavka.makeText("Очікується, що ʼстаре_значенняʼ не є пусто."));
        }

        pattern = pattern.asText(context).asJsValue(context);
      } catch (e) {
        if (e instanceof TypeError) {
          this.mavka.fall(context, this.mavka.makeText("Не вдалось перетворити параметр ʼстаре_значенняʼ у текст."));
        } else {
          throw e;
        }
      }

      try {
        if (this.mavka.isEmpty(replacement) || typeof replacement === "undefined") {
          this.mavka.fall(context, this.mavka.makeText("Очікується, що ʼнове_значенняʼ не є пусто."));
        }

        replacement = replacement.asText(context).asJsValue(context);
      } catch (e) {
        if (e instanceof TypeError) {
          this.mavka.fall(context, this.mavka.makeText("Не вдалось перетворити параметр ʼнове_значенняʼ у текст."));
        } else {
          throw e;
        }
      }

      return this.mavka.toCell(options.meValue.meta.value.replace(pattern, replacement));
    });
    this.setMethod("замінити", (args, context, options) => {
      let [pattern, replacement] = args;

      try {
        if (this.mavka.isEmpty(pattern) || typeof pattern === "undefined") {
          this.mavka.fall(context, this.mavka.makeText("Очікується, що ʼстаре_значенняʼ не є пусто."));
        }

        pattern = pattern.asText(context).asJsValue(context);
      } catch (e) {
        if (e instanceof TypeError) {
          this.mavka.fall(context, this.mavka.makeText("Не вдалось перетворити параметр ʼстаре_значенняʼ у текст."));
        } else {
          throw e;
        }
      }

      try {
        if (this.mavka.isEmpty(replacement) || typeof replacement === "undefined") {
          this.mavka.fall(context, this.mavka.makeText("Очікується, що ʼнове_значенняʼ не є пусто."));
        }

        replacement = replacement.asText(context).asJsValue(context);
      } catch (e) {
        if (e instanceof TypeError) {
          this.mavka.fall(context, this.mavka.makeText("Не вдалось перетворити параметр ʼнове_значенняʼ у текст."));
        } else {
          throw e;
        }
      }

      return this.mavka.toCell(options.meValue.meta.value.replaceAll(pattern, replacement));
    });
    this.setMethod("зрізати", (args, context, options) => {
      let [indexStart, indexEnd] = args;

      try {
        if (this.mavka.isEmpty(indexStart) || typeof indexStart === "undefined") {
          this.mavka.fall(context, this.mavka.makeText("Очікується, що ʼпозиція_відʼ не є пусто."));
        }

        indexStart = indexStart.asNumber(context).asJsValue(context);

        if (indexStart < 0) {
          this.mavka.fall(context, this.mavka.makeText("Очікується, що ʼпозиція_відʼ є не менше 0."));
        }

        if (Number.isNaN(indexStart)) {
          throw new TypeError("Expected `indexStart` to not be NaN");
        }
      } catch (e) {
        if (e instanceof TypeError) {
          this.mavka.fall(context, this.mavka.makeText("Не вдалось перетворити параметр ʼпозиція_відʼ у число."));
        } else {
          throw e;
        }
      }

      try {
        if (!(this.mavka.isEmpty(indexEnd) || typeof indexEnd === "undefined")) {
          indexEnd = indexEnd.asNumber(indexEnd).asJsValue(context);
          
          if (Number.isNaN(indexEnd)) {
            throw new TypeError("Expected `indexEnd` to not be NaN");
          }

          if (indexEnd < indexStart) {
            this.mavka.fall(context, this.mavka.makeText(`Очікується, що ʼпозиція_доʼ є не менше від ʼпозиція_відʼ (${indexStart}).`));
          }
        } else {
          indexEnd = undefined;
        }
      } catch (e) {
        if (e instanceof TypeError) {
          this.mavka.fall(context, this.mavka.makeText("Не вдалось перетворити параметр ʼпозиція_доʼ у число."));
        } else {
          throw e;
        }
      }

      return this.mavka.toCell(options.meValue.meta.value.substring(indexStart, indexEnd));
    });
    this.setMethod("приєднати", (args, context, options) => {
      if (args.length === 0) {
        return options.meValue;
      }
      try {
        args = args.map(v => v.asText(context).asJsValue(context));
      } catch (e) {
        if (e instanceof TypeError) {
          this.mavka.fall(context, this.mavka.makeText("Не вдалось перетворити деякі параметри ʼінші_текстиʼ у текст."))
        } else {
          throw e;
        }
      }

      return this.mavka.toCell(options.meValue.meta.value.concat(...args));
    });
    this.setMethod("розділити", (args, context, options) => {
      let separator = args[0];

      try {
        separator = separator.asText(context).asJsValue(context);
      } catch (e) {
        if (e instanceof TypeError) {
          this.mavka.fall(context, this.mavka.makeText("Не вдалось перетворити параметр ʼроздільникʼ у текст."));
        } else {
          throw e;
        }
      }

      return this.mavka.makeList(
        options.meValue.meta.value.split(separator).map(v => 
          this.mavka.makeText(v)));
    });
    this.setMethod("починається_з", (args, context, options) => {
      let searchString = args[0];

      try {
        searchString = searchString.asText(context).asJsValue(context);
      } catch (e) {
        if (e instanceof TypeError) {
          this.mavka.fall(context, this.mavka.makeText("Не вдалось перетворити параметр ʼзначенняʼ у текст."));
        } else {
          throw e;
        }
      }

      return this.mavka.toCell(options.meValue.meta.value.startsWith(searchString));
    });
    this.setMethod("закінчується_на", (args, context, options) => {
      let searchString = args[0];

      try {
        searchString = searchString.asText(context).asJsValue(context);
      } catch (e) {
        if (e instanceof TypeError) {
          this.mavka.fall(context, this.mavka.makeText("Не вдалось перетворити параметр ʼзначенняʼ у текст."));
        } else {
          throw e;
        }
      }

      return this.mavka.toCell(options.meValue.meta.value.endsWith(searchString));
    });
    this.setMethod("обрізати", (args, context, options) => {
      return this.mavka.toCell(options.meValue.meta.value.trim());
    });
    this.setMethod("виконати_порівняння_чи_містить", (args, context, options) => {
      let searchString = args[0];

      try {
        searchString = searchString.asText(context).asJsValue(context);
      } catch (e) {
        if (e instanceof TypeError) {
          this.mavka.fall(context, this.mavka.makeText("Не вдалось перетворити значення після ʼміститьʼ у текст."));
        } else {
          throw e;
        }
      }

      return this.mavka.toCell(options.meValue.meta.value.includes(searchString));
    });
    this.setMethod("виконати_порівняння_чи_не_містить", (args, context, options) => {
      let searchString = args[0];

      try {
        searchString = searchString.asText(context).asJsValue(context);
      } catch (e) {
        if (e instanceof TypeError) {
          this.mavka.fall(context, this.mavka.makeText("Не вдалось перетворити значення після ʼміститьʼ у текст."));
        } else {
          throw e;
        }
      }

      return this.mavka.toCell(!options.meValue.meta.value.includes(searchString));
    });
  }

  static createInstance(mavka) {
    return new TextStructureCell(mavka);
  }
}

export default TextStructureCell;
