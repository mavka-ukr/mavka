export const makeLoadExtensionFromFileDiiaCell = (mavka) => new mavka.PortalFunctionCell(mavka, (args, context) => {
  const path = mavka.toCell(args[0]).asText(context).asJsValue(context);
  const moduleDirname = context.get("__шлях_до_папки_модуля__");

  mavka.global.getContext = () => context;

  return new mavka.WaitCell(mavka, new mavka.AsyncCell(
    mavka,
    () => import(`${moduleDirname}/${path}`)
  ));
});

let extId = 0;

export const makeLoadExtensionFromNetworkDiiaCell = (mavka) => new mavka.PortalFunctionCell(mavka, (args, context) => {
  const url = mavka.toCell(args[0]).asText(context).asJsValue(context);

  mavka.global.getContext = () => context;

  return new mavka.WaitCell(mavka, new mavka.AsyncCell(
    mavka,
    async () => {
      const body = await (await fetch(url)).text();

      extId++;

      const wrappedCode = `
global.EXTENSION_EVAL_ASYNC_${extId} = async () => {
  ${body}
}
      `;

      eval(wrappedCode);

      const result = await global[`EXTENSION_EVAL_ASYNC_${extId}`]();
      delete global[`EXTENSION_EVAL_ASYNC_${extId}`];
      return result;
    }
  ));
});


export const makeLoadExtensionDiiaCell = (mavka) => new mavka.PortalFunctionCell(mavka, (args, context) => {
  const code = mavka.toCell(args[0]).asText(context).asJsValue(context);

  mavka.global.getContext = () => context;

  return new mavka.WaitCell(mavka, new mavka.AsyncCell(
    mavka,
    async () => {
      extId++;

      const wrappedCode = `
global.EXTENSION_EVAL_ASYNC_${extId} = async () => {
  ${code}
}
      `;

      eval(wrappedCode);

      const result = await global[`EXTENSION_EVAL_ASYNC_${extId}`]();
      delete global[`EXTENSION_EVAL_ASYNC_${extId}`];
      return result;
    }
  ));
});

