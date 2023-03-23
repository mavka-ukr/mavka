export const makePrintDiiaCell = (mavka) => mavka.tools.fn((args, context) => console.log(
  ...args
    .map((arg) => {
      return arg.asText(context).asJsValue(context);
    })
), {
  jsArgs: false
});

export const makeReadDiiaCell = (mavka) => mavka.tools.fn((args, context) => new mavka.TextCell(
  mavka,
  mavka.external.promptSync({ sigint: true })(mavka.toCell(args[0]).asText(context).asJsValue())
));
