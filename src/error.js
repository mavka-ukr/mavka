export class MavkaCompilationError extends Error {
  constructor(message, di) {
    super(message);
    this.message = message;
    this.di = di;
  }
}
