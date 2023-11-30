await ((async function() {
  var { default: http } = await import("http");
  var м_сервер = mavka_module("сервер");
  var м_Опції = mavka_structure("Опції", null, {
    "хост": mavka_param(0, "хост", м_текст, "localhost"),
    "порт": mavka_param(1, "порт", м_число, 80)
  });
  var м_Сервер = mavka_structure("Сервер", null, {
    "обробник": mavka_param(0, "обробник", м_Дія),
    "опції": mavka_param(1, "опції", м_Опції, mavka_call(м_Опції))
  });
  м_Сервер.__m_methods__["запустити"] = mavka_method(
    м_Сервер,
    "запустити",
    {
      "зворот": mavka_param(0, "зворот", [м_Дія, null], null)
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
            м_Запит,
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
            if (mavka_compare_is(result, м_текст, di)) {
              responseBody = result;
            } else if (mavka_compare_is(result, м_Байти, di)) {
              responseBody = result;
            } else if (mavka_compare_is(result, м_Відповідь, di)) {
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
  var м_Запит = mavka_structure("Запит", null, {
    "метод": mavka_param(0, "метод", м_текст),
    "шлях": mavka_param(1, "шлях", м_текст),
    "заголовки": mavka_param(2, "заголовки", м_словник),
    "дані": mavka_param(3, "дані", м_Байти)
  });
  var м_Відповідь = mavka_structure("Відповідь", null, {
    "код": mavka_param(0, "код", м_число, 200),
    "заголовки": mavka_param(1, "заголовки", м_словник, new Map()),
    "дані": mavka_param(2, "дані", [м_Байти, м_текст], "")
  });
  var м_запустити = mavka_diia(
    "запустити",
    {
      "обробник": mavka_param(0, "обробник", м_Дія),
      "опції": mavka_param(1, "опції", м_Опції, mavka_call(м_Опції)),
      "зворот": mavka_param(2, "зворот", [м_Дія, null], null)
    },
    function(args, di, { arg }) {
      var handler = arg("обробник");
      var options = arg("опції");
      var callback = arg("зворот");
      var server = mavka_call(
        м_Сервер,
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
  м_сервер.__m_props__["Опції"] = м_Опції;
  м_сервер.__m_props__["Сервер"] = м_Сервер;
  м_сервер.__m_props__["Запит"] = м_Запит;
  м_сервер.__m_props__["Відповідь"] = м_Відповідь;
  м_сервер.__m_props__["запустити"] = м_запустити;
  return м_сервер;
})());
