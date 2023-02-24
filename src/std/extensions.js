export const makeLoadExtensionFromFileDiiaCell = (mavka) => new mavka.JsFunctionCell(mavka, (args, context) => {
  const path = mavka.toCell(args[0]).asString().asJsValue();
  const moduleDirname = context.get("__module_dirname__");

  global.getContext = () => context;
  global.getMavka = () => mavka;

  return new mavka.WaitCell(mavka, new mavka.AsyncCell(
    mavka,
    () => import(`${moduleDirname}/${path}`)
  ));
});

let extId = 0;

export const makeLoadExtensionFromNetworkDiiaCell = (mavka) => new mavka.JsFunctionCell(mavka, (args, context) => {
  const url = mavka.toCell(args[0]).asString().asJsValue();

  global.getContext = () => context;
  global.getMavka = () => mavka;

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

