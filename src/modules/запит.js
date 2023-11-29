await ((async function() {
  var $запит = mavka_module("запит");
  var $Відповідь = mavka_structure("Відповідь", null, {
    "код": mavka_param(0, "код", $число),
    "заголовки": mavka_param(1, "заголовки", $словник),
    "тіло": mavka_param(2, "тіло", $байти)
  });
  var $надіслати = mavka_diia(
    "надіслати",
    {
      "метод": mavka_param(0, "метод", $текст, "GET"),
      "урл": mavka_param(1, "урл", $текст, ""),
      "заголовки": mavka_param(2, "заголовки", $словник, new Map()),
      "тіло": mavka_param(3, "тіло", [$байти, $текст], "")
    },
    async function(args, di, { arg }) {
      var method = arg("метод").toUpperCase();
      var url = arg("урл");
      var headers = arg("заголовки");
      var body = arg("тіло");

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
        $Відповідь,
        [
          response.status,
          headersDictionary,
          bytes
        ],
        di
      );
    }
  );
  $запит.__m_props__["Відповідь"] = $Відповідь;
  $запит.__m_props__["надіслати"] = $надіслати;
  return $запит;
})());
