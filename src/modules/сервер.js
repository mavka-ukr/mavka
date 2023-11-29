await ((async function() {
  var { default: http } = await import("http");
  var $сервер = mavka_module("сервер");
  var $Запит = mavka_structure("Запит", null, {
    "метод": mavka_param(0, "метод", $текст),
    "шлях": mavka_param(1, "шлях", $текст),
    "версія": mavka_param(2, "версія", $текст),
    "заголовки": mavka_param(3, "заголовки", $словник),
    "тіло": mavka_param(4, "тіло")
  });
  var $Відповідь = mavka_structure("Відповідь", null, {
    "код": mavka_param(0, "код", $число, 200),
    "заголовки": mavka_param(1, "заголовки", $словник, mavka_dictionary()),
    "тіло": mavka_param(2, "тіло", $текст, "")
  });
  var $запустити = mavka_diia(
    "запустити",
    {
      "обробник": mavka_param(0, "обробник", $Дія, undefined),
      "опції": mavka_param(1, "опції", $словник, mavka_dictionary()),
      "зворот": mavka_param(2, "зворот", [$Дія, null], null)
    },
    function(args, di, { arg }) {
      var handler = arg("обробник");
      var options = arg("опції");
      var callback = arg("зворот");

      var port = 80;
      if (mavka_compare_contains(options, "порт")) {
        port = mavka_get(options, "порт", di);
        if (mavka_compare_is_not(port, $число, di)) {
          throw new MavkaError("Властивість \"порт\" має бути числом.", di);
        }
      }

      var server = http.createServer(async (req, res) => {
        var headers = mavka_dictionary();
        for (var header in req.headers) {
          mavka_set(headers, header, req.headers[header], di);
        }
        var zapyt = mavka_call(
          $Запит,
          [
            req.method,
            decodeURI(req.url),
            req.httpVersion,
            headers,
            null
          ],
          di
        );

        var result = await mavka_call(handler, [zapyt], di);
        if (result) {
          var body;
          if (mavka_compare_is(result, $текст, di)) {
            body = result;
          } else if (mavka_compare_is(result, $Відповідь, di)) {
            res.statusCode = result.__m_props__["код"];
            for (const [hk, vv] of result.__m_props__["заголовки"].__m_map__.entries()) {
              res.setHeader(hk, vv);
            }
            body = result.__m_props__["тіло"];
          } else {
            throw new MavkaError("Обробник повинен повертати текст або Відповідь.", di);
          }
          var contentType = res.getHeader("content-type");
          if (!contentType) {
            contentType = "text/plain; charset=utf-8";
          } else if (!contentType.includes("charset")) {
            contentType += "; charset=utf-8";
          }
          res.setHeader("content-type", contentType);
          res.end(body);
        } else {
          res.end();
        }
      });

      server.listen(port, function(err) {
        if (err) {
          throw err;
        }
        if (callback) {
          mavka_call(callback, [], di);
        }
      });

      return null;
    }
  );
  $сервер.__m_props__["Запит"] = $Запит;
  $сервер.__m_props__["Відповідь"] = $Відповідь;
  $сервер.__m_props__["запустити"] = $запустити;
  return $сервер;
})());
