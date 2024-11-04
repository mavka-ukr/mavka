parser grammar MavkaParser;

options {
    tokenVocab=MavkaLexer;
}

nl: NL+;
nls: NL*;

number: INTEGER | FLOAT | HEX | BIN;
string: STRING | STRING_MULTILINE;
character: CHARACTER;
identifier: ID;
type: (t_nullable='?')? (subject_out | get_out | generic_out);

file: nls body nls EOF;

assign: as_identifier=identifier assign_op as_value=expr;

set: s_left=particle ('.' s_id=identifier) assign_op s_value=expr;

set_by_access: s_left=particle '[' s_id=expr ']' assign_op s_value=expr;

structure: 'структура' (s_name=identifier)? (KW_IS s_parent=identifier)? nl (s_elements=structure_elements nl)? nls KW_END;
structure_elements: structure_element (nl structure_element)*;
structure_element: structure_param;
structure_param: sp_name=identifier (sp_type=type)? ('=' sp_value=expr)?;

diia: (d_async=KW_ASYNC)? (d_spec=KW_SPEC)? KW_DIIA ((d_structure=identifier '.')? d_name=identifier)? '(' nls d_params=diia_params? nls ')' (d_type=type)? nl (d_body=body nl)? KW_END;
diia_params: diia_param (nls ',' nls diia_param)* (nls ',')?;
diia_param: p_name=identifier (p_type=type)? ('=' p_value=expr)?;

module: KW_MODULE (m_name=identifier)? nl (m_body=body nl)? KW_END;

if: KW_IF i_value=expr nl (i_body=body nl)? ((KW_ELSE nl i_else_body=body nl)? KW_END | (KW_ELSE i_else_if=if));

while: KW_WHILE w_value=operation nl (w_body=body nl)? KW_END;

interval: KW_FOR i_left=operation ('.' '.' i_right=operation)? KW_AS i_id=identifier nl (e_body=body nl)? KW_END;

cycle: KW_CYCLE ((c_a=cycle_step)? ',' (c_b=cycle_step)? ',' (c_c=cycle_step)?)? nl (c_body=body nl)? KW_END;
cycle_step: assign | set | operation;

try: KW_TRY nl (t_body=body nl)? KW_CATCH (t_name=identifier)? nl (t_catch_body=body nl)? KW_END;

throw: KW_THROW t_value=expr;

chain: identifier (nls '.' nls identifier)*;

take: KW_TAKE (t_repo=identifier)? t_chain=chain (t_elements=take_elements | (KW_AS t_as=identifier))?;
take_elements: '[' nls take_element (nls ',' nls take_element)* (nls ',')? nls ']';
take_element: te_name=identifier (KW_AS te_as=identifier)?;

subject_out: identifier;
get_out: g_left=particle nls '.' nls g_id=identifier;
generic_out: g_left=particle nls '<' nls type (nls ',' nls type)* nls;

particle: identifier #subject
        | g_left=particle nls '.' nls g_id=identifier #get
        | g_left=particle nls '<' nls type (nls ',' nls type)* nls '>' #generic
        | a_left=particle nls '[' nls expr nls ']' #access
        | c_value=particle '(' nls (c_args=call_args)? nls ')' #call
        | '(' nls n_value=expr nls ')' #nested;
call_args: call_arg (nls ',' nls call_arg)* (nls ',')?;
call_arg: ca_expr=expr | (ca_id=identifier nls '=' nls ca_expr=expr);

atom: particle #atom_particle
    | number #atom_number
    | string #atom_string
    | character #atom_character;

molecule: atom #molecule_atom
        | '!' n_value=molecule #not
        | '-' n_value=atom #negative
        | '~' bn_value=atom #bitwise_not;

operation: molecule #operation_molecule
         | '[' nls (array_elements)? nls ']' #array
         | '(' nls (dict_elements)? nls ')' #dict
         | a_left=operation a_operation=arithmetic_op_mul a_right=operation #mul
         | a_left=operation a_operation=arithmetic_op_add a_right=operation #add
         | b_left=operation b_operation=bitwise_op b_right=operation #bitwise
         | c_left=operation c_operation=comparison_op c_right=operation #comparison
         | t_left=operation t_operation=logical_op t_right=operation #logical;
array_elements: expr (nls ',' nls expr)* (nls ',')?;
dict_elements: dict_element (nls ',' nls dict_element)* (nls ',')?;
dict_element: (de_string=string | de_number=number | de_character=character) nls '=' nls de_value=expr;

expr: structure #expr_structure
    | diia #expr_diia
    | module #expr_module
    | KW_WAIT e_value=operation #wait
    | a_left=molecule KW_AS a_type=type #as
    | operation (nls KW_TA nls operation)+ #god
    | operation #expr_operation
    | '(' nls f_params=diia_params? nls ')' (f_type=type)? ':' nls f_body=expr #function
    | t_value=operation nls '?' nls t_positive=expr nls ':' nls t_negative=expr #ternary;

give: KW_GIVE give_element (nls ',' nls give_element)*;
give_element: ge_name=identifier (KW_AS ge_as=identifier)?;

body: body_element (nl body_element)*;
body_element: if | while | interval | cycle | try | throw | assign | set | set_by_access | expr | return_body_element | give | take | nls;
return_body_element: KW_RETURN (rbl_value=expr)?;

arithmetic_op_mul: '*' | '/' | '%' | '/' '/' | '*' '*';
arithmetic_op_add: '+' | '-';
bitwise_op: '^' | '|' | '&' | '<' '<' | '>' '>' | '>' '>' '>';
logical_op: KW_AND | KW_OR | '|' '|' | '&' '&';
comparison_op: '=' '=' | '!' '=' | '>' | '<' | '>' '=' | '<' '=' | KW_IS | KW_NOT KW_IS | KW_EQ_WORD | KW_NOT KW_EQ_WORD | KW_GR_WORD | KW_NOT KW_GR_WORD | KW_SM_WORD | KW_NOT KW_SM_WORD | KW_HAS_WORD | KW_NOT KW_HAS_WORD;
assign_op: KW_TSE | '=' | '+' '=' | '-' '=' | '*' '=' | '/' '=' | '%' '=' | '/' '/' '=' | '*' '*' '=' | '^' '=' | '|' '=' | '&' '=' | '<' '<' '=' | '>' '>' '=' | '>' '>' '>' '=';