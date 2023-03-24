export const makePrintDiiaCell = (mavka) => mavka.makeProxyFunction((args, context) => console.log(
  ...args
    .map((arg) => {
      return arg.asText(context).asJsValue(context);
    })
));

export const makeReadDiiaCell = (mavka) => mavka.makeProxyFunction((args, context) => mavka.makeText(
  mavka.external.promptSync({ sigint: true })(args[0].asText(context).asJsValue())
));
