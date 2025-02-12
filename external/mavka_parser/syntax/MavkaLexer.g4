lexer grammar MavkaLexer;

KW_END: 'кінець';
KW_DIIA: 'дія';
KW_STRUCTURE: 'структура';
KW_FOR: 'перебрати';
KW_CYCLE: 'цикл';
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
KW_HAS_WORD: 'містить';
KW_MOCKUP: 'макет';
KW_NOT: 'не';
KW_PARENT: 'предок';
KW_TSE: 'це';
KW_PERELIK: 'перелік';
KW_COMPOSITION: 'композиція';
KW_PUBLIC: 'зовнішня';
KW_PRIVATE: 'внутрішня';
KW_PROTECTED: 'місцева';
KW_PROPERTY: 'властивість';
KW_DELETE: 'видалити';
KW_OWN: 'власна';

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

NUMBER: INTEGER | FLOAT | HEX | BIN;

INTEGER: INTEGER_START INTEGER_CONTINUE*;
fragment INTEGER_START: DIGIT;
fragment INTEGER_CONTINUE: ('_')? DIGIT;

FLOAT: FLOAT_START FLOAT_CONTINUE* '.' FLOAT_START FLOAT_CONTINUE*;
fragment FLOAT_START: DIGIT;
fragment FLOAT_CONTINUE: ('_')? DIGIT;

HEX: '0' ('ш' | 'Ш') HEX_START HEX_CONTINUE*;
fragment HEX_START: ('А' | 'а' | 'Б' | 'б' | 'В' | 'в' | 'Г' | 'г' | 'Д' | 'д' | 'Е' | 'е' | DIGIT);
fragment HEX_CONTINUE: ('_')? ('А' | 'а' | 'Б' | 'б' | 'В' | 'в' | 'Г' | 'г' | 'Д' | 'д' | 'Е' | 'е' | DIGIT);

BIN: '0' ('д' | 'Д') BIN_START BIN_CONTINUE*;
fragment BIN_START: ('0' | '1');
fragment BIN_CONTINUE: ('_')? ('0' | '1');

fragment DIGIT: '0'..'9';

ID: ID_START ID_CONTINUE*;
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

STRING_MULTILINE: '"' '"' '"' ('\\"' | .)*? '"' '"' '"';
STRING: '"' ( ~["\n\r] | '\\"' )* '"';
CHARACTER: '\'' ( ~['\n\r] | '\\\'' )* '\'';

COMMENT: ';*' (COMMENT | .)*? '*;' -> channel(HIDDEN);
LINE_COMMENT: ';;' (LINE_COMMENT | ~[\r\n])* -> channel(HIDDEN);

NL: ( '\r'? '\n' );
WS: (' ' | '\t') -> channel(HIDDEN);
