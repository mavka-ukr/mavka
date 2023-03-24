class Method {
  /**
   * @param {string} name
   * @param {{ name: string, defaultValue: Cell|null }[]} parameters
   * @param {function|ASTNode[]} body
   * @param {boolean} isAsync
   * @param {Context|null} outerContext
   */
  constructor(name,
              parameters,
              body,
              isAsync,
              outerContext) {
    this.name = name;
    this.parameters = parameters;
    this.body = body;
    this.isAsync = isAsync;
    this.outerContext = outerContext;
  }
}

export default Method;
