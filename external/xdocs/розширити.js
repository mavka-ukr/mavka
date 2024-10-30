md.options.highlight = (str, lang) => {
  const wrap = (content) => {
    if (lang === "теорія") {
      return `<pre><div class="XDocsCodeImages"><img src="./ресурси/тема/теорія_х.лого.svg" alt="" /><img src="./ресурси/тема/теорія_х.лого.svg" alt="" /><img src="./ресурси/тема/теорія_х.лого.svg" alt="" /><img src="./ресурси/тема/теорія_х.лого.svg" alt="" /><img src="./ресурси/тема/теорія_х.лого.svg" alt="" /><img src="./ресурси/тема/теорія_х.лого.svg" alt="" /><img src="./ресурси/тема/теорія_х.лого.svg" alt="" /><img src="./ресурси/тема/теорія_х.лого.svg" alt="" /><img src="./ресурси/тема/теорія_х.лого.svg" alt="" /></div><div class="XDocsCodeWrapper"><code class="hljs">${content}</code></div><div class="XDocsCodeImages bottom"><img src="./ресурси/тема/теорія_х.лого.svg" alt="" /><img src="./ресурси/тема/теорія_х.лого.svg" alt="" /><img src="./ресурси/тема/теорія_х.лого.svg" alt="" /><img src="./ресурси/тема/теорія_х.лого.svg" alt="" /><img src="./ресурси/тема/теорія_х.лого.svg" alt="" /><img src="./ресурси/тема/теорія_х.лого.svg" alt="" /><img src="./ресурси/тема/теорія_х.лого.svg" alt="" /><img src="./ресурси/тема/теорія_х.лого.svg" alt="" /><img src="./ресурси/тема/теорія_х.лого.svg" alt="" /></div></pre>`;
    }
    return `<pre><div class="XDocsCodeWrapper"><code class="hljs">${content}</code></div></pre>`;
  };
  if (lang && hljs.getLanguage(lang)) {
    try {
      return wrap(
        hljs.highlight(str, {
          language: lang,
          ignoreIllegals: true
        }).value
      );
    } catch (__) {
    }
  }
  return wrap(md.utils.escapeHtml(str));
};

const mavkaSyntax = () => {
  return {
    name: "Mavka",
    aliases: ["mavka"],
    keywords: {
      $pattern: /[a-zA-Zа-яА-ЯіІїЇєЄ_ʼ]+/,
      keyword:
        "та композиція перелік риса втілює зовн внут біб імп спец власна ціль макет це дія рівно більше цикл менше макет пак спробувати містить не я js файл впасти тривала зловити є перебрати кінець структура чекати взяти якщо або і інакше вернути поки як дати модуль пропустити зупинити",
      literal:
        "так ні перебір перебір_з_ключем пусто символ текст логічне число п32 ц32 д32 список словник обʼєкт байти"
    },
    unicodeRegex: true,
    contains: [
      {
        begin: ["дія", /\(/],
        className: { 0: "keyword" }
      },
      {
        begin: [/[a-zа-яіїє_]/, /[a-zA-Zа-яА-ЯіІїЇєЄ_ʼ0-9]*/, /\(/],
        className: { 1: "title.function", 2: "title.function" }
      },
      {
        begin: [/[a-zа-яіїє_]/, /[a-zA-Zа-яА-ЯіІїЇєЄ_ʼ0-9]*/, /<.+>/, /\(/],
        className: { 1: "title.function", 2: "title.function" }
      },
      {
        begin: [/[A-ZА-ЯІЇЄ]/, /[a-zA-Zа-яА-ЯіІїЇєЄ_ʼ0-9]*/, /\(/],
        className: { 1: "title.class", 2: "title.class" }
      },
      {
        begin: [" ", /[A-ZА-ЯІЇЄ]/, /[a-zA-Zа-яА-ЯіІїЇєЄ_ʼ0-9]+/],
        className: { 2: "title.class", 3: "title.class" }
      },
      {
        begin: [/\[\]/, /[A-ZА-ЯІЇЄ]/, /[a-zA-Zа-яА-ЯіІїЇєЄ_ʼ0-9]+/],
        className: { 2: "title.class", 3: "title.class" }
      },
      {
        begin: [
          "структура ",
          /[a-zA-Zа-яА-ЯіІїЇєЄ_]/,
          /[a-zA-Zа-яА-ЯіІїЇєЄ_ʼ0-9]*/
        ],
        className: { 2: "title.class", 3: "title.class" }
      },
      {
        begin: [
          "макет модуль ",
          /[a-zA-Zа-яА-ЯіІїЇєЄ_]/,
          /[a-zA-Zа-яА-ЯіІїЇєЄ_ʼ0-9]*/
        ],
        className: {}
      },
      {
        begin: [
          "макет тривала дія ",
          /[a-zA-Zа-яА-ЯіІїЇєЄ_]/,
          /[a-zA-Zа-яА-ЯіІїЇєЄ_ʼ0-9]*/
        ],
        className: { 2: "title.function", 3: "title.function" }
      },
      {
        begin: [/[A-ZА-ЯІЇЄ]/, /[a-zA-Zа-яА-ЯіІїЇєЄ_ʼ0-9]+/, /\./],
        className: { 1: "title.class", 2: "title.class" }
      },
      {
        begin: ["дати ", /[A-ZА-ЯІЇЄ]/, /[a-zA-Zа-яА-ЯіІїЇєЄ_ʼ0-9]*/],
        className: { 2: "title.class", 3: "title.class" }
      },
      {
        begin: ["дати ", /[a-zа-яіїє_]/, /[a-zA-Zа-яА-ЯіІїЇєЄ_ʼ0-9]*/],
        className: { 2: "title.label", 3: "title.label" }
      },
      {
        begin: [
          "взяти ",
          /[a-zA-Zа-яА-ЯіІїЇєЄ_ʼ]+\./,
          /[a-zа-яіїє_]/,
          /[a-zA-Zа-яА-ЯіІїЇєЄ_ʼ]*/
        ],
        className: { 3: "label", 4: "label" }
      },
      {
        begin: [
          "взяти ",
          /[a-zA-Zа-яА-ЯіІїЇєЄ_ʼ]+\./,
          /[A-ZА-ЯІЇЄ]/,
          /[a-zA-Zа-яА-ЯіІїЇєЄ_ʼ]*/
        ],
        className: { 3: "title.class", 4: "title.class" }
      },
      {
        className: "string",
        begin: /"""/,
        end: /"""/,
        contains: [
          {
            begin: /%\(/,
            end: /\)/,
            scope: "subst"
          }
        ]
      },
      {
        className: "string",
        begin: /"/,
        end: /"/,
        contains: [
          {
            begin: /%\(/,
            end: /\)/,
            scope: "subst"
          }
        ]
      },
      {
        className: "string",
        begin: /'/,
        end: /'/
      },
      hljs.COMMENT(";\\*", "\\*;"),
      hljs.COMMENT(";;", "$"),
      {
        scope: "number",
        begin: /(-?)0ш([АБВГҐДабвгґд0-9])+/
      },
      {
        scope: "number",
        begin: /(-?)0д([01])+/
      },
      hljs.C_NUMBER_MODE,
      {
        begin: [" ", /[0-9]+(.[0-9]+)?/, "..", /[0-9]+(.[0-9]+)?/, " "],
        className: { 2: "number", 4: "number" }
      },
      {
        begin: [
          " ",
          /[0-9]+(.[0-9]+)?/,
          "..",
          /[0-9]+(.[0-9]+)?/,
          "..",
          /[0-9]+(.[0-9]+)?/,
          " "
        ],
        className: { 2: "number", 4: "number", 6: "number" }
      }
    ]
  };
};
const theoriaSyntax = () => {
  return {
    name: "Theoria",
    aliases: ["theoria"],
    unicodeRegex: true,
    contains: [
      {
        begin: [/[A-ZА-ЯІЇЄ]/, /[a-zA-Zа-яА-ЯіІїЇєЄ_ʼ0-9]*/, /\(/],
        className: { 1: "title.class", 2: "title.class" }
      }
    ]
  };
};
hljs.registerLanguage("мавка", mavkaSyntax);
hljs.registerLanguage("теорія", theoriaSyntax);

// const subjectWords = [
//   "мавка",
//   "мавки",
//   "мавці",
//   "мавку",
//   "код мавки",
//   "леся українка",
//   "лесі українці",
//   "теорія мавки",
//   "теорії мавки"
// ];
// md.renderer.rules.text = function(tokens, idx, options, env, self) {
//   return tokens[idx].content.replace(new RegExp(`(?<=[\\s,.:;"']|^)(${subjectWords.join("|")})(?=[\\s,.:;"']|$)`, "gi"), `<span class="XDocsTextSubject">$1</span>`);
// };