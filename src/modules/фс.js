await ((async function() {
  var { default: fs } = await import("fs");
  var $фс = mavka_module("фс");
  $фс.__m_props__["прочитати"] = mavka_diia(
    "прочитати",
    {
      "шлях": mavka_param(0, "шлях", $текст),
      "тип": mavka_param(1, "тип", $текст, "байти")
    },
    async function(args, di, { arg }) {
      var path = arg("шлях");
      var type = arg("тип");

      if (type === "байти") {
        return await fs.promises.readFile(path);
      } else if (type === "текст") {
        return await fs.promises.readFile(path, "utf8");
      } else {
        throw new MavkaError(`Невідомий тип даних "${type}".`, di);
      }
    }
  );
  $фс.__m_props__["записати"] = mavka_diia(
    "записати",
    {
      "шлях": mavka_param(0, "шлях", $текст),
      "дані": mavka_param(1, "дані", [$байти, $текст])
    },
    async function(args, di, { arg }) {
      var path = arg("шлях");
      var data = arg("дані");

      await fs.promises.writeFile(path, data);

      return null;
    }
  );
  $фс.__m_props__["дописати"] = mavka_diia(
    "дописати",
    {
      "шлях": mavka_param(0, "шлях", $текст),
      "дані": mavka_param(1, "дані", [$байти, $текст])
    },
    async function(args, di, { arg }) {
      var path = arg("шлях");
      var data = arg("дані");

      await fs.promises.appendFile(path, data);

      return null;
    }
  );
  $фс.__m_props__["перейменувати"] = mavka_diia(
    "перейменувати",
    {
      "шлях": mavka_param(0, "шлях", $текст),
      "новий_шлях": mavka_param(1, "новий_шлях", $текст)
    },
    async function(args, di, { arg }) {
      var path = arg("шлях");
      var newPath = arg("новий_шлях");

      await fs.promises.rename(path, newPath);

      return null;
    }
  );
  $фс.__m_props__["видалити"] = mavka_diia(
    "видалити",
    {
      "шлях": mavka_param(0, "шлях", $текст)
    },
    async function(args, di, { arg }) {
      var path = arg("шлях");

      await fs.promises.unlink(path);

      return null;
    }
  );
  return $фс;
})());
