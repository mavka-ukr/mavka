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
          this.mavka.fall(context, this.mavka.makeText("Очікується, що \"позиція\" не є пусто."));
        }

        index = index.asNumber(context).asJsValue(context);

        if (index < 0) {
          this.mavka.fall(context, this.mavka.makeText("Очікується, що \"позиція\" є не менше 0."));
        }
      } catch (e) {
        if (e instanceof TypeError) {
          this.mavka.fall(context, this.mavka.makeText("Не вдалось перетворити параметр \"позиція\" у число."));
        } else {
          throw e;
        }
      }

      return this.mavka.toCell(options.meValue.meta.value[index]);
    });
    this.setMethod("символ", (args, context, options) => {
      let index;

      if (Array.isArray(args)) {
        index = args[0];
      } else {
        index = args["позиція"];
      }

      try {
        if (this.mavka.isEmpty(index) || typeof index === "undefined") {
          this.mavka.fall(context, this.mavka.makeText("Очікується, що \"позиція\" не є пусто."));
        }

        index = index.asNumber(context).asJsValue(context);

        if (index < 0) {
          this.mavka.fall(context, this.mavka.makeText("Очікується, що \"позиція\" є не менше 0."));
        }
      } catch (e) {
        if (e instanceof TypeError) {
          this.mavka.fall(context, this.mavka.makeText("Не вдалось перетворити параметр \"позиція\" у число."));
        } else {
          throw e;
        }
      }

      return this.mavka.toCell(options.meValue.meta.value.charAt(index));
    });
    this.setMethod("код_символу", (args, context, options) => {
      let index;

      if (Array.isArray(args)) {
        index = args[0];
      } else {
        index = args["позиція"];
      }

      try {
        if (this.mavka.isEmpty(index) || typeof index === "undefined") {
          this.mavka.fall(context, this.mavka.makeText("Очікується, що \"позиція\" не є пусто."));
        }

        index = index.asNumber(context).asJsValue(context);

        if (index < 0) {
          this.mavka.fall(context, this.mavka.makeText("Очікується, що \"позиція\" є не менше 0."));
        }
      } catch (e) {
        if (e instanceof TypeError) {
          this.mavka.fall(context, this.mavka.makeText("Не вдалось перетворити параметр \"позиція\" у число."));
        } else {
          throw e;
        }
      }

      return this.mavka.toCell(options.meValue.meta.value.charCodeAt(index));
    });
    this.setMethod("позиція", (args, context, options) => {
      let searchString;

      if (Array.isArray(args)) {
        searchString = args[0];
      } else {
        searchString = args["значення"];
      }

      try {
        if (this.mavka.isEmpty(searchString) || typeof searchString === "undefined") {
          this.mavka.fall(context, this.mavka.makeText("Очікується, що \"значення\" не є пусто."));
        }

        searchString = searchString.asText(context).asJsValue(context);
      } catch (e) {
        if (e instanceof TypeError) {
          this.mavka.fall(context, this.mavka.makeText("Не вдалось перетворити параметр \"значення\" у текст."));
        } else {
          throw e;
        }
      }

      return this.mavka.toCell(options.meValue.meta.value.indexOf(searchString));
    });
    this.setMethod("повторити", (args, context, options) => {
      let count;

      if (Array.isArray(args)) {
        count = args[0];
      } else {
        count = args["кількість"];
      }

      try {
        if (this.mavka.isEmpty(count) || typeof count === "undefined") {
          this.mavka.fall(context, this.mavka.makeText("Очікується, що \"кількість\" не є пусто."));
        }

        count = count.asNumber(context).asJsValue(context);

        if (Number.isNaN(count)) {
          throw new TypeError("Expected `count` to not be NaN");
        }

        if (count < 0) {
          this.mavka.fall(context, this.mavka.makeText("Очікується, що \"кількість\" є не менше 0."));
        }
      } catch (e) {
        if (e instanceof TypeError) {
          this.mavka.fall(context, this.mavka.makeText("Не вдалось перетворити параметр \"кількість\" у число."));
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
      let pattern, replacement;

      if (Array.isArray(args)) {
        pattern = args[0];
        replacement = args[1];
      } else {
        pattern = args["старе_значення"];
        replacement = args["нове_значення"];
      }

      try {
        if (this.mavka.isEmpty(pattern) || typeof pattern === "undefined") {
          this.mavka.fall(context, this.mavka.makeText("Очікується, що \"старе_значення\" не є пусто."));
        }

        pattern = pattern.asText(context).asJsValue(context);
      } catch (e) {
        if (e instanceof TypeError) {
          this.mavka.fall(context, this.mavka.makeText("Не вдалось перетворити параметр \"старе_значення\" у текст."));
        } else {
          throw e;
        }
      }

      try {
        if (this.mavka.isEmpty(replacement) || typeof replacement === "undefined") {
          this.mavka.fall(context, this.mavka.makeText("Очікується, що \"нове_значення\" не є пусто."));
        }

        replacement = replacement.asText(context).asJsValue(context);
      } catch (e) {
        if (e instanceof TypeError) {
          this.mavka.fall(context, this.mavka.makeText("Не вдалось перетворити параметр \"нове_значення\" у текст."));
        } else {
          throw e;
        }
      }

      return this.mavka.toCell(options.meValue.meta.value.replace(pattern, replacement));
    });
    this.setMethod("замінити", (args, context, options) => {
      let pattern, replacement;

      if (Array.isArray(args)) {
        pattern = args[0];
        replacement = args[1];
      } else {
        pattern = args["старе_значення"];
        replacement = args["нове_значення"];
      }

      try {
        if (this.mavka.isEmpty(pattern) || typeof pattern === "undefined") {
          this.mavka.fall(context, this.mavka.makeText("Очікується, що \"старе_значення\" не є пусто."));
        }

        pattern = pattern.asText(context).asJsValue(context);
      } catch (e) {
        if (e instanceof TypeError) {
          this.mavka.fall(context, this.mavka.makeText("Не вдалось перетворити параметр \"старе_значення\" у текст."));
        } else {
          throw e;
        }
      }

      try {
        if (this.mavka.isEmpty(replacement) || typeof replacement === "undefined") {
          this.mavka.fall(context, this.mavka.makeText("Очікується, що \"нове_значення\" не є пусто."));
        }

        replacement = replacement.asText(context).asJsValue(context);
      } catch (e) {
        if (e instanceof TypeError) {
          this.mavka.fall(context, this.mavka.makeText("Не вдалось перетворити параметр \"нове_значення\" у текст."));
        } else {
          throw e;
        }
      }

      return this.mavka.toCell(options.meValue.meta.value.replaceAll(pattern, replacement));
    });
    this.setMethod("зрізати", (args, context, options) => {
      let indexStart, indexEnd;

      if (Array.isArray(args)) {
        indexStart = args[0];
        indexEnd = args[1];
      } else {
        indexStart = args["позиція_від"];
        indexEnd = args["позиція_до"];
      }

      try {
        if (this.mavka.isEmpty(indexStart) || typeof indexStart === "undefined") {
          this.mavka.fall(context, this.mavka.makeText("Очікується, що \"позиція_від\" не є пусто."));
        }

        indexStart = indexStart.asNumber(context).asJsValue(context);

        if (indexStart < 0) {
          this.mavka.fall(context, this.mavka.makeText("Очікується, що \"позиція_від\" є не менше 0."));
        }

        if (Number.isNaN(indexStart)) {
          throw new TypeError("Expected `indexStart` to not be NaN");
        }
      } catch (e) {
        if (e instanceof TypeError) {
          this.mavka.fall(context, this.mavka.makeText("Не вдалось перетворити параметр \"позиція_від\" у число."));
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
            this.mavka.fall(context, this.mavka.makeText(`Очікується, що "позиція_до" є не менше від "позиція_від" (${indexStart}).`));
          }
        } else {
          indexEnd = undefined;
        }
      } catch (e) {
        if (e instanceof TypeError) {
          this.mavka.fall(context, this.mavka.makeText("Не вдалось перетворити параметр \"позиція_до\" у число."));
        } else {
          throw e;
        }
      }

      return this.mavka.toCell(options.meValue.meta.value.substring(indexStart, indexEnd));
    });
    this.setMethod("приєднати", (args, context, options) => {
      args = Object.values(args);

      if (args.length === 0) {
        return options.meValue;
      }
      try {
        args = args.map(v => v.asText(context).asJsValue(context));
      } catch (e) {
        if (e instanceof TypeError) {
          this.mavka.fall(context, this.mavka.makeText("Не вдалось перетворити деякі параметри \"інші_тексти\" у текст."));
        } else {
          throw e;
        }
      }

      return this.mavka.toCell(options.meValue.meta.value.concat(...args));
    });
    this.setMethod("розділити", (args, context, options) => {
      let separator;

      if (Array.isArray(args)) {
        separator = args[0];
      } else {
        separator = args["роздільник"];
      }

      try {
        separator = separator.asText(context).asJsValue(context);
      } catch (e) {
        if (e instanceof TypeError) {
          this.mavka.fall(context, this.mavka.makeText("Не вдалось перетворити параметр \"роздільник\" у текст."));
        } else {
          throw e;
        }
      }

      return this.mavka.makeList(
        options.meValue.meta.value.split(separator).map(v =>
          this.mavka.makeText(v)));
    });
    this.setMethod("починається_з", (args, context, options) => {
      let searchString;

      if (Array.isArray(args)) {
        searchString = args[0];
      } else {
        searchString = args["значення"];
      }

      try {
        searchString = searchString.asText(context).asJsValue(context);
      } catch (e) {
        if (e instanceof TypeError) {
          this.mavka.fall(context, this.mavka.makeText("Не вдалось перетворити параметр \"значення\" у текст."));
        } else {
          throw e;
        }
      }

      return this.mavka.toCell(options.meValue.meta.value.startsWith(searchString));
    });
    this.setMethod("закінчується_на", (args, context, options) => {
      let searchString;

      if (Array.isArray(args)) {
        searchString = args[0];
      } else {
        searchString = args["значення"];
      }

      try {
        searchString = searchString.asText(context).asJsValue(context);
      } catch (e) {
        if (e instanceof TypeError) {
          this.mavka.fall(context, this.mavka.makeText("Не вдалось перетворити параметр \"значення\" у текст."));
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
      let searchString = Object.values(args)[0];

      try {
        searchString = searchString.asText(context).asJsValue(context);
      } catch (e) {
        if (e instanceof TypeError) {
          this.mavka.fall(context, this.mavka.makeText("Не вдалось перетворити значення після \"містить\" у текст."));
        } else {
          throw e;
        }
      }

      return this.mavka.toCell(options.meValue.meta.value.includes(searchString));
    });
    this.setMethod("виконати_порівняння_чи_не_містить", (args, context, options) => {
      let searchString = Object.values(args)[0];

      try {
        searchString = searchString.asText(context).asJsValue(context);
      } catch (e) {
        if (e instanceof TypeError) {
          this.mavka.fall(context, this.mavka.makeText("Не вдалось перетворити значення після \"містить\" у текст."));
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
