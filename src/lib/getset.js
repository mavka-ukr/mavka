// todo: optimize

function mavka_commonGet_bytes(a, b, di) {
  if (b.__m_type__ === "number") {
    return a[b];
  } else {
    if (b === "довжина") {
      return a.length;
    }
    if (b === "заповнити") {
      return mavka_diia(
        "заповнити",
        {
          "значення": mavka_param(0, "значення")
        },
        function(args, di, { arg }) {
          return a.fill(arg("значення"));
        }
      );
    }
    if (b === "обернути") {
      return mavka_diia(
        "обернути",
        {},
        function() {
          return a.reverse();
        }
      );
    }
    if (b === "зрізати") {
      return mavka_diia(
        "зрізати",
        {
          "від": mavka_param(0, м_число),
          "до": mavka_param(1, [м_число, null])
        },
        function(args, di, { arg }) {
          return a.slice(arg("від"), arg("до") ?? undefined);
        }
      );
    }
    return null;
  }
}

function mavka_commonGet_list(a, b, di) {
  if (b.__m_type__ === "number") {
    return a[b];
  } else {
    if (b === "довжина") {
      return a.length;
    }
    if (b === "додати") {
      return mavka_diia(
        "додати",
        {
          "значення": mavka_param(0, "значення")
        },
        function(args, di, { arg }) {
          a.push(arg("значення"));
          return a;
        }
      );
    }
    if (b === "забрати") {
      return mavka_diia(
        "забрати",
        {},
        function() {
          return a.pop();
        }
      );
    }
    if (b === "отримати") {
      return mavka_diia(
        "отримати",
        {
          "позиція": mavka_param(0, м_число)
        },
        function(args, di, { arg }) {
          return a[arg("позиція")];
        }
      );
    }
    if (b === "сортувати") {
      return mavka_diia(
        "сортувати",
        {
          "дія_порівняння": mavka_param(0, м_Дія)
        },
        function(args, di, { arg }) {
          return a.sort((a, b) => mavka_call(arg("дія_порівняння"), [a, b], di));
        }
      );
    }
    if (b === "фільтрувати") {
      return mavka_diia(
        "фільтрувати",
        {
          "дія_перевірки": mavka_param(0, м_Дія)
        },
        function(args, di, { arg }) {
          return a.filter((v) => mavka_call(arg("дія_перевірки"), [v], di));
        }
      );
    }
    if (b === "знайти") {
      return mavka_diia(
        "знайти",
        {
          "дія_перевірки": mavka_param(0, м_Дія)
        },
        function(args, di, { arg }) {
          return a.find((v) => mavka_call(arg("дія_перевірки"), [v], di));
        }
      );
    }
    if (b === "знайти_позицію") {
      return mavka_diia(
        "знайти_позицію",
        {
          "дія_перевірки": mavka_param(0, м_Дія)
        },
        function(args, di, { arg }) {
          return a.findIndex((v) => mavka_call(arg("дія_перевірки"), [v], di));
        }
      );
    }
    if (b === "перетворити") {
      return mavka_diia(
        "перетворити",
        {
          "дія_перетворення": mavka_param(0, м_Дія)
        },
        function(args, di, { arg }) {
          return a.map((v) => mavka_call(arg("дія_перетворення"), [v], di));
        }
      );
    }
    if (b === "заповнити") {
      return mavka_diia(
        "заповнити",
        {
          "значення": mavka_param(0, "значення")
        },
        function(args, di, { arg }) {
          return a.fill(arg("значення"));
        }
      );
    }
    if (b === "злити") {
      return mavka_diia(
        "злити",
        {
          "значення": mavka_param(0, м_список)
        },
        function(args, di, { arg }) {
          return a.concat(arg("значення"));
        }
      );
    }
    if (b === "зʼєднати") {
      return mavka_diia(
        "зʼєднати",
        {
          "роздільник": mavka_param(0, м_текст, "")
        },
        function(args, di, { arg }) {
          return a.map((v) => mavka_to_string(v, di)).join(arg("роздільник"));
        }
      );
    }
    if (b === "обернути") {
      return mavka_diia(
        "обернути",
        {},
        function() {
          return a.reverse();
        }
      );
    }
    if (b === "зрізати") {
      return mavka_diia(
        "зрізати",
        {
          "від": mavka_param(0, м_число),
          "до": mavka_param(1, [м_число, null])
        },
        function(args, di, { arg }) {
          return a.slice(arg("від"), arg("до") ?? undefined);
        }
      );
    }
    if (b === "скоротити") {
      return mavka_diia(
        "скоротити",
        {
          "дія_скорочення": mavka_param(0, м_Дія),
          "початкове_значення": mavka_param(1)
        },
        function(args, di, { arg }) {
          return a.reduce((acc, v) => mavka_call(arg("дія_скорочення"), [acc, v], di), arg("початкове_значення"));
        }
      );
    }
    return null;
  }
}

function mavka_commonGet_text(a, b, di) {
  if (b.__m_type__ === "number") {
    return a[b];
  }
  if (b === "символ") {
    return mavka_diia(
      "символ",
      {
        "позиція": mavka_param(0, м_число)
      },
      function(args, di, { arg }) {
        return a.charAt(arg("позиція"));
      }
    );
  }
  if (b === "код_символу") {
    return mavka_diia(
      "код_символу",
      {
        "позиція": mavka_param(0, м_число)
      },
      function(args, di, { arg }) {
        return a.charCodeAt(arg("позиція"));
      }
    );
  }
  if (b === "позиція") {
    return mavka_diia(
      "позиція",
      {
        "значення": mavka_param(0, м_текст)
      },
      function(args, di, { arg }) {
        return a.indexOf(arg("значення"));
      }
    );
  }
  if (b === "повторити") {
    return mavka_diia(
      "повторити",
      {
        "кількість": mavka_param(0, м_число)
      },
      function(args, di, { arg }) {
        return a.repeat(arg("кількість"));
      }
    );
  }
  if (b === "замінити") {
    return mavka_diia(
      "замінити",
      {
        "старе_значення": mavka_param(0, м_текст),
        "нове_значення": mavka_param(1, м_текст)
      },
      function(args, di, { arg }) {
        return a.replaceAll(arg("старе_значення"), arg("нове_значення"));
      }
    );
  }
  if (b === "замінити_перше") {
    return mavka_diia(
      "замінити_перше",
      {
        "старе_значення": mavka_param(0, м_текст),
        "нове_значення": mavka_param(1, м_текст)
      },
      function(args, di, { arg }) {
        return a.replace(arg("старе_значення"), arg("нове_значення"));
      }
    );
  }
  if (b === "зрізати") {
    return mavka_diia(
      "зрізати",
      {
        "від": mavka_param(0, м_число),
        "до": mavka_param(1, [м_число, null])
      },
      function(args, di, { arg }) {
        return a.substring(arg("від"), arg("до") ?? undefined);
      }
    );
  }
  if (b === "приєднати") {
    return mavka_diia(
      "приєднати",
      {},
      function(args, di, { arg }) {
        var value = (Array.isArray(p) ? p : Object.values(p))
          .map((v) => mavka_to_string(v, di))
          .join("");
        return a.concat(value);
      }
    );
  }
  if (b === "розділити") {
    return mavka_diia(
      "розділити",
      {
        "роздільник": mavka_param(0, м_текст)
      },
      function(args, di, { arg }) {
        return a.split(arg("роздільник"));
      }
    );
  }
  if (b === "починається_з") {
    return mavka_diia(
      "починається_з",
      {
        "значення": mavka_param(0, м_текст)
      },
      function(args, di, { arg }) {
        return a.startsWith(arg("значення"));
      }
    );
  }
  if (b === "закінчується_на") {
    return mavka_diia(
      "закінчується_на",
      {
        "значення": mavka_param(0, м_текст)
      },
      function(args, di, { arg }) {
        return a.endsWith(arg("значення"));
      }
    );
  }
  if (b === "обрізати") {
    return mavka_diia(
      "обрізати",
      {},
      function() {
        return a.trim();
      }
    );
  }
  if (b === "обтяти") {
    return mavka_diia(
      "обтяти",
      {},
      function() {
        var lineNumberWhereSmallestIndentationIs = 0;
        var lines = a.split("\n");
        var smallestIndentation = Infinity;
        for (let i = 0; i < lines.length; i++) {
          const line = lines[i];
          if (!line.trim()) {
            continue;
          }
          const indentation = line.match(/^\s*/)[0].length;
          if (indentation < smallestIndentation) {
            smallestIndentation = indentation;
            lineNumberWhereSmallestIndentationIs = i;
          }
        }
        const result = [];
        for (let i = 0; i < lines.length; i++) {
          const line = lines[i];
          if (!line.trim()) {
            continue;
          }
          result.push(line.slice(smallestIndentation));
        }
        return result.join("\n");
      }
    );
  }
  if (b === "довжина") {
    return a.length;
  }
  return null;
}

function mavka_commonGet(a, b, di, magicDiia) {
  if (a == null) {
    throw new MavkaError("Неможливо отримати властивість з \"пусто\".", di);
  }
  if (b == null) {
    return null;
  }
  if (a.__m_type__ === "list") {
    return mavka_commonGet_list(a, b, di);
  }
  if (a.__m_type__ === "bytes") {
    return mavka_commonGet_bytes(a, b, di);
  }
  if (a.__m_type__ === "dictionary") {
    return a.get(b);
  }
  if (a.__m_type__ === "text") {
    return mavka_commonGet_text(a, b, di);
  }
  if (!a.__m_props__) {
    throw new MavkaError(`Неможливо отримати властивість ${mavka_to_pretty_string(b, false)}.`, di);
  }
  if (magicDiia) {
    if (a.__m_props__[magicDiia]) {
      return a.__m_props__[magicDiia]([b], di);
    }
  }
  return a.__m_props__[b];
}

function mavka_get(a, b, di) {
  return mavka_commonGet(a, b, di);
}

function mavka_getSpecial(a, b, di) {
  return mavka_commonGet(a, b, di, "чародія_отримати_спеціальну_властивість");
}

function mavka_commonSet(a, b, c, di, magicDiia) {
  if (a == null) {
    throw new MavkaError("Неможливо встановити властивість для \"пусто\".", di);
  }
  if (a.__m_type__ === "list" && b.__m_type__ === "number") {
    a[b] = c;
    return a;
  } else if (a.__m_type__ === "bytes" && b.__m_type__ === "number") {
    a[b] = c;
    return a;
  } else if (a.__m_type__ === "dictionary") {
    a.set(b, c);
    return a;
  } else if (a.__m_type__ === "object") {
    if (magicDiia) {
      if (a.__m_props__[magicDiia]) {
        a.__m_props__[magicDiia]([b, c], di);
        return a;
      }
    }
    a.__m_props__[b] = c;
    return a;
  } else {
    throw new MavkaError("Неможливо встановити властивість.", di);
  }
}

function mavka_set(a, b, c, di) {
  return mavka_commonSet(a, b, c, di);
}

function mavka_setSpecial(a, b, c, di) {
  return mavka_commonSet(a, b, c, di, "чародія_змінити_спеціальну_властивість");
}