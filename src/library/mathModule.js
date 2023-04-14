const makeMathModule = (mavka) => {
  return mavka.makeModule("М", {
    "Е": mavka.makeNumber(Math.E),
    "ЛОГ10": mavka.makeNumber(Math.LN10),
    "ЛОГ2": mavka.makeNumber(Math.LN2),
    "ЛОГ2Е": mavka.makeNumber(Math.LOG2E),
    "ЛОГ10Е": mavka.makeNumber(Math.LOG10E),
    "ПІ": mavka.makeNumber(Math.PI),
    "КОРІНЬ1_2": mavka.makeNumber(Math.SQRT1_2),
    "КОРІНЬ2": mavka.makeNumber(Math.SQRT2),

    "абс": mavka.makeProxyFunction((args, context, { arg }) => mavka.makeNumber(
      Math.abs(arg(0, "значення").asJsValue(context)))
    ),
    "арккос": mavka.makeProxyFunction((args, context, { arg }) => mavka.makeNumber(
      Math.acos(arg(0, "значення").asJsValue(context)))
    ),
    "арксин": mavka.makeProxyFunction((args, context, { arg }) => mavka.makeNumber(
      Math.asin(arg(0, "значення").asJsValue(context)))
    ),
    "арктан": mavka.makeProxyFunction((args, context, { arg }) => mavka.makeNumber(
      Math.atan(arg(0, "значення").asJsValue(context)))
    ),
    "арктан2": mavka.makeProxyFunction((args, context, { arg }) => mavka.makeNumber(
      Math.atan2(arg(0, "х").asJsValue(context), arg(0, "y").asJsValue(context)))
    ),
    "стеля": mavka.makeProxyFunction((args, context, { arg }) => mavka.makeNumber(
      Math.ceil(arg(0, "значення").asJsValue(context)))
    ),
    "кос": mavka.makeProxyFunction((args, context, { arg }) => mavka.makeNumber(
      Math.cos(arg(0, "значення").asJsValue(context)))
    ),
    "експ": mavka.makeProxyFunction((args, context, { arg }) => mavka.makeNumber(
      Math.exp(arg(0, "значення").asJsValue(context)))
    ),
    "підлога": mavka.makeProxyFunction((args, context, { arg }) => mavka.makeNumber(
      Math.floor(arg(0, "значення").asJsValue(context)))
    ),
    "найбільше": mavka.makeProxyFunction((args, context) => mavka.makeNumber(
      Math.max(...Object.values(args).map((arg) => arg.asJsValue(context))))
    ),
    "найменше": mavka.makeProxyFunction((args, context) => mavka.makeNumber(
      Math.max(...Object.values(args).map((arg) => arg.asJsValue(context))))
    ),
    "степінь": mavka.makeProxyFunction((args, context, { arg }) => mavka.makeNumber(
      Math.pow(arg(0, "а").asJsValue(context), arg(1, "б").asJsValue(context)))
    ),
    "округлити": mavka.makeProxyFunction((args, context, { arg }) => mavka.makeNumber(
      Math.round(arg(0, "значення").asJsValue(context)))
    ),
    "син": mavka.makeProxyFunction((args, context, { arg }) => mavka.makeNumber(
      Math.sin(arg(0, "значення").asJsValue(context)))
    ),
    "корінь": mavka.makeProxyFunction((args, context, { arg }) => mavka.makeNumber(
      Math.sqrt(arg(0, "значення").asJsValue(context)))
    ),
    "тан": mavka.makeProxyFunction((args, context, { arg }) => mavka.makeNumber(
      Math.tan(arg(0, "значення").asJsValue(context)))
    )
  });
};

export default makeMathModule;
