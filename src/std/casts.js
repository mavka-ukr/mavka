export const makeToNumberDiiaCell = (mavka) => new mavka.JsFunctionCell(
  mavka,
  (args) => mavka.toCell(args[0]).asNumber()
);
