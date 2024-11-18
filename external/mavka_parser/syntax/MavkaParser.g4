parser grammar MavkaParser;

options {
    tokenVocab=MavkaLexer;
}

file: f_program=program EOF;

program: nls body_element (nl body_element)* nls;

atom: '(' nls expr nls ')' #atom_nested
    | '(' nls (object_arg (nls ',' nls object_arg)*)? nls ')' #operation_object
    | '[' nls '=' nls ']' #operation_dict_empty
    | '[' nls dict_arg (nls ',' nls dict_arg)* nls ']' #operation_dict
    | '[' nls (expr (nls ',' nls expr)*)? nls ']' #operation_array
    | (tt=ID)? STRING #operation_string
    | (tt=ID)? STRING_MULTILINE #operation_string_multiline
    | (tt=ID)? CHARACTER #operation_symbol
    | id=ID #atom_subject
    | object=atom nls '.' nls id=ID #atom_get
    | object=atom nls '[' nls position=expr nls ']' #atom_position_get
    | object=atom '(' nls (call_arg nls (nls ',' nls call_arg)*)? nls ')' #atom_call;
object_arg: id=ID nls '=' nls expr;
dict_arg: (key_number=NUMBER | ((key_string_tt=ID)? key_string=STRING) | ((key_stringml_tt=ID)? key_stringml=STRING_MULTILINE) | ((key_symbol_tt=ID)? key_symbol=CHARACTER)) nls '=' nls value=expr;
call_arg: (id=ID nls '=' nls)? expr;

operation: NUMBER #operation_number
         | atom #operation_atom
         | op='!' nls right=operation #operation_pre_not
         | op='~' nls right=operation #operation_pre_bw_not
         | op='+' nls right=operation #operation_pre_plus
         | op='-' nls right=operation #operation_pre_minus
         | left=operation nls op=op_pow nls right=operation #operation_pow
         | left=operation nls op='*' nls right=operation #operation_mul
         | left=operation nls op=op_div_div nls right=operation #operation_div_div
         | left=operation nls op='/' nls right=operation #operation_div
         | left=operation nls op='%' nls right=operation #operation_mod
         | left=operation nls op='+' nls right=operation #operation_add
         | left=operation nls op='-' nls right=operation #operation_sub
         | left=operation nls op=op_lshift nls right=operation #operation_lshift
         | left=operation nls op=op_rshift nls right=operation #operation_rshift
         | left=operation nls op=op_urshift nls right=operation #operation_urshift
         | left=operation nls op=op_lt nls right=operation #operation_lt
         | left=operation nls op=op_lte nls right=operation #operation_lte
         | left=operation nls op=op_gt nls right=operation #operation_gt
         | left=operation nls op=op_gte nls right=operation #operation_gte
         | left=operation nls op='містить' nls right=operation #operation_contains
         | left=operation nls op=op_not_contains nls right=operation #operation_not_contains
         | left=operation nls op='є' nls right=operation #operation_is
         | left=operation nls op=op_not_is nls right=operation #operation_not_is
         | left=operation nls op=op_eq nls right=operation #operation_eq
         | left=operation nls op=op_neq nls right=operation #operation_neq
         | left=operation nls op='&' nls right=operation #operation_and
         | left=operation nls op='^' nls right=operation #operation_xor
         | left=operation nls op='|' nls right=operation #operation_or
         | left=operation nls op=op_land nls right=operation #operation_land
         | left=operation nls op=op_lor nls right=operation #operation_lor
         | cond=operation nls '?' nls ifok=operation nls ':' nls ifnot=operation #operation_ternary;

op_pow: '*' '*';
op_div_div: '/' '/';
op_lshift: '<' '<';
op_rshift: '>' '>';
op_urshift: '>' '>' '>';
op_lt: '<' | 'менше';
op_lte: ('<' '=') | ('не' 'більше');
op_gt: '>' | 'більше';
op_gte: ('>' '=') | ('не' 'менше');
op_eq: ('=' '=') | 'рівно';
op_neq: ('!' '=') | ('не' 'рівно');
op_land: ('&' '&') | 'і';
op_lor: ('|' '|') | 'або';
op_not_contains: 'не' 'містить';
op_not_is: 'не' 'є';

gendef: ID;

expr: operation #expr_operation
    | diia_define #expr_diia
    | structure_define #expr_structure
    | '(' nls (diia_param nls (',' nls diia_param)*)? nls ')' (d_type=types)? ':' d_body=expr #function;

structure_define: 'структура' id=ID ('є' s_parent=atom)? nl (structure_element nls (nl nls structure_element)*)? nls 'кінець';
structure_element: param;

diia_define: (d_async='тривала')? (d_spec='спец')? 'дія' ((d_structure=atom '.')? d_name=ID)? '(' nls (diia_param nls (',' nls diia_param)*)? nls ')' (d_type=types)? nl (d_body=body nl)? nls 'кінець';
diia_param: param;

assign: id=ID (simpleas='=' | (parentas=':' '=')) (value_expr=expr);

set: object=atom '.' id=ID '=' (value_expr=expr);
position_set: object=atom '[' idx=expr ']' '=' (value_expr=expr);

if: 'якщо' cond=expr nl (ifok=body nl)? (('інакше' nl ifnot=body nl)? 'кінець' | ('інакше' ifnotif=if));

while: 'поки' cond=operation nl (w_body=body nl)? 'кінець';

each: 'перебрати' object=atom 'як' id=ID nl (e_body=body nl)? 'кінець';

loop_part: assign | set | position_set | expr;
loop: 'цикл' start=loop_part nls ',' nls cond=operation nls ',' nls iter=loop_part nl (w_body=body nl)? 'кінець';

body: body_element (nl body_element)*;
body_element: structure_define
            | diia_define
            | assign
            | set
            | position_set
            | if
            | while
            | each
            | loop
            | expr
            | return
            | try
            | throw
            | take
            | module
            | give;
return: 'вернути' (value_expr=expr)?;

module: 'модуль' (id=ID)? nl (body_=body nl)? 'кінець';

type: '(' nls expr nls ')' #type_nested
    | id=ID #type_subject
    | object=type nls '.' nls id=ID #type_get;
types: type (nls 'або' nls type)*;

param: id=ID (types)? ('=' expr)?;

take: 'взяти' (type_id=ID)? take_part ('.' take_part)*;
take_part: ID | STRING;
give: 'дати' give_element (nls ',' nls give_element)*;
give_element: id=ID (nls 'як' nls as=ID)?;

try: 'спробувати' nl (t_body=body nl)? 'зловити' (t_name=ID)? nl (t_catch_body=body nl)? 'кінець';
throw: 'впасти' (t_value=expr)?;

nl: NL+;
nls: NL*;