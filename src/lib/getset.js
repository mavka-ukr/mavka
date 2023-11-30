// todo: optimize

function mavka_commonGet_bytes(a, b, di) {
  if (b.__m_type__ === "number") {
    return a[b];
  } else {
    if (b === "довжина") {
      return a.length;
    }
    if (b === "заповнити") {
      return function(p, di) {
        var value = mavka_arg(p, 0, "значення", undefined, undefined, di);
        return a.fill(value);
      };
    }
    if (b === "обернути") {
      return function() {
        return a.reverse();
      };
    }
    if (b === "зрізати") {
      return function(p, di) {
        var indexStart = mavka_arg(p, 0, "від", м_число, undefined, di);
        var indexEnd = mavka_arg(p, 1, "до", [м_число, null], undefined, di);
        return a.slice(indexStart, indexEnd ?? undefined);
      };
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
      return function(p, di) {
        var value = mavka_arg(p, 0, "значення", undefined, undefined, di);
        a.push(value);
        return a;
      };
    }
    if (b === "забрати") {
      return function() {
        return a.pop();
      };
    }
    if (b === "отримати") {
      return function(p, di) {
        var index = mavka_arg(p, 0, "позиція", м_число, undefined, di);
        return a[index];
      };
    }
    if (b === "сортувати") {
      return function(p, di) {
        var compareFn = mavka_arg(p, 0, "дія_порівняння", м_Дія, undefined, di);
        return a.sort((a, b) => compareFn([a, b], di));
      };
    }
    if (b === "фільтрувати") {
      return function(p, di) {
        var predicateFn = mavka_arg(p, 0, "дія_перевірки", м_Дія, undefined, di);
        return a.filter((v) => predicateFn([v], di));
      };
    }
    if (b === "знайти") {
      return function(p, di) {
        var predicateFn = mavka_arg(p, 0, "дія_перевірки", м_Дія, undefined, di);
        return a.find((v) => predicateFn([v], di));
      };
    }
    if (b === "знайти_позицію") {
      return function(p, di) {
        var predicateFn = mavka_arg(p, 0, "дія_перевірки", м_Дія, undefined, di);
        return a.findIndex((v) => predicateFn([v], di));
      };
    }
    if (b === "перетворити") {
      return function(p, di) {
        var transformFn = mavka_arg(p, 0, "дія_перетворення", м_Дія, undefined, di);
        return a.map((v) => transformFn([v], di));
      };
    }
    if (b === "заповнити") {
      return function(p, di) {
        var value = mavka_arg(p, 0, "значення", undefined, undefined, di);
        return a.fill(value);
      };
    }
    if (b === "злити") {
      return function(p, di) {
        var value = mavka_arg(p, 0, "значення", м_список, undefined, di);
        return a.concat(value);
      };
    }
    if (b === "зʼєднати") {
      return function(p, di) {
        var separator = mavka_arg(p, 0, "роздільник", м_текст, "", di);
        return a.map((v) => mavka_to_string(v, di)).join(separator);
      };
    }
    if (b === "обернути") {
      return function() {
        return a.reverse();
      };
    }
    if (b === "зрізати") {
      return function(p, di) {
        var indexStart = mavka_arg(p, 0, "від", м_число, undefined, di);
        var indexEnd = mavka_arg(p, 1, "до", [м_число, null], undefined, di);
        return a.slice(indexStart, indexEnd ?? undefined);
      };
    }
    if (b === "скоротити") {
      return function(p, di) {
        var reduceFn = mavka_arg(p, 0, "дія_скорочення", м_Дія, undefined, di);
        var initialValue = mavka_arg(p, 1, "початкове_значення", undefined, undefined, di);
        return a.reduce((acc, v) => reduceFn([acc, v], di), initialValue);
      };
    }
    return null;
  }
}

function mavka_commonGet_text(a, b, di) {
  if (b.__m_type__ === "number") {
    return a[b];
  }
  if (b === "символ") {
    return function(p, di) {
      var index = mavka_arg(p, 0, "позиція", м_число, undefined, di);
      return a.charAt(index);
    };
  }
  if (b === "код_символу") {
    return function(p, di) {
      var index = mavka_arg(p, 0, "позиція", м_число, undefined, di);
      return a.charCodeAt(index);
    };
  }
  if (b === "позиція") {
    return function(p, di) {
      var value = mavka_arg(p, 0, "значення", м_текст, undefined, di);
      return a.indexOf(value);
    };
  }
  if (b === "повторити") {
    return function(p, di) {
      var count = mavka_arg(p, 0, "кількість", м_число, undefined, di);
      return a.repeat(count);
    };
  }
  if (b === "замінити") {
    return function(p, di) {
      var value = mavka_arg(p, 0, "старе_значення", м_текст, undefined, di);
      var replacement = mavka_arg(p, 1, "нове_значення", м_текст, undefined, di);
      return a.replaceAll(value, replacement);
    };
  }
  if (b === "замінити_перше") {
    return function(p, di) {
      var value = mavka_arg(p, 0, "старе_значення", м_текст, undefined, di);
      var replacement = mavka_arg(p, 1, "нове_значення", м_текст, undefined, di);
      return a.replace(value, replacement);
    };
  }
  if (b === "зрізати") {
    return function(p, di) {
      var indexStart = mavka_arg(p, 0, "від", м_число, undefined, di);
      var indexEnd = mavka_arg(p, 1, "до", [м_число, null], undefined, di);
      return a.substring(indexStart, indexEnd ?? undefined);
    };
  }
  if (b === "приєднати") {
    return function(p, di) {
      var value = (Array.isArray(p) ? p : Object.values(p))
        .map((v) => mavka_to_string(v, di))
        .join("");
      return a.concat(value);
    };
  }
  if (b === "розділити") {
    return function(p, di) {
      var separator = mavka_arg(p, 0, "роздільник", м_текст, undefined, di);
      return a.split(separator);
    };
  }
  if (b === "починається_з") {
    return function(p, di) {
      var value = mavka_arg(p, 0, "значення", м_текст, undefined, di);
      return a.startsWith(value);
    };
  }
  if (b === "закінчується_на") {
    return function(p, di) {
      var value = mavka_arg(p, 0, "значення", м_текст, undefined, di);
      return a.endsWith(value);
    };
  }
  if (b === "обрізати") {
    return function(p, di) {
      return a.trim();
    };
  }
  if (b === "обтяти") {
    return function(p, di) {
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
    };
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