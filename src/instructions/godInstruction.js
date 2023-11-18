import Instruction from "./instruction.js";

class GodInstruction extends Instruction {
  /**
   * @param {Scope} scope
   * @param {GodNode} node
   * @returns {*}
   */
  async compile(scope, node) {
    const debugInfoVarName = this.mavka.putDebugInfoVarName(node);
    const elements = await Promise.all(node.elements.map((element) => this.mavka.compileNode(scope, element)));

    return `((function() {
  const elements = [${elements.join(",")}];
  const newElements = [];
  const newNewElements = [];
  for (let i = 0; i < elements.length; i++) {
    if (elements[i].__m_type__ === "god") {
      newElements.push(...elements[i].__m_elements__);
    } else {
      newElements.push(elements[i]);
    }
  }
  for (let i = 0; i < newElements.length; i++) {
    if (newNewElements.find((e) => {
      if (e && e.__m_type__ === newElements[i].__m_type__) {
        return true;
      }
      if (typeof e === "boolean" && typeof newElements[i] === "boolean") {
        return true;
      }
      if (typeof e === "string" && typeof newElements[i] === "string") {
        return true;
      }
      if (typeof e === "number" && typeof newElements[i] === "number") {
        return true;
      }
      return e.constructor && newElements[i].constructor && e.constructor === newElements[i].constructor;
    })) {
      throw new MavkaError("Бог не може складатись з обʼєктів одинакових структур.", ${debugInfoVarName});
    }
    newNewElements.push(newElements[i]);
  }
  return {
    __m_type__: "god",
    __m_elements__: newNewElements
  }
})())`.trim();
  }
}

export default GodInstruction;
