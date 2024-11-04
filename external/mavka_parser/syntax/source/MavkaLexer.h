
// Generated from MavkaLexer.g4 by ANTLR 4.13.0

#pragma once


#include "antlr4-runtime.h"




class  MavkaLexer : public antlr4::Lexer {
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
    DOUBLE_QUOTE = 59, EXCLAMATION = 60, COMA = 61, NUMBER = 62, INTEGER = 63, 
    FLOAT = 64, HEX = 65, BIN = 66, ID = 67, STRING_MULTILINE = 68, STRING = 69, 
    CHARACTER = 70, COMMENT = 71, LINE_COMMENT = 72, NL = 73, WS = 74
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

