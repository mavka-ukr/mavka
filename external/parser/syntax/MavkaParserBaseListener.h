
// Generated from MavkaParser.g4 by ANTLR 4.13.0

#pragma once


#include "antlr4-runtime.h"
#include "MavkaParserListener.h"


/**
 * This class provides an empty implementation of MavkaParserListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  MavkaParserBaseListener : public MavkaParserListener {
public:

  virtual void enterNl(MavkaParser::NlContext * /*ctx*/) override { }
  virtual void exitNl(MavkaParser::NlContext * /*ctx*/) override { }

  virtual void enterNls(MavkaParser::NlsContext * /*ctx*/) override { }
  virtual void exitNls(MavkaParser::NlsContext * /*ctx*/) override { }

  virtual void enterNumber(MavkaParser::NumberContext * /*ctx*/) override { }
  virtual void exitNumber(MavkaParser::NumberContext * /*ctx*/) override { }

  virtual void enterString(MavkaParser::StringContext * /*ctx*/) override { }
  virtual void exitString(MavkaParser::StringContext * /*ctx*/) override { }

  virtual void enterCharacter(MavkaParser::CharacterContext * /*ctx*/) override { }
  virtual void exitCharacter(MavkaParser::CharacterContext * /*ctx*/) override { }

  virtual void enterIdentifier(MavkaParser::IdentifierContext * /*ctx*/) override { }
  virtual void exitIdentifier(MavkaParser::IdentifierContext * /*ctx*/) override { }

  virtual void enterType(MavkaParser::TypeContext * /*ctx*/) override { }
  virtual void exitType(MavkaParser::TypeContext * /*ctx*/) override { }

  virtual void enterFile(MavkaParser::FileContext * /*ctx*/) override { }
  virtual void exitFile(MavkaParser::FileContext * /*ctx*/) override { }

  virtual void enterAssign(MavkaParser::AssignContext * /*ctx*/) override { }
  virtual void exitAssign(MavkaParser::AssignContext * /*ctx*/) override { }

  virtual void enterSet(MavkaParser::SetContext * /*ctx*/) override { }
  virtual void exitSet(MavkaParser::SetContext * /*ctx*/) override { }

  virtual void enterSet_by_access(MavkaParser::Set_by_accessContext * /*ctx*/) override { }
  virtual void exitSet_by_access(MavkaParser::Set_by_accessContext * /*ctx*/) override { }

  virtual void enterStructure(MavkaParser::StructureContext * /*ctx*/) override { }
  virtual void exitStructure(MavkaParser::StructureContext * /*ctx*/) override { }

  virtual void enterStructure_elements(MavkaParser::Structure_elementsContext * /*ctx*/) override { }
  virtual void exitStructure_elements(MavkaParser::Structure_elementsContext * /*ctx*/) override { }

  virtual void enterStructure_element(MavkaParser::Structure_elementContext * /*ctx*/) override { }
  virtual void exitStructure_element(MavkaParser::Structure_elementContext * /*ctx*/) override { }

  virtual void enterStructure_param(MavkaParser::Structure_paramContext * /*ctx*/) override { }
  virtual void exitStructure_param(MavkaParser::Structure_paramContext * /*ctx*/) override { }

  virtual void enterDiia(MavkaParser::DiiaContext * /*ctx*/) override { }
  virtual void exitDiia(MavkaParser::DiiaContext * /*ctx*/) override { }

  virtual void enterDiia_params(MavkaParser::Diia_paramsContext * /*ctx*/) override { }
  virtual void exitDiia_params(MavkaParser::Diia_paramsContext * /*ctx*/) override { }

  virtual void enterDiia_param(MavkaParser::Diia_paramContext * /*ctx*/) override { }
  virtual void exitDiia_param(MavkaParser::Diia_paramContext * /*ctx*/) override { }

  virtual void enterModule(MavkaParser::ModuleContext * /*ctx*/) override { }
  virtual void exitModule(MavkaParser::ModuleContext * /*ctx*/) override { }

  virtual void enterIf(MavkaParser::IfContext * /*ctx*/) override { }
  virtual void exitIf(MavkaParser::IfContext * /*ctx*/) override { }

  virtual void enterWhile(MavkaParser::WhileContext * /*ctx*/) override { }
  virtual void exitWhile(MavkaParser::WhileContext * /*ctx*/) override { }

  virtual void enterInterval(MavkaParser::IntervalContext * /*ctx*/) override { }
  virtual void exitInterval(MavkaParser::IntervalContext * /*ctx*/) override { }

  virtual void enterCycle(MavkaParser::CycleContext * /*ctx*/) override { }
  virtual void exitCycle(MavkaParser::CycleContext * /*ctx*/) override { }

  virtual void enterCycle_step(MavkaParser::Cycle_stepContext * /*ctx*/) override { }
  virtual void exitCycle_step(MavkaParser::Cycle_stepContext * /*ctx*/) override { }

  virtual void enterTry(MavkaParser::TryContext * /*ctx*/) override { }
  virtual void exitTry(MavkaParser::TryContext * /*ctx*/) override { }

  virtual void enterThrow(MavkaParser::ThrowContext * /*ctx*/) override { }
  virtual void exitThrow(MavkaParser::ThrowContext * /*ctx*/) override { }

  virtual void enterChain(MavkaParser::ChainContext * /*ctx*/) override { }
  virtual void exitChain(MavkaParser::ChainContext * /*ctx*/) override { }

  virtual void enterTake(MavkaParser::TakeContext * /*ctx*/) override { }
  virtual void exitTake(MavkaParser::TakeContext * /*ctx*/) override { }

  virtual void enterTake_elements(MavkaParser::Take_elementsContext * /*ctx*/) override { }
  virtual void exitTake_elements(MavkaParser::Take_elementsContext * /*ctx*/) override { }

  virtual void enterTake_element(MavkaParser::Take_elementContext * /*ctx*/) override { }
  virtual void exitTake_element(MavkaParser::Take_elementContext * /*ctx*/) override { }

  virtual void enterSubject_out(MavkaParser::Subject_outContext * /*ctx*/) override { }
  virtual void exitSubject_out(MavkaParser::Subject_outContext * /*ctx*/) override { }

  virtual void enterGet_out(MavkaParser::Get_outContext * /*ctx*/) override { }
  virtual void exitGet_out(MavkaParser::Get_outContext * /*ctx*/) override { }

  virtual void enterGeneric_out(MavkaParser::Generic_outContext * /*ctx*/) override { }
  virtual void exitGeneric_out(MavkaParser::Generic_outContext * /*ctx*/) override { }

  virtual void enterCall(MavkaParser::CallContext * /*ctx*/) override { }
  virtual void exitCall(MavkaParser::CallContext * /*ctx*/) override { }

  virtual void enterAccess(MavkaParser::AccessContext * /*ctx*/) override { }
  virtual void exitAccess(MavkaParser::AccessContext * /*ctx*/) override { }

  virtual void enterSubject(MavkaParser::SubjectContext * /*ctx*/) override { }
  virtual void exitSubject(MavkaParser::SubjectContext * /*ctx*/) override { }

  virtual void enterGet(MavkaParser::GetContext * /*ctx*/) override { }
  virtual void exitGet(MavkaParser::GetContext * /*ctx*/) override { }

  virtual void enterNested(MavkaParser::NestedContext * /*ctx*/) override { }
  virtual void exitNested(MavkaParser::NestedContext * /*ctx*/) override { }

  virtual void enterGeneric(MavkaParser::GenericContext * /*ctx*/) override { }
  virtual void exitGeneric(MavkaParser::GenericContext * /*ctx*/) override { }

  virtual void enterCall_args(MavkaParser::Call_argsContext * /*ctx*/) override { }
  virtual void exitCall_args(MavkaParser::Call_argsContext * /*ctx*/) override { }

  virtual void enterCall_arg(MavkaParser::Call_argContext * /*ctx*/) override { }
  virtual void exitCall_arg(MavkaParser::Call_argContext * /*ctx*/) override { }

  virtual void enterAtom_particle(MavkaParser::Atom_particleContext * /*ctx*/) override { }
  virtual void exitAtom_particle(MavkaParser::Atom_particleContext * /*ctx*/) override { }

  virtual void enterAtom_number(MavkaParser::Atom_numberContext * /*ctx*/) override { }
  virtual void exitAtom_number(MavkaParser::Atom_numberContext * /*ctx*/) override { }

  virtual void enterAtom_string(MavkaParser::Atom_stringContext * /*ctx*/) override { }
  virtual void exitAtom_string(MavkaParser::Atom_stringContext * /*ctx*/) override { }

  virtual void enterAtom_character(MavkaParser::Atom_characterContext * /*ctx*/) override { }
  virtual void exitAtom_character(MavkaParser::Atom_characterContext * /*ctx*/) override { }

  virtual void enterMolecule_atom(MavkaParser::Molecule_atomContext * /*ctx*/) override { }
  virtual void exitMolecule_atom(MavkaParser::Molecule_atomContext * /*ctx*/) override { }

  virtual void enterNot(MavkaParser::NotContext * /*ctx*/) override { }
  virtual void exitNot(MavkaParser::NotContext * /*ctx*/) override { }

  virtual void enterNegative(MavkaParser::NegativeContext * /*ctx*/) override { }
  virtual void exitNegative(MavkaParser::NegativeContext * /*ctx*/) override { }

  virtual void enterBitwise_not(MavkaParser::Bitwise_notContext * /*ctx*/) override { }
  virtual void exitBitwise_not(MavkaParser::Bitwise_notContext * /*ctx*/) override { }

  virtual void enterAdd(MavkaParser::AddContext * /*ctx*/) override { }
  virtual void exitAdd(MavkaParser::AddContext * /*ctx*/) override { }

  virtual void enterComparison(MavkaParser::ComparisonContext * /*ctx*/) override { }
  virtual void exitComparison(MavkaParser::ComparisonContext * /*ctx*/) override { }

  virtual void enterArray(MavkaParser::ArrayContext * /*ctx*/) override { }
  virtual void exitArray(MavkaParser::ArrayContext * /*ctx*/) override { }

  virtual void enterMul(MavkaParser::MulContext * /*ctx*/) override { }
  virtual void exitMul(MavkaParser::MulContext * /*ctx*/) override { }

  virtual void enterBitwise(MavkaParser::BitwiseContext * /*ctx*/) override { }
  virtual void exitBitwise(MavkaParser::BitwiseContext * /*ctx*/) override { }

  virtual void enterDict(MavkaParser::DictContext * /*ctx*/) override { }
  virtual void exitDict(MavkaParser::DictContext * /*ctx*/) override { }

  virtual void enterOperation_molecule(MavkaParser::Operation_moleculeContext * /*ctx*/) override { }
  virtual void exitOperation_molecule(MavkaParser::Operation_moleculeContext * /*ctx*/) override { }

  virtual void enterLogical(MavkaParser::LogicalContext * /*ctx*/) override { }
  virtual void exitLogical(MavkaParser::LogicalContext * /*ctx*/) override { }

  virtual void enterArray_elements(MavkaParser::Array_elementsContext * /*ctx*/) override { }
  virtual void exitArray_elements(MavkaParser::Array_elementsContext * /*ctx*/) override { }

  virtual void enterDict_elements(MavkaParser::Dict_elementsContext * /*ctx*/) override { }
  virtual void exitDict_elements(MavkaParser::Dict_elementsContext * /*ctx*/) override { }

  virtual void enterDict_element(MavkaParser::Dict_elementContext * /*ctx*/) override { }
  virtual void exitDict_element(MavkaParser::Dict_elementContext * /*ctx*/) override { }

  virtual void enterExpr_structure(MavkaParser::Expr_structureContext * /*ctx*/) override { }
  virtual void exitExpr_structure(MavkaParser::Expr_structureContext * /*ctx*/) override { }

  virtual void enterExpr_diia(MavkaParser::Expr_diiaContext * /*ctx*/) override { }
  virtual void exitExpr_diia(MavkaParser::Expr_diiaContext * /*ctx*/) override { }

  virtual void enterExpr_module(MavkaParser::Expr_moduleContext * /*ctx*/) override { }
  virtual void exitExpr_module(MavkaParser::Expr_moduleContext * /*ctx*/) override { }

  virtual void enterWait(MavkaParser::WaitContext * /*ctx*/) override { }
  virtual void exitWait(MavkaParser::WaitContext * /*ctx*/) override { }

  virtual void enterAs(MavkaParser::AsContext * /*ctx*/) override { }
  virtual void exitAs(MavkaParser::AsContext * /*ctx*/) override { }

  virtual void enterGod(MavkaParser::GodContext * /*ctx*/) override { }
  virtual void exitGod(MavkaParser::GodContext * /*ctx*/) override { }

  virtual void enterExpr_operation(MavkaParser::Expr_operationContext * /*ctx*/) override { }
  virtual void exitExpr_operation(MavkaParser::Expr_operationContext * /*ctx*/) override { }

  virtual void enterFunction(MavkaParser::FunctionContext * /*ctx*/) override { }
  virtual void exitFunction(MavkaParser::FunctionContext * /*ctx*/) override { }

  virtual void enterTernary(MavkaParser::TernaryContext * /*ctx*/) override { }
  virtual void exitTernary(MavkaParser::TernaryContext * /*ctx*/) override { }

  virtual void enterGive(MavkaParser::GiveContext * /*ctx*/) override { }
  virtual void exitGive(MavkaParser::GiveContext * /*ctx*/) override { }

  virtual void enterGive_element(MavkaParser::Give_elementContext * /*ctx*/) override { }
  virtual void exitGive_element(MavkaParser::Give_elementContext * /*ctx*/) override { }

  virtual void enterBody(MavkaParser::BodyContext * /*ctx*/) override { }
  virtual void exitBody(MavkaParser::BodyContext * /*ctx*/) override { }

  virtual void enterBody_element(MavkaParser::Body_elementContext * /*ctx*/) override { }
  virtual void exitBody_element(MavkaParser::Body_elementContext * /*ctx*/) override { }

  virtual void enterReturn_body_element(MavkaParser::Return_body_elementContext * /*ctx*/) override { }
  virtual void exitReturn_body_element(MavkaParser::Return_body_elementContext * /*ctx*/) override { }

  virtual void enterArithmetic_op_mul(MavkaParser::Arithmetic_op_mulContext * /*ctx*/) override { }
  virtual void exitArithmetic_op_mul(MavkaParser::Arithmetic_op_mulContext * /*ctx*/) override { }

  virtual void enterArithmetic_op_add(MavkaParser::Arithmetic_op_addContext * /*ctx*/) override { }
  virtual void exitArithmetic_op_add(MavkaParser::Arithmetic_op_addContext * /*ctx*/) override { }

  virtual void enterBitwise_op(MavkaParser::Bitwise_opContext * /*ctx*/) override { }
  virtual void exitBitwise_op(MavkaParser::Bitwise_opContext * /*ctx*/) override { }

  virtual void enterLogical_op(MavkaParser::Logical_opContext * /*ctx*/) override { }
  virtual void exitLogical_op(MavkaParser::Logical_opContext * /*ctx*/) override { }

  virtual void enterComparison_op(MavkaParser::Comparison_opContext * /*ctx*/) override { }
  virtual void exitComparison_op(MavkaParser::Comparison_opContext * /*ctx*/) override { }

  virtual void enterAssign_op(MavkaParser::Assign_opContext * /*ctx*/) override { }
  virtual void exitAssign_op(MavkaParser::Assign_opContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

