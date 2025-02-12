
// Generated from MavkaLexer.g4 by ANTLR 4.13.0

#pragma once


#include "antlr4-runtime.h"




class  MavkaLexer : public antlr4::Lexer {
public:
  enum {
    KW_END = 1, KW_DIIA = 2, KW_STRUCTURE = 3, KW_FOR = 4, KW_CYCLE = 5, 
    KW_IF = 6, KW_WAIT = 7, KW_TAKE = 8, KW_GIVE = 9, KW_AS = 10, KW_TA = 11, 
    KW_IS = 12, KW_SPEC = 13, KW_RETURN = 14, KW_ASYNC = 15, KW_AND = 16, 
    KW_OR = 17, KW_TRY = 18, KW_CATCH = 19, KW_ELSE = 20, KW_THROW = 21, 
    KW_WHILE = 22, KW_MODULE = 23, KW_EQ_WORD = 24, KW_GR_WORD = 25, KW_SM_WORD = 26, 
    KW_HAS_WORD = 27, KW_MOCKUP = 28, KW_NOT = 29, KW_PARENT = 30, KW_TSE = 31, 
    KW_PERELIK = 32, KW_COMPOSITION = 33, KW_PUBLIC = 34, KW_PRIVATE = 35, 
    KW_PROTECTED = 36, KW_PROPERTY = 37, KW_DELETE = 38, KW_OWN = 39, EQUAL = 40, 
    GREATER = 41, LESSER = 42, DOT = 43, PLUS = 44, MINUS = 45, MULTIPLY = 46, 
    DIVIDE = 47, MOD = 48, POWER = 49, AND = 50, OR = 51, PAREN_OPEN = 52, 
    PAREN_CLOSE = 53, BRACKET_OPEN = 54, BRACKET_CLOSE = 55, QUESTION = 56, 
    COLON = 57, TILDA = 58, QUOTE = 59, DOUBLE_QUOTE = 60, EXCLAMATION = 61, 
    COMA = 62, NUMBER = 63, INTEGER = 64, FLOAT = 65, HEX = 66, BIN = 67, 
    ID = 68, STRING_MULTILINE = 69, STRING = 70, CHARACTER = 71, COMMENT = 72, 
    LINE_COMMENT = 73, NL = 74, WS = 75
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

