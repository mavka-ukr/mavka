await ((async function() {
  var { default: http } = await import("http");
  var $сервер = mavka_module("сервер");
  var $Опції = mavka_structure("Опції", null, {
    "хост": mavka_param(0, "хост", $текст, "localhost"),
    "порт": mavka_param(1, "порт", $число, 80)
  });
  var $Сервер = mavka_structure("Сервер", null, {
    "обробник": mavka_param(0, "обробник", $Дія),
    "опції": mavka_param(1, "опції", $Опції, mavka_call($Опції))
  });
  $Сервер.__m_methods__["запустити"] = mavka_method(
    $Сервер,
    "запустити",
    {
      "зворот": mavka_param(0, "зворот", [$Дія, null], null)
    },
    function(me, args, di, { arg }) {
      var handler = me.__m_props__["обробник"];
      var options = me.__m_props__["опції"];
      var callback = arg("зворот");
      var host = mavka_get(options, "хост", di);
      var port = mavka_get(options, "порт", di);

      var server = http.createServer((req, res) => {
        var parts = [];

        req.on("data", (chunk) => {
          parts.push(chunk);
        }).on("end", async () => {
          var requestBody = Buffer.concat(parts);
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
              requestBody
            ],
            di
          );

          var result = await mavka_call(handler, [zapyt], di);
          if (result) {
            var responseBody;
            if (mavka_compare_is(result, $текст, di)) {
              responseBody = result;
            } else if (mavka_compare_is(result, $байти, di)) {
              responseBody = result;
            } else if (mavka_compare_is(result, $Відповідь, di)) {
              res.statusCode = result.__m_props__["код"];
              for (var [hk, vv] of result.__m_props__["заголовки"].entries()) {
                res.setHeader(hk, vv);
              }
              responseBody = result.__m_props__["дані"];
            } else {
              throw new MavkaError("Обробник повинен повертати байти, текст або Відповідь.", di);
            }
            var contentType = res.getHeader("content-type");
            if (!contentType) {
              if (responseBody instanceof Uint8Array) {
                contentType = "application/octet-stream";
              } else {
                contentType = "text/plain; charset=utf-8";
              }
            } else if (!contentType.includes("charset")) {
              contentType += "; charset=utf-8";
            }
            res.setHeader("content-type", contentType);
            res.end(responseBody);
          } else {
            res.end();
          }
        });
      });

      server.listen(port, host, function(err) {
        if (err) {
          throw err;
        } else if (callback) {
          mavka_call(callback, [], di);
        }
      });

      return null;
    }
  );
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
      var server = mavka_call(
        $Сервер,
        [
          handler,
          options
        ],
        di
      );
      mavka_call(mavka_get(server, "запустити", di), [callback], di);
      return server;
    }
  );
  $сервер.__m_props__["Опції"] = $Опції;
  $сервер.__m_props__["Сервер"] = $Сервер;
  $сервер.__m_props__["Запит"] = $Запит;
  $сервер.__m_props__["Відповідь"] = $Відповідь;
  $сервер.__m_props__["запустити"] = $запустити;
  return $сервер;
})());
