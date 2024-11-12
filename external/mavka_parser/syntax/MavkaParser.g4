parser grammar MavkaParser;

options {
    tokenVocab=MavkaLexer;
}

file: f_program=program EOF;

program: nls body_element (nl body_element)* nls;

atom: '(' nls expr nls ')' #atom_nested
    | (tt=ID)? STRING #operation_string
    | id=ID #atom_subject
    | object=atom nls '.' nls id=ID #atom_get
    | object=atom nls '[' nls position=expr nls ']' #atom_position_get
    | object=atom '(' nls (call_arg nls (nls ',' nls call_arg)*)? nls ')' #atom_call;
object_arg: id=ID nls '=' nls expr;
dict_arg: (key_number=NUMBER | ((key_string_tt=ID)? key_string=STRING)) nls ':' nls value=expr;
call_arg: (id=ID nls '=' nls)? expr;

operation: NUMBER #operation_number
         | atom #operation_atom
         | '(' nls (object_arg (nls ',' nls object_arg)*)? nls ')' #operation_object
         | '[' nls ':' nls ']' #operation_dict_empty
         | '[' nls dict_arg (nls ',' nls dict_arg)* nls ']' #operation_dict
         | '[' nls (expr (nls ',' nls expr)*)? nls ']' #operation_array
         | left=operation nls op='як' nls (right_type=type) #operation_as
         | op='!' nls right=operation #operation_pre_not
         | op='~' nls right=operation #operation_pre_bw_not
         | op='+' nls right=operation #operation_pre_plus
         | op='-' nls right=operation #operation_pre_minus
         | left=operation nls op='*' nls right=operation #operation_mul
         | left=operation nls op='/' nls right=operation #operation_div
         | left=operation nls op='%' nls right=operation #operation_mod
         | left=operation nls op='+' nls right=operation #operation_add
         | left=operation nls op='-' nls right=operation #operation_sub
         | left=operation nls op=op_lshift nls right=operation #operation_lshift
         | left=operation nls op=op_rshift nls right=operation #operation_rshift
         | left=operation nls op=op_urshift nls right=operation #operation_urshift
         | left=operation nls op='<' nls right=operation #operation_lt
         | left=operation nls op=op_lte nls right=operation #operation_lte
         | left=operation nls op='>' nls right=operation #operation_gt
         | left=operation nls op=op_gte nls right=operation #operation_gte
         | left=operation nls op=op_eq nls right=operation #operation_eq
         | left=operation nls op=op_neq nls right=operation #operation_neq
         | left=operation nls op='&' nls right=operation #operation_and
         | left=operation nls op='^' nls right=operation #operation_xor
         | left=operation nls op='|' nls right=operation #operation_or
         | left=operation nls op=op_land nls right=operation #operation_land
         | left=operation nls op=op_lor nls right=operation #operation_lor
         | cond=operation nls '?' nls ifok=operation nls ':' nls ifnot=operation #operation_ternary;

op_lshift: '<' '<';
op_rshift: '>' '>';
op_urshift: '>' '>' '>';
op_lte: '<' '=';
op_gte: '>' '=';
op_eq: '=' '=';
op_neq: '!' '=';
op_land: '&' '&';
op_lor: '|' '|';

gendef: ID;

expr: operation #expr_operation;

structure_define: 'структура' id=ID ('є' s_parent=atom)? nl (structure_element nls (nl nls structure_element)*)? nls 'кінець';
structure_element: param;

diia_define: (d_async='тривала')? (d_spec='спец')? 'дія' ((d_structure=atom '.')? d_name=ID)? '(' nls (diia_param nls (',' nls diia_param)*)? nls ')' (d_type=types)? nl (d_body=body nl)? nls 'кінець';
diia_param: param;

assign: id=ID (simpleas='=' | (parentas=':' '=')) (value_expr=expr);

set: object=atom '.' id=ID '=' (value_expr=expr);
position_set: object=atom '[' idx=expr ']' '=' (value_expr=expr);

if: 'якщо' cond=expr nl (ifok=body nl)? (('інакше' nl ifnot=body nl)? 'кінець' | ('інакше' ifnotif=if));

while: 'поки' cond=operation nl (w_body=body nl)? 'кінець';

body: body_element (nl body_element)*;
body_element: structure_define
            | diia_define
            | assign
            | set
            | position_set
            | if
            | while
            | expr
            | return
            | try
            | throw
            | take
            | module
            | give;
return: 'вернути' (value_expr=expr)?;

module: 'модуль' (id=ID)? nl (body_=body nl)? 'кінець';

type: atom;
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