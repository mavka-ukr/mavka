await ((async function() {
  var { default: fs } = await import("fs");
  var фс = mavka_module("фс");
  фс.__m_props__["прочитати"] = mavka_diia(
    "прочитати",
    {
      "шлях": mavka_param(0, м_текст)
    },
    async function(args, di, { arg }) {
      var path = arg("шлях");

      return await fs.promises.readFile(path);

      if (type === "байти") {
      } else if (type === "текст") {
        return await fs.promises.readFile(path, "utf8");
      } else {
        throw new MavkaError(`Невідомий тип даних "${type}".`, di);
      }
    }
  );
  фс.__m_props__["прочитати_текст"] = mavka_diia(
    "прочитати",
    {
      "шлях": mavka_param(0, м_текст),
      "кодування": mavka_param(1, м_текст, "utf8")
    },
    async function(args, di, { arg }) {
      var path = arg("шлях");
      var encoding = arg("кодування");

      return await fs.promises.readFile(path, encoding);
    }
  );
  фс.__m_props__["записати"] = mavka_diia(
    "записати",
    {
      "шлях": mavka_param(0, м_текст),
      "дані": mavka_param(1, [м_байти, м_текст])
    },
    async function(args, di, { arg }) {
      var path = arg("шлях");
      var data = arg("дані");

      await fs.promises.writeFile(path, data);

      return null;
    }
  );
  фс.__m_props__["дописати"] = mavka_diia(
    "дописати",
    {
      "шлях": mavka_param(0, м_текст),
      "дані": mavka_param(1, [м_байти, м_текст])
    },
    async function(args, di, { arg }) {
      var path = arg("шлях");
      var data = arg("дані");

      await fs.promises.appendFile(path, data);

      return null;
    }
  );
  фс.__m_props__["перейменувати"] = mavka_diia(
    "перейменувати",
    {
      "шлях": mavka_param(0, м_текст),
      "новий_шлях": mavka_param(1, м_текст)
    },
    async function(args, di, { arg }) {
      var path = arg("шлях");
      var newPath = arg("новий_шлях");

      await fs.promises.rename(path, newPath);

      return null;
    }
  );
  фс.__m_props__["видалити"] = mavka_diia(
    "видалити",
    {
      "шлях": mavka_param(0, м_текст)
    },
    async function(args, di, { arg }) {
      var path = arg("шлях");

      await fs.promises.unlink(path);

      return null;
    }
  );
  фс.__m_props__["створити_папку"] = mavka_diia(
    "створити_папку",
    {
      "шлях": mavka_param(0, м_текст)
    },
    async function(args, di, { arg }) {
      var path = arg("шлях");

      return await fs.promises.mkdir(path);
    }
  );
  фс.__m_props__["створити_папку_рекурсивно"] = mavka_diia(
    "створити_папку_рекурсивно",
    {
      "шлях": mavka_param(0, м_текст)
    },
    async function(args, di, { arg }) {
      var path = arg("шлях");

      return await fs.promises.mkdir(path, { recursive: true });
    }
  );
  фс.__m_props__["видалити_папку"] = mavka_diia(
    "видалити_папку",
    {
      "шлях": mavka_param(0, м_текст)
    },
    async function(args, di, { arg }) {
      var path = arg("шлях");

      if (fs.existsSync(path)) {
        fs.rmdirSync(path);
      }

      return null;
    }
  );
  фс.__m_props__["видалити_папку_рекурсивно"] = mavka_diia(
    "видалити_папку_рекурсивно",
    {
      "шлях": mavka_param(0, м_текст)
    },
    async function(args, di, { arg }) {
      var path = arg("шлях");

      if (fs.existsSync(path)) {
        fs.rmdirSync(path, { recursive: true });
      }

      return null;
    }
  );
  фс.__m_props__["існує"] = mavka_diia(
    "існує",
    {
      "шлях": mavka_param(0, м_текст)
    },
    async function(args, di, { arg }) {
      var path = arg("шлях");

      return fs.existsSync(path);
    }
  );
  return фс;
})());
