/**
 * Cell represents a value in Mavka.
 */
export class Cell {
  /**
   * @param {Mavka} mavka
   * @param {string} name
   * @param {Object} properties
   * @param {Object} methods
   * @param {Cell|null} parent
   * @param {StructureCell} structure
   */
  constructor(mavka,
              name = "<>",
              properties = {},
              methods = {},
              parent = null, // structure's parent (mb will be multiple inheritance in the future)
              structure = null) {
    this.mavka = mavka;

    this.name = name;
    this.properties = properties;
    this.methods = methods;

    this.parent = parent;
    this.structure = structure;
  }

  /**
   * @param {Context} context
   * @param {string} name
   * @returns {Cell}
   */
  get(context, name) {
    if (name === "__структура__") {
      return this.structure || this.mavka.emptyCellInstance;
    }

    if (name === "__батько__") {
      return this.parent || this.mavka.emptyCellInstance;
    }

    if (name in this.properties) {
      return this.properties[name];
    }

    if (name in this.methods) {
      return this.methods[name];
    }

    if (this.parent) {
      return this.parent.get(name);
    }

    if (this.structure) {
      if (name in this.structure.methods) {
        return this.structure.methods[name];
      }
    }

    if (name !== "виконати_отримання") {
      const getDiiaResult = this.doAction(context, "виконати_отримання", [this.mavka.toCell(name)]);
      if (getDiiaResult) {
        return getDiiaResult;
      }
    }

    return this.mavka.emptyCellInstance;
  }

  /**
   * @param {Context} context
   * @param {string} name
   * @param {Cell} value
   */
  set(context, name, value) {
    if (name !== "виконати_присвоєння") {
      const setDiiaResult = this.doAction(context, "виконати_присвоєння", [this.mavka.toCell(name), value]);
      if (setDiiaResult) {
        return setDiiaResult;
      }
    }

    this.properties[name] = this.mavka.toCell(value);
  }

  /**
   * @param {Context} context
   * @param {string} name
   */
  delete(context, name) {
    if (name !== "виконати_видалення") {
      const deleteDiiaResult = this.doAction(context, "виконати_видалення", [this.mavka.toCell(name)]);
      if (deleteDiiaResult) {
        return deleteDiiaResult;
      }
    }

    delete this.properties[name];
  }

  /**
   * @param {Context} context
   * @param {Record<string, Cell>|Cell[]} args
   * @param {Object} options
   * @return {Cell}
   */
  doCall(context, args, options = {}) {
    const callDiiaResult = this.doAction(context, "виконати_виклик", args);
    if (callDiiaResult) {
      return callDiiaResult;
    }

    throw "Не реалізовано.";
  }

  /**
   * @param {Context} context
   * @param {Cell} name
   * @return {Cell}
   */
  doGetElement(context, name) {
    const getElementDiiaResult = this.doAction(context, "виконати_отримання_елемента", [name]);
    if (getElementDiiaResult) {
      return getElementDiiaResult;
    }

    throw "Не реалізовано.";
  }

  /**
   * @param {Context} context
   * @param {Cell} name
   * @param {Cell} value
   * @return {Cell}
   */
  doSetElement(context, name, value) {
    const setElementDiiaResult = this.doAction(context, "виконати_присвоєння_елемента", [name, value]);
    if (setElementDiiaResult) {
      return setElementDiiaResult;
    }

    throw "Не реалізовано.";
  }

  /**
   * @param {Context} context
   * @param {Cell} value
   * @return {Cell}
   */
  doAdd(context, value) {
    const addDiiaResult = this.doAction(context, "виконати_додавання", [value]);
    if (addDiiaResult) {
      return addDiiaResult;
    }

    throw "Не реалізовано.";
  }

  /**
   * @param {Context} context
   * @param {Cell} value
   * @return {Cell}
   */
  doSub(context, value) {
    const subDiiaResult = this.doAction(context, "виконати_віднімання", [value]);
    if (subDiiaResult) {
      return subDiiaResult;
    }

    throw "Не реалізовано.";
  }

  /**
   * @param {Context} context
   * @param {Cell} value
   * @return {Cell}
   */
  doMul(context, value) {
    const mulDiiaResult = this.doAction(context, "виконати_множення", [value]);
    if (mulDiiaResult) {
      return mulDiiaResult;
    }

    throw "Не реалізовано.";
  }

  /**
   * @param {Context} context
   * @param {Cell} value
   * @return {Cell}
   */
  doDiv(context, value) {
    const divDiiaResult = this.doAction(context, "виконати_ділення", [value]);
    if (divDiiaResult) {
      return divDiiaResult;
    }

    throw "Не реалізовано.";
  }

  /**
   * @param {Context} context
   * @param {Cell} value
   * @return {Cell}
   */
  doDivMod(context, value) {
    const divModDiiaResult = this.doAction(context, "виконати_ділення_за_модулем_остача", [value]);
    if (divModDiiaResult) {
      return divModDiiaResult;
    }

    throw "Не реалізовано.";
  }

  /**
   * @param {Context} context
   * @param {Cell} value
   * @return {Cell}
   */
  doDivFloor(context, value) {
    const divFloorDiiaResult = this.doAction(context, "виконати_ділення_за_модулем_частка", [value]);
    if (divFloorDiiaResult) {
      return divFloorDiiaResult;
    }

    throw "Не реалізовано.";
  }

  /**
   * @param {Context} context
   * @param {Cell} value
   * @return {Cell}
   */
  doPow(context, value) {
    const powDiiaResult = this.doAction(context, "виконати_піднесення_до_степеня", [value]);
    if (powDiiaResult) {
      return powDiiaResult;
    }

    throw "Не реалізовано.";
  }

  /**
   * @param {Context} context
   * @param {Cell} value
   * @return {Cell}
   */
  doXor(context, value) {
    const xorDiiaResult = this.doAction(context, "виконати_виняткову_дизʼюнкцію", [value]);
    if (xorDiiaResult) {
      return xorDiiaResult;
    }

    throw "Не реалізовано.";
  }

  /**
   * @param {Context} context
   * @param {Cell} value
   * @return {Cell}
   */
  doCompareEquals(context, value) {
    const eqDiiaResult = this.doAction(context, "виконати_порівняння_чи_рівно", [value]);
    if (eqDiiaResult) {
      return eqDiiaResult;
    }

    throw "Не реалізовано.";
  }

  /**
   * @param {Context} context
   * @param {Cell} value
   * @return {Cell}
   */
  doCompareNotEquals(context, value) {
    const notEqDiiaResult = this.doAction(context, "виконати_порівняння_чи_не_рівно", [value]);
    if (notEqDiiaResult) {
      return notEqDiiaResult;
    }

    throw "Не реалізовано.";
  }

  /**
   * @param {Context} context
   * @param {Cell} value
   * @return {Cell}
   */
  doCompareLesserThan(context, value) {
    const ltDiiaResult = this.doAction(context, "виконати_порівняння_чи_менше", [value]);
    if (ltDiiaResult) {
      return ltDiiaResult;
    }

    throw "Не реалізовано.";
  }

  /**
   * @param {Context} context
   * @param {Cell} value
   * @return {Cell}
   */
  doCompareGreaterThanOrEquals(context, value) {
    const gteDiiaResult = this.doAction(context, "виконати_порівняння_чи_не_менше", [value]);
    if (gteDiiaResult) {
      return gteDiiaResult;
    }

    throw "Не реалізовано.";
  }

  /**
   * @param {Context} context
   * @param {Cell} value
   * @return {Cell}
   */
  doCompareGreaterThan(context, value) {
    const gtDiiaResult = this.doAction(context, "виконати_порівняння_чи_більше", [value]);
    if (gtDiiaResult) {
      return gtDiiaResult;
    }

    throw "Не реалізовано.";
  }

  /**
   * @param {Context} context
   * @param {Cell} value
   * @return {Cell}
   */
  doCompareLesserThanOrEquals(context, value) {
    const lteDiiaResult = this.doAction(context, "виконати_порівняння_чи_не_більше", [value]);
    if (lteDiiaResult) {
      return lteDiiaResult;
    }

    throw "Не реалізовано.";
  }

  /**
   * @param {Context} context
   * @param {Cell} value
   * @return {BooleanCell}
   */
  isInstanceOf(context, value) {
    return this.mavka.toCell(
      this.structure
        ? this.structure === value || this.isInstanceOfThroughStructure(context, this.structure, value)
        : false
    );
  }

  /**
   * @param {Context} context
   * @param {StructureCell} structure
   * @param {Cell} value
   */
  isInstanceOfThroughStructure(context, structure, value) {
    return structure.parent
      ? structure.parent === value || structure.parent.isInstanceOfThroughStructure(context, structure.parent, value)
      : false;
  }

  /**
   * @param {Context} context
   * @return {TextCell}
   */
  asText(context) {
    const asTextDiiaResult = this.doAction(context, "виконати_перетворення_на_текст");
    if (asTextDiiaResult) {
      return asTextDiiaResult;
    }

    return this.mavka.toCell(this.name);
  }

  /**
   * @param {Context} context
   * @return {NumberCell}
   */
  asNumber(context) {
    const asNumberDiiaResult = this.doAction(context, "виконати_перетворення_на_число");
    if (asNumberDiiaResult) {
      return asNumberDiiaResult;
    }

    throw "Не реалізовано.";
  }

  /**
   * @param {Context} context
   * @return {BooleanCell}
   */
  asBoolean(context) {
    const asBooleanDiiaResult = this.doAction(context, "виконати_перетворення_на_логічне");
    if (asBooleanDiiaResult) {
      return asBooleanDiiaResult;
    }

    return this.mavka.toCell(true);
  }

  /**
   * @param {Context} context
   * @return {*}
   */
  asJsValue(context) {
    return null;
  }

  /**
   * @param {Cell} value
   * @param {function} fn
   * @return {BooleanCell}
   * @deprecated
   */
  compare(value, fn) {
    if (value instanceof Cell) {
      return this.mavka.toCell(fn(this, value));
    }

    return this.mavka.falseCellInstance;
  }

  [Symbol.iterator]() {
    return {
      next() {
        return { done: true };
      }
    };
  }

  /**
   * @param {Context} context
   * @param {string} name
   * @param {Record<string, Cell>|Cell[]} args
   * @return {Cell|undefined}
   */
  doAction(context, name, args = []) {
    const actionDiia = this.get(context, name);

    if (this.mavka.isEmpty(actionDiia)) {
      return undefined;
    }

    return actionDiia.doCall(context, args, {
      meValue: this
    });
  }
}

