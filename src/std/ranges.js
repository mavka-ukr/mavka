import { RangeDiiaCell } from "../interpreter/cells/utils/stdCells.js";

export const makeRangeDiiaCell = (mavka) => new RangeDiiaCell(mavka, mavka.context);
