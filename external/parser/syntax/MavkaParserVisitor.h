
// Generated from MavkaParser.g4 by ANTLR 4.13.0

#pragma once


#include "antlr4-runtime.h"
#include "MavkaParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by MavkaParser.
 */
class  MavkaParserVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by MavkaParser.
   */
    virtual std::any visitNl(MavkaParser::NlContext *context) = 0;

    virtual std::any visitNls(MavkaParser::NlsContext *context) = 0;

    virtual std::any visitNumber(MavkaParser::NumberContext *context) = 0;

    virtual std::any visitString(MavkaParser::StringContext *context) = 0;

    virtual std::any visitCharacter(MavkaParser::CharacterContext *context) = 0;

    virtual std::any visitIdentifier(MavkaParser::IdentifierContext *context) = 0;

    virtual std::any visitType(MavkaParser::TypeContext *context) = 0;

    virtual std::any visitFile(MavkaParser::FileContext *context) = 0;

    virtual std::any visitAssign(MavkaParser::AssignContext *context) = 0;

    virtual std::any visitSet(MavkaParser::SetContext *context) = 0;

    virtual std::any visitSet_by_access(MavkaParser::Set_by_accessContext *context) = 0;

    virtual std::any visitStructure(MavkaParser::StructureContext *context) = 0;

    virtual std::any visitStructure_elements(MavkaParser::Structure_elementsContext *context) = 0;

    virtual std::any visitStructure_element(MavkaParser::Structure_elementContext *context) = 0;

    virtual std::any visitStructure_param(MavkaParser::Structure_paramContext *context) = 0;

    virtual std::any visitDiia(MavkaParser::DiiaContext *context) = 0;

    virtual std::any visitDiia_params(MavkaParser::Diia_paramsContext *context) = 0;

    virtual std::any visitDiia_param(MavkaParser::Diia_paramContext *context) = 0;

    virtual std::any visitModule(MavkaParser::ModuleContext *context) = 0;

    virtual std::any visitIf(MavkaParser::IfContext *context) = 0;

    virtual std::any visitWhile(MavkaParser::WhileContext *context) = 0;

    virtual std::any visitInterval(MavkaParser::IntervalContext *context) = 0;

    virtual std::any visitCycle(MavkaParser::CycleContext *context) = 0;

    virtual std::any visitCycle_step(MavkaParser::Cycle_stepContext *context) = 0;

    virtual std::any visitTry(MavkaParser::TryContext *context) = 0;

    virtual std::any visitThrow(MavkaParser::ThrowContext *context) = 0;

    virtual std::any visitChain(MavkaParser::ChainContext *context) = 0;

    virtual std::any visitTake(MavkaParser::TakeContext *context) = 0;

    virtual std::any visitTake_elements(MavkaParser::Take_elementsContext *context) = 0;

    virtual std::any visitTake_element(MavkaParser::Take_elementContext *context) = 0;

    virtual std::any visitSubject_out(MavkaParser::Subject_outContext *context) = 0;

    virtual std::any visitGet_out(MavkaParser::Get_outContext *context) = 0;

    virtual std::any visitGeneric_out(MavkaParser::Generic_outContext *context) = 0;

    virtual std::any visitCall(MavkaParser::CallContext *context) = 0;

    virtual std::any visitAccess(MavkaParser::AccessContext *context) = 0;

    virtual std::any visitSubject(MavkaParser::SubjectContext *context) = 0;

    virtual std::any visitGet(MavkaParser::GetContext *context) = 0;

    virtual std::any visitNested(MavkaParser::NestedContext *context) = 0;

    virtual std::any visitGeneric(MavkaParser::GenericContext *context) = 0;

    virtual std::any visitCall_args(MavkaParser::Call_argsContext *context) = 0;

    virtual std::any visitCall_arg(MavkaParser::Call_argContext *context) = 0;

    virtual std::any visitAtom_particle(MavkaParser::Atom_particleContext *context) = 0;

    virtual std::any visitAtom_number(MavkaParser::Atom_numberContext *context) = 0;

    virtual std::any visitAtom_string(MavkaParser::Atom_stringContext *context) = 0;

    virtual std::any visitAtom_character(MavkaParser::Atom_characterContext *context) = 0;

    virtual std::any visitMolecule_atom(MavkaParser::Molecule_atomContext *context) = 0;

    virtual std::any visitNot(MavkaParser::NotContext *context) = 0;

    virtual std::any visitNegative(MavkaParser::NegativeContext *context) = 0;

    virtual std::any visitBitwise_not(MavkaParser::Bitwise_notContext *context) = 0;

    virtual std::any visitAdd(MavkaParser::AddContext *context) = 0;

    virtual std::any visitComparison(MavkaParser::ComparisonContext *context) = 0;

    virtual std::any visitArray(MavkaParser::ArrayContext *context) = 0;

    virtual std::any visitMul(MavkaParser::MulContext *context) = 0;

    virtual std::any visitBitwise(MavkaParser::BitwiseContext *context) = 0;

    virtual std::any visitDict(MavkaParser::DictContext *context) = 0;

    virtual std::any visitOperation_molecule(MavkaParser::Operation_moleculeContext *context) = 0;

    virtual std::any visitLogical(MavkaParser::LogicalContext *context) = 0;

    virtual std::any visitArray_elements(MavkaParser::Array_elementsContext *context) = 0;

    virtual std::any visitDict_elements(MavkaParser::Dict_elementsContext *context) = 0;

    virtual std::any visitDict_element(MavkaParser::Dict_elementContext *context) = 0;

    virtual std::any visitExpr_structure(MavkaParser::Expr_structureContext *context) = 0;

    virtual std::any visitExpr_diia(MavkaParser::Expr_diiaContext *context) = 0;

    virtual std::any visitExpr_module(MavkaParser::Expr_moduleContext *context) = 0;

    virtual std::any visitWait(MavkaParser::WaitContext *context) = 0;

    virtual std::any visitAs(MavkaParser::AsContext *context) = 0;

    virtual std::any visitGod(MavkaParser::GodContext *context) = 0;

    virtual std::any visitExpr_operation(MavkaParser::Expr_operationContext *context) = 0;

    virtual std::any visitFunction(MavkaParser::FunctionContext *context) = 0;

    virtual std::any visitTernary(MavkaParser::TernaryContext *context) = 0;

    virtual std::any visitGive(MavkaParser::GiveContext *context) = 0;

    virtual std::any visitGive_element(MavkaParser::Give_elementContext *context) = 0;

    virtual std::any visitBody(MavkaParser::BodyContext *context) = 0;

    virtual std::any visitBody_element(MavkaParser::Body_elementContext *context) = 0;

    virtual std::any visitReturn_body_element(MavkaParser::Return_body_elementContext *context) = 0;

    virtual std::any visitArithmetic_op_mul(MavkaParser::Arithmetic_op_mulContext *context) = 0;

    virtual std::any visitArithmetic_op_add(MavkaParser::Arithmetic_op_addContext *context) = 0;

    virtual std::any visitBitwise_op(MavkaParser::Bitwise_opContext *context) = 0;

    virtual std::any visitLogical_op(MavkaParser::Logical_opContext *context) = 0;

    virtual std::any visitComparison_op(MavkaParser::Comparison_opContext *context) = 0;

    virtual std::any visitAssign_op(MavkaParser::Assign_opContext *context) = 0;


};

