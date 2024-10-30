
// Generated from MavkaParser.g4 by ANTLR 4.13.0

#pragma once


#include "antlr4-runtime.h"




class  MavkaParser : public antlr4::Parser {
public:
  enum {
    KW_END = 1, KW_DIIA = 2, KW_STRUCTURE = 3, KW_FOR = 4, KW_CYCLE = 5, 
    KW_IF = 6, KW_WAIT = 7, KW_TAKE = 8, KW_GIVE = 9, KW_AS = 10, KW_TA = 11, 
    KW_IS = 12, KW_SPEC = 13, KW_RETURN = 14, KW_ASYNC = 15, KW_SUBJECT = 16, 
    KW_AND = 17, KW_OR = 18, KW_TRY = 19, KW_CATCH = 20, KW_ELSE = 21, KW_THROW = 22, 
    KW_WHILE = 23, KW_MODULE = 24, KW_EQ_WORD = 25, KW_GR_WORD = 26, KW_SM_WORD = 27, 
    KW_HAS_WORD = 28, KW_MOCKUP = 29, KW_NOT = 30, KW_PARENT = 31, KW_TSE = 32, 
    KW_PERELIK = 33, KW_COMPOSITION = 34, KW_PUBLIC = 35, KW_PRIVATE = 36, 
    KW_PROTECTED = 37, KW_PROPERTY = 38, EQUAL = 39, GREATER = 40, LESSER = 41, 
    DOT = 42, PLUS = 43, MINUS = 44, MULTIPLY = 45, DIVIDE = 46, MOD = 47, 
    POWER = 48, AND = 49, OR = 50, PAREN_OPEN = 51, PAREN_CLOSE = 52, BRACKET_OPEN = 53, 
    BRACKET_CLOSE = 54, QUESTION = 55, COLON = 56, TILDA = 57, QUOTE = 58, 
    DOUBLE_QUOTE = 59, EXCLAMATION = 60, COMA = 61, INTEGER = 62, FLOAT = 63, 
    HEX = 64, BIN = 65, NUMBER = 66, ID = 67, KWID = 68, STRING_MULTILINE = 69, 
    STRING = 70, CHARACTER = 71, COMMENT = 72, LINE_COMMENT = 73, MRM_DIIA = 74, 
    NL = 75, WS = 76
  };

  enum {
    RuleNl = 0, RuleNls = 1, RuleNumber = 2, RuleString = 3, RuleCharacter = 4, 
    RuleIdentifier = 5, RuleType = 6, RuleFile = 7, RuleAssign = 8, RuleSet = 9, 
    RuleSet_by_access = 10, RuleStructure = 11, RuleStructure_elements = 12, 
    RuleStructure_element = 13, RuleStructure_param = 14, RuleDiia = 15, 
    RuleDiia_params = 16, RuleDiia_param = 17, RuleModule = 18, RuleIf = 19, 
    RuleWhile = 20, RuleInterval = 21, RuleCycle = 22, RuleCycle_step = 23, 
    RuleTry = 24, RuleThrow = 25, RuleChain = 26, RuleTake = 27, RuleTake_elements = 28, 
    RuleTake_element = 29, RuleSubject_out = 30, RuleGet_out = 31, RuleGeneric_out = 32, 
    RuleParticle = 33, RuleCall_args = 34, RuleCall_arg = 35, RuleAtom = 36, 
    RuleMolecule = 37, RuleOperation = 38, RuleArray_elements = 39, RuleDict_elements = 40, 
    RuleDict_element = 41, RuleExpr = 42, RuleGive = 43, RuleGive_element = 44, 
    RuleBody = 45, RuleBody_element = 46, RuleReturn_body_element = 47, 
    RuleArithmetic_op_mul = 48, RuleArithmetic_op_add = 49, RuleBitwise_op = 50, 
    RuleLogical_op = 51, RuleComparison_op = 52, RuleAssign_op = 53
  };

  explicit MavkaParser(antlr4::TokenStream *input);

  MavkaParser(antlr4::TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options);

  ~MavkaParser() override;

  std::string getGrammarFileName() const override;

  const antlr4::atn::ATN& getATN() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;


  class NlContext;
  class NlsContext;
  class NumberContext;
  class StringContext;
  class CharacterContext;
  class IdentifierContext;
  class TypeContext;
  class FileContext;
  class AssignContext;
  class SetContext;
  class Set_by_accessContext;
  class StructureContext;
  class Structure_elementsContext;
  class Structure_elementContext;
  class Structure_paramContext;
  class DiiaContext;
  class Diia_paramsContext;
  class Diia_paramContext;
  class ModuleContext;
  class IfContext;
  class WhileContext;
  class IntervalContext;
  class CycleContext;
  class Cycle_stepContext;
  class TryContext;
  class ThrowContext;
  class ChainContext;
  class TakeContext;
  class Take_elementsContext;
  class Take_elementContext;
  class Subject_outContext;
  class Get_outContext;
  class Generic_outContext;
  class ParticleContext;
  class Call_argsContext;
  class Call_argContext;
  class AtomContext;
  class MoleculeContext;
  class OperationContext;
  class Array_elementsContext;
  class Dict_elementsContext;
  class Dict_elementContext;
  class ExprContext;
  class GiveContext;
  class Give_elementContext;
  class BodyContext;
  class Body_elementContext;
  class Return_body_elementContext;
  class Arithmetic_op_mulContext;
  class Arithmetic_op_addContext;
  class Bitwise_opContext;
  class Logical_opContext;
  class Comparison_opContext;
  class Assign_opContext; 

  class  NlContext : public antlr4::ParserRuleContext {
  public:
    NlContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> NL();
    antlr4::tree::TerminalNode* NL(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  NlContext* nl();

  class  NlsContext : public antlr4::ParserRuleContext {
  public:
    NlsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> NL();
    antlr4::tree::TerminalNode* NL(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  NlsContext* nls();

  class  NumberContext : public antlr4::ParserRuleContext {
  public:
    NumberContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *INTEGER();
    antlr4::tree::TerminalNode *FLOAT();
    antlr4::tree::TerminalNode *HEX();
    antlr4::tree::TerminalNode *BIN();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  NumberContext* number();

  class  StringContext : public antlr4::ParserRuleContext {
  public:
    StringContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *STRING();
    antlr4::tree::TerminalNode *STRING_MULTILINE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StringContext* string();

  class  CharacterContext : public antlr4::ParserRuleContext {
  public:
    CharacterContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *CHARACTER();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CharacterContext* character();

  class  IdentifierContext : public antlr4::ParserRuleContext {
  public:
    IdentifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  IdentifierContext* identifier();

  class  TypeContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *t_nullable = nullptr;
    TypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Subject_outContext *subject_out();
    Get_outContext *get_out();
    Generic_outContext *generic_out();
    antlr4::tree::TerminalNode *QUESTION();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TypeContext* type();

  class  FileContext : public antlr4::ParserRuleContext {
  public:
    FileContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<NlsContext *> nls();
    NlsContext* nls(size_t i);
    BodyContext *body();
    antlr4::tree::TerminalNode *EOF();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FileContext* file();

  class  AssignContext : public antlr4::ParserRuleContext {
  public:
    MavkaParser::IdentifierContext *as_identifier = nullptr;
    MavkaParser::ExprContext *as_value = nullptr;
    AssignContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Assign_opContext *assign_op();
    IdentifierContext *identifier();
    ExprContext *expr();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AssignContext* assign();

  class  SetContext : public antlr4::ParserRuleContext {
  public:
    MavkaParser::ParticleContext *s_left = nullptr;
    MavkaParser::IdentifierContext *s_id = nullptr;
    MavkaParser::ExprContext *s_value = nullptr;
    SetContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Assign_opContext *assign_op();
    ParticleContext *particle();
    ExprContext *expr();
    antlr4::tree::TerminalNode *DOT();
    IdentifierContext *identifier();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SetContext* set();

  class  Set_by_accessContext : public antlr4::ParserRuleContext {
  public:
    MavkaParser::ParticleContext *s_left = nullptr;
    MavkaParser::ExprContext *s_id = nullptr;
    MavkaParser::ExprContext *s_value = nullptr;
    Set_by_accessContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *BRACKET_OPEN();
    antlr4::tree::TerminalNode *BRACKET_CLOSE();
    Assign_opContext *assign_op();
    ParticleContext *particle();
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Set_by_accessContext* set_by_access();

  class  StructureContext : public antlr4::ParserRuleContext {
  public:
    MavkaParser::IdentifierContext *s_name = nullptr;
    MavkaParser::IdentifierContext *s_parent = nullptr;
    MavkaParser::Structure_elementsContext *s_elements = nullptr;
    StructureContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *KW_STRUCTURE();
    std::vector<NlContext *> nl();
    NlContext* nl(size_t i);
    NlsContext *nls();
    antlr4::tree::TerminalNode *KW_END();
    antlr4::tree::TerminalNode *KW_IS();
    std::vector<IdentifierContext *> identifier();
    IdentifierContext* identifier(size_t i);
    Structure_elementsContext *structure_elements();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StructureContext* structure();

  class  Structure_elementsContext : public antlr4::ParserRuleContext {
  public:
    Structure_elementsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Structure_elementContext *> structure_element();
    Structure_elementContext* structure_element(size_t i);
    std::vector<NlContext *> nl();
    NlContext* nl(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Structure_elementsContext* structure_elements();

  class  Structure_elementContext : public antlr4::ParserRuleContext {
  public:
    Structure_elementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Structure_paramContext *structure_param();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Structure_elementContext* structure_element();

  class  Structure_paramContext : public antlr4::ParserRuleContext {
  public:
    MavkaParser::IdentifierContext *sp_name = nullptr;
    MavkaParser::TypeContext *sp_type = nullptr;
    MavkaParser::ExprContext *sp_value = nullptr;
    Structure_paramContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IdentifierContext *identifier();
    antlr4::tree::TerminalNode *EQUAL();
    TypeContext *type();
    ExprContext *expr();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Structure_paramContext* structure_param();

  class  DiiaContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *d_async = nullptr;
    antlr4::Token *d_spec = nullptr;
    MavkaParser::IdentifierContext *d_structure = nullptr;
    MavkaParser::IdentifierContext *d_name = nullptr;
    MavkaParser::Diia_paramsContext *d_params = nullptr;
    MavkaParser::TypeContext *d_type = nullptr;
    MavkaParser::BodyContext *d_body = nullptr;
    DiiaContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *KW_DIIA();
    antlr4::tree::TerminalNode *PAREN_OPEN();
    std::vector<NlsContext *> nls();
    NlsContext* nls(size_t i);
    antlr4::tree::TerminalNode *PAREN_CLOSE();
    std::vector<NlContext *> nl();
    NlContext* nl(size_t i);
    antlr4::tree::TerminalNode *KW_END();
    antlr4::tree::TerminalNode *KW_ASYNC();
    antlr4::tree::TerminalNode *KW_SPEC();
    std::vector<IdentifierContext *> identifier();
    IdentifierContext* identifier(size_t i);
    Diia_paramsContext *diia_params();
    TypeContext *type();
    BodyContext *body();
    antlr4::tree::TerminalNode *DOT();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DiiaContext* diia();

  class  Diia_paramsContext : public antlr4::ParserRuleContext {
  public:
    Diia_paramsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Diia_paramContext *> diia_param();
    Diia_paramContext* diia_param(size_t i);
    std::vector<NlsContext *> nls();
    NlsContext* nls(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMA();
    antlr4::tree::TerminalNode* COMA(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Diia_paramsContext* diia_params();

  class  Diia_paramContext : public antlr4::ParserRuleContext {
  public:
    MavkaParser::IdentifierContext *p_name = nullptr;
    MavkaParser::TypeContext *p_type = nullptr;
    MavkaParser::ExprContext *p_value = nullptr;
    Diia_paramContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IdentifierContext *identifier();
    antlr4::tree::TerminalNode *EQUAL();
    TypeContext *type();
    ExprContext *expr();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Diia_paramContext* diia_param();

  class  ModuleContext : public antlr4::ParserRuleContext {
  public:
    MavkaParser::IdentifierContext *m_name = nullptr;
    MavkaParser::BodyContext *m_body = nullptr;
    ModuleContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *KW_MODULE();
    std::vector<NlContext *> nl();
    NlContext* nl(size_t i);
    antlr4::tree::TerminalNode *KW_END();
    IdentifierContext *identifier();
    BodyContext *body();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ModuleContext* module();

  class  IfContext : public antlr4::ParserRuleContext {
  public:
    MavkaParser::ExprContext *i_value = nullptr;
    MavkaParser::BodyContext *i_body = nullptr;
    MavkaParser::BodyContext *i_else_body = nullptr;
    MavkaParser::IfContext *i_else_if = nullptr;
    IfContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *KW_IF();
    std::vector<NlContext *> nl();
    NlContext* nl(size_t i);
    ExprContext *expr();
    antlr4::tree::TerminalNode *KW_END();
    std::vector<BodyContext *> body();
    BodyContext* body(size_t i);
    antlr4::tree::TerminalNode *KW_ELSE();
    IfContext *if_();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  IfContext* if_();

  class  WhileContext : public antlr4::ParserRuleContext {
  public:
    MavkaParser::OperationContext *w_value = nullptr;
    MavkaParser::BodyContext *w_body = nullptr;
    WhileContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *KW_WHILE();
    std::vector<NlContext *> nl();
    NlContext* nl(size_t i);
    antlr4::tree::TerminalNode *KW_END();
    OperationContext *operation();
    BodyContext *body();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  WhileContext* while_();

  class  IntervalContext : public antlr4::ParserRuleContext {
  public:
    MavkaParser::OperationContext *i_left = nullptr;
    MavkaParser::OperationContext *i_right = nullptr;
    MavkaParser::IdentifierContext *i_id = nullptr;
    MavkaParser::BodyContext *e_body = nullptr;
    IntervalContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *KW_FOR();
    antlr4::tree::TerminalNode *KW_AS();
    std::vector<NlContext *> nl();
    NlContext* nl(size_t i);
    antlr4::tree::TerminalNode *KW_END();
    std::vector<OperationContext *> operation();
    OperationContext* operation(size_t i);
    IdentifierContext *identifier();
    std::vector<antlr4::tree::TerminalNode *> DOT();
    antlr4::tree::TerminalNode* DOT(size_t i);
    BodyContext *body();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  IntervalContext* interval();

  class  CycleContext : public antlr4::ParserRuleContext {
  public:
    MavkaParser::Cycle_stepContext *c_a = nullptr;
    MavkaParser::Cycle_stepContext *c_b = nullptr;
    MavkaParser::Cycle_stepContext *c_c = nullptr;
    MavkaParser::BodyContext *c_body = nullptr;
    CycleContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *KW_CYCLE();
    std::vector<NlContext *> nl();
    NlContext* nl(size_t i);
    antlr4::tree::TerminalNode *KW_END();
    std::vector<antlr4::tree::TerminalNode *> COMA();
    antlr4::tree::TerminalNode* COMA(size_t i);
    BodyContext *body();
    std::vector<Cycle_stepContext *> cycle_step();
    Cycle_stepContext* cycle_step(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CycleContext* cycle();

  class  Cycle_stepContext : public antlr4::ParserRuleContext {
  public:
    Cycle_stepContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    AssignContext *assign();
    SetContext *set();
    OperationContext *operation();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Cycle_stepContext* cycle_step();

  class  TryContext : public antlr4::ParserRuleContext {
  public:
    MavkaParser::BodyContext *t_body = nullptr;
    MavkaParser::IdentifierContext *t_name = nullptr;
    MavkaParser::BodyContext *t_catch_body = nullptr;
    TryContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *KW_TRY();
    std::vector<NlContext *> nl();
    NlContext* nl(size_t i);
    antlr4::tree::TerminalNode *KW_CATCH();
    antlr4::tree::TerminalNode *KW_END();
    std::vector<BodyContext *> body();
    BodyContext* body(size_t i);
    IdentifierContext *identifier();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TryContext* try_();

  class  ThrowContext : public antlr4::ParserRuleContext {
  public:
    MavkaParser::ExprContext *t_value = nullptr;
    ThrowContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *KW_THROW();
    ExprContext *expr();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ThrowContext* throw_();

  class  ChainContext : public antlr4::ParserRuleContext {
  public:
    ChainContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<IdentifierContext *> identifier();
    IdentifierContext* identifier(size_t i);
    std::vector<NlsContext *> nls();
    NlsContext* nls(size_t i);
    std::vector<antlr4::tree::TerminalNode *> DOT();
    antlr4::tree::TerminalNode* DOT(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ChainContext* chain();

  class  TakeContext : public antlr4::ParserRuleContext {
  public:
    MavkaParser::IdentifierContext *t_repo = nullptr;
    MavkaParser::ChainContext *t_chain = nullptr;
    MavkaParser::Take_elementsContext *t_elements = nullptr;
    MavkaParser::IdentifierContext *t_as = nullptr;
    TakeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *KW_TAKE();
    ChainContext *chain();
    std::vector<IdentifierContext *> identifier();
    IdentifierContext* identifier(size_t i);
    Take_elementsContext *take_elements();
    antlr4::tree::TerminalNode *KW_AS();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TakeContext* take();

  class  Take_elementsContext : public antlr4::ParserRuleContext {
  public:
    Take_elementsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *BRACKET_OPEN();
    std::vector<NlsContext *> nls();
    NlsContext* nls(size_t i);
    std::vector<Take_elementContext *> take_element();
    Take_elementContext* take_element(size_t i);
    antlr4::tree::TerminalNode *BRACKET_CLOSE();
    std::vector<antlr4::tree::TerminalNode *> COMA();
    antlr4::tree::TerminalNode* COMA(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Take_elementsContext* take_elements();

  class  Take_elementContext : public antlr4::ParserRuleContext {
  public:
    MavkaParser::IdentifierContext *te_name = nullptr;
    MavkaParser::IdentifierContext *te_as = nullptr;
    Take_elementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<IdentifierContext *> identifier();
    IdentifierContext* identifier(size_t i);
    antlr4::tree::TerminalNode *KW_AS();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Take_elementContext* take_element();

  class  Subject_outContext : public antlr4::ParserRuleContext {
  public:
    Subject_outContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IdentifierContext *identifier();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Subject_outContext* subject_out();

  class  Get_outContext : public antlr4::ParserRuleContext {
  public:
    MavkaParser::ParticleContext *g_left = nullptr;
    MavkaParser::IdentifierContext *g_id = nullptr;
    Get_outContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<NlsContext *> nls();
    NlsContext* nls(size_t i);
    antlr4::tree::TerminalNode *DOT();
    ParticleContext *particle();
    IdentifierContext *identifier();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Get_outContext* get_out();

  class  Generic_outContext : public antlr4::ParserRuleContext {
  public:
    MavkaParser::ParticleContext *g_left = nullptr;
    Generic_outContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<NlsContext *> nls();
    NlsContext* nls(size_t i);
    antlr4::tree::TerminalNode *LESSER();
    std::vector<TypeContext *> type();
    TypeContext* type(size_t i);
    ParticleContext *particle();
    std::vector<antlr4::tree::TerminalNode *> COMA();
    antlr4::tree::TerminalNode* COMA(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Generic_outContext* generic_out();

  class  ParticleContext : public antlr4::ParserRuleContext {
  public:
    ParticleContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    ParticleContext() = default;
    void copyFrom(ParticleContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  CallContext : public ParticleContext {
  public:
    CallContext(ParticleContext *ctx);

    MavkaParser::ParticleContext *c_value = nullptr;
    MavkaParser::Call_argsContext *c_args = nullptr;
    antlr4::tree::TerminalNode *PAREN_OPEN();
    std::vector<NlsContext *> nls();
    NlsContext* nls(size_t i);
    antlr4::tree::TerminalNode *PAREN_CLOSE();
    ParticleContext *particle();
    Call_argsContext *call_args();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  AccessContext : public ParticleContext {
  public:
    AccessContext(ParticleContext *ctx);

    MavkaParser::ParticleContext *a_left = nullptr;
    std::vector<NlsContext *> nls();
    NlsContext* nls(size_t i);
    antlr4::tree::TerminalNode *BRACKET_OPEN();
    ExprContext *expr();
    antlr4::tree::TerminalNode *BRACKET_CLOSE();
    ParticleContext *particle();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  SubjectContext : public ParticleContext {
  public:
    SubjectContext(ParticleContext *ctx);

    IdentifierContext *identifier();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  GetContext : public ParticleContext {
  public:
    GetContext(ParticleContext *ctx);

    MavkaParser::ParticleContext *g_left = nullptr;
    MavkaParser::IdentifierContext *g_id = nullptr;
    std::vector<NlsContext *> nls();
    NlsContext* nls(size_t i);
    antlr4::tree::TerminalNode *DOT();
    ParticleContext *particle();
    IdentifierContext *identifier();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  NestedContext : public ParticleContext {
  public:
    NestedContext(ParticleContext *ctx);

    MavkaParser::ExprContext *n_value = nullptr;
    antlr4::tree::TerminalNode *PAREN_OPEN();
    std::vector<NlsContext *> nls();
    NlsContext* nls(size_t i);
    antlr4::tree::TerminalNode *PAREN_CLOSE();
    ExprContext *expr();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  GenericContext : public ParticleContext {
  public:
    GenericContext(ParticleContext *ctx);

    MavkaParser::ParticleContext *g_left = nullptr;
    std::vector<NlsContext *> nls();
    NlsContext* nls(size_t i);
    antlr4::tree::TerminalNode *LESSER();
    std::vector<TypeContext *> type();
    TypeContext* type(size_t i);
    antlr4::tree::TerminalNode *GREATER();
    ParticleContext *particle();
    std::vector<antlr4::tree::TerminalNode *> COMA();
    antlr4::tree::TerminalNode* COMA(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  ParticleContext* particle();
  ParticleContext* particle(int precedence);
  class  Call_argsContext : public antlr4::ParserRuleContext {
  public:
    Call_argsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Call_argContext *> call_arg();
    Call_argContext* call_arg(size_t i);
    std::vector<NlsContext *> nls();
    NlsContext* nls(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMA();
    antlr4::tree::TerminalNode* COMA(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Call_argsContext* call_args();

  class  Call_argContext : public antlr4::ParserRuleContext {
  public:
    MavkaParser::ExprContext *ca_expr = nullptr;
    MavkaParser::IdentifierContext *ca_id = nullptr;
    Call_argContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExprContext *expr();
    std::vector<NlsContext *> nls();
    NlsContext* nls(size_t i);
    antlr4::tree::TerminalNode *EQUAL();
    IdentifierContext *identifier();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Call_argContext* call_arg();

  class  AtomContext : public antlr4::ParserRuleContext {
  public:
    AtomContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    AtomContext() = default;
    void copyFrom(AtomContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  Atom_particleContext : public AtomContext {
  public:
    Atom_particleContext(AtomContext *ctx);

    ParticleContext *particle();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Atom_characterContext : public AtomContext {
  public:
    Atom_characterContext(AtomContext *ctx);

    CharacterContext *character();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Atom_numberContext : public AtomContext {
  public:
    Atom_numberContext(AtomContext *ctx);

    NumberContext *number();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Atom_stringContext : public AtomContext {
  public:
    Atom_stringContext(AtomContext *ctx);

    StringContext *string();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  AtomContext* atom();

  class  MoleculeContext : public antlr4::ParserRuleContext {
  public:
    MoleculeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    MoleculeContext() = default;
    void copyFrom(MoleculeContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  Molecule_atomContext : public MoleculeContext {
  public:
    Molecule_atomContext(MoleculeContext *ctx);

    AtomContext *atom();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  NotContext : public MoleculeContext {
  public:
    NotContext(MoleculeContext *ctx);

    MavkaParser::MoleculeContext *n_value = nullptr;
    antlr4::tree::TerminalNode *EXCLAMATION();
    MoleculeContext *molecule();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  NegativeContext : public MoleculeContext {
  public:
    NegativeContext(MoleculeContext *ctx);

    MavkaParser::AtomContext *n_value = nullptr;
    antlr4::tree::TerminalNode *MINUS();
    AtomContext *atom();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Bitwise_notContext : public MoleculeContext {
  public:
    Bitwise_notContext(MoleculeContext *ctx);

    MavkaParser::AtomContext *bn_value = nullptr;
    antlr4::tree::TerminalNode *TILDA();
    AtomContext *atom();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  MoleculeContext* molecule();

  class  OperationContext : public antlr4::ParserRuleContext {
  public:
    OperationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    OperationContext() = default;
    void copyFrom(OperationContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  AddContext : public OperationContext {
  public:
    AddContext(OperationContext *ctx);

    MavkaParser::OperationContext *a_left = nullptr;
    MavkaParser::Arithmetic_op_addContext *a_operation = nullptr;
    MavkaParser::OperationContext *a_right = nullptr;
    std::vector<OperationContext *> operation();
    OperationContext* operation(size_t i);
    Arithmetic_op_addContext *arithmetic_op_add();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ComparisonContext : public OperationContext {
  public:
    ComparisonContext(OperationContext *ctx);

    MavkaParser::OperationContext *c_left = nullptr;
    MavkaParser::Comparison_opContext *c_operation = nullptr;
    MavkaParser::OperationContext *c_right = nullptr;
    std::vector<OperationContext *> operation();
    OperationContext* operation(size_t i);
    Comparison_opContext *comparison_op();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ArrayContext : public OperationContext {
  public:
    ArrayContext(OperationContext *ctx);

    antlr4::tree::TerminalNode *BRACKET_OPEN();
    std::vector<NlsContext *> nls();
    NlsContext* nls(size_t i);
    antlr4::tree::TerminalNode *BRACKET_CLOSE();
    Array_elementsContext *array_elements();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  MulContext : public OperationContext {
  public:
    MulContext(OperationContext *ctx);

    MavkaParser::OperationContext *a_left = nullptr;
    MavkaParser::Arithmetic_op_mulContext *a_operation = nullptr;
    MavkaParser::OperationContext *a_right = nullptr;
    std::vector<OperationContext *> operation();
    OperationContext* operation(size_t i);
    Arithmetic_op_mulContext *arithmetic_op_mul();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  BitwiseContext : public OperationContext {
  public:
    BitwiseContext(OperationContext *ctx);

    MavkaParser::OperationContext *b_left = nullptr;
    MavkaParser::Bitwise_opContext *b_operation = nullptr;
    MavkaParser::OperationContext *b_right = nullptr;
    std::vector<OperationContext *> operation();
    OperationContext* operation(size_t i);
    Bitwise_opContext *bitwise_op();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  DictContext : public OperationContext {
  public:
    DictContext(OperationContext *ctx);

    antlr4::tree::TerminalNode *PAREN_OPEN();
    std::vector<NlsContext *> nls();
    NlsContext* nls(size_t i);
    antlr4::tree::TerminalNode *PAREN_CLOSE();
    Dict_elementsContext *dict_elements();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Operation_moleculeContext : public OperationContext {
  public:
    Operation_moleculeContext(OperationContext *ctx);

    MoleculeContext *molecule();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  LogicalContext : public OperationContext {
  public:
    LogicalContext(OperationContext *ctx);

    MavkaParser::OperationContext *t_left = nullptr;
    MavkaParser::Logical_opContext *t_operation = nullptr;
    MavkaParser::OperationContext *t_right = nullptr;
    std::vector<OperationContext *> operation();
    OperationContext* operation(size_t i);
    Logical_opContext *logical_op();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  OperationContext* operation();
  OperationContext* operation(int precedence);
  class  Array_elementsContext : public antlr4::ParserRuleContext {
  public:
    Array_elementsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    std::vector<NlsContext *> nls();
    NlsContext* nls(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMA();
    antlr4::tree::TerminalNode* COMA(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Array_elementsContext* array_elements();

  class  Dict_elementsContext : public antlr4::ParserRuleContext {
  public:
    Dict_elementsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Dict_elementContext *> dict_element();
    Dict_elementContext* dict_element(size_t i);
    std::vector<NlsContext *> nls();
    NlsContext* nls(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMA();
    antlr4::tree::TerminalNode* COMA(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Dict_elementsContext* dict_elements();

  class  Dict_elementContext : public antlr4::ParserRuleContext {
  public:
    MavkaParser::StringContext *de_string = nullptr;
    MavkaParser::NumberContext *de_number = nullptr;
    MavkaParser::CharacterContext *de_character = nullptr;
    MavkaParser::ExprContext *de_value = nullptr;
    Dict_elementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<NlsContext *> nls();
    NlsContext* nls(size_t i);
    antlr4::tree::TerminalNode *EQUAL();
    ExprContext *expr();
    StringContext *string();
    NumberContext *number();
    CharacterContext *character();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Dict_elementContext* dict_element();

  class  ExprContext : public antlr4::ParserRuleContext {
  public:
    ExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    ExprContext() = default;
    void copyFrom(ExprContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  Expr_structureContext : public ExprContext {
  public:
    Expr_structureContext(ExprContext *ctx);

    StructureContext *structure();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  WaitContext : public ExprContext {
  public:
    WaitContext(ExprContext *ctx);

    MavkaParser::OperationContext *e_value = nullptr;
    antlr4::tree::TerminalNode *KW_WAIT();
    OperationContext *operation();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  AsContext : public ExprContext {
  public:
    AsContext(ExprContext *ctx);

    MavkaParser::MoleculeContext *a_left = nullptr;
    MavkaParser::TypeContext *a_type = nullptr;
    antlr4::tree::TerminalNode *KW_AS();
    MoleculeContext *molecule();
    TypeContext *type();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  FunctionContext : public ExprContext {
  public:
    FunctionContext(ExprContext *ctx);

    MavkaParser::Diia_paramsContext *f_params = nullptr;
    MavkaParser::TypeContext *f_type = nullptr;
    MavkaParser::ExprContext *f_body = nullptr;
    antlr4::tree::TerminalNode *PAREN_OPEN();
    std::vector<NlsContext *> nls();
    NlsContext* nls(size_t i);
    antlr4::tree::TerminalNode *PAREN_CLOSE();
    antlr4::tree::TerminalNode *COLON();
    ExprContext *expr();
    Diia_paramsContext *diia_params();
    TypeContext *type();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Expr_operationContext : public ExprContext {
  public:
    Expr_operationContext(ExprContext *ctx);

    OperationContext *operation();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  GodContext : public ExprContext {
  public:
    GodContext(ExprContext *ctx);

    std::vector<OperationContext *> operation();
    OperationContext* operation(size_t i);
    std::vector<NlsContext *> nls();
    NlsContext* nls(size_t i);
    std::vector<antlr4::tree::TerminalNode *> KW_TA();
    antlr4::tree::TerminalNode* KW_TA(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  TernaryContext : public ExprContext {
  public:
    TernaryContext(ExprContext *ctx);

    MavkaParser::OperationContext *t_value = nullptr;
    MavkaParser::ExprContext *t_positive = nullptr;
    MavkaParser::ExprContext *t_negative = nullptr;
    std::vector<NlsContext *> nls();
    NlsContext* nls(size_t i);
    antlr4::tree::TerminalNode *QUESTION();
    antlr4::tree::TerminalNode *COLON();
    OperationContext *operation();
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Expr_diiaContext : public ExprContext {
  public:
    Expr_diiaContext(ExprContext *ctx);

    DiiaContext *diia();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Expr_moduleContext : public ExprContext {
  public:
    Expr_moduleContext(ExprContext *ctx);

    ModuleContext *module();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  ExprContext* expr();

  class  GiveContext : public antlr4::ParserRuleContext {
  public:
    GiveContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *KW_GIVE();
    std::vector<Give_elementContext *> give_element();
    Give_elementContext* give_element(size_t i);
    std::vector<NlsContext *> nls();
    NlsContext* nls(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMA();
    antlr4::tree::TerminalNode* COMA(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  GiveContext* give();

  class  Give_elementContext : public antlr4::ParserRuleContext {
  public:
    MavkaParser::IdentifierContext *ge_name = nullptr;
    MavkaParser::IdentifierContext *ge_as = nullptr;
    Give_elementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<IdentifierContext *> identifier();
    IdentifierContext* identifier(size_t i);
    antlr4::tree::TerminalNode *KW_AS();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Give_elementContext* give_element();

  class  BodyContext : public antlr4::ParserRuleContext {
  public:
    BodyContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Body_elementContext *> body_element();
    Body_elementContext* body_element(size_t i);
    std::vector<NlContext *> nl();
    NlContext* nl(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  BodyContext* body();

  class  Body_elementContext : public antlr4::ParserRuleContext {
  public:
    Body_elementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IfContext *if_();
    WhileContext *while_();
    IntervalContext *interval();
    CycleContext *cycle();
    TryContext *try_();
    ThrowContext *throw_();
    AssignContext *assign();
    SetContext *set();
    Set_by_accessContext *set_by_access();
    ExprContext *expr();
    Return_body_elementContext *return_body_element();
    GiveContext *give();
    TakeContext *take();
    NlsContext *nls();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Body_elementContext* body_element();

  class  Return_body_elementContext : public antlr4::ParserRuleContext {
  public:
    MavkaParser::ExprContext *rbl_value = nullptr;
    Return_body_elementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *KW_RETURN();
    ExprContext *expr();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Return_body_elementContext* return_body_element();

  class  Arithmetic_op_mulContext : public antlr4::ParserRuleContext {
  public:
    Arithmetic_op_mulContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> MULTIPLY();
    antlr4::tree::TerminalNode* MULTIPLY(size_t i);
    std::vector<antlr4::tree::TerminalNode *> DIVIDE();
    antlr4::tree::TerminalNode* DIVIDE(size_t i);
    antlr4::tree::TerminalNode *MOD();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Arithmetic_op_mulContext* arithmetic_op_mul();

  class  Arithmetic_op_addContext : public antlr4::ParserRuleContext {
  public:
    Arithmetic_op_addContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *PLUS();
    antlr4::tree::TerminalNode *MINUS();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Arithmetic_op_addContext* arithmetic_op_add();

  class  Bitwise_opContext : public antlr4::ParserRuleContext {
  public:
    Bitwise_opContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *POWER();
    antlr4::tree::TerminalNode *OR();
    antlr4::tree::TerminalNode *AND();
    std::vector<antlr4::tree::TerminalNode *> LESSER();
    antlr4::tree::TerminalNode* LESSER(size_t i);
    std::vector<antlr4::tree::TerminalNode *> GREATER();
    antlr4::tree::TerminalNode* GREATER(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Bitwise_opContext* bitwise_op();

  class  Logical_opContext : public antlr4::ParserRuleContext {
  public:
    Logical_opContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *KW_AND();
    antlr4::tree::TerminalNode *KW_OR();
    std::vector<antlr4::tree::TerminalNode *> OR();
    antlr4::tree::TerminalNode* OR(size_t i);
    std::vector<antlr4::tree::TerminalNode *> AND();
    antlr4::tree::TerminalNode* AND(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Logical_opContext* logical_op();

  class  Comparison_opContext : public antlr4::ParserRuleContext {
  public:
    Comparison_opContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> EQUAL();
    antlr4::tree::TerminalNode* EQUAL(size_t i);
    antlr4::tree::TerminalNode *EXCLAMATION();
    antlr4::tree::TerminalNode *GREATER();
    antlr4::tree::TerminalNode *LESSER();
    antlr4::tree::TerminalNode *KW_IS();
    antlr4::tree::TerminalNode *KW_NOT();
    antlr4::tree::TerminalNode *KW_EQ_WORD();
    antlr4::tree::TerminalNode *KW_GR_WORD();
    antlr4::tree::TerminalNode *KW_SM_WORD();
    antlr4::tree::TerminalNode *KW_HAS_WORD();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Comparison_opContext* comparison_op();

  class  Assign_opContext : public antlr4::ParserRuleContext {
  public:
    Assign_opContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *KW_TSE();
    antlr4::tree::TerminalNode *EQUAL();
    antlr4::tree::TerminalNode *PLUS();
    antlr4::tree::TerminalNode *MINUS();
    std::vector<antlr4::tree::TerminalNode *> MULTIPLY();
    antlr4::tree::TerminalNode* MULTIPLY(size_t i);
    std::vector<antlr4::tree::TerminalNode *> DIVIDE();
    antlr4::tree::TerminalNode* DIVIDE(size_t i);
    antlr4::tree::TerminalNode *MOD();
    antlr4::tree::TerminalNode *POWER();
    antlr4::tree::TerminalNode *OR();
    antlr4::tree::TerminalNode *AND();
    std::vector<antlr4::tree::TerminalNode *> LESSER();
    antlr4::tree::TerminalNode* LESSER(size_t i);
    std::vector<antlr4::tree::TerminalNode *> GREATER();
    antlr4::tree::TerminalNode* GREATER(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Assign_opContext* assign_op();


  bool sempred(antlr4::RuleContext *_localctx, size_t ruleIndex, size_t predicateIndex) override;

  bool particleSempred(ParticleContext *_localctx, size_t predicateIndex);
  bool operationSempred(OperationContext *_localctx, size_t predicateIndex);

  // By default the static state used to implement the parser is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:
};

