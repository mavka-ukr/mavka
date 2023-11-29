await ((async function() {
  var { default: http } = await import("http");
  var $сервер = mavka_module("сервер");
  var $Запит = mavka_structure("Запит", null, {
    "метод": mavka_param(0, "метод", $текст),
    "шлях": mavka_param(1, "шлях", $текст),
    "заголовки": mavka_param(2, "заголовки", $словник),
    "дані": mavka_param(3, "дані", $байти)
  });
  var $Відповідь = mavka_structure("Відповідь", null, {
    "код": mavka_param(0, "код", $число, 200),
    "заголовки": mavka_param(1, "заголовки", $словник, new Map()),
    "дані": mavka_param(2, "дані", [$байти, $текст], "")
  });
  var $Опції = mavka_structure("Опції", null, {
    "порт": mavka_param(0, "порт", $число, 80)
  });
  var $запустити = mavka_diia(
    "запустити",
    {
      "обробник": mavka_param(0, "обробник", $Дія),
      "опції": mavka_param(1, "опції", $Опції, mavka_call($Опції)),
      "зворот": mavka_param(2, "зворот", [$Дія, null], null)
    },
    function(args, di, { arg }) {
      var handler = arg("обробник");
      var options = arg("опції");
      var callback = arg("зворот");
      var port = mavka_get(options, "порт", di);

      var server = http.createServer(async (req, res) => {
        var headers = new Map();
        for (var header in req.headers) {
          headers.set(header, req.headers[header]);
        }
        var zapyt = mavka_call(
          $Запит,
          [
            req.method,
            decodeURI(req.url),
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
          } else if (mavka_compare_is(result, $байти, di)) {
            body = result;
          } else if (mavka_compare_is(result, $Відповідь, di)) {
            res.statusCode = result.__m_props__["код"];
            for (var [hk, vv] of result.__m_props__["заголовки"].entries()) {
              res.setHeader(hk, vv);
            }
            body = result.__m_props__["дані"];
          } else {
            throw new MavkaError("Обробник повинен повертати байти, текст або Відповідь.", di);
          }
          var contentType = res.getHeader("content-type");
          if (!contentType) {
            if (body instanceof Uint8Array) {
              contentType = "application/octet-stream";
            } else {
              contentType = "text/plain; charset=utf-8";
            }
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
  $сервер.__m_props__["Опції"] = $Опції;
  $сервер.__m_props__["запустити"] = $запустити;
  return $сервер;
})());
