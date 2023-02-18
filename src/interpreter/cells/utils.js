export function makeAsyncFn(mavka, context, fn) {
  return new mavka.JsFunctionCell(mavka, (args, context) => {
    args = args.map((arg) => {
      return mavka.toCell(arg).asJsValue();
    });

    return new mavka.AsyncCell(mavka, async () => {
      const result = await fn(args, context);

      return mavka.toCell(result);
    });
  });
}

export function makeFn(mavka, context, fn) {
  return new mavka.JsFunctionCell(mavka, (args, context) => {
    args = args.map((arg) => {
      return mavka.toCell(arg).asJsValue();
    });

    const result = fn(args, context);

    return mavka.toCell(result);
  });
}
