import {
  DictionaryNode,
  EmptyNode,
  ListNode,
  LogicalNode,
  NumberNode,
  ObjectNode,
  parse as parseDid,
  ParserError,
  TextNode
} from "mavka-did";

const makeDidModule = (mavka) => {
  return mavka.makeModule("Дід", {
    "розібрати": mavka.makeProxyFunction((args, context, { arg }) => {
      let text = arg(0, "значення");
      if (!mavka.isText(text)) {
        mavka.fall(context, mavka.makeText("Першим параметром має бути текст"));
      }
      text = text.asJsValue(context);

      let ast;

      try {
        ast = parseDid(text);
      } catch (e) {
        if (e && e instanceof ParserError) {
          mavka.fall(context, mavka.makeText(e.message));
        } else {
          throw e;
        }
      }

      const makeCell = (node) => {
        if (node instanceof NumberNode) {
          return mavka.makeNumber(node.value);
        }

        if (node instanceof TextNode) {
          return mavka.makeText(node.value);
        }

        if (node instanceof EmptyNode) {
          return mavka.empty;
        }

        if (node instanceof LogicalNode) {
          return node.value ? mavka.yes : mavka.no;
        }

        if (node instanceof ListNode) {
          return mavka.makeList(node.contents.map(makeCell));
        }

        if (node instanceof DictionaryNode) {
          const map = new Map();
          for (const entry of node.contents) {
            map.set(makeCell(entry.key), makeCell(entry.value));
          }
          return mavka.makeDictionary(map);
        }

        if (node instanceof ObjectNode) {
          // todo: handle object as actual object not dictionary
          const map = new Map();
          for (const entry of node.contents) {
            map.set(makeCell(entry.key), makeCell(entry.value));
          }
          return mavka.makeDictionary(map);
        }

        return mavka.empty;
      };

      return makeCell(ast);
    }),
    "зібрати": mavka.makeProxyFunction((args, context, { arg }) => {
      let value = arg(0, "значення");

      const makeDidValue = (value) => {
        if (mavka.isNumber(value)) {
          return `${value.asText(context).asJsValue(context)}`;
        }

        if (mavka.isText(value)) {
          return `"${value.asJsValue(context)}"`;
        }

        if (mavka.isEmpty(value)) {
          return "пусто";
        }

        if (mavka.isBoolean(value)) {
          return value.asJsValue(context) ? "так" : "ні";
        }

        if (mavka.isList(value)) {
          return `[${value.meta.values.map(makeDidValue).join(",")}]`;
        }

        if (mavka.isDictionary(value)) {
          const values = [];
          for (const [k, v] of value.meta.items.entries()) {
            const kk = makeDidValue(mavka.toCell(k));
            const vv = makeDidValue(v);

            values.push(`${kk}=${vv}`);
          }
          return `(${values.join(",")})`;
        }

        if (value instanceof ObjectNode) {
          const values = [];
          for (const [k, v] of value.meta.contents.entries()) {
            const kk = makeDidValue(mavka.toCell(k));
            const vv = makeDidValue(v);

            values.push(`${kk}=${vv}`);
          }
          return `(${values.join(",")})`;
        }

        return "пусто";
      };

      return mavka.makeText(makeDidValue(value));
    })
  });
};

export default makeDidModule;
