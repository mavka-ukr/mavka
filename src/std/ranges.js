import { RangeDiiaCell } from "../interpreter/stdCells.js";

export const makeRangeDiiaCell = (mavka) => new RangeDiiaCell(mavka, mavka.context);
