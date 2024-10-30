
// Generated from MavkaParser.g4 by ANTLR 4.13.0

#pragma once


#include "antlr4-runtime.h"
#include "MavkaParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by MavkaParser.
 */
class  MavkaParserListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterNl(MavkaParser::NlContext *ctx) = 0;
  virtual void exitNl(MavkaParser::NlContext *ctx) = 0;

  virtual void enterNls(MavkaParser::NlsContext *ctx) = 0;
  virtual void exitNls(MavkaParser::NlsContext *ctx) = 0;

  virtual void enterNumber(MavkaParser::NumberContext *ctx) = 0;
  virtual void exitNumber(MavkaParser::NumberContext *ctx) = 0;

  virtual void enterString(MavkaParser::StringContext *ctx) = 0;
  virtual void exitString(MavkaParser::StringContext *ctx) = 0;

  virtual void enterCharacter(MavkaParser::CharacterContext *ctx) = 0;
  virtual void exitCharacter(MavkaParser::CharacterContext *ctx) = 0;

  virtual void enterIdentifier(MavkaParser::IdentifierContext *ctx) = 0;
  virtual void exitIdentifier(MavkaParser::IdentifierContext *ctx) = 0;

  virtual void enterType(MavkaParser::TypeContext *ctx) = 0;
  virtual void exitType(MavkaParser::TypeContext *ctx) = 0;

  virtual void enterFile(MavkaParser::FileContext *ctx) = 0;
  virtual void exitFile(MavkaParser::FileContext *ctx) = 0;

  virtual void enterAssign(MavkaParser::AssignContext *ctx) = 0;
  virtual void exitAssign(MavkaParser::AssignContext *ctx) = 0;

  virtual void enterSet(MavkaParser::SetContext *ctx) = 0;
  virtual void exitSet(MavkaParser::SetContext *ctx) = 0;

  virtual void enterSet_by_access(MavkaParser::Set_by_accessContext *ctx) = 0;
  virtual void exitSet_by_access(MavkaParser::Set_by_accessContext *ctx) = 0;

  virtual void enterStructure(MavkaParser::StructureContext *ctx) = 0;
  virtual void exitStructure(MavkaParser::StructureContext *ctx) = 0;

  virtual void enterStructure_elements(MavkaParser::Structure_elementsContext *ctx) = 0;
  virtual void exitStructure_elements(MavkaParser::Structure_elementsContext *ctx) = 0;

  virtual void enterStructure_element(MavkaParser::Structure_elementContext *ctx) = 0;
  virtual void exitStructure_element(MavkaParser::Structure_elementContext *ctx) = 0;

  virtual void enterStructure_param(MavkaParser::Structure_paramContext *ctx) = 0;
  virtual void exitStructure_param(MavkaParser::Structure_paramContext *ctx) = 0;

  virtual void enterDiia(MavkaParser::DiiaContext *ctx) = 0;
  virtual void exitDiia(MavkaParser::DiiaContext *ctx) = 0;

  virtual void enterDiia_params(MavkaParser::Diia_paramsContext *ctx) = 0;
  virtual void exitDiia_params(MavkaParser::Diia_paramsContext *ctx) = 0;

  virtual void enterDiia_param(MavkaParser::Diia_paramContext *ctx) = 0;
  virtual void exitDiia_param(MavkaParser::Diia_paramContext *ctx) = 0;

  virtual void enterModule(MavkaParser::ModuleContext *ctx) = 0;
  virtual void exitModule(MavkaParser::ModuleContext *ctx) = 0;

  virtual void enterIf(MavkaParser::IfContext *ctx) = 0;
  virtual void exitIf(MavkaParser::IfContext *ctx) = 0;

  virtual void enterWhile(MavkaParser::WhileContext *ctx) = 0;
  virtual void exitWhile(MavkaParser::WhileContext *ctx) = 0;

  virtual void enterInterval(MavkaParser::IntervalContext *ctx) = 0;
  virtual void exitInterval(MavkaParser::IntervalContext *ctx) = 0;

  virtual void enterCycle(MavkaParser::CycleContext *ctx) = 0;
  virtual void exitCycle(MavkaParser::CycleContext *ctx) = 0;

  virtual void enterCycle_step(MavkaParser::Cycle_stepContext *ctx) = 0;
  virtual void exitCycle_step(MavkaParser::Cycle_stepContext *ctx) = 0;

  virtual void enterTry(MavkaParser::TryContext *ctx) = 0;
  virtual void exitTry(MavkaParser::TryContext *ctx) = 0;

  virtual void enterThrow(MavkaParser::ThrowContext *ctx) = 0;
  virtual void exitThrow(MavkaParser::ThrowContext *ctx) = 0;

  virtual void enterChain(MavkaParser::ChainContext *ctx) = 0;
  virtual void exitChain(MavkaParser::ChainContext *ctx) = 0;

  virtual void enterTake(MavkaParser::TakeContext *ctx) = 0;
  virtual void exitTake(MavkaParser::TakeContext *ctx) = 0;

  virtual void enterTake_elements(MavkaParser::Take_elementsContext *ctx) = 0;
  virtual void exitTake_elements(MavkaParser::Take_elementsContext *ctx) = 0;

  virtual void enterTake_element(MavkaParser::Take_elementContext *ctx) = 0;
  virtual void exitTake_element(MavkaParser::Take_elementContext *ctx) = 0;

  virtual void enterSubject_out(MavkaParser::Subject_outContext *ctx) = 0;
  virtual void exitSubject_out(MavkaParser::Subject_outContext *ctx) = 0;

  virtual void enterGet_out(MavkaParser::Get_outContext *ctx) = 0;
  virtual void exitGet_out(MavkaParser::Get_outContext *ctx) = 0;

  virtual void enterGeneric_out(MavkaParser::Generic_outContext *ctx) = 0;
  virtual void exitGeneric_out(MavkaParser::Generic_outContext *ctx) = 0;

  virtual void enterCall(MavkaParser::CallContext *ctx) = 0;
  virtual void exitCall(MavkaParser::CallContext *ctx) = 0;

  virtual void enterAccess(MavkaParser::AccessContext *ctx) = 0;
  virtual void exitAccess(MavkaParser::AccessContext *ctx) = 0;

  virtual void enterSubject(MavkaParser::SubjectContext *ctx) = 0;
  virtual void exitSubject(MavkaParser::SubjectContext *ctx) = 0;

  virtual void enterGet(MavkaParser::GetContext *ctx) = 0;
  virtual void exitGet(MavkaParser::GetContext *ctx) = 0;

  virtual void enterNested(MavkaParser::NestedContext *ctx) = 0;
  virtual void exitNested(MavkaParser::NestedContext *ctx) = 0;

  virtual void enterGeneric(MavkaParser::GenericContext *ctx) = 0;
  virtual void exitGeneric(MavkaParser::GenericContext *ctx) = 0;

  virtual void enterCall_args(MavkaParser::Call_argsContext *ctx) = 0;
  virtual void exitCall_args(MavkaParser::Call_argsContext *ctx) = 0;

  virtual void enterCall_arg(MavkaParser::Call_argContext *ctx) = 0;
  virtual void exitCall_arg(MavkaParser::Call_argContext *ctx) = 0;

  virtual void enterAtom_particle(MavkaParser::Atom_particleContext *ctx) = 0;
  virtual void exitAtom_particle(MavkaParser::Atom_particleContext *ctx) = 0;

  virtual void enterAtom_number(MavkaParser::Atom_numberContext *ctx) = 0;
  virtual void exitAtom_number(MavkaParser::Atom_numberContext *ctx) = 0;

  virtual void enterAtom_string(MavkaParser::Atom_stringContext *ctx) = 0;
  virtual void exitAtom_string(MavkaParser::Atom_stringContext *ctx) = 0;

  virtual void enterAtom_character(MavkaParser::Atom_characterContext *ctx) = 0;
  virtual void exitAtom_character(MavkaParser::Atom_characterContext *ctx) = 0;

  virtual void enterMolecule_atom(MavkaParser::Molecule_atomContext *ctx) = 0;
  virtual void exitMolecule_atom(MavkaParser::Molecule_atomContext *ctx) = 0;

  virtual void enterNot(MavkaParser::NotContext *ctx) = 0;
  virtual void exitNot(MavkaParser::NotContext *ctx) = 0;

  virtual void enterNegative(MavkaParser::NegativeContext *ctx) = 0;
  virtual void exitNegative(MavkaParser::NegativeContext *ctx) = 0;

  virtual void enterBitwise_not(MavkaParser::Bitwise_notContext *ctx) = 0;
  virtual void exitBitwise_not(MavkaParser::Bitwise_notContext *ctx) = 0;

  virtual void enterAdd(MavkaParser::AddContext *ctx) = 0;
  virtual void exitAdd(MavkaParser::AddContext *ctx) = 0;

  virtual void enterComparison(MavkaParser::ComparisonContext *ctx) = 0;
  virtual void exitComparison(MavkaParser::ComparisonContext *ctx) = 0;

  virtual void enterArray(MavkaParser::ArrayContext *ctx) = 0;
  virtual void exitArray(MavkaParser::ArrayContext *ctx) = 0;

  virtual void enterMul(MavkaParser::MulContext *ctx) = 0;
  virtual void exitMul(MavkaParser::MulContext *ctx) = 0;

  virtual void enterBitwise(MavkaParser::BitwiseContext *ctx) = 0;
  virtual void exitBitwise(MavkaParser::BitwiseContext *ctx) = 0;

  virtual void enterDict(MavkaParser::DictContext *ctx) = 0;
  virtual void exitDict(MavkaParser::DictContext *ctx) = 0;

  virtual void enterOperation_molecule(MavkaParser::Operation_moleculeContext *ctx) = 0;
  virtual void exitOperation_molecule(MavkaParser::Operation_moleculeContext *ctx) = 0;

  virtual void enterLogical(MavkaParser::LogicalContext *ctx) = 0;
  virtual void exitLogical(MavkaParser::LogicalContext *ctx) = 0;

  virtual void enterArray_elements(MavkaParser::Array_elementsContext *ctx) = 0;
  virtual void exitArray_elements(MavkaParser::Array_elementsContext *ctx) = 0;

  virtual void enterDict_elements(MavkaParser::Dict_elementsContext *ctx) = 0;
  virtual void exitDict_elements(MavkaParser::Dict_elementsContext *ctx) = 0;

  virtual void enterDict_element(MavkaParser::Dict_elementContext *ctx) = 0;
  virtual void exitDict_element(MavkaParser::Dict_elementContext *ctx) = 0;

  virtual void enterExpr_structure(MavkaParser::Expr_structureContext *ctx) = 0;
  virtual void exitExpr_structure(MavkaParser::Expr_structureContext *ctx) = 0;

  virtual void enterExpr_diia(MavkaParser::Expr_diiaContext *ctx) = 0;
  virtual void exitExpr_diia(MavkaParser::Expr_diiaContext *ctx) = 0;

  virtual void enterExpr_module(MavkaParser::Expr_moduleContext *ctx) = 0;
  virtual void exitExpr_module(MavkaParser::Expr_moduleContext *ctx) = 0;

  virtual void enterWait(MavkaParser::WaitContext *ctx) = 0;
  virtual void exitWait(MavkaParser::WaitContext *ctx) = 0;

  virtual void enterAs(MavkaParser::AsContext *ctx) = 0;
  virtual void exitAs(MavkaParser::AsContext *ctx) = 0;

  virtual void enterGod(MavkaParser::GodContext *ctx) = 0;
  virtual void exitGod(MavkaParser::GodContext *ctx) = 0;

  virtual void enterExpr_operation(MavkaParser::Expr_operationContext *ctx) = 0;
  virtual void exitExpr_operation(MavkaParser::Expr_operationContext *ctx) = 0;

  virtual void enterFunction(MavkaParser::FunctionContext *ctx) = 0;
  virtual void exitFunction(MavkaParser::FunctionContext *ctx) = 0;

  virtual void enterTernary(MavkaParser::TernaryContext *ctx) = 0;
  virtual void exitTernary(MavkaParser::TernaryContext *ctx) = 0;

  virtual void enterGive(MavkaParser::GiveContext *ctx) = 0;
  virtual void exitGive(MavkaParser::GiveContext *ctx) = 0;

  virtual void enterGive_element(MavkaParser::Give_elementContext *ctx) = 0;
  virtual void exitGive_element(MavkaParser::Give_elementContext *ctx) = 0;

  virtual void enterBody(MavkaParser::BodyContext *ctx) = 0;
  virtual void exitBody(MavkaParser::BodyContext *ctx) = 0;

  virtual void enterBody_element(MavkaParser::Body_elementContext *ctx) = 0;
  virtual void exitBody_element(MavkaParser::Body_elementContext *ctx) = 0;

  virtual void enterReturn_body_element(MavkaParser::Return_body_elementContext *ctx) = 0;
  virtual void exitReturn_body_element(MavkaParser::Return_body_elementContext *ctx) = 0;

  virtual void enterArithmetic_op_mul(MavkaParser::Arithmetic_op_mulContext *ctx) = 0;
  virtual void exitArithmetic_op_mul(MavkaParser::Arithmetic_op_mulContext *ctx) = 0;

  virtual void enterArithmetic_op_add(MavkaParser::Arithmetic_op_addContext *ctx) = 0;
  virtual void exitArithmetic_op_add(MavkaParser::Arithmetic_op_addContext *ctx) = 0;

  virtual void enterBitwise_op(MavkaParser::Bitwise_opContext *ctx) = 0;
  virtual void exitBitwise_op(MavkaParser::Bitwise_opContext *ctx) = 0;

  virtual void enterLogical_op(MavkaParser::Logical_opContext *ctx) = 0;
  virtual void exitLogical_op(MavkaParser::Logical_opContext *ctx) = 0;

  virtual void enterComparison_op(MavkaParser::Comparison_opContext *ctx) = 0;
  virtual void exitComparison_op(MavkaParser::Comparison_opContext *ctx) = 0;

  virtual void enterAssign_op(MavkaParser::Assign_opContext *ctx) = 0;
  virtual void exitAssign_op(MavkaParser::Assign_opContext *ctx) = 0;


};

