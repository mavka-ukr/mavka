import { RangeDiiaCell } from "../interpreter/cells/stdCells.js";

export const makeRangeDiiaCell = (mavka) => new RangeDiiaCell(mavka, mavka.context);
