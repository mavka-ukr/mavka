export const makeLoadExtensionFromFileDiiaCell = (mavka) => new mavka.JsFunctionCell(mavka, (args, context) => {
  const path = mavka.toCell(args[0]).asString().asJsValue();
  const moduleDirname = context.get("__module_dirname__");

  global.getContext = () => context;
  global.getMavka = () => mavka;

  return new mavka.WaitCell(mavka, new mavka.AsyncCell(
    mavka,
    new Promise((resolve) => {
      (async () => {
        resolve(await import(`${moduleDirname}/${path}`));
      })();
    })
  ));
});

export const makeLoadExtensionFromNetworkDiiaCell = (mavka) => new mavka.JsFunctionCell(mavka, (args, context) => {
  const url = mavka.toCell(args[0]).asString().asJsValue();

  global.getContext = () => context;
  global.getMavka = () => mavka;

  return new mavka.WaitCell(mavka, new mavka.AsyncCell(
    mavka,
    new Promise((resolve) => {
      (async () => {
        const body = await (await fetch(url)).text();
        resolve(eval(body));
      })();
    })
  ));
});

