class MockupMethod {
  /**
   * @param {string} name
   * @param {{ name: string, defaultValue: Cell|null }[]} parameters
   */
  constructor(name,
              parameters) {
    this.name = name;
    this.parameters = parameters;
  }
}

export default MockupMethod;
