lexer grammar MavkaLexer;

KW_END: 'кінець';
KW_DIIA: 'дія';
KW_STRUCTURE: 'структура';
KW_FOR: 'перебрати';
KW_IF: 'якщо';
KW_WAIT: 'чекати';
KW_TAKE: 'взяти';
KW_GIVE: 'дати';
KW_AS: 'як';
KW_TA: 'та';
KW_IS: 'є';
KW_SPEC: 'спец';
KW_RETURN: 'вернути';
KW_ASYNC: 'тривала';
KW_SUBJECT: 'субʼєкт';
KW_AND: 'і';
KW_OR: 'або';
KW_TRY: 'спробувати';
KW_CATCH: 'зловити';
KW_ELSE: 'інакше';
KW_THROW: 'впасти';
KW_WHILE: 'поки';
KW_MODULE: 'модуль';
KW_EQ_WORD: 'рівно';
KW_GR_WORD: 'більше';
KW_SM_WORD: 'менше';
KW_HAS_IS_WORD: 'містить';
KW_MOCKUP: 'макет';
KW_NOT: 'не';
KW_JS: 'js';
KW_PARENT: 'предок';
KW_TSE: 'це';

EQUAL: '=';
GREATER: '>';
LESSER: '<';
DOT: '.';
PLUS: '+';
MINUS: '-';
MULTIPLY: '*';
DIVIDE: '/';
MOD: '%';
POWER: '^';
AND: '&';
OR: '|';
PAREN_OPEN: '(';
PAREN_CLOSE: ')';
BRACKET_OPEN: '[';
BRACKET_CLOSE: ']';
QUESTION: '?';
COLON: ':';
TILDA: '~';
QUOTE: '\'';
DOUBLE_QUOTE: '"';
EXCLAMATION: '!';
COMA: ',';

INTEGER: DIGIT+;
FLOAT: DIGIT+ '.' DIGIT+;
HEX: '0' ('ш' | 'Ш' | 'x' | 'X') (DIGIT | 'А' | 'а' | 'Б' | 'б' | 'В' | 'в' | 'Г' | 'г' | 'Ґ' | 'ґ' | 'Д' | 'д' | 'A'..'F' | 'a'..'f')+;
BIN: '0' ('д' | 'Д' | 'b' | 'B') ('0' | '1')+;
NUMBER: INTEGER | FLOAT | HEX | BIN;

ID: ID_START ID_CONTINUE*;
KWID: QUOTE (KW_END | KW_DIIA | KW_STRUCTURE | KW_FOR | KW_IF | KW_WAIT | KW_TAKE | KW_GIVE | KW_AS | KW_TA | KW_IS | KW_SPEC | KW_RETURN | KW_ASYNC | KW_SUBJECT | KW_AND | KW_OR | KW_TRY | KW_CATCH | KW_ELSE | KW_THROW | KW_WHILE | KW_MODULE | KW_EQ_WORD | KW_GR_WORD | KW_SM_WORD | KW_HAS_IS_WORD | KW_MOCKUP | KW_NOT | KW_JS | KW_PARENT | KW_TSE);

STRING_MULTILINE: '"' '"' '"' TRIPPLE_QUOTED_STRING_PART*? '"' '"' '"';
STRING: '"' ( ~["\n\r] )* '"';

COMP_INST_START: ';' '+';
COMP_INST_END: ';' '-';
COMP_INST_ASSIGN: ';' '=';

COMMENT: ';' ';' ';' (COMMENT | .)*? ';' ';' ';' -> channel(HIDDEN);
LINE_COMMENT: ';' ';' (LINE_COMMENT | ~[\r\n])* -> channel(HIDDEN);

MRM_DIIA: '<дія>' .*? '</дія>';

NL: ( '\r'? '\n' );
WS: (' ' | '\t') -> channel(HIDDEN);

fragment DIGIT
    : '0'..'9'
    ;

fragment ID_START
    : 'a'..'z' | 'A'..'Z'
    | 'а'..'я' | 'А'..'Я' | 'і' | 'І' | 'ї' | 'Ї' | 'є' | 'Є' | 'ґ' | 'Ґ'
    | '_'
    ;

fragment ID_CONTINUE
    : ID_START
    | '0'..'9'
    | 'ʼ'
    | ID_START
    ;

fragment TRIPPLE_QUOTED_STRING_PART
    : (ESCAPED_TRIPPLE_QUOTE | .)+?
    ;

fragment ESCAPED_TRIPPLE_QUOTE
    : '\\"'
    ;
