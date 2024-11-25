
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
    KW_PROTECTED = 37, KW_PROPERTY = 38, KW_DELETE = 39, KW_OWN = 40, EQUAL = 41, 
    GREATER = 42, LESSER = 43, DOT = 44, PLUS = 45, MINUS = 46, MULTIPLY = 47, 
    DIVIDE = 48, MOD = 49, POWER = 50, AND = 51, OR = 52, PAREN_OPEN = 53, 
    PAREN_CLOSE = 54, BRACKET_OPEN = 55, BRACKET_CLOSE = 56, QUESTION = 57, 
    COLON = 58, TILDA = 59, QUOTE = 60, DOUBLE_QUOTE = 61, EXCLAMATION = 62, 
    COMA = 63, NUMBER = 64, INTEGER = 65, FLOAT = 66, HEX = 67, BIN = 68, 
    ID = 69, STRING_MULTILINE = 70, STRING = 71, CHARACTER = 72, COMMENT = 73, 
    LINE_COMMENT = 74, NL = 75, WS = 76
  };

  enum {
    RuleFile = 0, RuleProgram = 1, RuleAtom = 2, RuleObject_arg = 3, RuleDict_arg = 4, 
    RuleCall_arg = 5, RuleOperation = 6, RuleOp_pow = 7, RuleOp_div_div = 8, 
    RuleOp_lshift = 9, RuleOp_rshift = 10, RuleOp_urshift = 11, RuleOp_lt = 12, 
    RuleOp_lte = 13, RuleOp_gt = 14, RuleOp_gte = 15, RuleOp_eq = 16, RuleOp_neq = 17, 
    RuleOp_land = 18, RuleOp_lor = 19, RuleOp_not_contains = 20, RuleOp_not_is = 21, 
    RuleGendef = 22, RuleExpr = 23, RuleStructure_define = 24, RuleStructure_element = 25, 
    RuleDiia_define = 26, RuleDiia_param = 27, RuleAssign = 28, RuleAssign_op = 29, 
    RuleSet = 30, RulePosition_set = 31, RuleIf = 32, RuleWhile = 33, RuleEach = 34, 
    RuleEach_range_value = 35, RuleEach_range = 36, RuleLoop_part = 37, 
    RuleLoop = 38, RuleBody = 39, RuleBody_element = 40, RuleReturn = 41, 
    RuleModule = 42, RuleType = 43, RuleTypes = 44, RuleParam = 45, RuleTake = 46, 
    RuleTake_part = 47, RuleTake_element = 48, RuleGive = 49, RuleGive_element = 50, 
    RuleTry = 51, RuleThrow = 52, RuleNl = 53, RuleNls = 54
  };

  explicit MavkaParser(antlr4::TokenStream *input);

  MavkaParser(antlr4::TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options);

  ~MavkaParser() override;

  std::string getGrammarFileName() const override;

  const antlr4::atn::ATN& getATN() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;


  class FileContext;
  class ProgramContext;
  class AtomContext;
  class Object_argContext;
  class Dict_argContext;
  class Call_argContext;
  class OperationContext;
  class Op_powContext;
  class Op_div_divContext;
  class Op_lshiftContext;
  class Op_rshiftContext;
  class Op_urshiftContext;
  class Op_ltContext;
  class Op_lteContext;
  class Op_gtContext;
  class Op_gteContext;
  class Op_eqContext;
  class Op_neqContext;
  class Op_landContext;
  class Op_lorContext;
  class Op_not_containsContext;
  class Op_not_isContext;
  class GendefContext;
  class ExprContext;
  class Structure_defineContext;
  class Structure_elementContext;
  class Diia_defineContext;
  class Diia_paramContext;
  class AssignContext;
  class Assign_opContext;
  class SetContext;
  class Position_setContext;
  class IfContext;
  class WhileContext;
  class EachContext;
  class Each_range_valueContext;
  class Each_rangeContext;
  class Loop_partContext;
  class LoopContext;
  class BodyContext;
  class Body_elementContext;
  class ReturnContext;
  class ModuleContext;
  class TypeContext;
  class TypesContext;
  class ParamContext;
  class TakeContext;
  class Take_partContext;
  class Take_elementContext;
  class GiveContext;
  class Give_elementContext;
  class TryContext;
  class ThrowContext;
  class NlContext;
  class NlsContext; 

  class  FileContext : public antlr4::ParserRuleContext {
  public:
    MavkaParser::ProgramContext *f_program = nullptr;
    FileContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EOF();
    ProgramContext *program();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FileContext* file();

  class  ProgramContext : public antlr4::ParserRuleContext {
  public:
    ProgramContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<NlsContext *> nls();
    NlsContext* nls(size_t i);
    std::vector<Body_elementContext *> body_element();
    Body_elementContext* body_element(size_t i);
    std::vector<NlContext *> nl();
    NlContext* nl(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ProgramContext* program();

  class  AtomContext : public antlr4::ParserRuleContext {
  public:
    AtomContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    AtomContext() = default;
    void copyFrom(AtomContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  Atom_nestedContext : public AtomContext {
  public:
    Atom_nestedContext(AtomContext *ctx);

    antlr4::tree::TerminalNode *PAREN_OPEN();
    std::vector<NlsContext *> nls();
    NlsContext* nls(size_t i);
    ExprContext *expr();
    antlr4::tree::TerminalNode *PAREN_CLOSE();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Operation_arrayContext : public AtomContext {
  public:
    Operation_arrayContext(AtomContext *ctx);

    antlr4::tree::TerminalNode *BRACKET_OPEN();
    std::vector<NlsContext *> nls();
    NlsContext* nls(size_t i);
    antlr4::tree::TerminalNode *BRACKET_CLOSE();
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMA();
    antlr4::tree::TerminalNode* COMA(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Operation_stringContext : public AtomContext {
  public:
    Operation_stringContext(AtomContext *ctx);

    antlr4::Token *tt = nullptr;
    antlr4::tree::TerminalNode *STRING();
    antlr4::tree::TerminalNode *ID();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Operation_dict_emptyContext : public AtomContext {
  public:
    Operation_dict_emptyContext(AtomContext *ctx);

    antlr4::tree::TerminalNode *BRACKET_OPEN();
    std::vector<NlsContext *> nls();
    NlsContext* nls(size_t i);
    antlr4::tree::TerminalNode *EQUAL();
    antlr4::tree::TerminalNode *BRACKET_CLOSE();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Operation_dictContext : public AtomContext {
  public:
    Operation_dictContext(AtomContext *ctx);

    antlr4::tree::TerminalNode *BRACKET_OPEN();
    std::vector<NlsContext *> nls();
    NlsContext* nls(size_t i);
    std::vector<Dict_argContext *> dict_arg();
    Dict_argContext* dict_arg(size_t i);
    antlr4::tree::TerminalNode *BRACKET_CLOSE();
    std::vector<antlr4::tree::TerminalNode *> COMA();
    antlr4::tree::TerminalNode* COMA(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Atom_getContext : public AtomContext {
  public:
    Atom_getContext(AtomContext *ctx);

    MavkaParser::AtomContext *object = nullptr;
    antlr4::Token *id = nullptr;
    std::vector<NlsContext *> nls();
    NlsContext* nls(size_t i);
    antlr4::tree::TerminalNode *DOT();
    AtomContext *atom();
    antlr4::tree::TerminalNode *ID();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Operation_string_multilineContext : public AtomContext {
  public:
    Operation_string_multilineContext(AtomContext *ctx);

    antlr4::Token *tt = nullptr;
    antlr4::tree::TerminalNode *STRING_MULTILINE();
    antlr4::tree::TerminalNode *ID();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Atom_subjectContext : public AtomContext {
  public:
    Atom_subjectContext(AtomContext *ctx);

    antlr4::Token *id = nullptr;
    antlr4::tree::TerminalNode *ID();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Atom_position_getContext : public AtomContext {
  public:
    Atom_position_getContext(AtomContext *ctx);

    MavkaParser::AtomContext *object = nullptr;
    MavkaParser::ExprContext *position = nullptr;
    std::vector<NlsContext *> nls();
    NlsContext* nls(size_t i);
    antlr4::tree::TerminalNode *BRACKET_OPEN();
    antlr4::tree::TerminalNode *BRACKET_CLOSE();
    AtomContext *atom();
    ExprContext *expr();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Operation_symbolContext : public AtomContext {
  public:
    Operation_symbolContext(AtomContext *ctx);

    antlr4::Token *tt = nullptr;
    antlr4::tree::TerminalNode *CHARACTER();
    antlr4::tree::TerminalNode *ID();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Atom_callContext : public AtomContext {
  public:
    Atom_callContext(AtomContext *ctx);

    MavkaParser::AtomContext *object = nullptr;
    antlr4::tree::TerminalNode *PAREN_OPEN();
    std::vector<NlsContext *> nls();
    NlsContext* nls(size_t i);
    antlr4::tree::TerminalNode *PAREN_CLOSE();
    AtomContext *atom();
    std::vector<Call_argContext *> call_arg();
    Call_argContext* call_arg(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMA();
    antlr4::tree::TerminalNode* COMA(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  AtomContext* atom();
  AtomContext* atom(int precedence);
  class  Object_argContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *id = nullptr;
    Object_argContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<NlsContext *> nls();
    NlsContext* nls(size_t i);
    antlr4::tree::TerminalNode *EQUAL();
    ExprContext *expr();
    antlr4::tree::TerminalNode *ID();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Object_argContext* object_arg();

  class  Dict_argContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *key_number = nullptr;
    antlr4::Token *key_string_tt = nullptr;
    antlr4::Token *key_string = nullptr;
    antlr4::Token *key_stringml_tt = nullptr;
    antlr4::Token *key_stringml = nullptr;
    antlr4::Token *key_symbol_tt = nullptr;
    antlr4::Token *key_symbol = nullptr;
    MavkaParser::ExprContext *value = nullptr;
    Dict_argContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<NlsContext *> nls();
    NlsContext* nls(size_t i);
    antlr4::tree::TerminalNode *EQUAL();
    ExprContext *expr();
    antlr4::tree::TerminalNode *NUMBER();
    antlr4::tree::TerminalNode *STRING();
    antlr4::tree::TerminalNode *STRING_MULTILINE();
    antlr4::tree::TerminalNode *CHARACTER();
    antlr4::tree::TerminalNode *ID();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Dict_argContext* dict_arg();

  class  Call_argContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *id = nullptr;
    Call_argContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExprContext *expr();
    std::vector<NlsContext *> nls();
    NlsContext* nls(size_t i);
    antlr4::tree::TerminalNode *EQUAL();
    antlr4::tree::TerminalNode *ID();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Call_argContext* call_arg();

  class  OperationContext : public antlr4::ParserRuleContext {
  public:
    OperationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    OperationContext() = default;
    void copyFrom(OperationContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  Operation_powContext : public OperationContext {
  public:
    Operation_powContext(OperationContext *ctx);

    MavkaParser::OperationContext *left = nullptr;
    MavkaParser::Op_powContext *op = nullptr;
    MavkaParser::OperationContext *right = nullptr;
    std::vector<NlsContext *> nls();
    NlsContext* nls(size_t i);
    std::vector<OperationContext *> operation();
    OperationContext* operation(size_t i);
    Op_powContext *op_pow();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Operation_gteContext : public OperationContext {
  public:
    Operation_gteContext(OperationContext *ctx);

    MavkaParser::OperationContext *left = nullptr;
    MavkaParser::Op_gteContext *op = nullptr;
    MavkaParser::OperationContext *right = nullptr;
    std::vector<NlsContext *> nls();
    NlsContext* nls(size_t i);
    std::vector<OperationContext *> operation();
    OperationContext* operation(size_t i);
    Op_gteContext *op_gte();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Operation_neqContext : public OperationContext {
  public:
    Operation_neqContext(OperationContext *ctx);

    MavkaParser::OperationContext *left = nullptr;
    MavkaParser::Op_neqContext *op = nullptr;
    MavkaParser::OperationContext *right = nullptr;
    std::vector<NlsContext *> nls();
    NlsContext* nls(size_t i);
    std::vector<OperationContext *> operation();
    OperationContext* operation(size_t i);
    Op_neqContext *op_neq();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Operation_xorContext : public OperationContext {
  public:
    Operation_xorContext(OperationContext *ctx);

    MavkaParser::OperationContext *left = nullptr;
    antlr4::Token *op = nullptr;
    MavkaParser::OperationContext *right = nullptr;
    std::vector<NlsContext *> nls();
    NlsContext* nls(size_t i);
    std::vector<OperationContext *> operation();
    OperationContext* operation(size_t i);
    antlr4::tree::TerminalNode *POWER();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Operation_lteContext : public OperationContext {
  public:
    Operation_lteContext(OperationContext *ctx);

    MavkaParser::OperationContext *left = nullptr;
    MavkaParser::Op_lteContext *op = nullptr;
    MavkaParser::OperationContext *right = nullptr;
    std::vector<NlsContext *> nls();
    NlsContext* nls(size_t i);
    std::vector<OperationContext *> operation();
    OperationContext* operation(size_t i);
    Op_lteContext *op_lte();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Operation_pre_plusContext : public OperationContext {
  public:
    Operation_pre_plusContext(OperationContext *ctx);

    antlr4::Token *op = nullptr;
    MavkaParser::OperationContext *right = nullptr;
    NlsContext *nls();
    antlr4::tree::TerminalNode *PLUS();
    OperationContext *operation();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Operation_addContext : public OperationContext {
  public:
    Operation_addContext(OperationContext *ctx);

    MavkaParser::OperationContext *left = nullptr;
    antlr4::Token *op = nullptr;
    MavkaParser::OperationContext *right = nullptr;
    std::vector<NlsContext *> nls();
    NlsContext* nls(size_t i);
    std::vector<OperationContext *> operation();
    OperationContext* operation(size_t i);
    antlr4::tree::TerminalNode *PLUS();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Operation_ltContext : public OperationContext {
  public:
    Operation_ltContext(OperationContext *ctx);

    MavkaParser::OperationContext *left = nullptr;
    MavkaParser::Op_ltContext *op = nullptr;
    MavkaParser::OperationContext *right = nullptr;
    std::vector<NlsContext *> nls();
    NlsContext* nls(size_t i);
    std::vector<OperationContext *> operation();
    OperationContext* operation(size_t i);
    Op_ltContext *op_lt();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Operation_pre_minusContext : public OperationContext {
  public:
    Operation_pre_minusContext(OperationContext *ctx);

    antlr4::Token *op = nullptr;
    MavkaParser::OperationContext *right = nullptr;
    NlsContext *nls();
    antlr4::tree::TerminalNode *MINUS();
    OperationContext *operation();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Operation_landContext : public OperationContext {
  public:
    Operation_landContext(OperationContext *ctx);

    MavkaParser::OperationContext *left = nullptr;
    MavkaParser::Op_landContext *op = nullptr;
    MavkaParser::OperationContext *right = nullptr;
    std::vector<NlsContext *> nls();
    NlsContext* nls(size_t i);
    std::vector<OperationContext *> operation();
    OperationContext* operation(size_t i);
    Op_landContext *op_land();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Operation_orContext : public OperationContext {
  public:
    Operation_orContext(OperationContext *ctx);

    MavkaParser::OperationContext *left = nullptr;
    antlr4::Token *op = nullptr;
    MavkaParser::OperationContext *right = nullptr;
    std::vector<NlsContext *> nls();
    NlsContext* nls(size_t i);
    std::vector<OperationContext *> operation();
    OperationContext* operation(size_t i);
    antlr4::tree::TerminalNode *OR();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Operation_pre_notContext : public OperationContext {
  public:
    Operation_pre_notContext(OperationContext *ctx);

    antlr4::Token *op = nullptr;
    MavkaParser::OperationContext *right = nullptr;
    NlsContext *nls();
    antlr4::tree::TerminalNode *EXCLAMATION();
    OperationContext *operation();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Operation_containsContext : public OperationContext {
  public:
    Operation_containsContext(OperationContext *ctx);

    MavkaParser::OperationContext *left = nullptr;
    antlr4::Token *op = nullptr;
    MavkaParser::OperationContext *right = nullptr;
    std::vector<NlsContext *> nls();
    NlsContext* nls(size_t i);
    std::vector<OperationContext *> operation();
    OperationContext* operation(size_t i);
    antlr4::tree::TerminalNode *KW_HAS_WORD();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Operation_delete_elementContext : public OperationContext {
  public:
    Operation_delete_elementContext(OperationContext *ctx);

    antlr4::Token *op = nullptr;
    MavkaParser::AtomContext *object = nullptr;
    MavkaParser::ExprContext *position = nullptr;
    std::vector<NlsContext *> nls();
    NlsContext* nls(size_t i);
    antlr4::tree::TerminalNode *BRACKET_OPEN();
    antlr4::tree::TerminalNode *BRACKET_CLOSE();
    antlr4::tree::TerminalNode *KW_DELETE();
    AtomContext *atom();
    ExprContext *expr();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Operation_delete_propContext : public OperationContext {
  public:
    Operation_delete_propContext(OperationContext *ctx);

    antlr4::Token *op = nullptr;
    MavkaParser::AtomContext *object = nullptr;
    antlr4::Token *id = nullptr;
    std::vector<NlsContext *> nls();
    NlsContext* nls(size_t i);
    antlr4::tree::TerminalNode *DOT();
    antlr4::tree::TerminalNode *KW_DELETE();
    AtomContext *atom();
    antlr4::tree::TerminalNode *ID();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Operation_waitContext : public OperationContext {
  public:
    Operation_waitContext(OperationContext *ctx);

    antlr4::Token *op = nullptr;
    MavkaParser::AtomContext *object = nullptr;
    NlsContext *nls();
    antlr4::tree::TerminalNode *KW_WAIT();
    AtomContext *atom();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Operation_div_divContext : public OperationContext {
  public:
    Operation_div_divContext(OperationContext *ctx);

    MavkaParser::OperationContext *left = nullptr;
    MavkaParser::Op_div_divContext *op = nullptr;
    MavkaParser::OperationContext *right = nullptr;
    std::vector<NlsContext *> nls();
    NlsContext* nls(size_t i);
    std::vector<OperationContext *> operation();
    OperationContext* operation(size_t i);
    Op_div_divContext *op_div_div();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Operation_not_isContext : public OperationContext {
  public:
    Operation_not_isContext(OperationContext *ctx);

    MavkaParser::OperationContext *left = nullptr;
    MavkaParser::Op_not_isContext *op = nullptr;
    MavkaParser::OperationContext *right = nullptr;
    std::vector<NlsContext *> nls();
    NlsContext* nls(size_t i);
    std::vector<OperationContext *> operation();
    OperationContext* operation(size_t i);
    Op_not_isContext *op_not_is();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Operation_atomContext : public OperationContext {
  public:
    Operation_atomContext(OperationContext *ctx);

    AtomContext *atom();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Operation_subContext : public OperationContext {
  public:
    Operation_subContext(OperationContext *ctx);

    MavkaParser::OperationContext *left = nullptr;
    antlr4::Token *op = nullptr;
    MavkaParser::OperationContext *right = nullptr;
    std::vector<NlsContext *> nls();
    NlsContext* nls(size_t i);
    std::vector<OperationContext *> operation();
    OperationContext* operation(size_t i);
    antlr4::tree::TerminalNode *MINUS();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Operation_modContext : public OperationContext {
  public:
    Operation_modContext(OperationContext *ctx);

    MavkaParser::OperationContext *left = nullptr;
    antlr4::Token *op = nullptr;
    MavkaParser::OperationContext *right = nullptr;
    std::vector<NlsContext *> nls();
    NlsContext* nls(size_t i);
    std::vector<OperationContext *> operation();
    OperationContext* operation(size_t i);
    antlr4::tree::TerminalNode *MOD();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Operation_isContext : public OperationContext {
  public:
    Operation_isContext(OperationContext *ctx);

    MavkaParser::OperationContext *left = nullptr;
    antlr4::Token *op = nullptr;
    MavkaParser::OperationContext *right = nullptr;
    std::vector<NlsContext *> nls();
    NlsContext* nls(size_t i);
    std::vector<OperationContext *> operation();
    OperationContext* operation(size_t i);
    antlr4::tree::TerminalNode *KW_IS();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Operation_mulContext : public OperationContext {
  public:
    Operation_mulContext(OperationContext *ctx);

    MavkaParser::OperationContext *left = nullptr;
    antlr4::Token *op = nullptr;
    MavkaParser::OperationContext *right = nullptr;
    std::vector<NlsContext *> nls();
    NlsContext* nls(size_t i);
    std::vector<OperationContext *> operation();
    OperationContext* operation(size_t i);
    antlr4::tree::TerminalNode *MULTIPLY();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Operation_gtContext : public OperationContext {
  public:
    Operation_gtContext(OperationContext *ctx);

    MavkaParser::OperationContext *left = nullptr;
    MavkaParser::Op_gtContext *op = nullptr;
    MavkaParser::OperationContext *right = nullptr;
    std::vector<NlsContext *> nls();
    NlsContext* nls(size_t i);
    std::vector<OperationContext *> operation();
    OperationContext* operation(size_t i);
    Op_gtContext *op_gt();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Operation_eqContext : public OperationContext {
  public:
    Operation_eqContext(OperationContext *ctx);

    MavkaParser::OperationContext *left = nullptr;
    MavkaParser::Op_eqContext *op = nullptr;
    MavkaParser::OperationContext *right = nullptr;
    std::vector<NlsContext *> nls();
    NlsContext* nls(size_t i);
    std::vector<OperationContext *> operation();
    OperationContext* operation(size_t i);
    Op_eqContext *op_eq();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Operation_delete_idContext : public OperationContext {
  public:
    Operation_delete_idContext(OperationContext *ctx);

    antlr4::Token *op = nullptr;
    antlr4::Token *id = nullptr;
    NlsContext *nls();
    antlr4::tree::TerminalNode *KW_DELETE();
    antlr4::tree::TerminalNode *ID();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Operation_pre_bw_notContext : public OperationContext {
  public:
    Operation_pre_bw_notContext(OperationContext *ctx);

    antlr4::Token *op = nullptr;
    MavkaParser::OperationContext *right = nullptr;
    NlsContext *nls();
    antlr4::tree::TerminalNode *TILDA();
    OperationContext *operation();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Operation_lorContext : public OperationContext {
  public:
    Operation_lorContext(OperationContext *ctx);

    MavkaParser::OperationContext *left = nullptr;
    MavkaParser::Op_lorContext *op = nullptr;
    MavkaParser::OperationContext *right = nullptr;
    std::vector<NlsContext *> nls();
    NlsContext* nls(size_t i);
    std::vector<OperationContext *> operation();
    OperationContext* operation(size_t i);
    Op_lorContext *op_lor();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Operation_ternaryContext : public OperationContext {
  public:
    Operation_ternaryContext(OperationContext *ctx);

    MavkaParser::OperationContext *cond = nullptr;
    MavkaParser::OperationContext *ifok = nullptr;
    MavkaParser::OperationContext *ifnot = nullptr;
    std::vector<NlsContext *> nls();
    NlsContext* nls(size_t i);
    antlr4::tree::TerminalNode *QUESTION();
    antlr4::tree::TerminalNode *COLON();
    std::vector<OperationContext *> operation();
    OperationContext* operation(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Operation_urshiftContext : public OperationContext {
  public:
    Operation_urshiftContext(OperationContext *ctx);

    MavkaParser::OperationContext *left = nullptr;
    MavkaParser::Op_urshiftContext *op = nullptr;
    MavkaParser::OperationContext *right = nullptr;
    std::vector<NlsContext *> nls();
    NlsContext* nls(size_t i);
    std::vector<OperationContext *> operation();
    OperationContext* operation(size_t i);
    Op_urshiftContext *op_urshift();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Operation_not_containsContext : public OperationContext {
  public:
    Operation_not_containsContext(OperationContext *ctx);

    MavkaParser::OperationContext *left = nullptr;
    MavkaParser::Op_not_containsContext *op = nullptr;
    MavkaParser::OperationContext *right = nullptr;
    std::vector<NlsContext *> nls();
    NlsContext* nls(size_t i);
    std::vector<OperationContext *> operation();
    OperationContext* operation(size_t i);
    Op_not_containsContext *op_not_contains();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Operation_divContext : public OperationContext {
  public:
    Operation_divContext(OperationContext *ctx);

    MavkaParser::OperationContext *left = nullptr;
    antlr4::Token *op = nullptr;
    MavkaParser::OperationContext *right = nullptr;
    std::vector<NlsContext *> nls();
    NlsContext* nls(size_t i);
    std::vector<OperationContext *> operation();
    OperationContext* operation(size_t i);
    antlr4::tree::TerminalNode *DIVIDE();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Operation_rshiftContext : public OperationContext {
  public:
    Operation_rshiftContext(OperationContext *ctx);

    MavkaParser::OperationContext *left = nullptr;
    MavkaParser::Op_rshiftContext *op = nullptr;
    MavkaParser::OperationContext *right = nullptr;
    std::vector<NlsContext *> nls();
    NlsContext* nls(size_t i);
    std::vector<OperationContext *> operation();
    OperationContext* operation(size_t i);
    Op_rshiftContext *op_rshift();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Operation_lshiftContext : public OperationContext {
  public:
    Operation_lshiftContext(OperationContext *ctx);

    MavkaParser::OperationContext *left = nullptr;
    MavkaParser::Op_lshiftContext *op = nullptr;
    MavkaParser::OperationContext *right = nullptr;
    std::vector<NlsContext *> nls();
    NlsContext* nls(size_t i);
    std::vector<OperationContext *> operation();
    OperationContext* operation(size_t i);
    Op_lshiftContext *op_lshift();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Operation_numberContext : public OperationContext {
  public:
    Operation_numberContext(OperationContext *ctx);

    antlr4::tree::TerminalNode *NUMBER();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Operation_andContext : public OperationContext {
  public:
    Operation_andContext(OperationContext *ctx);

    MavkaParser::OperationContext *left = nullptr;
    antlr4::Token *op = nullptr;
    MavkaParser::OperationContext *right = nullptr;
    std::vector<NlsContext *> nls();
    NlsContext* nls(size_t i);
    std::vector<OperationContext *> operation();
    OperationContext* operation(size_t i);
    antlr4::tree::TerminalNode *AND();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  OperationContext* operation();
  OperationContext* operation(int precedence);
  class  Op_powContext : public antlr4::ParserRuleContext {
  public:
    Op_powContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> MULTIPLY();
    antlr4::tree::TerminalNode* MULTIPLY(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Op_powContext* op_pow();

  class  Op_div_divContext : public antlr4::ParserRuleContext {
  public:
    Op_div_divContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> DIVIDE();
    antlr4::tree::TerminalNode* DIVIDE(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Op_div_divContext* op_div_div();

  class  Op_lshiftContext : public antlr4::ParserRuleContext {
  public:
    Op_lshiftContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> LESSER();
    antlr4::tree::TerminalNode* LESSER(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Op_lshiftContext* op_lshift();

  class  Op_rshiftContext : public antlr4::ParserRuleContext {
  public:
    Op_rshiftContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> GREATER();
    antlr4::tree::TerminalNode* GREATER(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Op_rshiftContext* op_rshift();

  class  Op_urshiftContext : public antlr4::ParserRuleContext {
  public:
    Op_urshiftContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> GREATER();
    antlr4::tree::TerminalNode* GREATER(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Op_urshiftContext* op_urshift();

  class  Op_ltContext : public antlr4::ParserRuleContext {
  public:
    Op_ltContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LESSER();
    antlr4::tree::TerminalNode *KW_SM_WORD();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Op_ltContext* op_lt();

  class  Op_lteContext : public antlr4::ParserRuleContext {
  public:
    Op_lteContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LESSER();
    antlr4::tree::TerminalNode *EQUAL();
    antlr4::tree::TerminalNode *KW_NOT();
    antlr4::tree::TerminalNode *KW_GR_WORD();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Op_lteContext* op_lte();

  class  Op_gtContext : public antlr4::ParserRuleContext {
  public:
    Op_gtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *GREATER();
    antlr4::tree::TerminalNode *KW_GR_WORD();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Op_gtContext* op_gt();

  class  Op_gteContext : public antlr4::ParserRuleContext {
  public:
    Op_gteContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *GREATER();
    antlr4::tree::TerminalNode *EQUAL();
    antlr4::tree::TerminalNode *KW_NOT();
    antlr4::tree::TerminalNode *KW_SM_WORD();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Op_gteContext* op_gte();

  class  Op_eqContext : public antlr4::ParserRuleContext {
  public:
    Op_eqContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> EQUAL();
    antlr4::tree::TerminalNode* EQUAL(size_t i);
    antlr4::tree::TerminalNode *KW_EQ_WORD();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Op_eqContext* op_eq();

  class  Op_neqContext : public antlr4::ParserRuleContext {
  public:
    Op_neqContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EXCLAMATION();
    antlr4::tree::TerminalNode *EQUAL();
    antlr4::tree::TerminalNode *KW_NOT();
    antlr4::tree::TerminalNode *KW_EQ_WORD();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Op_neqContext* op_neq();

  class  Op_landContext : public antlr4::ParserRuleContext {
  public:
    Op_landContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> AND();
    antlr4::tree::TerminalNode* AND(size_t i);
    antlr4::tree::TerminalNode *KW_AND();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Op_landContext* op_land();

  class  Op_lorContext : public antlr4::ParserRuleContext {
  public:
    Op_lorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> OR();
    antlr4::tree::TerminalNode* OR(size_t i);
    antlr4::tree::TerminalNode *KW_OR();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Op_lorContext* op_lor();

  class  Op_not_containsContext : public antlr4::ParserRuleContext {
  public:
    Op_not_containsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *KW_NOT();
    antlr4::tree::TerminalNode *KW_HAS_WORD();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Op_not_containsContext* op_not_contains();

  class  Op_not_isContext : public antlr4::ParserRuleContext {
  public:
    Op_not_isContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *KW_NOT();
    antlr4::tree::TerminalNode *KW_IS();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Op_not_isContext* op_not_is();

  class  GendefContext : public antlr4::ParserRuleContext {
  public:
    GendefContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  GendefContext* gendef();

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

    Structure_defineContext *structure_define();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  FunctionContext : public ExprContext {
  public:
    FunctionContext(ExprContext *ctx);

    MavkaParser::TypesContext *d_type = nullptr;
    MavkaParser::ExprContext *d_body = nullptr;
    antlr4::tree::TerminalNode *PAREN_OPEN();
    std::vector<NlsContext *> nls();
    NlsContext* nls(size_t i);
    antlr4::tree::TerminalNode *PAREN_CLOSE();
    antlr4::tree::TerminalNode *COLON();
    ExprContext *expr();
    std::vector<Diia_paramContext *> diia_param();
    Diia_paramContext* diia_param(size_t i);
    TypesContext *types();
    std::vector<antlr4::tree::TerminalNode *> COMA();
    antlr4::tree::TerminalNode* COMA(size_t i);
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

  class  Expr_diiaContext : public ExprContext {
  public:
    Expr_diiaContext(ExprContext *ctx);

    Diia_defineContext *diia_define();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  ExprContext* expr();

  class  Structure_defineContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *id = nullptr;
    MavkaParser::AtomContext *s_parent = nullptr;
    Structure_defineContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *KW_STRUCTURE();
    std::vector<NlContext *> nl();
    NlContext* nl(size_t i);
    std::vector<NlsContext *> nls();
    NlsContext* nls(size_t i);
    antlr4::tree::TerminalNode *KW_END();
    antlr4::tree::TerminalNode *KW_IS();
    std::vector<Structure_elementContext *> structure_element();
    Structure_elementContext* structure_element(size_t i);
    antlr4::tree::TerminalNode *ID();
    AtomContext *atom();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Structure_defineContext* structure_define();

  class  Structure_elementContext : public antlr4::ParserRuleContext {
  public:
    Structure_elementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ParamContext *param();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Structure_elementContext* structure_element();

  class  Diia_defineContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *d_async = nullptr;
    antlr4::Token *d_spec = nullptr;
    antlr4::Token *d_own = nullptr;
    antlr4::Token *d_structure = nullptr;
    antlr4::Token *d_name = nullptr;
    MavkaParser::TypesContext *d_type = nullptr;
    MavkaParser::BodyContext *d_body = nullptr;
    Diia_defineContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *KW_DIIA();
    antlr4::tree::TerminalNode *PAREN_OPEN();
    std::vector<NlsContext *> nls();
    NlsContext* nls(size_t i);
    antlr4::tree::TerminalNode *PAREN_CLOSE();
    std::vector<NlContext *> nl();
    NlContext* nl(size_t i);
    antlr4::tree::TerminalNode *KW_END();
    std::vector<Diia_paramContext *> diia_param();
    Diia_paramContext* diia_param(size_t i);
    antlr4::tree::TerminalNode *KW_ASYNC();
    antlr4::tree::TerminalNode *KW_SPEC();
    antlr4::tree::TerminalNode *KW_OWN();
    std::vector<antlr4::tree::TerminalNode *> ID();
    antlr4::tree::TerminalNode* ID(size_t i);
    TypesContext *types();
    BodyContext *body();
    antlr4::tree::TerminalNode *DOT();
    std::vector<antlr4::tree::TerminalNode *> COMA();
    antlr4::tree::TerminalNode* COMA(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Diia_defineContext* diia_define();

  class  Diia_paramContext : public antlr4::ParserRuleContext {
  public:
    Diia_paramContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ParamContext *param();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Diia_paramContext* diia_param();

  class  AssignContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *id = nullptr;
    antlr4::Token *parentas = nullptr;
    MavkaParser::ExprContext *value_expr = nullptr;
    AssignContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();
    Assign_opContext *assign_op();
    ExprContext *expr();
    antlr4::tree::TerminalNode *EQUAL();
    antlr4::tree::TerminalNode *COLON();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AssignContext* assign();

  class  Assign_opContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *aop_mul = nullptr;
    antlr4::Token *aop_div = nullptr;
    MavkaParser::Op_div_divContext *aop_div_div = nullptr;
    MavkaParser::Op_powContext *aop_pow = nullptr;
    antlr4::Token *aop_mod = nullptr;
    antlr4::Token *aop_plus = nullptr;
    antlr4::Token *aop_minus = nullptr;
    antlr4::Token *aop_and = nullptr;
    antlr4::Token *aop_xor = nullptr;
    antlr4::Token *aop_or = nullptr;
    antlr4::Token *aop_itis = nullptr;
    Assign_opContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EQUAL();
    Op_lshiftContext *op_lshift();
    Op_rshiftContext *op_rshift();
    Op_urshiftContext *op_urshift();
    antlr4::tree::TerminalNode *MULTIPLY();
    antlr4::tree::TerminalNode *DIVIDE();
    Op_div_divContext *op_div_div();
    Op_powContext *op_pow();
    antlr4::tree::TerminalNode *MOD();
    antlr4::tree::TerminalNode *PLUS();
    antlr4::tree::TerminalNode *MINUS();
    antlr4::tree::TerminalNode *AND();
    antlr4::tree::TerminalNode *POWER();
    antlr4::tree::TerminalNode *OR();
    antlr4::tree::TerminalNode *KW_TSE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Assign_opContext* assign_op();

  class  SetContext : public antlr4::ParserRuleContext {
  public:
    MavkaParser::AtomContext *object = nullptr;
    antlr4::Token *id = nullptr;
    MavkaParser::ExprContext *value_expr = nullptr;
    SetContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *DOT();
    Assign_opContext *assign_op();
    AtomContext *atom();
    antlr4::tree::TerminalNode *ID();
    ExprContext *expr();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SetContext* set();

  class  Position_setContext : public antlr4::ParserRuleContext {
  public:
    MavkaParser::AtomContext *object = nullptr;
    MavkaParser::ExprContext *idx = nullptr;
    MavkaParser::ExprContext *value_expr = nullptr;
    Position_setContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *BRACKET_OPEN();
    antlr4::tree::TerminalNode *BRACKET_CLOSE();
    Assign_opContext *assign_op();
    AtomContext *atom();
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Position_setContext* position_set();

  class  IfContext : public antlr4::ParserRuleContext {
  public:
    MavkaParser::ExprContext *cond = nullptr;
    MavkaParser::BodyContext *ifok = nullptr;
    MavkaParser::BodyContext *ifnot = nullptr;
    MavkaParser::IfContext *ifnotif = nullptr;
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
    MavkaParser::OperationContext *cond = nullptr;
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

  class  EachContext : public antlr4::ParserRuleContext {
  public:
    MavkaParser::AtomContext *object = nullptr;
    antlr4::Token *id = nullptr;
    MavkaParser::BodyContext *e_body = nullptr;
    EachContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *KW_FOR();
    antlr4::tree::TerminalNode *KW_AS();
    std::vector<NlContext *> nl();
    NlContext* nl(size_t i);
    antlr4::tree::TerminalNode *KW_END();
    antlr4::tree::TerminalNode *ID();
    Each_rangeContext *each_range();
    AtomContext *atom();
    BodyContext *body();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  EachContext* each();

  class  Each_range_valueContext : public antlr4::ParserRuleContext {
  public:
    MavkaParser::AtomContext *erv_atom = nullptr;
    antlr4::Token *erv_number = nullptr;
    Each_range_valueContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    AtomContext *atom();
    antlr4::tree::TerminalNode *NUMBER();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Each_range_valueContext* each_range_value();

  class  Each_rangeContext : public antlr4::ParserRuleContext {
  public:
    MavkaParser::Each_range_valueContext *from = nullptr;
    antlr4::Token *incl = nullptr;
    MavkaParser::Each_range_valueContext *to = nullptr;
    Each_rangeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> DOT();
    antlr4::tree::TerminalNode* DOT(size_t i);
    std::vector<Each_range_valueContext *> each_range_value();
    Each_range_valueContext* each_range_value(size_t i);
    antlr4::tree::TerminalNode *EQUAL();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Each_rangeContext* each_range();

  class  Loop_partContext : public antlr4::ParserRuleContext {
  public:
    Loop_partContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    AssignContext *assign();
    SetContext *set();
    Position_setContext *position_set();
    ExprContext *expr();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Loop_partContext* loop_part();

  class  LoopContext : public antlr4::ParserRuleContext {
  public:
    MavkaParser::Loop_partContext *start = nullptr;
    MavkaParser::OperationContext *cond = nullptr;
    MavkaParser::Loop_partContext *iter = nullptr;
    MavkaParser::BodyContext *w_body = nullptr;
    LoopContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *KW_CYCLE();
    std::vector<NlContext *> nl();
    NlContext* nl(size_t i);
    antlr4::tree::TerminalNode *KW_END();
    std::vector<NlsContext *> nls();
    NlsContext* nls(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMA();
    antlr4::tree::TerminalNode* COMA(size_t i);
    std::vector<Loop_partContext *> loop_part();
    Loop_partContext* loop_part(size_t i);
    OperationContext *operation();
    BodyContext *body();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  LoopContext* loop();

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
    Structure_defineContext *structure_define();
    Diia_defineContext *diia_define();
    AssignContext *assign();
    SetContext *set();
    Position_setContext *position_set();
    IfContext *if_();
    WhileContext *while_();
    EachContext *each();
    LoopContext *loop();
    ExprContext *expr();
    ReturnContext *return_();
    TryContext *try_();
    ThrowContext *throw_();
    TakeContext *take();
    ModuleContext *module();
    GiveContext *give();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Body_elementContext* body_element();

  class  ReturnContext : public antlr4::ParserRuleContext {
  public:
    MavkaParser::ExprContext *value_expr = nullptr;
    ReturnContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *KW_RETURN();
    ExprContext *expr();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ReturnContext* return_();

  class  ModuleContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *id = nullptr;
    MavkaParser::BodyContext *body_ = nullptr;
    ModuleContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *KW_MODULE();
    std::vector<NlContext *> nl();
    NlContext* nl(size_t i);
    antlr4::tree::TerminalNode *KW_END();
    antlr4::tree::TerminalNode *ID();
    BodyContext *body();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ModuleContext* module();

  class  TypeContext : public antlr4::ParserRuleContext {
  public:
    TypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    TypeContext() = default;
    void copyFrom(TypeContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  Type_getContext : public TypeContext {
  public:
    Type_getContext(TypeContext *ctx);

    MavkaParser::TypeContext *object = nullptr;
    antlr4::Token *id = nullptr;
    std::vector<NlsContext *> nls();
    NlsContext* nls(size_t i);
    antlr4::tree::TerminalNode *DOT();
    TypeContext *type();
    antlr4::tree::TerminalNode *ID();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Type_nestedContext : public TypeContext {
  public:
    Type_nestedContext(TypeContext *ctx);

    antlr4::tree::TerminalNode *PAREN_OPEN();
    std::vector<NlsContext *> nls();
    NlsContext* nls(size_t i);
    ExprContext *expr();
    antlr4::tree::TerminalNode *PAREN_CLOSE();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Type_subjectContext : public TypeContext {
  public:
    Type_subjectContext(TypeContext *ctx);

    antlr4::Token *id = nullptr;
    antlr4::tree::TerminalNode *ID();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  TypeContext* type();
  TypeContext* type(int precedence);
  class  TypesContext : public antlr4::ParserRuleContext {
  public:
    TypesContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<TypeContext *> type();
    TypeContext* type(size_t i);
    std::vector<NlsContext *> nls();
    NlsContext* nls(size_t i);
    std::vector<antlr4::tree::TerminalNode *> KW_OR();
    antlr4::tree::TerminalNode* KW_OR(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TypesContext* types();

  class  ParamContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *id = nullptr;
    ParamContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();
    TypesContext *types();
    antlr4::tree::TerminalNode *EQUAL();
    ExprContext *expr();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ParamContext* param();

  class  TakeContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *type_id = nullptr;
    antlr4::Token *as = nullptr;
    TakeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *KW_TAKE();
    std::vector<Take_partContext *> take_part();
    Take_partContext* take_part(size_t i);
    std::vector<antlr4::tree::TerminalNode *> DOT();
    antlr4::tree::TerminalNode* DOT(size_t i);
    std::vector<antlr4::tree::TerminalNode *> ID();
    antlr4::tree::TerminalNode* ID(size_t i);
    antlr4::tree::TerminalNode *KW_AS();
    antlr4::tree::TerminalNode *BRACKET_OPEN();
    std::vector<NlsContext *> nls();
    NlsContext* nls(size_t i);
    antlr4::tree::TerminalNode *BRACKET_CLOSE();
    std::vector<Take_elementContext *> take_element();
    Take_elementContext* take_element(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMA();
    antlr4::tree::TerminalNode* COMA(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TakeContext* take();

  class  Take_partContext : public antlr4::ParserRuleContext {
  public:
    Take_partContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *STRING();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Take_partContext* take_part();

  class  Take_elementContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *id = nullptr;
    antlr4::Token *as = nullptr;
    Take_elementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> ID();
    antlr4::tree::TerminalNode* ID(size_t i);
    antlr4::tree::TerminalNode *KW_AS();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Take_elementContext* take_element();

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
    antlr4::Token *id = nullptr;
    antlr4::Token *as = nullptr;
    Give_elementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> ID();
    antlr4::tree::TerminalNode* ID(size_t i);
    std::vector<NlsContext *> nls();
    NlsContext* nls(size_t i);
    antlr4::tree::TerminalNode *KW_AS();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Give_elementContext* give_element();

  class  TryContext : public antlr4::ParserRuleContext {
  public:
    MavkaParser::BodyContext *t_body = nullptr;
    antlr4::Token *t_name = nullptr;
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
    antlr4::tree::TerminalNode *ID();

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


  bool sempred(antlr4::RuleContext *_localctx, size_t ruleIndex, size_t predicateIndex) override;

  bool atomSempred(AtomContext *_localctx, size_t predicateIndex);
  bool operationSempred(OperationContext *_localctx, size_t predicateIndex);
  bool typeSempred(TypeContext *_localctx, size_t predicateIndex);

  // By default the static state used to implement the parser is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:
};

