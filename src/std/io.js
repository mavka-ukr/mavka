export const makePrintDiiaCell = (mavka) => mavka.tools.fn((args, context) => console.log(
  ...args
    .map((arg) => {
      const cell = mavka.toCell(arg);
      return cell.asText(context).asJsValue(context);
    })
));

export const makeReadDiiaCell = (mavka) => mavka.tools.fn((args, context) => new mavka.TextCell(
  mavka,
  mavka.external.promptSync({ sigint: true })(mavka.toCell(args[0]).asText(context).asJsString())
));
