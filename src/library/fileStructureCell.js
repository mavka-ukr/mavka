import StructureCell from "../interpreter/cells/common/structureCell.js";

class FileStructureCell extends StructureCell {
  static instance = null;

  /**
   * @param {Mavka} mavka
   */
  constructor(mavka) {
    super(mavka, "Файл");
  }

  static getInstance(mavka) {
    if (!FileStructureCell.instance) {
      FileStructureCell.instance = new FileStructureCell(mavka);
    }
    return FileStructureCell.instance;
  }
}

export default FileStructureCell;
