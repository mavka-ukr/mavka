await ((async function() {
  var { default: fs } = await import("fs");
  var м_фс = mavka_module("фс");
  м_фс.__m_props__["прочитати"] = mavka_diia(
    "прочитати",
    {
      "шлях": mavka_param(0, "шлях", м_текст),
      "тип": mavka_param(1, "тип", м_текст, "байти")
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
  м_фс.__m_props__["записати"] = mavka_diia(
    "записати",
    {
      "шлях": mavka_param(0, "шлях", м_текст),
      "дані": mavka_param(1, "дані", [м_Байти, м_текст])
    },
    async function(args, di, { arg }) {
      var path = arg("шлях");
      var data = arg("дані");

      await fs.promises.writeFile(path, data);

      return null;
    }
  );
  м_фс.__m_props__["дописати"] = mavka_diia(
    "дописати",
    {
      "шлях": mavka_param(0, "шлях", м_текст),
      "дані": mavka_param(1, "дані", [м_Байти, м_текст])
    },
    async function(args, di, { arg }) {
      var path = arg("шлях");
      var data = arg("дані");

      await fs.promises.appendFile(path, data);

      return null;
    }
  );
  м_фс.__m_props__["перейменувати"] = mavka_diia(
    "перейменувати",
    {
      "шлях": mavka_param(0, "шлях", м_текст),
      "новий_шлях": mavka_param(1, "новий_шлях", м_текст)
    },
    async function(args, di, { arg }) {
      var path = arg("шлях");
      var newPath = arg("новий_шлях");

      await fs.promises.rename(path, newPath);

      return null;
    }
  );
  м_фс.__m_props__["видалити"] = mavka_diia(
    "видалити",
    {
      "шлях": mavka_param(0, "шлях", м_текст)
    },
    async function(args, di, { arg }) {
      var path = arg("шлях");

      await fs.promises.unlink(path);

      return null;
    }
  );
  м_фс.__m_props__["існує"] = mavka_diia(
    "видалити",
    {
      "шлях": mavka_param(0, "шлях", м_текст)
    },
    async function(args, di, { arg }) {
      var path = arg("шлях");

      return fs.existsSync(path);
    }
  );
  м_фс.__m_props__["створити_папку"] = mavka_diia(
    "створити_папку",
    {
      "шлях": mavka_param(0, "шлях", м_текст)
    },
    async function(args, di, { arg }) {
      var path = arg("шлях");

      return await fs.promises.mkdir(path);
    }
  );
  м_фс.__m_props__["створити_папку_рекурсивно"] = mavka_diia(
    "створити_папку_рекурсивно",
    {
      "шлях": mavka_param(0, "шлях", м_текст)
    },
    async function(args, di, { arg }) {
      var path = arg("шлях");

      return await fs.promises.mkdir(path, { recursive: true });
    }
  );
  return м_фс;
})());
