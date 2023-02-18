export const makePrintDiiaCell = (mavka) => new mavka.JsFunctionCell(mavka, (args) => console.log(
  ...args
    .map((arg) => mavka.toCell(arg).asString().asJsString())
));

export const makeReadDiiaCell = (mavka) => new mavka.JsFunctionCell(
  mavka,
  (args) => new mavka.StringCell(
    mavka,
    mavka.external.promptSync({ sigint: true })(mavka.toCell(args[0]).asString().asJsString())
  )
);
