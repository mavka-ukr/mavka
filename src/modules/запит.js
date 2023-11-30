await ((async function() {
  var м_запит = mavka_module("запит");
  var м_Відповідь = mavka_structure("Відповідь", null, {
    "код": mavka_param(0, "код", м_число),
    "заголовки": mavka_param(1, "заголовки", м_словник),
    "дані": mavka_param(2, "дані", м_Байти)
  });
  var м_надіслати = mavka_diia(
    "надіслати",
    {
      "метод": mavka_param(0, "метод", м_текст, "GET"),
      "урл": mavka_param(1, "урл", м_текст, ""),
      "заголовки": mavka_param(2, "заголовки", м_словник, new Map()),
      "дані": mavka_param(3, "дані", [м_Байти, м_текст], "")
    },
    async function(args, di, { arg }) {
      var method = arg("метод").toUpperCase();
      var url = arg("урл");
      var headers = arg("заголовки");
      var body = arg("дані");

      const response = await fetch(url, {
        method,
        headers: Object.fromEntries(headers.entries()),
        body: method === "GET" || method === "HEAD" ? undefined : body
      });
      const bytes = new Uint8Array(await response.arrayBuffer());

      const headersDictionary = new Map();
      for (const [hk, vv] of response.headers.entries()) {
        mavka_set(headersDictionary, hk, vv, di);
      }

      return mavka_call(
        м_Відповідь,
        [
          response.status,
          headersDictionary,
          bytes
        ],
        di
      );
    }
  );
  м_запит.__m_props__["Відповідь"] = м_Відповідь;
  м_запит.__m_props__["надіслати"] = м_надіслати;
  return м_запит;
})());
