export const makeGetJsonDiiaCell = (diia, context) => diia.tools.asyncFn(context, async ([url]) => {
  const response = await fetch(url, {
    method: "get",
    headers: {
      "Accept": "application/json"
    }
  });
  const result = await response.json();

  return result;
});
