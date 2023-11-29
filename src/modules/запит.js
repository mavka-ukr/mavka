await ((async function() {
  var $запит = mavka_module("запит");
  var $Відповідь = mavka_structure("Відповідь", null, {
    "код": mavka_param(0, "код", $число, 200),
    "заголовки": mavka_param(1, "заголовки", $словник, mavka_dictionary()),
    "тіло": mavka_param(2, "тіло", $текст, "")
  });
  var $надіслати = mavka_diia(
    "надіслати",
    {
      "метод": mavka_param(0, "метод", $текст),
      "урл": mavka_param(1, "урл", $текст),
      "заголовки": mavka_param(2, "заголовки", $словник, mavka_dictionary()),
      "тіло": mavka_param(3, "тіло", [$текст, $словник, null], null)
    },
    async function(args, di, { arg }) {
      var method = arg("метод");
      var url = arg("урл");
      var headers = arg("заголовки");
      var body = arg("тіло");

      const response = await fetch(url, {
        method,
        headers: mavka_dictionary_to_js_object(headers),
        body
      });
      const text = await response.text();

      const headersDictionary = mavka_dictionary();
      for (const [hk, vv] of response.headers.entries()) {
        mavka_set(headersDictionary, hk, vv, di);
      }

      return mavka_call(
        $Відповідь,
        [
          response.status,
          headersDictionary,
          text
        ],
        di
      );
    }
  );
  $запит.__m_props__["Відповідь"] = $Відповідь;
  $запит.__m_props__["надіслати"] = $надіслати;
  return $запит;
})());
