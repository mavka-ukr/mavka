parser grammar MavkaParser;

options {
    tokenVocab=MavkaLexer;
}

nl: NL+;
nls: NL*;

number_token: INTEGER | FLOAT | HEX | BIN;
string: STRING | STRING_MULTILINE;

identifier: ID;

file: f_program=program EOF;

program: program_element (nl program_element)*;
program_element: module | structure | mockup | diia | if | each | while | try | expr | throw | eval | wait_assign | assign | take | give | comp_inst_block_program | comp_inst_assign | nls;

module: 'модуль' (m_name=identifier)? nl (m_body=module_body nl)? 'кінець';
module_body: module_body_element (nl module_body_element)*;
module_body_element: module | structure | mockup | diia | if | each | while | try | expr | throw | eval | wait_assign | assign | give | nls;

structure: 'структура' s_name=identifier ('<' s_generics=generics '>')? ('є' s_parent=super_identifiers_chain ('<' s_parent_generics=generics '>')?)? nl (s_elements=structure_elements nl)? nls 'кінець';
structure_elements: structure_element (nl structure_element)*;
structure_element: structure_param;
structure_param: (sp_static='спец')? sp_name=identifier (sp_type=type_value)? ('=' sp_value=param_value)?;

generics: identifier (',' identifier)*;

mockup: mockup_module | mockup_structure | mockup_diia | mockup_subject;
mockup_module: 'макет' 'модуль' mm_name=identifier nl (mm_elements=mockup_module_body nl)? 'кінець';
mockup_module_body: mockup (nl mockup)*;
mockup_structure: 'макет' 'структура' ms_name=identifier ('<' ms_generics=generics '>')? ('є' ms_parent=super_identifiers_chain ('<' ms_parent_generics=generics '>')?)? nl (ms_elements=mockup_structure_body nl)? 'кінець';
mockup_structure_body: mockup_structure_body_element (nl mockup_structure_body_element)*;
mockup_structure_body_element: structure_param;
mockup_diia: 'макет' (md_async='тривала')? (md_static='спец')? 'дія' (md_structure=identifier '.')? md_name=identifier ('<' md_generics=generics '>')? '(' nls md_params=params? nls ')' (md_type=type_value)?;
mockup_subject: 'макет' 'субʼєкт' ms_name=identifier ms_type=type_value;

diia: (d_async='тривала')? (d_static='спец')? 'дія' (d_structure=identifier '.')? d_name=identifier ('<' d_generics=generics '>')? '(' nls d_params=params? nls ')' (d_type=type_value)? nl (d_body=body nl)? 'кінець';

if: 'якщо' i_value=expr nl (i_body=body nl)? ((('інакше' nl i_else_body=body nl)? 'кінець') | ('інакше' i_else_if=if));

each: 'перебрати' (e_iterator=atom | e_fromto=fromto) 'як' (e_key_name=identifier ',')? e_name=identifier? nl (e_body=body nl)? 'кінець';

fromto: fromto_simple | fromto_complex;
fromto_simple: fs_from=fromto_value '.' '.' (fs_to_symbol=fromto_to_symbol)? fs_to=fromto_value;
fromto_complex: fc_from=fromto_value '.' '.' (fc_middle_symbol=fromto_middle_symbol)? fc_middle=fromto_value '.' '.' (fc_to_symbol=fromto_to_symbol)? fc_to=fromto_value;
fromto_value: number_token #fromto_number
            | identifier #fromto_id
            | '(' nls fn_value=expr nls ')' #fromto_nested;
fromto_middle_symbol: '+' | '-' | '*' | '/' | '%' | '/' '/' | '*' '*';
fromto_to_symbol: '!' '=' | '=' '=' | '>' | '<' | '>' '=' | '<' '=';

while: 'поки' w_value=expr nl (w_body=body nl)? 'кінець';

try: 'спробувати' nl (t_body=body nl)? 'зловити' tc_name=identifier? nl (tc_body=body nl)? 'кінець';

eval: 'js' e_value=string;

take: 'взяти' (tm_relative='.')? tm_name_chain=identifiers_chain (tm_elements=take_module_elements | ('як' tm_as=identifier))? #take_module
    | 'взяти' identifier tr_url=STRING tr_version=STRING ('як' tr_as=identifier)? #take_remote;
take_module_elements: '[' take_module_element (',' take_module_element)* ']';
take_module_element: tme_name=identifier ('як' tme_as=identifier)?;

give: 'дати' give_element (nls ',' nls give_element)*;
give_element: ge_name=identifier ('як' ge_as=identifier)?;

mrm: mrm_element | mrm_element_closed | mrm_diia;
mrm_element: '<' nls me_name=identifiers_chain nls (me_args=mrm_args)? nls me_me='>' me_content=mrm_content '<' '/' nls me_end_name=identifiers_chain nls '>';
mrm_element_closed: '<' nls me_name=identifiers_chain nls (me_args=mrm_args)? nls '/' '>';
mrm_args: mrm_arg (nls mrm_arg)*;
mrm_arg: ma_name=identifier '=' ma_value=atom;
mrm_content: mrm_chardata? (mrm mrm_chardata?)*;
mrm_chardata: ~('<' | MRM_DIIA)+;
mrm_diia: MRM_DIIA;

atom: number_token #number
    | string #string_value
    | identifier #id
    | c_left=atom nls '.' nls c_right=identifier #chain
    | c_value=atom ('<' call_generics '>')? '(' nls (c_args=args | c_named_args=named_args)? nls ')' #call
    | ge_left=atom '[' nls ge_element=expr nls ']' #get_element
    | '[' nls a_elements=array_elements? nls ']' #typeless_array
    | '(' nls d_args=dictionary_args? nls ')' #typeless_dictionary
    | '+' p_value=atom  #positive
    | '-' n_value=atom  #negative
    | '-' '-' pd_value=atom  #pre_decrement
    | '+' '+' pi_value=atom  #pre_increment
    | pd_value=atom '-' '-' #post_decrement
    | pi_value=atom '+' '+' #post_increment
    | '!' n_value=atom  #not
    | '~' bn_value=atom  #bitwise_not
    | '(' nls n_value=expr nls ')' #nested;

value: atom #value_atom
     | a_left=value nls a_operation=arithmetic_op_mul nls a_right=value #arithmetic_mul
     | a_left=value nls a_operation=arithmetic_op_add nls a_right=value #arithmetic_add
     | b_left=value nls b_operation=bitwise_op nls b_right=value #bitwise
     | c_left=value nls c_operation=comparison_op nls c_right=value #comparison
     | t_left=value nls t_operation=test_op nls t_right=value #test
     ;

call_generics: type_value (',' type_value)*;

array_elements: array_element (nls ',' nls array_element)*;
array_element: ae_value=expr;

dictionary_args: dictionary_arg (nls ',' nls dictionary_arg)*;
dictionary_arg: (da_name_id=identifier | da_name_string=STRING) '=' da_value=expr;

expr: 'предок' nls '.' nls cp_id=identifier '(' nls (cp_args=args | cp_named_args=named_args)? nls ')' #call_parent
    | value #simple
    | a_left=atom 'як' a_right=type_value_item #as
    | t_value=value nls '?' nls t_positive=expr nls ':' nls t_negative=expr #ternary
    | atom ('та' atom)+ #god
    | 'чекати' w_value=value #wait
    | (f_async='тривала')? '(' nls f_params=params? nls ')' f_type=type_value? ':' nls f_body=expr #function
    | (d_async='тривала')? 'дія' (nls '<' nls d_generics=generics nls '>')? '(' nls d_params=params? nls ')' (d_type=type_value)? nl (d_body=body nl)? 'кінець' #anonymous_diia
    | mrm #expr_mrm
    ;

throw: 'впасти' t_value=expr;

assign: assign_simple | assign_by_identifier | assign_by_element;
assign_simple: (as_subject='субʼєкт')? as_identifier=identifier (as_type=type_value)? as_symbol=assign_symbol as_value=expr;
assign_by_identifier: abi_left=super_identifiers_chain nls '.' nls abi_identifier=identifier abi_symbol=assign_symbol abi_value=expr;
assign_by_element: abe_left=super_identifiers_chain '[' nls abe_index=expr nls ']' abe_symbol=assign_symbol abe_value=expr;
assign_symbol: 'це' | '=' | ':' '=' | '+' '=' | '-' '=' | '*' '=' | '/' '=' | '/' '/' '=' | '%' '=' | '*' '*' '=' | '&' '=' | '|' '=' | '<' '<' '=' | '>' '>' '=' | '^' '=' | '&' '&' '=' | '|' '|' '=' | '?' '?' '=';
wait_assign: 'чекати' wa_assign=assign;

identifiers_chain: ic_identifier=identifier | ic_left=identifiers_chain nls '.' nls ic_right=identifier;
super_identifiers_chain: sic_identifier=identifier
                       | sic_left=super_identifiers_chain nls '.' nls sic_right=identifier
                       | sic_left=super_identifiers_chain '[' nls sic_index=expr nls ']';

type_value: type_value_item (('|' | 'або') type_value_item)*;
type_value_item: type_value_item_simple | type_value_item_array;
type_value_item_simple: tvi_value=identifiers_chain ('<' tvi_generics=type_value_item_generics '>')?;
type_value_item_generics: type_value (',' type_value)*;
type_value_item_array: '[' ']' type_value_item;

args: arg (nls ',' nls arg)*;
arg: a_value=expr;
named_args: named_arg (nls ',' nls named_arg)*;
named_arg: na_name=identifier '=' na_value=expr;

params: param (nls ',' nls param)* (nls ',' nls p_variadic='.' '.' '.' p_variadic_name=identifier (p_variadic_type=type_value)?)?
      | p_variadic='.' '.' '.' p_variadic_name=identifier (p_variadic_type=type_value)?;
param: p_name=identifier (p_type=type_value)? ('=' p_value=param_value)?;
param_value: number_token #param_value_number
           | string #param_value_string
           | identifier #param_value_identifier
           | '(' ')' #param_value_empty_dictionary
           | '[' ']' #param_value_empty_list;

body: body_element_or_return (nl body_element_or_return)*;
body_element_or_return: body_element | return_body_line;
body_element: if | each | while | try | expr | throw | wait_assign | assign | nls;
return_body_line: 'вернути' rbl_value=expr;

arithmetic_op_mul: '*' | '/' | '%' | '/' '/' | '*' '*';
arithmetic_op_add: '+' | '-';
bitwise_op: '^' | '|' | '&' | '<' '<' | '>' '>';
test_op: 'і' | 'або' | '|' '|' | '&' '&';
comparison_op: '=' '=' | '!' '=' | '>' | '<' | '>' '=' | '<' '=' | 'є' | 'не' 'є' | 'рівно' | 'не' 'рівно' | 'більше' | 'не' 'більше' | 'менше' | 'не' 'менше' | 'містить' | 'не' 'містить';

comp_inst_block_program: COMP_INST_START cibp_name=identifier cibp_value=STRING nl cibp_program=program nl COMP_INST_END;
comp_inst_assign: COMP_INST_ASSIGN cia_name=identifier cia_value=STRING;