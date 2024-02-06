
// Generated from MavkaLexer.g4 by ANTLR 4.13.0

#pragma once


#include "antlr4-runtime.h"




class  MavkaLexer : public antlr4::Lexer {
public:
  enum {
    KW_END = 1, KW_DIIA = 2, KW_STRUCTURE = 3, KW_FOR = 4, KW_IF = 5, KW_WAIT = 6, 
    KW_TAKE = 7, KW_GIVE = 8, KW_AS = 9, KW_TA = 10, KW_IS = 11, KW_SPEC = 12, 
    KW_RETURN = 13, KW_ASYNC = 14, KW_SUBJECT = 15, KW_AND = 16, KW_OR = 17, 
    KW_TRY = 18, KW_CATCH = 19, KW_ELSE = 20, KW_THROW = 21, KW_WHILE = 22, 
    KW_MODULE = 23, KW_EQ_WORD = 24, KW_GR_WORD = 25, KW_SM_WORD = 26, KW_HAS_IS_WORD = 27, 
    KW_MOCKUP = 28, KW_NOT = 29, KW_JS = 30, KW_PARENT = 31, KW_TSE = 32, 
    EQUAL = 33, GREATER = 34, LESSER = 35, DOT = 36, PLUS = 37, MINUS = 38, 
    MULTIPLY = 39, DIVIDE = 40, MOD = 41, POWER = 42, AND = 43, OR = 44, 
    PAREN_OPEN = 45, PAREN_CLOSE = 46, BRACKET_OPEN = 47, BRACKET_CLOSE = 48, 
    QUESTION = 49, COLON = 50, TILDA = 51, QUOTE = 52, DOUBLE_QUOTE = 53, 
    EXCLAMATION = 54, COMA = 55, INTEGER = 56, FLOAT = 57, HEX = 58, BIN = 59, 
    NUMBER = 60, ID = 61, KWID = 62, STRING_MULTILINE = 63, STRING = 64, 
    COMP_INST_START = 65, COMP_INST_END = 66, COMP_INST_ASSIGN = 67, COMMENT = 68, 
    LINE_COMMENT = 69, MRM_DIIA = 70, NL = 71, WS = 72
  };

  explicit MavkaLexer(antlr4::CharStream *input);

  ~MavkaLexer() override;


  std::string getGrammarFileName() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const std::vector<std::string>& getChannelNames() const override;

  const std::vector<std::string>& getModeNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;

  const antlr4::atn::ATN& getATN() const override;

  // By default the static state used to implement the lexer is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:

  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

};

