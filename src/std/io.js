export const makePrintDiiaCell = (mavka) => mavka.makeProxyFunction((args, context) => {
  console.log(
    ...args
      .map((arg) => {
        return arg.asText(context).asJsValue(context);
      })
  );

  return mavka.empty;
});

export const makeReadDiiaCell = (mavka) => mavka.makeProxyFunction((args, context) => {
  const ask = Object.values(args).length ? args[0].asText(context).asJsValue() : undefined;

  return mavka.makeText(mavka.external.promptSync({ sigint: true })(ask));
});
