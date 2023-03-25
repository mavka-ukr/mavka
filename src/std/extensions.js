export const makeLoadExtensionFromFileDiiaCell = (mavka) => mavka.makeProxyFunction((args, context) => {
  const path = mavka.toCell(args[0]).asText(context).asJsValue(context);
  const moduleDirname = context.get("__шлях_до_папки_модуля__").asJsValue(context);

  mavka.global.getContext = () => context;

  const loadExtensionAsyncCell = new mavka.AsyncCell(mavka, async () => {
    return mavka.toCell(await import(`${moduleDirname}/${path}`));
  });

  return new mavka.AwaitCell(mavka, loadExtensionAsyncCell);
});

let extId = 0;

export const makeLoadExtensionFromNetworkDiiaCell = (mavka) => mavka.makeProxyFunction((args, context) => {
  const url = mavka.toCell(args[0]).asText(context).asJsValue(context);

  mavka.global.getContext = () => context;

  const loadExtensionAsyncCell = new mavka.AsyncCell(mavka, async () => {
    const body = await (await fetch(url)).text();

    extId++;

    const wrappedCode = `
mavka.global.EXTENSION_EVAL_ASYNC_${extId} = async () => {
  ${body}
}
      `;

    eval(wrappedCode);

    const result = await mavka.global[`EXTENSION_EVAL_ASYNC_${extId}`]();
    delete mavka.global[`EXTENSION_EVAL_ASYNC_${extId}`];

    return mavka.toCell(result);
  });

  return new mavka.AwaitCell(mavka, loadExtensionAsyncCell);
});


export const makeLoadExtensionDiiaCell = (mavka) => mavka.makeProxyFunction((args, context) => {
  const code = mavka.toCell(args[0]).asText(context).asJsValue(context);

  mavka.global.getContext = () => context;

  const loadExtensionAsyncCell = new mavka.AsyncCell(mavka, async () => {
    extId++;

    const wrappedCode = `
mavka.global.EXTENSION_EVAL_ASYNC_${extId} = async () => {
  ${code}
}
      `;

    eval(wrappedCode);

    const result = await mavka.global[`EXTENSION_EVAL_ASYNC_${extId}`]();
    delete mavka.global[`EXTENSION_EVAL_ASYNC_${extId}`];

    return mavka.toCell(result);
  });

  return new mavka.AwaitCell(mavka, loadExtensionAsyncCell);
});
