class Instruction {
  constructor(mavka) {
    this.mavka = mavka;
  }

  /**
   * @param {Context} context
   * @param {ASTNode} node
   */
  runSync(context, node) {
  }

  /**
   * @param {Context} context
   * @param {ASTNode} node
   */
  async runAsync(context, node) {
  }

  run(context, node) {
    return context.isAsync() ?
      this.runAsync(context, node) :
      this.runSync(context, node);
  }
}

export default Instruction;
