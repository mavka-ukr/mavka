
// Generated from MavkaParser.g4 by ANTLR 4.13.0

#pragma once


#include "antlr4-runtime.h"
#include "MavkaParserVisitor.h"


/**
 * This class provides an empty implementation of MavkaParserVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  MavkaParserBaseVisitor : public MavkaParserVisitor {
public:

  virtual std::any visitNl(MavkaParser::NlContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNls(MavkaParser::NlsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNumber(MavkaParser::NumberContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitString(MavkaParser::StringContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCharacter(MavkaParser::CharacterContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIdentifier(MavkaParser::IdentifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitType(MavkaParser::TypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFile(MavkaParser::FileContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAssign(MavkaParser::AssignContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSet(MavkaParser::SetContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSet_by_access(MavkaParser::Set_by_accessContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStructure(MavkaParser::StructureContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStructure_elements(MavkaParser::Structure_elementsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStructure_element(MavkaParser::Structure_elementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStructure_param(MavkaParser::Structure_paramContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDiia(MavkaParser::DiiaContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDiia_params(MavkaParser::Diia_paramsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDiia_param(MavkaParser::Diia_paramContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitModule(MavkaParser::ModuleContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIf(MavkaParser::IfContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitWhile(MavkaParser::WhileContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitInterval(MavkaParser::IntervalContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCycle(MavkaParser::CycleContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCycle_step(MavkaParser::Cycle_stepContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTry(MavkaParser::TryContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitThrow(MavkaParser::ThrowContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitChain(MavkaParser::ChainContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTake(MavkaParser::TakeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTake_elements(MavkaParser::Take_elementsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTake_element(MavkaParser::Take_elementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSubject_out(MavkaParser::Subject_outContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitGet_out(MavkaParser::Get_outContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitGeneric_out(MavkaParser::Generic_outContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCall(MavkaParser::CallContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAccess(MavkaParser::AccessContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSubject(MavkaParser::SubjectContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitGet(MavkaParser::GetContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNested(MavkaParser::NestedContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitGeneric(MavkaParser::GenericContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCall_args(MavkaParser::Call_argsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCall_arg(MavkaParser::Call_argContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAtom_particle(MavkaParser::Atom_particleContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAtom_number(MavkaParser::Atom_numberContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAtom_string(MavkaParser::Atom_stringContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAtom_character(MavkaParser::Atom_characterContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMolecule_atom(MavkaParser::Molecule_atomContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNot(MavkaParser::NotContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNegative(MavkaParser::NegativeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBitwise_not(MavkaParser::Bitwise_notContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAdd(MavkaParser::AddContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitComparison(MavkaParser::ComparisonContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArray(MavkaParser::ArrayContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMul(MavkaParser::MulContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBitwise(MavkaParser::BitwiseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDict(MavkaParser::DictContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOperation_molecule(MavkaParser::Operation_moleculeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLogical(MavkaParser::LogicalContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArray_elements(MavkaParser::Array_elementsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDict_elements(MavkaParser::Dict_elementsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDict_element(MavkaParser::Dict_elementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExpr_structure(MavkaParser::Expr_structureContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExpr_diia(MavkaParser::Expr_diiaContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExpr_module(MavkaParser::Expr_moduleContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitWait(MavkaParser::WaitContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAs(MavkaParser::AsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitGod(MavkaParser::GodContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExpr_operation(MavkaParser::Expr_operationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFunction(MavkaParser::FunctionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTernary(MavkaParser::TernaryContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitGive(MavkaParser::GiveContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitGive_element(MavkaParser::Give_elementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBody(MavkaParser::BodyContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBody_element(MavkaParser::Body_elementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitReturn_body_element(MavkaParser::Return_body_elementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArithmetic_op_mul(MavkaParser::Arithmetic_op_mulContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArithmetic_op_add(MavkaParser::Arithmetic_op_addContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBitwise_op(MavkaParser::Bitwise_opContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLogical_op(MavkaParser::Logical_opContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitComparison_op(MavkaParser::Comparison_opContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAssign_op(MavkaParser::Assign_opContext *ctx) override {
    return visitChildren(ctx);
  }


};

