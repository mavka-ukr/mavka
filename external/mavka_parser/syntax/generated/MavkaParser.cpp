
// Generated from MavkaParser.g4 by ANTLR 4.13.0


#include "MavkaParserListener.h"
#include "MavkaParserVisitor.h"

#include "MavkaParser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct MavkaParserStaticData final {
  MavkaParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  MavkaParserStaticData(const MavkaParserStaticData&) = delete;
  MavkaParserStaticData(MavkaParserStaticData&&) = delete;
  MavkaParserStaticData& operator=(const MavkaParserStaticData&) = delete;
  MavkaParserStaticData& operator=(MavkaParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag mavkaparserParserOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
MavkaParserStaticData *mavkaparserParserStaticData = nullptr;

void mavkaparserParserInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (mavkaparserParserStaticData != nullptr) {
    return;
  }
#else
  assert(mavkaparserParserStaticData == nullptr);
#endif
  auto staticData = std::make_unique<MavkaParserStaticData>(
    std::vector<std::string>{
      "file", "program", "atom", "object_arg", "dict_arg", "call_arg", "operation", 
      "op_lshift", "op_rshift", "op_urshift", "op_lte", "op_gte", "op_eq", 
      "op_neq", "op_land", "op_lor", "gendef", "expr", "structure_define", 
      "structure_element", "diia_define", "diia_param", "assign", "set", 
      "position_set", "if", "while", "body", "body_element", "return", "type", 
      "param", "take", "take_element", "nl", "nls"
    },
    std::vector<std::string>{
      "", "'\\u043A\\u0456\\u043D\\u0435\\u0446\\u044C'", "'\\u0434\\u0456\\u044F'", 
      "'\\u0441\\u0442\\u0440\\u0443\\u043A\\u0442\\u0443\\u0440\\u0430'", 
      "'\\u043F\\u0435\\u0440\\u0435\\u0431\\u0440\\u0430\\u0442\\u0438'", 
      "'\\u0446\\u0438\\u043A\\u043B'", "'\\u044F\\u043A\\u0449\\u043E'", 
      "'\\u0447\\u0435\\u043A\\u0430\\u0442\\u0438'", "'\\u0432\\u0437\\u044F\\u0442\\u0438'", 
      "'\\u0434\\u0430\\u0442\\u0438'", "'\\u044F\\u043A'", "'\\u0442\\u0430'", 
      "'\\u0454'", "'\\u0441\\u043F\\u0435\\u0446'", "'\\u0432\\u0435\\u0440\\u043D\\u0443\\u0442\\u0438'", 
      "'\\u0442\\u0440\\u0438\\u0432\\u0430\\u043B\\u0430'", "'\\u0441\\u0443\\u0431\\u02BC\\u0454\\u043A\\u0442'", 
      "'\\u0456'", "'\\u0430\\u0431\\u043E'", "'\\u0441\\u043F\\u0440\\u043E\\u0431\\u0443\\u0432\\u0430\\u0442\\u0438'", 
      "'\\u0437\\u043B\\u043E\\u0432\\u0438\\u0442\\u0438'", "'\\u0456\\u043D\\u0430\\u043A\\u0448\\u0435'", 
      "'\\u0432\\u043F\\u0430\\u0441\\u0442\\u0438'", "'\\u043F\\u043E\\u043A\\u0438'", 
      "'\\u043C\\u043E\\u0434\\u0443\\u043B\\u044C'", "'\\u0440\\u0456\\u0432\\u043D\\u043E'", 
      "'\\u0431\\u0456\\u043B\\u044C\\u0448\\u0435'", "'\\u043C\\u0435\\u043D\\u0448\\u0435'", 
      "'\\u043C\\u0456\\u0441\\u0442\\u0438\\u0442\\u044C'", "'\\u043C\\u0430\\u043A\\u0435\\u0442'", 
      "'\\u043D\\u0435'", "'\\u043F\\u0440\\u0435\\u0434\\u043E\\u043A'", 
      "'\\u0446\\u0435'", "'\\u043F\\u0435\\u0440\\u0435\\u043B\\u0456\\u043A'", 
      "'\\u043A\\u043E\\u043C\\u043F\\u043E\\u0437\\u0438\\u0446\\u0456\\u044F'", 
      "'\\u0437\\u043E\\u0432\\u043D\\u0456\\u0448\\u043D\\u044F'", "'\\u0432\\u043D\\u0443\\u0442\\u0440\\u0456\\u0448\\u043D\\u044F'", 
      "'\\u043C\\u0456\\u0441\\u0446\\u0435\\u0432\\u0430'", "'\\u0432\\u043B\\u0430\\u0441\\u0442\\u0438\\u0432\\u0456\\u0441\\u0442\\u044C'", 
      "'='", "'>'", "'<'", "'.'", "'+'", "'-'", "'*'", "'/'", "'%'", "'^'", 
      "'&'", "'|'", "'('", "')'", "'['", "']'", "'\\u003F'", "':'", "'~'", 
      "'''", "'\"'", "'!'", "','"
    },
    std::vector<std::string>{
      "", "KW_END", "KW_DIIA", "KW_STRUCTURE", "KW_FOR", "KW_CYCLE", "KW_IF", 
      "KW_WAIT", "KW_TAKE", "KW_GIVE", "KW_AS", "KW_TA", "KW_IS", "KW_SPEC", 
      "KW_RETURN", "KW_ASYNC", "KW_SUBJECT", "KW_AND", "KW_OR", "KW_TRY", 
      "KW_CATCH", "KW_ELSE", "KW_THROW", "KW_WHILE", "KW_MODULE", "KW_EQ_WORD", 
      "KW_GR_WORD", "KW_SM_WORD", "KW_HAS_WORD", "KW_MOCKUP", "KW_NOT", 
      "KW_PARENT", "KW_TSE", "KW_PERELIK", "KW_COMPOSITION", "KW_PUBLIC", 
      "KW_PRIVATE", "KW_PROTECTED", "KW_PROPERTY", "EQUAL", "GREATER", "LESSER", 
      "DOT", "PLUS", "MINUS", "MULTIPLY", "DIVIDE", "MOD", "POWER", "AND", 
      "OR", "PAREN_OPEN", "PAREN_CLOSE", "BRACKET_OPEN", "BRACKET_CLOSE", 
      "QUESTION", "COLON", "TILDA", "QUOTE", "DOUBLE_QUOTE", "EXCLAMATION", 
      "COMA", "NUMBER", "INTEGER", "FLOAT", "HEX", "BIN", "ID", "STRING_MULTILINE", 
      "STRING", "CHARACTER", "COMMENT", "LINE_COMMENT", "NL", "WS"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,74,591,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,7,
  	21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,7,
  	28,2,29,7,29,2,30,7,30,2,31,7,31,2,32,7,32,2,33,7,33,2,34,7,34,2,35,7,
  	35,1,0,1,0,1,0,1,1,1,1,1,1,1,1,1,1,5,1,81,8,1,10,1,12,1,84,9,1,1,1,1,
  	1,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,3,2,97,8,2,1,2,1,2,3,2,101,8,2,
  	1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,
  	2,1,2,1,2,1,2,1,2,1,2,1,2,5,2,127,8,2,10,2,12,2,130,9,2,3,2,132,8,2,1,
  	2,1,2,1,2,5,2,137,8,2,10,2,12,2,140,9,2,1,3,1,3,1,3,1,3,1,3,1,3,1,4,1,
  	4,3,4,150,8,4,1,4,1,4,1,4,1,4,1,4,1,5,1,5,1,5,1,5,1,5,1,5,1,5,3,5,164,
  	8,5,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,5,6,176,8,6,10,6,12,6,179,
  	9,6,3,6,181,8,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,5,6,195,
  	8,6,10,6,12,6,198,9,6,3,6,200,8,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,
  	1,6,1,6,1,6,5,6,214,8,6,10,6,12,6,217,9,6,3,6,219,8,6,1,6,1,6,1,6,1,6,
  	1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,3,6,240,8,
  	6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,
  	1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,
  	6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,
  	1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,
  	6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,
  	1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,
  	6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,
  	1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,5,6,372,8,6,10,6,12,6,375,9,6,1,7,1,7,
  	1,7,1,8,1,8,1,8,1,9,1,9,1,9,1,9,1,10,1,10,1,10,1,11,1,11,1,11,1,12,1,
  	12,1,12,1,13,1,13,1,13,1,14,1,14,1,14,1,15,1,15,1,15,1,16,1,16,1,17,1,
  	17,1,18,1,18,1,18,1,18,3,18,413,8,18,1,18,1,18,1,18,1,18,1,18,1,18,1,
  	18,5,18,422,8,18,10,18,12,18,425,9,18,3,18,427,8,18,1,18,1,18,1,18,1,
  	19,1,19,1,20,3,20,435,8,20,1,20,3,20,438,8,20,1,20,1,20,1,20,1,20,3,20,
  	444,8,20,1,20,3,20,447,8,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,5,
  	20,457,8,20,10,20,12,20,460,9,20,3,20,462,8,20,1,20,1,20,1,20,3,20,467,
  	8,20,1,20,1,20,1,20,1,20,3,20,473,8,20,1,20,1,20,1,20,1,21,1,21,1,22,
  	1,22,1,22,1,22,3,22,484,8,22,1,22,1,22,1,23,1,23,1,23,1,23,1,23,1,23,
  	1,24,1,24,1,24,1,24,1,24,1,24,1,24,1,25,1,25,1,25,1,25,1,25,1,25,3,25,
  	507,8,25,1,25,1,25,1,25,1,25,1,25,3,25,514,8,25,1,25,1,25,1,25,3,25,519,
  	8,25,1,26,1,26,1,26,1,26,1,26,1,26,3,26,527,8,26,1,26,1,26,1,27,1,27,
  	1,27,1,27,5,27,535,8,27,10,27,12,27,538,9,27,1,28,1,28,1,28,1,28,1,28,
  	1,28,1,28,1,28,1,28,1,28,3,28,550,8,28,1,29,1,29,3,29,554,8,29,1,30,1,
  	30,1,31,1,31,3,31,560,8,31,1,31,1,31,3,31,564,8,31,1,32,1,32,3,32,568,
  	8,32,1,32,1,32,1,32,5,32,573,8,32,10,32,12,32,576,9,32,1,33,1,33,1,34,
  	4,34,581,8,34,11,34,12,34,582,1,35,5,35,586,8,35,10,35,12,35,589,9,35,
  	1,35,0,2,4,12,36,0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,
  	38,40,42,44,46,48,50,52,54,56,58,60,62,64,66,68,70,0,1,2,0,67,67,69,69,
  	633,0,72,1,0,0,0,2,75,1,0,0,0,4,100,1,0,0,0,6,141,1,0,0,0,8,149,1,0,0,
  	0,10,163,1,0,0,0,12,239,1,0,0,0,14,376,1,0,0,0,16,379,1,0,0,0,18,382,
  	1,0,0,0,20,386,1,0,0,0,22,389,1,0,0,0,24,392,1,0,0,0,26,395,1,0,0,0,28,
  	398,1,0,0,0,30,401,1,0,0,0,32,404,1,0,0,0,34,406,1,0,0,0,36,408,1,0,0,
  	0,38,431,1,0,0,0,40,434,1,0,0,0,42,477,1,0,0,0,44,479,1,0,0,0,46,487,
  	1,0,0,0,48,493,1,0,0,0,50,500,1,0,0,0,52,520,1,0,0,0,54,530,1,0,0,0,56,
  	549,1,0,0,0,58,551,1,0,0,0,60,555,1,0,0,0,62,557,1,0,0,0,64,565,1,0,0,
  	0,66,577,1,0,0,0,68,580,1,0,0,0,70,587,1,0,0,0,72,73,3,2,1,0,73,74,5,
  	0,0,1,74,1,1,0,0,0,75,76,3,70,35,0,76,82,3,56,28,0,77,78,3,68,34,0,78,
  	79,3,56,28,0,79,81,1,0,0,0,80,77,1,0,0,0,81,84,1,0,0,0,82,80,1,0,0,0,
  	82,83,1,0,0,0,83,85,1,0,0,0,84,82,1,0,0,0,85,86,3,70,35,0,86,3,1,0,0,
  	0,87,88,6,2,-1,0,88,89,5,51,0,0,89,90,3,70,35,0,90,91,3,34,17,0,91,92,
  	3,70,35,0,92,93,5,52,0,0,93,101,1,0,0,0,94,101,5,62,0,0,95,97,5,67,0,
  	0,96,95,1,0,0,0,96,97,1,0,0,0,97,98,1,0,0,0,98,101,5,69,0,0,99,101,5,
  	67,0,0,100,87,1,0,0,0,100,94,1,0,0,0,100,96,1,0,0,0,100,99,1,0,0,0,101,
  	138,1,0,0,0,102,103,10,3,0,0,103,104,3,70,35,0,104,105,5,42,0,0,105,106,
  	3,70,35,0,106,107,5,67,0,0,107,137,1,0,0,0,108,109,10,2,0,0,109,110,3,
  	70,35,0,110,111,5,53,0,0,111,112,3,70,35,0,112,113,3,34,17,0,113,114,
  	3,70,35,0,114,115,5,54,0,0,115,137,1,0,0,0,116,117,10,1,0,0,117,118,5,
  	51,0,0,118,131,3,70,35,0,119,120,3,10,5,0,120,128,3,70,35,0,121,122,3,
  	70,35,0,122,123,5,61,0,0,123,124,3,70,35,0,124,125,3,10,5,0,125,127,1,
  	0,0,0,126,121,1,0,0,0,127,130,1,0,0,0,128,126,1,0,0,0,128,129,1,0,0,0,
  	129,132,1,0,0,0,130,128,1,0,0,0,131,119,1,0,0,0,131,132,1,0,0,0,132,133,
  	1,0,0,0,133,134,3,70,35,0,134,135,5,52,0,0,135,137,1,0,0,0,136,102,1,
  	0,0,0,136,108,1,0,0,0,136,116,1,0,0,0,137,140,1,0,0,0,138,136,1,0,0,0,
  	138,139,1,0,0,0,139,5,1,0,0,0,140,138,1,0,0,0,141,142,5,67,0,0,142,143,
  	3,70,35,0,143,144,5,39,0,0,144,145,3,70,35,0,145,146,3,34,17,0,146,7,
  	1,0,0,0,147,150,5,62,0,0,148,150,5,69,0,0,149,147,1,0,0,0,149,148,1,0,
  	0,0,150,151,1,0,0,0,151,152,3,70,35,0,152,153,5,39,0,0,153,154,3,70,35,
  	0,154,155,3,34,17,0,155,9,1,0,0,0,156,157,5,67,0,0,157,158,3,70,35,0,
  	158,159,5,39,0,0,159,160,3,70,35,0,160,161,3,34,17,0,161,164,1,0,0,0,
  	162,164,3,34,17,0,163,156,1,0,0,0,163,162,1,0,0,0,164,11,1,0,0,0,165,
  	166,6,6,-1,0,166,240,3,4,2,0,167,168,5,51,0,0,168,180,3,70,35,0,169,177,
  	3,6,3,0,170,171,3,70,35,0,171,172,5,61,0,0,172,173,3,70,35,0,173,174,
  	3,6,3,0,174,176,1,0,0,0,175,170,1,0,0,0,176,179,1,0,0,0,177,175,1,0,0,
  	0,177,178,1,0,0,0,178,181,1,0,0,0,179,177,1,0,0,0,180,169,1,0,0,0,180,
  	181,1,0,0,0,181,182,1,0,0,0,182,183,3,70,35,0,183,184,5,52,0,0,184,240,
  	1,0,0,0,185,186,5,53,0,0,186,199,3,70,35,0,187,188,3,8,4,0,188,196,3,
  	70,35,0,189,190,3,70,35,0,190,191,5,61,0,0,191,192,3,70,35,0,192,193,
  	3,8,4,0,193,195,1,0,0,0,194,189,1,0,0,0,195,198,1,0,0,0,196,194,1,0,0,
  	0,196,197,1,0,0,0,197,200,1,0,0,0,198,196,1,0,0,0,199,187,1,0,0,0,199,
  	200,1,0,0,0,200,201,1,0,0,0,201,202,3,70,35,0,202,203,5,54,0,0,203,240,
  	1,0,0,0,204,205,5,53,0,0,205,218,3,70,35,0,206,207,3,34,17,0,207,215,
  	3,70,35,0,208,209,3,70,35,0,209,210,5,61,0,0,210,211,3,70,35,0,211,212,
  	3,34,17,0,212,214,1,0,0,0,213,208,1,0,0,0,214,217,1,0,0,0,215,213,1,0,
  	0,0,215,216,1,0,0,0,216,219,1,0,0,0,217,215,1,0,0,0,218,206,1,0,0,0,218,
  	219,1,0,0,0,219,220,1,0,0,0,220,221,3,70,35,0,221,222,5,54,0,0,222,240,
  	1,0,0,0,223,224,5,60,0,0,224,225,3,70,35,0,225,226,3,12,6,24,226,240,
  	1,0,0,0,227,228,5,57,0,0,228,229,3,70,35,0,229,230,3,12,6,23,230,240,
  	1,0,0,0,231,232,5,43,0,0,232,233,3,70,35,0,233,234,3,12,6,22,234,240,
  	1,0,0,0,235,236,5,44,0,0,236,237,3,70,35,0,237,238,3,12,6,21,238,240,
  	1,0,0,0,239,165,1,0,0,0,239,167,1,0,0,0,239,185,1,0,0,0,239,204,1,0,0,
  	0,239,223,1,0,0,0,239,227,1,0,0,0,239,231,1,0,0,0,239,235,1,0,0,0,240,
  	373,1,0,0,0,241,242,10,20,0,0,242,243,3,70,35,0,243,244,5,45,0,0,244,
  	245,3,70,35,0,245,246,3,12,6,21,246,372,1,0,0,0,247,248,10,19,0,0,248,
  	249,3,70,35,0,249,250,5,46,0,0,250,251,3,70,35,0,251,252,3,12,6,20,252,
  	372,1,0,0,0,253,254,10,18,0,0,254,255,3,70,35,0,255,256,5,47,0,0,256,
  	257,3,70,35,0,257,258,3,12,6,19,258,372,1,0,0,0,259,260,10,17,0,0,260,
  	261,3,70,35,0,261,262,5,43,0,0,262,263,3,70,35,0,263,264,3,12,6,18,264,
  	372,1,0,0,0,265,266,10,16,0,0,266,267,3,70,35,0,267,268,5,44,0,0,268,
  	269,3,70,35,0,269,270,3,12,6,17,270,372,1,0,0,0,271,272,10,15,0,0,272,
  	273,3,70,35,0,273,274,3,14,7,0,274,275,3,70,35,0,275,276,3,12,6,16,276,
  	372,1,0,0,0,277,278,10,14,0,0,278,279,3,70,35,0,279,280,3,16,8,0,280,
  	281,3,70,35,0,281,282,3,12,6,15,282,372,1,0,0,0,283,284,10,13,0,0,284,
  	285,3,70,35,0,285,286,3,18,9,0,286,287,3,70,35,0,287,288,3,12,6,14,288,
  	372,1,0,0,0,289,290,10,12,0,0,290,291,3,70,35,0,291,292,5,41,0,0,292,
  	293,3,70,35,0,293,294,3,12,6,13,294,372,1,0,0,0,295,296,10,11,0,0,296,
  	297,3,70,35,0,297,298,3,20,10,0,298,299,3,70,35,0,299,300,3,12,6,12,300,
  	372,1,0,0,0,301,302,10,10,0,0,302,303,3,70,35,0,303,304,5,40,0,0,304,
  	305,3,70,35,0,305,306,3,12,6,11,306,372,1,0,0,0,307,308,10,9,0,0,308,
  	309,3,70,35,0,309,310,3,22,11,0,310,311,3,70,35,0,311,312,3,12,6,10,312,
  	372,1,0,0,0,313,314,10,8,0,0,314,315,3,70,35,0,315,316,3,24,12,0,316,
  	317,3,70,35,0,317,318,3,12,6,9,318,372,1,0,0,0,319,320,10,7,0,0,320,321,
  	3,70,35,0,321,322,3,26,13,0,322,323,3,70,35,0,323,324,3,12,6,8,324,372,
  	1,0,0,0,325,326,10,6,0,0,326,327,3,70,35,0,327,328,5,49,0,0,328,329,3,
  	70,35,0,329,330,3,12,6,7,330,372,1,0,0,0,331,332,10,5,0,0,332,333,3,70,
  	35,0,333,334,5,48,0,0,334,335,3,70,35,0,335,336,3,12,6,6,336,372,1,0,
  	0,0,337,338,10,4,0,0,338,339,3,70,35,0,339,340,5,50,0,0,340,341,3,70,
  	35,0,341,342,3,12,6,5,342,372,1,0,0,0,343,344,10,3,0,0,344,345,3,70,35,
  	0,345,346,3,28,14,0,346,347,3,70,35,0,347,348,3,12,6,4,348,372,1,0,0,
  	0,349,350,10,2,0,0,350,351,3,70,35,0,351,352,3,30,15,0,352,353,3,70,35,
  	0,353,354,3,12,6,3,354,372,1,0,0,0,355,356,10,1,0,0,356,357,3,70,35,0,
  	357,358,5,55,0,0,358,359,3,70,35,0,359,360,3,12,6,0,360,361,3,70,35,0,
  	361,362,5,56,0,0,362,363,3,70,35,0,363,364,3,12,6,2,364,372,1,0,0,0,365,
  	366,10,25,0,0,366,367,3,70,35,0,367,368,5,10,0,0,368,369,3,70,35,0,369,
  	370,3,60,30,0,370,372,1,0,0,0,371,241,1,0,0,0,371,247,1,0,0,0,371,253,
  	1,0,0,0,371,259,1,0,0,0,371,265,1,0,0,0,371,271,1,0,0,0,371,277,1,0,0,
  	0,371,283,1,0,0,0,371,289,1,0,0,0,371,295,1,0,0,0,371,301,1,0,0,0,371,
  	307,1,0,0,0,371,313,1,0,0,0,371,319,1,0,0,0,371,325,1,0,0,0,371,331,1,
  	0,0,0,371,337,1,0,0,0,371,343,1,0,0,0,371,349,1,0,0,0,371,355,1,0,0,0,
  	371,365,1,0,0,0,372,375,1,0,0,0,373,371,1,0,0,0,373,374,1,0,0,0,374,13,
  	1,0,0,0,375,373,1,0,0,0,376,377,5,41,0,0,377,378,5,41,0,0,378,15,1,0,
  	0,0,379,380,5,40,0,0,380,381,5,40,0,0,381,17,1,0,0,0,382,383,5,40,0,0,
  	383,384,5,40,0,0,384,385,5,40,0,0,385,19,1,0,0,0,386,387,5,41,0,0,387,
  	388,5,39,0,0,388,21,1,0,0,0,389,390,5,40,0,0,390,391,5,39,0,0,391,23,
  	1,0,0,0,392,393,5,39,0,0,393,394,5,39,0,0,394,25,1,0,0,0,395,396,5,60,
  	0,0,396,397,5,39,0,0,397,27,1,0,0,0,398,399,5,49,0,0,399,400,5,49,0,0,
  	400,29,1,0,0,0,401,402,5,50,0,0,402,403,5,50,0,0,403,31,1,0,0,0,404,405,
  	5,67,0,0,405,33,1,0,0,0,406,407,3,12,6,0,407,35,1,0,0,0,408,409,5,3,0,
  	0,409,412,5,67,0,0,410,411,5,12,0,0,411,413,3,4,2,0,412,410,1,0,0,0,412,
  	413,1,0,0,0,413,414,1,0,0,0,414,426,3,68,34,0,415,416,3,38,19,0,416,423,
  	3,70,35,0,417,418,3,68,34,0,418,419,3,70,35,0,419,420,3,38,19,0,420,422,
  	1,0,0,0,421,417,1,0,0,0,422,425,1,0,0,0,423,421,1,0,0,0,423,424,1,0,0,
  	0,424,427,1,0,0,0,425,423,1,0,0,0,426,415,1,0,0,0,426,427,1,0,0,0,427,
  	428,1,0,0,0,428,429,3,70,35,0,429,430,5,1,0,0,430,37,1,0,0,0,431,432,
  	3,62,31,0,432,39,1,0,0,0,433,435,5,15,0,0,434,433,1,0,0,0,434,435,1,0,
  	0,0,435,437,1,0,0,0,436,438,5,13,0,0,437,436,1,0,0,0,437,438,1,0,0,0,
  	438,439,1,0,0,0,439,446,5,2,0,0,440,441,3,4,2,0,441,442,5,42,0,0,442,
  	444,1,0,0,0,443,440,1,0,0,0,443,444,1,0,0,0,444,445,1,0,0,0,445,447,5,
  	67,0,0,446,443,1,0,0,0,446,447,1,0,0,0,447,448,1,0,0,0,448,449,5,51,0,
  	0,449,461,3,70,35,0,450,451,3,42,21,0,451,458,3,70,35,0,452,453,5,61,
  	0,0,453,454,3,70,35,0,454,455,3,42,21,0,455,457,1,0,0,0,456,452,1,0,0,
  	0,457,460,1,0,0,0,458,456,1,0,0,0,458,459,1,0,0,0,459,462,1,0,0,0,460,
  	458,1,0,0,0,461,450,1,0,0,0,461,462,1,0,0,0,462,463,1,0,0,0,463,464,3,
  	70,35,0,464,466,5,52,0,0,465,467,3,60,30,0,466,465,1,0,0,0,466,467,1,
  	0,0,0,467,468,1,0,0,0,468,472,3,68,34,0,469,470,3,54,27,0,470,471,3,68,
  	34,0,471,473,1,0,0,0,472,469,1,0,0,0,472,473,1,0,0,0,473,474,1,0,0,0,
  	474,475,3,70,35,0,475,476,5,1,0,0,476,41,1,0,0,0,477,478,3,62,31,0,478,
  	43,1,0,0,0,479,483,5,67,0,0,480,484,5,39,0,0,481,482,5,56,0,0,482,484,
  	5,39,0,0,483,480,1,0,0,0,483,481,1,0,0,0,484,485,1,0,0,0,485,486,3,34,
  	17,0,486,45,1,0,0,0,487,488,3,4,2,0,488,489,5,42,0,0,489,490,5,67,0,0,
  	490,491,5,39,0,0,491,492,3,34,17,0,492,47,1,0,0,0,493,494,3,4,2,0,494,
  	495,5,53,0,0,495,496,3,34,17,0,496,497,5,54,0,0,497,498,5,39,0,0,498,
  	499,3,34,17,0,499,49,1,0,0,0,500,501,5,6,0,0,501,502,3,34,17,0,502,506,
  	3,68,34,0,503,504,3,54,27,0,504,505,3,68,34,0,505,507,1,0,0,0,506,503,
  	1,0,0,0,506,507,1,0,0,0,507,518,1,0,0,0,508,509,5,21,0,0,509,510,3,68,
  	34,0,510,511,3,54,27,0,511,512,3,68,34,0,512,514,1,0,0,0,513,508,1,0,
  	0,0,513,514,1,0,0,0,514,515,1,0,0,0,515,519,5,1,0,0,516,517,5,21,0,0,
  	517,519,3,50,25,0,518,513,1,0,0,0,518,516,1,0,0,0,519,51,1,0,0,0,520,
  	521,5,23,0,0,521,522,3,12,6,0,522,526,3,68,34,0,523,524,3,54,27,0,524,
  	525,3,68,34,0,525,527,1,0,0,0,526,523,1,0,0,0,526,527,1,0,0,0,527,528,
  	1,0,0,0,528,529,5,1,0,0,529,53,1,0,0,0,530,536,3,56,28,0,531,532,3,68,
  	34,0,532,533,3,56,28,0,533,535,1,0,0,0,534,531,1,0,0,0,535,538,1,0,0,
  	0,536,534,1,0,0,0,536,537,1,0,0,0,537,55,1,0,0,0,538,536,1,0,0,0,539,
  	550,3,36,18,0,540,550,3,40,20,0,541,550,3,44,22,0,542,550,3,46,23,0,543,
  	550,3,48,24,0,544,550,3,50,25,0,545,550,3,52,26,0,546,550,3,34,17,0,547,
  	550,3,58,29,0,548,550,3,64,32,0,549,539,1,0,0,0,549,540,1,0,0,0,549,541,
  	1,0,0,0,549,542,1,0,0,0,549,543,1,0,0,0,549,544,1,0,0,0,549,545,1,0,0,
  	0,549,546,1,0,0,0,549,547,1,0,0,0,549,548,1,0,0,0,550,57,1,0,0,0,551,
  	553,5,14,0,0,552,554,3,34,17,0,553,552,1,0,0,0,553,554,1,0,0,0,554,59,
  	1,0,0,0,555,556,3,4,2,0,556,61,1,0,0,0,557,559,5,67,0,0,558,560,3,60,
  	30,0,559,558,1,0,0,0,559,560,1,0,0,0,560,563,1,0,0,0,561,562,5,39,0,0,
  	562,564,3,34,17,0,563,561,1,0,0,0,563,564,1,0,0,0,564,63,1,0,0,0,565,
  	567,5,8,0,0,566,568,5,67,0,0,567,566,1,0,0,0,567,568,1,0,0,0,568,569,
  	1,0,0,0,569,574,3,66,33,0,570,571,5,42,0,0,571,573,3,66,33,0,572,570,
  	1,0,0,0,573,576,1,0,0,0,574,572,1,0,0,0,574,575,1,0,0,0,575,65,1,0,0,
  	0,576,574,1,0,0,0,577,578,7,0,0,0,578,67,1,0,0,0,579,581,5,73,0,0,580,
  	579,1,0,0,0,581,582,1,0,0,0,582,580,1,0,0,0,582,583,1,0,0,0,583,69,1,
  	0,0,0,584,586,5,73,0,0,585,584,1,0,0,0,586,589,1,0,0,0,587,585,1,0,0,
  	0,587,588,1,0,0,0,588,71,1,0,0,0,589,587,1,0,0,0,43,82,96,100,128,131,
  	136,138,149,163,177,180,196,199,215,218,239,371,373,412,423,426,434,437,
  	443,446,458,461,466,472,483,506,513,518,526,536,549,553,559,563,567,574,
  	582,587
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  mavkaparserParserStaticData = staticData.release();
}

}

MavkaParser::MavkaParser(TokenStream *input) : MavkaParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

MavkaParser::MavkaParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  MavkaParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *mavkaparserParserStaticData->atn, mavkaparserParserStaticData->decisionToDFA, mavkaparserParserStaticData->sharedContextCache, options);
}

MavkaParser::~MavkaParser() {
  delete _interpreter;
}

const atn::ATN& MavkaParser::getATN() const {
  return *mavkaparserParserStaticData->atn;
}

std::string MavkaParser::getGrammarFileName() const {
  return "MavkaParser.g4";
}

const std::vector<std::string>& MavkaParser::getRuleNames() const {
  return mavkaparserParserStaticData->ruleNames;
}

const dfa::Vocabulary& MavkaParser::getVocabulary() const {
  return mavkaparserParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView MavkaParser::getSerializedATN() const {
  return mavkaparserParserStaticData->serializedATN;
}


//----------------- FileContext ------------------------------------------------------------------

MavkaParser::FileContext::FileContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MavkaParser::FileContext::EOF() {
  return getToken(MavkaParser::EOF, 0);
}

MavkaParser::ProgramContext* MavkaParser::FileContext::program() {
  return getRuleContext<MavkaParser::ProgramContext>(0);
}


size_t MavkaParser::FileContext::getRuleIndex() const {
  return MavkaParser::RuleFile;
}

void MavkaParser::FileContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFile(this);
}

void MavkaParser::FileContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFile(this);
}


std::any MavkaParser::FileContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MavkaParserVisitor*>(visitor))
    return parserVisitor->visitFile(this);
  else
    return visitor->visitChildren(this);
}

MavkaParser::FileContext* MavkaParser::file() {
  FileContext *_localctx = _tracker.createInstance<FileContext>(_ctx, getState());
  enterRule(_localctx, 0, MavkaParser::RuleFile);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(72);
    antlrcpp::downCast<FileContext *>(_localctx)->f_program = program();
    setState(73);
    match(MavkaParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ProgramContext ------------------------------------------------------------------

MavkaParser::ProgramContext::ProgramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<MavkaParser::NlsContext *> MavkaParser::ProgramContext::nls() {
  return getRuleContexts<MavkaParser::NlsContext>();
}

MavkaParser::NlsContext* MavkaParser::ProgramContext::nls(size_t i) {
  return getRuleContext<MavkaParser::NlsContext>(i);
}

std::vector<MavkaParser::Body_elementContext *> MavkaParser::ProgramContext::body_element() {
  return getRuleContexts<MavkaParser::Body_elementContext>();
}

MavkaParser::Body_elementContext* MavkaParser::ProgramContext::body_element(size_t i) {
  return getRuleContext<MavkaParser::Body_elementContext>(i);
}

std::vector<MavkaParser::NlContext *> MavkaParser::ProgramContext::nl() {
  return getRuleContexts<MavkaParser::NlContext>();
}

MavkaParser::NlContext* MavkaParser::ProgramContext::nl(size_t i) {
  return getRuleContext<MavkaParser::NlContext>(i);
}


size_t MavkaParser::ProgramContext::getRuleIndex() const {
  return MavkaParser::RuleProgram;
}

void MavkaParser::ProgramContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProgram(this);
}

void MavkaParser::ProgramContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProgram(this);
}


std::any MavkaParser::ProgramContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MavkaParserVisitor*>(visitor))
    return parserVisitor->visitProgram(this);
  else
    return visitor->visitChildren(this);
}

MavkaParser::ProgramContext* MavkaParser::program() {
  ProgramContext *_localctx = _tracker.createInstance<ProgramContext>(_ctx, getState());
  enterRule(_localctx, 2, MavkaParser::RuleProgram);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(75);
    nls();
    setState(76);
    body_element();
    setState(82);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(77);
        nl();
        setState(78);
        body_element(); 
      }
      setState(84);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx);
    }
    setState(85);
    nls();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AtomContext ------------------------------------------------------------------

MavkaParser::AtomContext::AtomContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t MavkaParser::AtomContext::getRuleIndex() const {
  return MavkaParser::RuleAtom;
}

void MavkaParser::AtomContext::copyFrom(AtomContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- Atom_nestedContext ------------------------------------------------------------------

tree::TerminalNode* MavkaParser::Atom_nestedContext::PAREN_OPEN() {
  return getToken(MavkaParser::PAREN_OPEN, 0);
}

std::vector<MavkaParser::NlsContext *> MavkaParser::Atom_nestedContext::nls() {
  return getRuleContexts<MavkaParser::NlsContext>();
}

MavkaParser::NlsContext* MavkaParser::Atom_nestedContext::nls(size_t i) {
  return getRuleContext<MavkaParser::NlsContext>(i);
}

MavkaParser::ExprContext* MavkaParser::Atom_nestedContext::expr() {
  return getRuleContext<MavkaParser::ExprContext>(0);
}

tree::TerminalNode* MavkaParser::Atom_nestedContext::PAREN_CLOSE() {
  return getToken(MavkaParser::PAREN_CLOSE, 0);
}

MavkaParser::Atom_nestedContext::Atom_nestedContext(AtomContext *ctx) { copyFrom(ctx); }

void MavkaParser::Atom_nestedContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAtom_nested(this);
}
void MavkaParser::Atom_nestedContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAtom_nested(this);
}

std::any MavkaParser::Atom_nestedContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MavkaParserVisitor*>(visitor))
    return parserVisitor->visitAtom_nested(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Operation_stringContext ------------------------------------------------------------------

tree::TerminalNode* MavkaParser::Operation_stringContext::STRING() {
  return getToken(MavkaParser::STRING, 0);
}

tree::TerminalNode* MavkaParser::Operation_stringContext::ID() {
  return getToken(MavkaParser::ID, 0);
}

MavkaParser::Operation_stringContext::Operation_stringContext(AtomContext *ctx) { copyFrom(ctx); }

void MavkaParser::Operation_stringContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOperation_string(this);
}
void MavkaParser::Operation_stringContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOperation_string(this);
}

std::any MavkaParser::Operation_stringContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MavkaParserVisitor*>(visitor))
    return parserVisitor->visitOperation_string(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Atom_getContext ------------------------------------------------------------------

std::vector<MavkaParser::NlsContext *> MavkaParser::Atom_getContext::nls() {
  return getRuleContexts<MavkaParser::NlsContext>();
}

MavkaParser::NlsContext* MavkaParser::Atom_getContext::nls(size_t i) {
  return getRuleContext<MavkaParser::NlsContext>(i);
}

tree::TerminalNode* MavkaParser::Atom_getContext::DOT() {
  return getToken(MavkaParser::DOT, 0);
}

MavkaParser::AtomContext* MavkaParser::Atom_getContext::atom() {
  return getRuleContext<MavkaParser::AtomContext>(0);
}

tree::TerminalNode* MavkaParser::Atom_getContext::ID() {
  return getToken(MavkaParser::ID, 0);
}

MavkaParser::Atom_getContext::Atom_getContext(AtomContext *ctx) { copyFrom(ctx); }

void MavkaParser::Atom_getContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAtom_get(this);
}
void MavkaParser::Atom_getContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAtom_get(this);
}

std::any MavkaParser::Atom_getContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MavkaParserVisitor*>(visitor))
    return parserVisitor->visitAtom_get(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Atom_subjectContext ------------------------------------------------------------------

tree::TerminalNode* MavkaParser::Atom_subjectContext::ID() {
  return getToken(MavkaParser::ID, 0);
}

MavkaParser::Atom_subjectContext::Atom_subjectContext(AtomContext *ctx) { copyFrom(ctx); }

void MavkaParser::Atom_subjectContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAtom_subject(this);
}
void MavkaParser::Atom_subjectContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAtom_subject(this);
}

std::any MavkaParser::Atom_subjectContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MavkaParserVisitor*>(visitor))
    return parserVisitor->visitAtom_subject(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Operation_numberContext ------------------------------------------------------------------

tree::TerminalNode* MavkaParser::Operation_numberContext::NUMBER() {
  return getToken(MavkaParser::NUMBER, 0);
}

MavkaParser::Operation_numberContext::Operation_numberContext(AtomContext *ctx) { copyFrom(ctx); }

void MavkaParser::Operation_numberContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOperation_number(this);
}
void MavkaParser::Operation_numberContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOperation_number(this);
}

std::any MavkaParser::Operation_numberContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MavkaParserVisitor*>(visitor))
    return parserVisitor->visitOperation_number(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Atom_position_getContext ------------------------------------------------------------------

std::vector<MavkaParser::NlsContext *> MavkaParser::Atom_position_getContext::nls() {
  return getRuleContexts<MavkaParser::NlsContext>();
}

MavkaParser::NlsContext* MavkaParser::Atom_position_getContext::nls(size_t i) {
  return getRuleContext<MavkaParser::NlsContext>(i);
}

tree::TerminalNode* MavkaParser::Atom_position_getContext::BRACKET_OPEN() {
  return getToken(MavkaParser::BRACKET_OPEN, 0);
}

tree::TerminalNode* MavkaParser::Atom_position_getContext::BRACKET_CLOSE() {
  return getToken(MavkaParser::BRACKET_CLOSE, 0);
}

MavkaParser::AtomContext* MavkaParser::Atom_position_getContext::atom() {
  return getRuleContext<MavkaParser::AtomContext>(0);
}

MavkaParser::ExprContext* MavkaParser::Atom_position_getContext::expr() {
  return getRuleContext<MavkaParser::ExprContext>(0);
}

MavkaParser::Atom_position_getContext::Atom_position_getContext(AtomContext *ctx) { copyFrom(ctx); }

void MavkaParser::Atom_position_getContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAtom_position_get(this);
}
void MavkaParser::Atom_position_getContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAtom_position_get(this);
}

std::any MavkaParser::Atom_position_getContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MavkaParserVisitor*>(visitor))
    return parserVisitor->visitAtom_position_get(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Atom_callContext ------------------------------------------------------------------

tree::TerminalNode* MavkaParser::Atom_callContext::PAREN_OPEN() {
  return getToken(MavkaParser::PAREN_OPEN, 0);
}

std::vector<MavkaParser::NlsContext *> MavkaParser::Atom_callContext::nls() {
  return getRuleContexts<MavkaParser::NlsContext>();
}

MavkaParser::NlsContext* MavkaParser::Atom_callContext::nls(size_t i) {
  return getRuleContext<MavkaParser::NlsContext>(i);
}

tree::TerminalNode* MavkaParser::Atom_callContext::PAREN_CLOSE() {
  return getToken(MavkaParser::PAREN_CLOSE, 0);
}

MavkaParser::AtomContext* MavkaParser::Atom_callContext::atom() {
  return getRuleContext<MavkaParser::AtomContext>(0);
}

std::vector<MavkaParser::Call_argContext *> MavkaParser::Atom_callContext::call_arg() {
  return getRuleContexts<MavkaParser::Call_argContext>();
}

MavkaParser::Call_argContext* MavkaParser::Atom_callContext::call_arg(size_t i) {
  return getRuleContext<MavkaParser::Call_argContext>(i);
}

std::vector<tree::TerminalNode *> MavkaParser::Atom_callContext::COMA() {
  return getTokens(MavkaParser::COMA);
}

tree::TerminalNode* MavkaParser::Atom_callContext::COMA(size_t i) {
  return getToken(MavkaParser::COMA, i);
}

MavkaParser::Atom_callContext::Atom_callContext(AtomContext *ctx) { copyFrom(ctx); }

void MavkaParser::Atom_callContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAtom_call(this);
}
void MavkaParser::Atom_callContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAtom_call(this);
}

std::any MavkaParser::Atom_callContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MavkaParserVisitor*>(visitor))
    return parserVisitor->visitAtom_call(this);
  else
    return visitor->visitChildren(this);
}

MavkaParser::AtomContext* MavkaParser::atom() {
   return atom(0);
}

MavkaParser::AtomContext* MavkaParser::atom(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  MavkaParser::AtomContext *_localctx = _tracker.createInstance<AtomContext>(_ctx, parentState);
  MavkaParser::AtomContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 4;
  enterRecursionRule(_localctx, 4, MavkaParser::RuleAtom, precedence);

    size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(100);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<Atom_nestedContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;

      setState(88);
      match(MavkaParser::PAREN_OPEN);
      setState(89);
      nls();
      setState(90);
      expr();
      setState(91);
      nls();
      setState(92);
      match(MavkaParser::PAREN_CLOSE);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<Operation_numberContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(94);
      match(MavkaParser::NUMBER);
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<Operation_stringContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(96);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == MavkaParser::ID) {
        setState(95);
        antlrcpp::downCast<Operation_stringContext *>(_localctx)->tt = match(MavkaParser::ID);
      }
      setState(98);
      match(MavkaParser::STRING);
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<Atom_subjectContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(99);
      antlrcpp::downCast<Atom_subjectContext *>(_localctx)->id = match(MavkaParser::ID);
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(138);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(136);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<Atom_getContext>(_tracker.createInstance<AtomContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->object = previousContext;
          pushNewRecursionContext(newContext, startState, RuleAtom);
          setState(102);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(103);
          nls();
          setState(104);
          match(MavkaParser::DOT);
          setState(105);
          nls();
          setState(106);
          antlrcpp::downCast<Atom_getContext *>(_localctx)->id = match(MavkaParser::ID);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<Atom_position_getContext>(_tracker.createInstance<AtomContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->object = previousContext;
          pushNewRecursionContext(newContext, startState, RuleAtom);
          setState(108);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(109);
          nls();
          setState(110);
          match(MavkaParser::BRACKET_OPEN);
          setState(111);
          nls();
          setState(112);
          antlrcpp::downCast<Atom_position_getContext *>(_localctx)->position = expr();
          setState(113);
          nls();
          setState(114);
          match(MavkaParser::BRACKET_CLOSE);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<Atom_callContext>(_tracker.createInstance<AtomContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->object = previousContext;
          pushNewRecursionContext(newContext, startState, RuleAtom);
          setState(116);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(117);
          match(MavkaParser::PAREN_OPEN);
          setState(118);
          nls();
          setState(131);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if (((((_la - 43) & ~ 0x3fULL) == 0) &&
            ((1ULL << (_la - 43)) & 84559107) != 0)) {
            setState(119);
            call_arg();
            setState(120);
            nls();
            setState(128);
            _errHandler->sync(this);
            alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx);
            while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
              if (alt == 1) {
                setState(121);
                nls();
                setState(122);
                match(MavkaParser::COMA);
                setState(123);
                nls();
                setState(124);
                call_arg(); 
              }
              setState(130);
              _errHandler->sync(this);
              alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx);
            }
          }
          setState(133);
          nls();
          setState(134);
          match(MavkaParser::PAREN_CLOSE);
          break;
        }

        default:
          break;
        } 
      }
      setState(140);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- Object_argContext ------------------------------------------------------------------

MavkaParser::Object_argContext::Object_argContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<MavkaParser::NlsContext *> MavkaParser::Object_argContext::nls() {
  return getRuleContexts<MavkaParser::NlsContext>();
}

MavkaParser::NlsContext* MavkaParser::Object_argContext::nls(size_t i) {
  return getRuleContext<MavkaParser::NlsContext>(i);
}

tree::TerminalNode* MavkaParser::Object_argContext::EQUAL() {
  return getToken(MavkaParser::EQUAL, 0);
}

MavkaParser::ExprContext* MavkaParser::Object_argContext::expr() {
  return getRuleContext<MavkaParser::ExprContext>(0);
}

tree::TerminalNode* MavkaParser::Object_argContext::ID() {
  return getToken(MavkaParser::ID, 0);
}


size_t MavkaParser::Object_argContext::getRuleIndex() const {
  return MavkaParser::RuleObject_arg;
}

void MavkaParser::Object_argContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterObject_arg(this);
}

void MavkaParser::Object_argContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitObject_arg(this);
}


std::any MavkaParser::Object_argContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MavkaParserVisitor*>(visitor))
    return parserVisitor->visitObject_arg(this);
  else
    return visitor->visitChildren(this);
}

MavkaParser::Object_argContext* MavkaParser::object_arg() {
  Object_argContext *_localctx = _tracker.createInstance<Object_argContext>(_ctx, getState());
  enterRule(_localctx, 6, MavkaParser::RuleObject_arg);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(141);
    antlrcpp::downCast<Object_argContext *>(_localctx)->id = match(MavkaParser::ID);
    setState(142);
    nls();
    setState(143);
    match(MavkaParser::EQUAL);
    setState(144);
    nls();
    setState(145);
    expr();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Dict_argContext ------------------------------------------------------------------

MavkaParser::Dict_argContext::Dict_argContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<MavkaParser::NlsContext *> MavkaParser::Dict_argContext::nls() {
  return getRuleContexts<MavkaParser::NlsContext>();
}

MavkaParser::NlsContext* MavkaParser::Dict_argContext::nls(size_t i) {
  return getRuleContext<MavkaParser::NlsContext>(i);
}

tree::TerminalNode* MavkaParser::Dict_argContext::EQUAL() {
  return getToken(MavkaParser::EQUAL, 0);
}

MavkaParser::ExprContext* MavkaParser::Dict_argContext::expr() {
  return getRuleContext<MavkaParser::ExprContext>(0);
}

tree::TerminalNode* MavkaParser::Dict_argContext::NUMBER() {
  return getToken(MavkaParser::NUMBER, 0);
}

tree::TerminalNode* MavkaParser::Dict_argContext::STRING() {
  return getToken(MavkaParser::STRING, 0);
}


size_t MavkaParser::Dict_argContext::getRuleIndex() const {
  return MavkaParser::RuleDict_arg;
}

void MavkaParser::Dict_argContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDict_arg(this);
}

void MavkaParser::Dict_argContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDict_arg(this);
}


std::any MavkaParser::Dict_argContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MavkaParserVisitor*>(visitor))
    return parserVisitor->visitDict_arg(this);
  else
    return visitor->visitChildren(this);
}

MavkaParser::Dict_argContext* MavkaParser::dict_arg() {
  Dict_argContext *_localctx = _tracker.createInstance<Dict_argContext>(_ctx, getState());
  enterRule(_localctx, 8, MavkaParser::RuleDict_arg);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(149);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MavkaParser::NUMBER: {
        setState(147);
        antlrcpp::downCast<Dict_argContext *>(_localctx)->key_number = match(MavkaParser::NUMBER);
        break;
      }

      case MavkaParser::STRING: {
        setState(148);
        antlrcpp::downCast<Dict_argContext *>(_localctx)->key_string = match(MavkaParser::STRING);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(151);
    nls();
    setState(152);
    match(MavkaParser::EQUAL);
    setState(153);
    nls();
    setState(154);
    expr();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Call_argContext ------------------------------------------------------------------

MavkaParser::Call_argContext::Call_argContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<MavkaParser::NlsContext *> MavkaParser::Call_argContext::nls() {
  return getRuleContexts<MavkaParser::NlsContext>();
}

MavkaParser::NlsContext* MavkaParser::Call_argContext::nls(size_t i) {
  return getRuleContext<MavkaParser::NlsContext>(i);
}

tree::TerminalNode* MavkaParser::Call_argContext::EQUAL() {
  return getToken(MavkaParser::EQUAL, 0);
}

MavkaParser::ExprContext* MavkaParser::Call_argContext::expr() {
  return getRuleContext<MavkaParser::ExprContext>(0);
}

tree::TerminalNode* MavkaParser::Call_argContext::ID() {
  return getToken(MavkaParser::ID, 0);
}


size_t MavkaParser::Call_argContext::getRuleIndex() const {
  return MavkaParser::RuleCall_arg;
}

void MavkaParser::Call_argContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCall_arg(this);
}

void MavkaParser::Call_argContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCall_arg(this);
}


std::any MavkaParser::Call_argContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MavkaParserVisitor*>(visitor))
    return parserVisitor->visitCall_arg(this);
  else
    return visitor->visitChildren(this);
}

MavkaParser::Call_argContext* MavkaParser::call_arg() {
  Call_argContext *_localctx = _tracker.createInstance<Call_argContext>(_ctx, getState());
  enterRule(_localctx, 10, MavkaParser::RuleCall_arg);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(163);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(156);
      antlrcpp::downCast<Call_argContext *>(_localctx)->id = match(MavkaParser::ID);
      setState(157);
      nls();
      setState(158);
      match(MavkaParser::EQUAL);
      setState(159);
      nls();
      setState(160);
      expr();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(162);
      expr();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- OperationContext ------------------------------------------------------------------

MavkaParser::OperationContext::OperationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t MavkaParser::OperationContext::getRuleIndex() const {
  return MavkaParser::RuleOperation;
}

void MavkaParser::OperationContext::copyFrom(OperationContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- Operation_gteContext ------------------------------------------------------------------

std::vector<MavkaParser::NlsContext *> MavkaParser::Operation_gteContext::nls() {
  return getRuleContexts<MavkaParser::NlsContext>();
}

MavkaParser::NlsContext* MavkaParser::Operation_gteContext::nls(size_t i) {
  return getRuleContext<MavkaParser::NlsContext>(i);
}

std::vector<MavkaParser::OperationContext *> MavkaParser::Operation_gteContext::operation() {
  return getRuleContexts<MavkaParser::OperationContext>();
}

MavkaParser::OperationContext* MavkaParser::Operation_gteContext::operation(size_t i) {
  return getRuleContext<MavkaParser::OperationContext>(i);
}

MavkaParser::Op_gteContext* MavkaParser::Operation_gteContext::op_gte() {
  return getRuleContext<MavkaParser::Op_gteContext>(0);
}

MavkaParser::Operation_gteContext::Operation_gteContext(OperationContext *ctx) { copyFrom(ctx); }

void MavkaParser::Operation_gteContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOperation_gte(this);
}
void MavkaParser::Operation_gteContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOperation_gte(this);
}

std::any MavkaParser::Operation_gteContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MavkaParserVisitor*>(visitor))
    return parserVisitor->visitOperation_gte(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Operation_dictContext ------------------------------------------------------------------

tree::TerminalNode* MavkaParser::Operation_dictContext::BRACKET_OPEN() {
  return getToken(MavkaParser::BRACKET_OPEN, 0);
}

std::vector<MavkaParser::NlsContext *> MavkaParser::Operation_dictContext::nls() {
  return getRuleContexts<MavkaParser::NlsContext>();
}

MavkaParser::NlsContext* MavkaParser::Operation_dictContext::nls(size_t i) {
  return getRuleContext<MavkaParser::NlsContext>(i);
}

tree::TerminalNode* MavkaParser::Operation_dictContext::BRACKET_CLOSE() {
  return getToken(MavkaParser::BRACKET_CLOSE, 0);
}

std::vector<MavkaParser::Dict_argContext *> MavkaParser::Operation_dictContext::dict_arg() {
  return getRuleContexts<MavkaParser::Dict_argContext>();
}

MavkaParser::Dict_argContext* MavkaParser::Operation_dictContext::dict_arg(size_t i) {
  return getRuleContext<MavkaParser::Dict_argContext>(i);
}

std::vector<tree::TerminalNode *> MavkaParser::Operation_dictContext::COMA() {
  return getTokens(MavkaParser::COMA);
}

tree::TerminalNode* MavkaParser::Operation_dictContext::COMA(size_t i) {
  return getToken(MavkaParser::COMA, i);
}

MavkaParser::Operation_dictContext::Operation_dictContext(OperationContext *ctx) { copyFrom(ctx); }

void MavkaParser::Operation_dictContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOperation_dict(this);
}
void MavkaParser::Operation_dictContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOperation_dict(this);
}

std::any MavkaParser::Operation_dictContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MavkaParserVisitor*>(visitor))
    return parserVisitor->visitOperation_dict(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Operation_neqContext ------------------------------------------------------------------

std::vector<MavkaParser::NlsContext *> MavkaParser::Operation_neqContext::nls() {
  return getRuleContexts<MavkaParser::NlsContext>();
}

MavkaParser::NlsContext* MavkaParser::Operation_neqContext::nls(size_t i) {
  return getRuleContext<MavkaParser::NlsContext>(i);
}

std::vector<MavkaParser::OperationContext *> MavkaParser::Operation_neqContext::operation() {
  return getRuleContexts<MavkaParser::OperationContext>();
}

MavkaParser::OperationContext* MavkaParser::Operation_neqContext::operation(size_t i) {
  return getRuleContext<MavkaParser::OperationContext>(i);
}

MavkaParser::Op_neqContext* MavkaParser::Operation_neqContext::op_neq() {
  return getRuleContext<MavkaParser::Op_neqContext>(0);
}

MavkaParser::Operation_neqContext::Operation_neqContext(OperationContext *ctx) { copyFrom(ctx); }

void MavkaParser::Operation_neqContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOperation_neq(this);
}
void MavkaParser::Operation_neqContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOperation_neq(this);
}

std::any MavkaParser::Operation_neqContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MavkaParserVisitor*>(visitor))
    return parserVisitor->visitOperation_neq(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Operation_xorContext ------------------------------------------------------------------

std::vector<MavkaParser::NlsContext *> MavkaParser::Operation_xorContext::nls() {
  return getRuleContexts<MavkaParser::NlsContext>();
}

MavkaParser::NlsContext* MavkaParser::Operation_xorContext::nls(size_t i) {
  return getRuleContext<MavkaParser::NlsContext>(i);
}

std::vector<MavkaParser::OperationContext *> MavkaParser::Operation_xorContext::operation() {
  return getRuleContexts<MavkaParser::OperationContext>();
}

MavkaParser::OperationContext* MavkaParser::Operation_xorContext::operation(size_t i) {
  return getRuleContext<MavkaParser::OperationContext>(i);
}

tree::TerminalNode* MavkaParser::Operation_xorContext::POWER() {
  return getToken(MavkaParser::POWER, 0);
}

MavkaParser::Operation_xorContext::Operation_xorContext(OperationContext *ctx) { copyFrom(ctx); }

void MavkaParser::Operation_xorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOperation_xor(this);
}
void MavkaParser::Operation_xorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOperation_xor(this);
}

std::any MavkaParser::Operation_xorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MavkaParserVisitor*>(visitor))
    return parserVisitor->visitOperation_xor(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Operation_lteContext ------------------------------------------------------------------

std::vector<MavkaParser::NlsContext *> MavkaParser::Operation_lteContext::nls() {
  return getRuleContexts<MavkaParser::NlsContext>();
}

MavkaParser::NlsContext* MavkaParser::Operation_lteContext::nls(size_t i) {
  return getRuleContext<MavkaParser::NlsContext>(i);
}

std::vector<MavkaParser::OperationContext *> MavkaParser::Operation_lteContext::operation() {
  return getRuleContexts<MavkaParser::OperationContext>();
}

MavkaParser::OperationContext* MavkaParser::Operation_lteContext::operation(size_t i) {
  return getRuleContext<MavkaParser::OperationContext>(i);
}

MavkaParser::Op_lteContext* MavkaParser::Operation_lteContext::op_lte() {
  return getRuleContext<MavkaParser::Op_lteContext>(0);
}

MavkaParser::Operation_lteContext::Operation_lteContext(OperationContext *ctx) { copyFrom(ctx); }

void MavkaParser::Operation_lteContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOperation_lte(this);
}
void MavkaParser::Operation_lteContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOperation_lte(this);
}

std::any MavkaParser::Operation_lteContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MavkaParserVisitor*>(visitor))
    return parserVisitor->visitOperation_lte(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Operation_pre_plusContext ------------------------------------------------------------------

MavkaParser::NlsContext* MavkaParser::Operation_pre_plusContext::nls() {
  return getRuleContext<MavkaParser::NlsContext>(0);
}

tree::TerminalNode* MavkaParser::Operation_pre_plusContext::PLUS() {
  return getToken(MavkaParser::PLUS, 0);
}

MavkaParser::OperationContext* MavkaParser::Operation_pre_plusContext::operation() {
  return getRuleContext<MavkaParser::OperationContext>(0);
}

MavkaParser::Operation_pre_plusContext::Operation_pre_plusContext(OperationContext *ctx) { copyFrom(ctx); }

void MavkaParser::Operation_pre_plusContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOperation_pre_plus(this);
}
void MavkaParser::Operation_pre_plusContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOperation_pre_plus(this);
}

std::any MavkaParser::Operation_pre_plusContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MavkaParserVisitor*>(visitor))
    return parserVisitor->visitOperation_pre_plus(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Operation_addContext ------------------------------------------------------------------

std::vector<MavkaParser::NlsContext *> MavkaParser::Operation_addContext::nls() {
  return getRuleContexts<MavkaParser::NlsContext>();
}

MavkaParser::NlsContext* MavkaParser::Operation_addContext::nls(size_t i) {
  return getRuleContext<MavkaParser::NlsContext>(i);
}

std::vector<MavkaParser::OperationContext *> MavkaParser::Operation_addContext::operation() {
  return getRuleContexts<MavkaParser::OperationContext>();
}

MavkaParser::OperationContext* MavkaParser::Operation_addContext::operation(size_t i) {
  return getRuleContext<MavkaParser::OperationContext>(i);
}

tree::TerminalNode* MavkaParser::Operation_addContext::PLUS() {
  return getToken(MavkaParser::PLUS, 0);
}

MavkaParser::Operation_addContext::Operation_addContext(OperationContext *ctx) { copyFrom(ctx); }

void MavkaParser::Operation_addContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOperation_add(this);
}
void MavkaParser::Operation_addContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOperation_add(this);
}

std::any MavkaParser::Operation_addContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MavkaParserVisitor*>(visitor))
    return parserVisitor->visitOperation_add(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Operation_ltContext ------------------------------------------------------------------

std::vector<MavkaParser::NlsContext *> MavkaParser::Operation_ltContext::nls() {
  return getRuleContexts<MavkaParser::NlsContext>();
}

MavkaParser::NlsContext* MavkaParser::Operation_ltContext::nls(size_t i) {
  return getRuleContext<MavkaParser::NlsContext>(i);
}

std::vector<MavkaParser::OperationContext *> MavkaParser::Operation_ltContext::operation() {
  return getRuleContexts<MavkaParser::OperationContext>();
}

MavkaParser::OperationContext* MavkaParser::Operation_ltContext::operation(size_t i) {
  return getRuleContext<MavkaParser::OperationContext>(i);
}

tree::TerminalNode* MavkaParser::Operation_ltContext::LESSER() {
  return getToken(MavkaParser::LESSER, 0);
}

MavkaParser::Operation_ltContext::Operation_ltContext(OperationContext *ctx) { copyFrom(ctx); }

void MavkaParser::Operation_ltContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOperation_lt(this);
}
void MavkaParser::Operation_ltContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOperation_lt(this);
}

std::any MavkaParser::Operation_ltContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MavkaParserVisitor*>(visitor))
    return parserVisitor->visitOperation_lt(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Operation_pre_minusContext ------------------------------------------------------------------

MavkaParser::NlsContext* MavkaParser::Operation_pre_minusContext::nls() {
  return getRuleContext<MavkaParser::NlsContext>(0);
}

tree::TerminalNode* MavkaParser::Operation_pre_minusContext::MINUS() {
  return getToken(MavkaParser::MINUS, 0);
}

MavkaParser::OperationContext* MavkaParser::Operation_pre_minusContext::operation() {
  return getRuleContext<MavkaParser::OperationContext>(0);
}

MavkaParser::Operation_pre_minusContext::Operation_pre_minusContext(OperationContext *ctx) { copyFrom(ctx); }

void MavkaParser::Operation_pre_minusContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOperation_pre_minus(this);
}
void MavkaParser::Operation_pre_minusContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOperation_pre_minus(this);
}

std::any MavkaParser::Operation_pre_minusContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MavkaParserVisitor*>(visitor))
    return parserVisitor->visitOperation_pre_minus(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Operation_landContext ------------------------------------------------------------------

std::vector<MavkaParser::NlsContext *> MavkaParser::Operation_landContext::nls() {
  return getRuleContexts<MavkaParser::NlsContext>();
}

MavkaParser::NlsContext* MavkaParser::Operation_landContext::nls(size_t i) {
  return getRuleContext<MavkaParser::NlsContext>(i);
}

std::vector<MavkaParser::OperationContext *> MavkaParser::Operation_landContext::operation() {
  return getRuleContexts<MavkaParser::OperationContext>();
}

MavkaParser::OperationContext* MavkaParser::Operation_landContext::operation(size_t i) {
  return getRuleContext<MavkaParser::OperationContext>(i);
}

MavkaParser::Op_landContext* MavkaParser::Operation_landContext::op_land() {
  return getRuleContext<MavkaParser::Op_landContext>(0);
}

MavkaParser::Operation_landContext::Operation_landContext(OperationContext *ctx) { copyFrom(ctx); }

void MavkaParser::Operation_landContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOperation_land(this);
}
void MavkaParser::Operation_landContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOperation_land(this);
}

std::any MavkaParser::Operation_landContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MavkaParserVisitor*>(visitor))
    return parserVisitor->visitOperation_land(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Operation_objectContext ------------------------------------------------------------------

tree::TerminalNode* MavkaParser::Operation_objectContext::PAREN_OPEN() {
  return getToken(MavkaParser::PAREN_OPEN, 0);
}

std::vector<MavkaParser::NlsContext *> MavkaParser::Operation_objectContext::nls() {
  return getRuleContexts<MavkaParser::NlsContext>();
}

MavkaParser::NlsContext* MavkaParser::Operation_objectContext::nls(size_t i) {
  return getRuleContext<MavkaParser::NlsContext>(i);
}

tree::TerminalNode* MavkaParser::Operation_objectContext::PAREN_CLOSE() {
  return getToken(MavkaParser::PAREN_CLOSE, 0);
}

std::vector<MavkaParser::Object_argContext *> MavkaParser::Operation_objectContext::object_arg() {
  return getRuleContexts<MavkaParser::Object_argContext>();
}

MavkaParser::Object_argContext* MavkaParser::Operation_objectContext::object_arg(size_t i) {
  return getRuleContext<MavkaParser::Object_argContext>(i);
}

std::vector<tree::TerminalNode *> MavkaParser::Operation_objectContext::COMA() {
  return getTokens(MavkaParser::COMA);
}

tree::TerminalNode* MavkaParser::Operation_objectContext::COMA(size_t i) {
  return getToken(MavkaParser::COMA, i);
}

MavkaParser::Operation_objectContext::Operation_objectContext(OperationContext *ctx) { copyFrom(ctx); }

void MavkaParser::Operation_objectContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOperation_object(this);
}
void MavkaParser::Operation_objectContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOperation_object(this);
}

std::any MavkaParser::Operation_objectContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MavkaParserVisitor*>(visitor))
    return parserVisitor->visitOperation_object(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Operation_orContext ------------------------------------------------------------------

std::vector<MavkaParser::NlsContext *> MavkaParser::Operation_orContext::nls() {
  return getRuleContexts<MavkaParser::NlsContext>();
}

MavkaParser::NlsContext* MavkaParser::Operation_orContext::nls(size_t i) {
  return getRuleContext<MavkaParser::NlsContext>(i);
}

std::vector<MavkaParser::OperationContext *> MavkaParser::Operation_orContext::operation() {
  return getRuleContexts<MavkaParser::OperationContext>();
}

MavkaParser::OperationContext* MavkaParser::Operation_orContext::operation(size_t i) {
  return getRuleContext<MavkaParser::OperationContext>(i);
}

tree::TerminalNode* MavkaParser::Operation_orContext::OR() {
  return getToken(MavkaParser::OR, 0);
}

MavkaParser::Operation_orContext::Operation_orContext(OperationContext *ctx) { copyFrom(ctx); }

void MavkaParser::Operation_orContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOperation_or(this);
}
void MavkaParser::Operation_orContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOperation_or(this);
}

std::any MavkaParser::Operation_orContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MavkaParserVisitor*>(visitor))
    return parserVisitor->visitOperation_or(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Operation_pre_notContext ------------------------------------------------------------------

MavkaParser::NlsContext* MavkaParser::Operation_pre_notContext::nls() {
  return getRuleContext<MavkaParser::NlsContext>(0);
}

tree::TerminalNode* MavkaParser::Operation_pre_notContext::EXCLAMATION() {
  return getToken(MavkaParser::EXCLAMATION, 0);
}

MavkaParser::OperationContext* MavkaParser::Operation_pre_notContext::operation() {
  return getRuleContext<MavkaParser::OperationContext>(0);
}

MavkaParser::Operation_pre_notContext::Operation_pre_notContext(OperationContext *ctx) { copyFrom(ctx); }

void MavkaParser::Operation_pre_notContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOperation_pre_not(this);
}
void MavkaParser::Operation_pre_notContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOperation_pre_not(this);
}

std::any MavkaParser::Operation_pre_notContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MavkaParserVisitor*>(visitor))
    return parserVisitor->visitOperation_pre_not(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Operation_asContext ------------------------------------------------------------------

std::vector<MavkaParser::NlsContext *> MavkaParser::Operation_asContext::nls() {
  return getRuleContexts<MavkaParser::NlsContext>();
}

MavkaParser::NlsContext* MavkaParser::Operation_asContext::nls(size_t i) {
  return getRuleContext<MavkaParser::NlsContext>(i);
}

MavkaParser::OperationContext* MavkaParser::Operation_asContext::operation() {
  return getRuleContext<MavkaParser::OperationContext>(0);
}

tree::TerminalNode* MavkaParser::Operation_asContext::KW_AS() {
  return getToken(MavkaParser::KW_AS, 0);
}

MavkaParser::TypeContext* MavkaParser::Operation_asContext::type() {
  return getRuleContext<MavkaParser::TypeContext>(0);
}

MavkaParser::Operation_asContext::Operation_asContext(OperationContext *ctx) { copyFrom(ctx); }

void MavkaParser::Operation_asContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOperation_as(this);
}
void MavkaParser::Operation_asContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOperation_as(this);
}

std::any MavkaParser::Operation_asContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MavkaParserVisitor*>(visitor))
    return parserVisitor->visitOperation_as(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Operation_atomContext ------------------------------------------------------------------

MavkaParser::AtomContext* MavkaParser::Operation_atomContext::atom() {
  return getRuleContext<MavkaParser::AtomContext>(0);
}

MavkaParser::Operation_atomContext::Operation_atomContext(OperationContext *ctx) { copyFrom(ctx); }

void MavkaParser::Operation_atomContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOperation_atom(this);
}
void MavkaParser::Operation_atomContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOperation_atom(this);
}

std::any MavkaParser::Operation_atomContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MavkaParserVisitor*>(visitor))
    return parserVisitor->visitOperation_atom(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Operation_subContext ------------------------------------------------------------------

std::vector<MavkaParser::NlsContext *> MavkaParser::Operation_subContext::nls() {
  return getRuleContexts<MavkaParser::NlsContext>();
}

MavkaParser::NlsContext* MavkaParser::Operation_subContext::nls(size_t i) {
  return getRuleContext<MavkaParser::NlsContext>(i);
}

std::vector<MavkaParser::OperationContext *> MavkaParser::Operation_subContext::operation() {
  return getRuleContexts<MavkaParser::OperationContext>();
}

MavkaParser::OperationContext* MavkaParser::Operation_subContext::operation(size_t i) {
  return getRuleContext<MavkaParser::OperationContext>(i);
}

tree::TerminalNode* MavkaParser::Operation_subContext::MINUS() {
  return getToken(MavkaParser::MINUS, 0);
}

MavkaParser::Operation_subContext::Operation_subContext(OperationContext *ctx) { copyFrom(ctx); }

void MavkaParser::Operation_subContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOperation_sub(this);
}
void MavkaParser::Operation_subContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOperation_sub(this);
}

std::any MavkaParser::Operation_subContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MavkaParserVisitor*>(visitor))
    return parserVisitor->visitOperation_sub(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Operation_modContext ------------------------------------------------------------------

std::vector<MavkaParser::NlsContext *> MavkaParser::Operation_modContext::nls() {
  return getRuleContexts<MavkaParser::NlsContext>();
}

MavkaParser::NlsContext* MavkaParser::Operation_modContext::nls(size_t i) {
  return getRuleContext<MavkaParser::NlsContext>(i);
}

std::vector<MavkaParser::OperationContext *> MavkaParser::Operation_modContext::operation() {
  return getRuleContexts<MavkaParser::OperationContext>();
}

MavkaParser::OperationContext* MavkaParser::Operation_modContext::operation(size_t i) {
  return getRuleContext<MavkaParser::OperationContext>(i);
}

tree::TerminalNode* MavkaParser::Operation_modContext::MOD() {
  return getToken(MavkaParser::MOD, 0);
}

MavkaParser::Operation_modContext::Operation_modContext(OperationContext *ctx) { copyFrom(ctx); }

void MavkaParser::Operation_modContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOperation_mod(this);
}
void MavkaParser::Operation_modContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOperation_mod(this);
}

std::any MavkaParser::Operation_modContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MavkaParserVisitor*>(visitor))
    return parserVisitor->visitOperation_mod(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Operation_mulContext ------------------------------------------------------------------

std::vector<MavkaParser::NlsContext *> MavkaParser::Operation_mulContext::nls() {
  return getRuleContexts<MavkaParser::NlsContext>();
}

MavkaParser::NlsContext* MavkaParser::Operation_mulContext::nls(size_t i) {
  return getRuleContext<MavkaParser::NlsContext>(i);
}

std::vector<MavkaParser::OperationContext *> MavkaParser::Operation_mulContext::operation() {
  return getRuleContexts<MavkaParser::OperationContext>();
}

MavkaParser::OperationContext* MavkaParser::Operation_mulContext::operation(size_t i) {
  return getRuleContext<MavkaParser::OperationContext>(i);
}

tree::TerminalNode* MavkaParser::Operation_mulContext::MULTIPLY() {
  return getToken(MavkaParser::MULTIPLY, 0);
}

MavkaParser::Operation_mulContext::Operation_mulContext(OperationContext *ctx) { copyFrom(ctx); }

void MavkaParser::Operation_mulContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOperation_mul(this);
}
void MavkaParser::Operation_mulContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOperation_mul(this);
}

std::any MavkaParser::Operation_mulContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MavkaParserVisitor*>(visitor))
    return parserVisitor->visitOperation_mul(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Operation_gtContext ------------------------------------------------------------------

std::vector<MavkaParser::NlsContext *> MavkaParser::Operation_gtContext::nls() {
  return getRuleContexts<MavkaParser::NlsContext>();
}

MavkaParser::NlsContext* MavkaParser::Operation_gtContext::nls(size_t i) {
  return getRuleContext<MavkaParser::NlsContext>(i);
}

std::vector<MavkaParser::OperationContext *> MavkaParser::Operation_gtContext::operation() {
  return getRuleContexts<MavkaParser::OperationContext>();
}

MavkaParser::OperationContext* MavkaParser::Operation_gtContext::operation(size_t i) {
  return getRuleContext<MavkaParser::OperationContext>(i);
}

tree::TerminalNode* MavkaParser::Operation_gtContext::GREATER() {
  return getToken(MavkaParser::GREATER, 0);
}

MavkaParser::Operation_gtContext::Operation_gtContext(OperationContext *ctx) { copyFrom(ctx); }

void MavkaParser::Operation_gtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOperation_gt(this);
}
void MavkaParser::Operation_gtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOperation_gt(this);
}

std::any MavkaParser::Operation_gtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MavkaParserVisitor*>(visitor))
    return parserVisitor->visitOperation_gt(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Operation_eqContext ------------------------------------------------------------------

std::vector<MavkaParser::NlsContext *> MavkaParser::Operation_eqContext::nls() {
  return getRuleContexts<MavkaParser::NlsContext>();
}

MavkaParser::NlsContext* MavkaParser::Operation_eqContext::nls(size_t i) {
  return getRuleContext<MavkaParser::NlsContext>(i);
}

std::vector<MavkaParser::OperationContext *> MavkaParser::Operation_eqContext::operation() {
  return getRuleContexts<MavkaParser::OperationContext>();
}

MavkaParser::OperationContext* MavkaParser::Operation_eqContext::operation(size_t i) {
  return getRuleContext<MavkaParser::OperationContext>(i);
}

MavkaParser::Op_eqContext* MavkaParser::Operation_eqContext::op_eq() {
  return getRuleContext<MavkaParser::Op_eqContext>(0);
}

MavkaParser::Operation_eqContext::Operation_eqContext(OperationContext *ctx) { copyFrom(ctx); }

void MavkaParser::Operation_eqContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOperation_eq(this);
}
void MavkaParser::Operation_eqContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOperation_eq(this);
}

std::any MavkaParser::Operation_eqContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MavkaParserVisitor*>(visitor))
    return parserVisitor->visitOperation_eq(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Operation_arrayContext ------------------------------------------------------------------

tree::TerminalNode* MavkaParser::Operation_arrayContext::BRACKET_OPEN() {
  return getToken(MavkaParser::BRACKET_OPEN, 0);
}

std::vector<MavkaParser::NlsContext *> MavkaParser::Operation_arrayContext::nls() {
  return getRuleContexts<MavkaParser::NlsContext>();
}

MavkaParser::NlsContext* MavkaParser::Operation_arrayContext::nls(size_t i) {
  return getRuleContext<MavkaParser::NlsContext>(i);
}

tree::TerminalNode* MavkaParser::Operation_arrayContext::BRACKET_CLOSE() {
  return getToken(MavkaParser::BRACKET_CLOSE, 0);
}

std::vector<MavkaParser::ExprContext *> MavkaParser::Operation_arrayContext::expr() {
  return getRuleContexts<MavkaParser::ExprContext>();
}

MavkaParser::ExprContext* MavkaParser::Operation_arrayContext::expr(size_t i) {
  return getRuleContext<MavkaParser::ExprContext>(i);
}

std::vector<tree::TerminalNode *> MavkaParser::Operation_arrayContext::COMA() {
  return getTokens(MavkaParser::COMA);
}

tree::TerminalNode* MavkaParser::Operation_arrayContext::COMA(size_t i) {
  return getToken(MavkaParser::COMA, i);
}

MavkaParser::Operation_arrayContext::Operation_arrayContext(OperationContext *ctx) { copyFrom(ctx); }

void MavkaParser::Operation_arrayContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOperation_array(this);
}
void MavkaParser::Operation_arrayContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOperation_array(this);
}

std::any MavkaParser::Operation_arrayContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MavkaParserVisitor*>(visitor))
    return parserVisitor->visitOperation_array(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Operation_pre_bw_notContext ------------------------------------------------------------------

MavkaParser::NlsContext* MavkaParser::Operation_pre_bw_notContext::nls() {
  return getRuleContext<MavkaParser::NlsContext>(0);
}

tree::TerminalNode* MavkaParser::Operation_pre_bw_notContext::TILDA() {
  return getToken(MavkaParser::TILDA, 0);
}

MavkaParser::OperationContext* MavkaParser::Operation_pre_bw_notContext::operation() {
  return getRuleContext<MavkaParser::OperationContext>(0);
}

MavkaParser::Operation_pre_bw_notContext::Operation_pre_bw_notContext(OperationContext *ctx) { copyFrom(ctx); }

void MavkaParser::Operation_pre_bw_notContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOperation_pre_bw_not(this);
}
void MavkaParser::Operation_pre_bw_notContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOperation_pre_bw_not(this);
}

std::any MavkaParser::Operation_pre_bw_notContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MavkaParserVisitor*>(visitor))
    return parserVisitor->visitOperation_pre_bw_not(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Operation_lorContext ------------------------------------------------------------------

std::vector<MavkaParser::NlsContext *> MavkaParser::Operation_lorContext::nls() {
  return getRuleContexts<MavkaParser::NlsContext>();
}

MavkaParser::NlsContext* MavkaParser::Operation_lorContext::nls(size_t i) {
  return getRuleContext<MavkaParser::NlsContext>(i);
}

std::vector<MavkaParser::OperationContext *> MavkaParser::Operation_lorContext::operation() {
  return getRuleContexts<MavkaParser::OperationContext>();
}

MavkaParser::OperationContext* MavkaParser::Operation_lorContext::operation(size_t i) {
  return getRuleContext<MavkaParser::OperationContext>(i);
}

MavkaParser::Op_lorContext* MavkaParser::Operation_lorContext::op_lor() {
  return getRuleContext<MavkaParser::Op_lorContext>(0);
}

MavkaParser::Operation_lorContext::Operation_lorContext(OperationContext *ctx) { copyFrom(ctx); }

void MavkaParser::Operation_lorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOperation_lor(this);
}
void MavkaParser::Operation_lorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOperation_lor(this);
}

std::any MavkaParser::Operation_lorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MavkaParserVisitor*>(visitor))
    return parserVisitor->visitOperation_lor(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Operation_ternaryContext ------------------------------------------------------------------

std::vector<MavkaParser::NlsContext *> MavkaParser::Operation_ternaryContext::nls() {
  return getRuleContexts<MavkaParser::NlsContext>();
}

MavkaParser::NlsContext* MavkaParser::Operation_ternaryContext::nls(size_t i) {
  return getRuleContext<MavkaParser::NlsContext>(i);
}

tree::TerminalNode* MavkaParser::Operation_ternaryContext::QUESTION() {
  return getToken(MavkaParser::QUESTION, 0);
}

tree::TerminalNode* MavkaParser::Operation_ternaryContext::COLON() {
  return getToken(MavkaParser::COLON, 0);
}

std::vector<MavkaParser::OperationContext *> MavkaParser::Operation_ternaryContext::operation() {
  return getRuleContexts<MavkaParser::OperationContext>();
}

MavkaParser::OperationContext* MavkaParser::Operation_ternaryContext::operation(size_t i) {
  return getRuleContext<MavkaParser::OperationContext>(i);
}

MavkaParser::Operation_ternaryContext::Operation_ternaryContext(OperationContext *ctx) { copyFrom(ctx); }

void MavkaParser::Operation_ternaryContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOperation_ternary(this);
}
void MavkaParser::Operation_ternaryContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOperation_ternary(this);
}

std::any MavkaParser::Operation_ternaryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MavkaParserVisitor*>(visitor))
    return parserVisitor->visitOperation_ternary(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Operation_urshiftContext ------------------------------------------------------------------

std::vector<MavkaParser::NlsContext *> MavkaParser::Operation_urshiftContext::nls() {
  return getRuleContexts<MavkaParser::NlsContext>();
}

MavkaParser::NlsContext* MavkaParser::Operation_urshiftContext::nls(size_t i) {
  return getRuleContext<MavkaParser::NlsContext>(i);
}

std::vector<MavkaParser::OperationContext *> MavkaParser::Operation_urshiftContext::operation() {
  return getRuleContexts<MavkaParser::OperationContext>();
}

MavkaParser::OperationContext* MavkaParser::Operation_urshiftContext::operation(size_t i) {
  return getRuleContext<MavkaParser::OperationContext>(i);
}

MavkaParser::Op_urshiftContext* MavkaParser::Operation_urshiftContext::op_urshift() {
  return getRuleContext<MavkaParser::Op_urshiftContext>(0);
}

MavkaParser::Operation_urshiftContext::Operation_urshiftContext(OperationContext *ctx) { copyFrom(ctx); }

void MavkaParser::Operation_urshiftContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOperation_urshift(this);
}
void MavkaParser::Operation_urshiftContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOperation_urshift(this);
}

std::any MavkaParser::Operation_urshiftContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MavkaParserVisitor*>(visitor))
    return parserVisitor->visitOperation_urshift(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Operation_divContext ------------------------------------------------------------------

std::vector<MavkaParser::NlsContext *> MavkaParser::Operation_divContext::nls() {
  return getRuleContexts<MavkaParser::NlsContext>();
}

MavkaParser::NlsContext* MavkaParser::Operation_divContext::nls(size_t i) {
  return getRuleContext<MavkaParser::NlsContext>(i);
}

std::vector<MavkaParser::OperationContext *> MavkaParser::Operation_divContext::operation() {
  return getRuleContexts<MavkaParser::OperationContext>();
}

MavkaParser::OperationContext* MavkaParser::Operation_divContext::operation(size_t i) {
  return getRuleContext<MavkaParser::OperationContext>(i);
}

tree::TerminalNode* MavkaParser::Operation_divContext::DIVIDE() {
  return getToken(MavkaParser::DIVIDE, 0);
}

MavkaParser::Operation_divContext::Operation_divContext(OperationContext *ctx) { copyFrom(ctx); }

void MavkaParser::Operation_divContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOperation_div(this);
}
void MavkaParser::Operation_divContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOperation_div(this);
}

std::any MavkaParser::Operation_divContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MavkaParserVisitor*>(visitor))
    return parserVisitor->visitOperation_div(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Operation_rshiftContext ------------------------------------------------------------------

std::vector<MavkaParser::NlsContext *> MavkaParser::Operation_rshiftContext::nls() {
  return getRuleContexts<MavkaParser::NlsContext>();
}

MavkaParser::NlsContext* MavkaParser::Operation_rshiftContext::nls(size_t i) {
  return getRuleContext<MavkaParser::NlsContext>(i);
}

std::vector<MavkaParser::OperationContext *> MavkaParser::Operation_rshiftContext::operation() {
  return getRuleContexts<MavkaParser::OperationContext>();
}

MavkaParser::OperationContext* MavkaParser::Operation_rshiftContext::operation(size_t i) {
  return getRuleContext<MavkaParser::OperationContext>(i);
}

MavkaParser::Op_rshiftContext* MavkaParser::Operation_rshiftContext::op_rshift() {
  return getRuleContext<MavkaParser::Op_rshiftContext>(0);
}

MavkaParser::Operation_rshiftContext::Operation_rshiftContext(OperationContext *ctx) { copyFrom(ctx); }

void MavkaParser::Operation_rshiftContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOperation_rshift(this);
}
void MavkaParser::Operation_rshiftContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOperation_rshift(this);
}

std::any MavkaParser::Operation_rshiftContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MavkaParserVisitor*>(visitor))
    return parserVisitor->visitOperation_rshift(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Operation_lshiftContext ------------------------------------------------------------------

std::vector<MavkaParser::NlsContext *> MavkaParser::Operation_lshiftContext::nls() {
  return getRuleContexts<MavkaParser::NlsContext>();
}

MavkaParser::NlsContext* MavkaParser::Operation_lshiftContext::nls(size_t i) {
  return getRuleContext<MavkaParser::NlsContext>(i);
}

std::vector<MavkaParser::OperationContext *> MavkaParser::Operation_lshiftContext::operation() {
  return getRuleContexts<MavkaParser::OperationContext>();
}

MavkaParser::OperationContext* MavkaParser::Operation_lshiftContext::operation(size_t i) {
  return getRuleContext<MavkaParser::OperationContext>(i);
}

MavkaParser::Op_lshiftContext* MavkaParser::Operation_lshiftContext::op_lshift() {
  return getRuleContext<MavkaParser::Op_lshiftContext>(0);
}

MavkaParser::Operation_lshiftContext::Operation_lshiftContext(OperationContext *ctx) { copyFrom(ctx); }

void MavkaParser::Operation_lshiftContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOperation_lshift(this);
}
void MavkaParser::Operation_lshiftContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOperation_lshift(this);
}

std::any MavkaParser::Operation_lshiftContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MavkaParserVisitor*>(visitor))
    return parserVisitor->visitOperation_lshift(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Operation_andContext ------------------------------------------------------------------

std::vector<MavkaParser::NlsContext *> MavkaParser::Operation_andContext::nls() {
  return getRuleContexts<MavkaParser::NlsContext>();
}

MavkaParser::NlsContext* MavkaParser::Operation_andContext::nls(size_t i) {
  return getRuleContext<MavkaParser::NlsContext>(i);
}

std::vector<MavkaParser::OperationContext *> MavkaParser::Operation_andContext::operation() {
  return getRuleContexts<MavkaParser::OperationContext>();
}

MavkaParser::OperationContext* MavkaParser::Operation_andContext::operation(size_t i) {
  return getRuleContext<MavkaParser::OperationContext>(i);
}

tree::TerminalNode* MavkaParser::Operation_andContext::AND() {
  return getToken(MavkaParser::AND, 0);
}

MavkaParser::Operation_andContext::Operation_andContext(OperationContext *ctx) { copyFrom(ctx); }

void MavkaParser::Operation_andContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOperation_and(this);
}
void MavkaParser::Operation_andContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOperation_and(this);
}

std::any MavkaParser::Operation_andContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MavkaParserVisitor*>(visitor))
    return parserVisitor->visitOperation_and(this);
  else
    return visitor->visitChildren(this);
}

MavkaParser::OperationContext* MavkaParser::operation() {
   return operation(0);
}

MavkaParser::OperationContext* MavkaParser::operation(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  MavkaParser::OperationContext *_localctx = _tracker.createInstance<OperationContext>(_ctx, parentState);
  MavkaParser::OperationContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 12;
  enterRecursionRule(_localctx, 12, MavkaParser::RuleOperation, precedence);

    size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(239);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<Operation_atomContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;

      setState(166);
      atom(0);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<Operation_objectContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(167);
      match(MavkaParser::PAREN_OPEN);
      setState(168);
      nls();
      setState(180);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == MavkaParser::ID) {
        setState(169);
        object_arg();
        setState(177);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx);
        while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
          if (alt == 1) {
            setState(170);
            nls();
            setState(171);
            match(MavkaParser::COMA);
            setState(172);
            nls();
            setState(173);
            object_arg(); 
          }
          setState(179);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx);
        }
      }
      setState(182);
      nls();
      setState(183);
      match(MavkaParser::PAREN_CLOSE);
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<Operation_dictContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(185);
      match(MavkaParser::BRACKET_OPEN);
      setState(186);
      nls();
      setState(199);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == MavkaParser::NUMBER

      || _la == MavkaParser::STRING) {
        setState(187);
        dict_arg();
        setState(188);
        nls();
        setState(196);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx);
        while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
          if (alt == 1) {
            setState(189);
            nls();
            setState(190);
            match(MavkaParser::COMA);
            setState(191);
            nls();
            setState(192);
            dict_arg(); 
          }
          setState(198);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx);
        }
      }
      setState(201);
      nls();
      setState(202);
      match(MavkaParser::BRACKET_CLOSE);
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<Operation_arrayContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(204);
      match(MavkaParser::BRACKET_OPEN);
      setState(205);
      nls();
      setState(218);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (((((_la - 43) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 43)) & 84559107) != 0)) {
        setState(206);
        expr();
        setState(207);
        nls();
        setState(215);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx);
        while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
          if (alt == 1) {
            setState(208);
            nls();
            setState(209);
            match(MavkaParser::COMA);
            setState(210);
            nls();
            setState(211);
            expr(); 
          }
          setState(217);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx);
        }
      }
      setState(220);
      nls();
      setState(221);
      match(MavkaParser::BRACKET_CLOSE);
      break;
    }

    case 5: {
      _localctx = _tracker.createInstance<Operation_pre_notContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(223);
      antlrcpp::downCast<Operation_pre_notContext *>(_localctx)->op = match(MavkaParser::EXCLAMATION);
      setState(224);
      nls();
      setState(225);
      antlrcpp::downCast<Operation_pre_notContext *>(_localctx)->right = operation(24);
      break;
    }

    case 6: {
      _localctx = _tracker.createInstance<Operation_pre_bw_notContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(227);
      antlrcpp::downCast<Operation_pre_bw_notContext *>(_localctx)->op = match(MavkaParser::TILDA);
      setState(228);
      nls();
      setState(229);
      antlrcpp::downCast<Operation_pre_bw_notContext *>(_localctx)->right = operation(23);
      break;
    }

    case 7: {
      _localctx = _tracker.createInstance<Operation_pre_plusContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(231);
      antlrcpp::downCast<Operation_pre_plusContext *>(_localctx)->op = match(MavkaParser::PLUS);
      setState(232);
      nls();
      setState(233);
      antlrcpp::downCast<Operation_pre_plusContext *>(_localctx)->right = operation(22);
      break;
    }

    case 8: {
      _localctx = _tracker.createInstance<Operation_pre_minusContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(235);
      antlrcpp::downCast<Operation_pre_minusContext *>(_localctx)->op = match(MavkaParser::MINUS);
      setState(236);
      nls();
      setState(237);
      antlrcpp::downCast<Operation_pre_minusContext *>(_localctx)->right = operation(21);
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(373);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(371);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<Operation_mulContext>(_tracker.createInstance<OperationContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleOperation);
          setState(241);

          if (!(precpred(_ctx, 20))) throw FailedPredicateException(this, "precpred(_ctx, 20)");
          setState(242);
          nls();
          setState(243);
          antlrcpp::downCast<Operation_mulContext *>(_localctx)->op = match(MavkaParser::MULTIPLY);
          setState(244);
          nls();
          setState(245);
          antlrcpp::downCast<Operation_mulContext *>(_localctx)->right = operation(21);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<Operation_divContext>(_tracker.createInstance<OperationContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleOperation);
          setState(247);

          if (!(precpred(_ctx, 19))) throw FailedPredicateException(this, "precpred(_ctx, 19)");
          setState(248);
          nls();
          setState(249);
          antlrcpp::downCast<Operation_divContext *>(_localctx)->op = match(MavkaParser::DIVIDE);
          setState(250);
          nls();
          setState(251);
          antlrcpp::downCast<Operation_divContext *>(_localctx)->right = operation(20);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<Operation_modContext>(_tracker.createInstance<OperationContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleOperation);
          setState(253);

          if (!(precpred(_ctx, 18))) throw FailedPredicateException(this, "precpred(_ctx, 18)");
          setState(254);
          nls();
          setState(255);
          antlrcpp::downCast<Operation_modContext *>(_localctx)->op = match(MavkaParser::MOD);
          setState(256);
          nls();
          setState(257);
          antlrcpp::downCast<Operation_modContext *>(_localctx)->right = operation(19);
          break;
        }

        case 4: {
          auto newContext = _tracker.createInstance<Operation_addContext>(_tracker.createInstance<OperationContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleOperation);
          setState(259);

          if (!(precpred(_ctx, 17))) throw FailedPredicateException(this, "precpred(_ctx, 17)");
          setState(260);
          nls();
          setState(261);
          antlrcpp::downCast<Operation_addContext *>(_localctx)->op = match(MavkaParser::PLUS);
          setState(262);
          nls();
          setState(263);
          antlrcpp::downCast<Operation_addContext *>(_localctx)->right = operation(18);
          break;
        }

        case 5: {
          auto newContext = _tracker.createInstance<Operation_subContext>(_tracker.createInstance<OperationContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleOperation);
          setState(265);

          if (!(precpred(_ctx, 16))) throw FailedPredicateException(this, "precpred(_ctx, 16)");
          setState(266);
          nls();
          setState(267);
          antlrcpp::downCast<Operation_subContext *>(_localctx)->op = match(MavkaParser::MINUS);
          setState(268);
          nls();
          setState(269);
          antlrcpp::downCast<Operation_subContext *>(_localctx)->right = operation(17);
          break;
        }

        case 6: {
          auto newContext = _tracker.createInstance<Operation_lshiftContext>(_tracker.createInstance<OperationContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleOperation);
          setState(271);

          if (!(precpred(_ctx, 15))) throw FailedPredicateException(this, "precpred(_ctx, 15)");
          setState(272);
          nls();
          setState(273);
          antlrcpp::downCast<Operation_lshiftContext *>(_localctx)->op = op_lshift();
          setState(274);
          nls();
          setState(275);
          antlrcpp::downCast<Operation_lshiftContext *>(_localctx)->right = operation(16);
          break;
        }

        case 7: {
          auto newContext = _tracker.createInstance<Operation_rshiftContext>(_tracker.createInstance<OperationContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleOperation);
          setState(277);

          if (!(precpred(_ctx, 14))) throw FailedPredicateException(this, "precpred(_ctx, 14)");
          setState(278);
          nls();
          setState(279);
          antlrcpp::downCast<Operation_rshiftContext *>(_localctx)->op = op_rshift();
          setState(280);
          nls();
          setState(281);
          antlrcpp::downCast<Operation_rshiftContext *>(_localctx)->right = operation(15);
          break;
        }

        case 8: {
          auto newContext = _tracker.createInstance<Operation_urshiftContext>(_tracker.createInstance<OperationContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleOperation);
          setState(283);

          if (!(precpred(_ctx, 13))) throw FailedPredicateException(this, "precpred(_ctx, 13)");
          setState(284);
          nls();
          setState(285);
          antlrcpp::downCast<Operation_urshiftContext *>(_localctx)->op = op_urshift();
          setState(286);
          nls();
          setState(287);
          antlrcpp::downCast<Operation_urshiftContext *>(_localctx)->right = operation(14);
          break;
        }

        case 9: {
          auto newContext = _tracker.createInstance<Operation_ltContext>(_tracker.createInstance<OperationContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleOperation);
          setState(289);

          if (!(precpred(_ctx, 12))) throw FailedPredicateException(this, "precpred(_ctx, 12)");
          setState(290);
          nls();
          setState(291);
          antlrcpp::downCast<Operation_ltContext *>(_localctx)->op = match(MavkaParser::LESSER);
          setState(292);
          nls();
          setState(293);
          antlrcpp::downCast<Operation_ltContext *>(_localctx)->right = operation(13);
          break;
        }

        case 10: {
          auto newContext = _tracker.createInstance<Operation_lteContext>(_tracker.createInstance<OperationContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleOperation);
          setState(295);

          if (!(precpred(_ctx, 11))) throw FailedPredicateException(this, "precpred(_ctx, 11)");
          setState(296);
          nls();
          setState(297);
          antlrcpp::downCast<Operation_lteContext *>(_localctx)->op = op_lte();
          setState(298);
          nls();
          setState(299);
          antlrcpp::downCast<Operation_lteContext *>(_localctx)->right = operation(12);
          break;
        }

        case 11: {
          auto newContext = _tracker.createInstance<Operation_gtContext>(_tracker.createInstance<OperationContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleOperation);
          setState(301);

          if (!(precpred(_ctx, 10))) throw FailedPredicateException(this, "precpred(_ctx, 10)");
          setState(302);
          nls();
          setState(303);
          antlrcpp::downCast<Operation_gtContext *>(_localctx)->op = match(MavkaParser::GREATER);
          setState(304);
          nls();
          setState(305);
          antlrcpp::downCast<Operation_gtContext *>(_localctx)->right = operation(11);
          break;
        }

        case 12: {
          auto newContext = _tracker.createInstance<Operation_gteContext>(_tracker.createInstance<OperationContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleOperation);
          setState(307);

          if (!(precpred(_ctx, 9))) throw FailedPredicateException(this, "precpred(_ctx, 9)");
          setState(308);
          nls();
          setState(309);
          antlrcpp::downCast<Operation_gteContext *>(_localctx)->op = op_gte();
          setState(310);
          nls();
          setState(311);
          antlrcpp::downCast<Operation_gteContext *>(_localctx)->right = operation(10);
          break;
        }

        case 13: {
          auto newContext = _tracker.createInstance<Operation_eqContext>(_tracker.createInstance<OperationContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleOperation);
          setState(313);

          if (!(precpred(_ctx, 8))) throw FailedPredicateException(this, "precpred(_ctx, 8)");
          setState(314);
          nls();
          setState(315);
          antlrcpp::downCast<Operation_eqContext *>(_localctx)->op = op_eq();
          setState(316);
          nls();
          setState(317);
          antlrcpp::downCast<Operation_eqContext *>(_localctx)->right = operation(9);
          break;
        }

        case 14: {
          auto newContext = _tracker.createInstance<Operation_neqContext>(_tracker.createInstance<OperationContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleOperation);
          setState(319);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(320);
          nls();
          setState(321);
          antlrcpp::downCast<Operation_neqContext *>(_localctx)->op = op_neq();
          setState(322);
          nls();
          setState(323);
          antlrcpp::downCast<Operation_neqContext *>(_localctx)->right = operation(8);
          break;
        }

        case 15: {
          auto newContext = _tracker.createInstance<Operation_andContext>(_tracker.createInstance<OperationContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleOperation);
          setState(325);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(326);
          nls();
          setState(327);
          antlrcpp::downCast<Operation_andContext *>(_localctx)->op = match(MavkaParser::AND);
          setState(328);
          nls();
          setState(329);
          antlrcpp::downCast<Operation_andContext *>(_localctx)->right = operation(7);
          break;
        }

        case 16: {
          auto newContext = _tracker.createInstance<Operation_xorContext>(_tracker.createInstance<OperationContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleOperation);
          setState(331);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(332);
          nls();
          setState(333);
          antlrcpp::downCast<Operation_xorContext *>(_localctx)->op = match(MavkaParser::POWER);
          setState(334);
          nls();
          setState(335);
          antlrcpp::downCast<Operation_xorContext *>(_localctx)->right = operation(6);
          break;
        }

        case 17: {
          auto newContext = _tracker.createInstance<Operation_orContext>(_tracker.createInstance<OperationContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleOperation);
          setState(337);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(338);
          nls();
          setState(339);
          antlrcpp::downCast<Operation_orContext *>(_localctx)->op = match(MavkaParser::OR);
          setState(340);
          nls();
          setState(341);
          antlrcpp::downCast<Operation_orContext *>(_localctx)->right = operation(5);
          break;
        }

        case 18: {
          auto newContext = _tracker.createInstance<Operation_landContext>(_tracker.createInstance<OperationContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleOperation);
          setState(343);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(344);
          nls();
          setState(345);
          antlrcpp::downCast<Operation_landContext *>(_localctx)->op = op_land();
          setState(346);
          nls();
          setState(347);
          antlrcpp::downCast<Operation_landContext *>(_localctx)->right = operation(4);
          break;
        }

        case 19: {
          auto newContext = _tracker.createInstance<Operation_lorContext>(_tracker.createInstance<OperationContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleOperation);
          setState(349);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(350);
          nls();
          setState(351);
          antlrcpp::downCast<Operation_lorContext *>(_localctx)->op = op_lor();
          setState(352);
          nls();
          setState(353);
          antlrcpp::downCast<Operation_lorContext *>(_localctx)->right = operation(3);
          break;
        }

        case 20: {
          auto newContext = _tracker.createInstance<Operation_ternaryContext>(_tracker.createInstance<OperationContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->cond = previousContext;
          pushNewRecursionContext(newContext, startState, RuleOperation);
          setState(355);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(356);
          nls();
          setState(357);
          match(MavkaParser::QUESTION);
          setState(358);
          nls();
          setState(359);
          antlrcpp::downCast<Operation_ternaryContext *>(_localctx)->ifok = operation(0);
          setState(360);
          nls();
          setState(361);
          match(MavkaParser::COLON);
          setState(362);
          nls();
          setState(363);
          antlrcpp::downCast<Operation_ternaryContext *>(_localctx)->ifnot = operation(2);
          break;
        }

        case 21: {
          auto newContext = _tracker.createInstance<Operation_asContext>(_tracker.createInstance<OperationContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleOperation);
          setState(365);

          if (!(precpred(_ctx, 25))) throw FailedPredicateException(this, "precpred(_ctx, 25)");
          setState(366);
          nls();
          setState(367);
          antlrcpp::downCast<Operation_asContext *>(_localctx)->op = match(MavkaParser::KW_AS);
          setState(368);
          nls();

          setState(369);
          antlrcpp::downCast<Operation_asContext *>(_localctx)->right_type = type();
          break;
        }

        default:
          break;
        } 
      }
      setState(375);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- Op_lshiftContext ------------------------------------------------------------------

MavkaParser::Op_lshiftContext::Op_lshiftContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> MavkaParser::Op_lshiftContext::LESSER() {
  return getTokens(MavkaParser::LESSER);
}

tree::TerminalNode* MavkaParser::Op_lshiftContext::LESSER(size_t i) {
  return getToken(MavkaParser::LESSER, i);
}


size_t MavkaParser::Op_lshiftContext::getRuleIndex() const {
  return MavkaParser::RuleOp_lshift;
}

void MavkaParser::Op_lshiftContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOp_lshift(this);
}

void MavkaParser::Op_lshiftContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOp_lshift(this);
}


std::any MavkaParser::Op_lshiftContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MavkaParserVisitor*>(visitor))
    return parserVisitor->visitOp_lshift(this);
  else
    return visitor->visitChildren(this);
}

MavkaParser::Op_lshiftContext* MavkaParser::op_lshift() {
  Op_lshiftContext *_localctx = _tracker.createInstance<Op_lshiftContext>(_ctx, getState());
  enterRule(_localctx, 14, MavkaParser::RuleOp_lshift);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(376);
    match(MavkaParser::LESSER);
    setState(377);
    match(MavkaParser::LESSER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Op_rshiftContext ------------------------------------------------------------------

MavkaParser::Op_rshiftContext::Op_rshiftContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> MavkaParser::Op_rshiftContext::GREATER() {
  return getTokens(MavkaParser::GREATER);
}

tree::TerminalNode* MavkaParser::Op_rshiftContext::GREATER(size_t i) {
  return getToken(MavkaParser::GREATER, i);
}


size_t MavkaParser::Op_rshiftContext::getRuleIndex() const {
  return MavkaParser::RuleOp_rshift;
}

void MavkaParser::Op_rshiftContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOp_rshift(this);
}

void MavkaParser::Op_rshiftContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOp_rshift(this);
}


std::any MavkaParser::Op_rshiftContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MavkaParserVisitor*>(visitor))
    return parserVisitor->visitOp_rshift(this);
  else
    return visitor->visitChildren(this);
}

MavkaParser::Op_rshiftContext* MavkaParser::op_rshift() {
  Op_rshiftContext *_localctx = _tracker.createInstance<Op_rshiftContext>(_ctx, getState());
  enterRule(_localctx, 16, MavkaParser::RuleOp_rshift);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(379);
    match(MavkaParser::GREATER);
    setState(380);
    match(MavkaParser::GREATER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Op_urshiftContext ------------------------------------------------------------------

MavkaParser::Op_urshiftContext::Op_urshiftContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> MavkaParser::Op_urshiftContext::GREATER() {
  return getTokens(MavkaParser::GREATER);
}

tree::TerminalNode* MavkaParser::Op_urshiftContext::GREATER(size_t i) {
  return getToken(MavkaParser::GREATER, i);
}


size_t MavkaParser::Op_urshiftContext::getRuleIndex() const {
  return MavkaParser::RuleOp_urshift;
}

void MavkaParser::Op_urshiftContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOp_urshift(this);
}

void MavkaParser::Op_urshiftContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOp_urshift(this);
}


std::any MavkaParser::Op_urshiftContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MavkaParserVisitor*>(visitor))
    return parserVisitor->visitOp_urshift(this);
  else
    return visitor->visitChildren(this);
}

MavkaParser::Op_urshiftContext* MavkaParser::op_urshift() {
  Op_urshiftContext *_localctx = _tracker.createInstance<Op_urshiftContext>(_ctx, getState());
  enterRule(_localctx, 18, MavkaParser::RuleOp_urshift);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(382);
    match(MavkaParser::GREATER);
    setState(383);
    match(MavkaParser::GREATER);
    setState(384);
    match(MavkaParser::GREATER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Op_lteContext ------------------------------------------------------------------

MavkaParser::Op_lteContext::Op_lteContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MavkaParser::Op_lteContext::LESSER() {
  return getToken(MavkaParser::LESSER, 0);
}

tree::TerminalNode* MavkaParser::Op_lteContext::EQUAL() {
  return getToken(MavkaParser::EQUAL, 0);
}


size_t MavkaParser::Op_lteContext::getRuleIndex() const {
  return MavkaParser::RuleOp_lte;
}

void MavkaParser::Op_lteContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOp_lte(this);
}

void MavkaParser::Op_lteContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOp_lte(this);
}


std::any MavkaParser::Op_lteContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MavkaParserVisitor*>(visitor))
    return parserVisitor->visitOp_lte(this);
  else
    return visitor->visitChildren(this);
}

MavkaParser::Op_lteContext* MavkaParser::op_lte() {
  Op_lteContext *_localctx = _tracker.createInstance<Op_lteContext>(_ctx, getState());
  enterRule(_localctx, 20, MavkaParser::RuleOp_lte);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(386);
    match(MavkaParser::LESSER);
    setState(387);
    match(MavkaParser::EQUAL);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Op_gteContext ------------------------------------------------------------------

MavkaParser::Op_gteContext::Op_gteContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MavkaParser::Op_gteContext::GREATER() {
  return getToken(MavkaParser::GREATER, 0);
}

tree::TerminalNode* MavkaParser::Op_gteContext::EQUAL() {
  return getToken(MavkaParser::EQUAL, 0);
}


size_t MavkaParser::Op_gteContext::getRuleIndex() const {
  return MavkaParser::RuleOp_gte;
}

void MavkaParser::Op_gteContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOp_gte(this);
}

void MavkaParser::Op_gteContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOp_gte(this);
}


std::any MavkaParser::Op_gteContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MavkaParserVisitor*>(visitor))
    return parserVisitor->visitOp_gte(this);
  else
    return visitor->visitChildren(this);
}

MavkaParser::Op_gteContext* MavkaParser::op_gte() {
  Op_gteContext *_localctx = _tracker.createInstance<Op_gteContext>(_ctx, getState());
  enterRule(_localctx, 22, MavkaParser::RuleOp_gte);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(389);
    match(MavkaParser::GREATER);
    setState(390);
    match(MavkaParser::EQUAL);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Op_eqContext ------------------------------------------------------------------

MavkaParser::Op_eqContext::Op_eqContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> MavkaParser::Op_eqContext::EQUAL() {
  return getTokens(MavkaParser::EQUAL);
}

tree::TerminalNode* MavkaParser::Op_eqContext::EQUAL(size_t i) {
  return getToken(MavkaParser::EQUAL, i);
}


size_t MavkaParser::Op_eqContext::getRuleIndex() const {
  return MavkaParser::RuleOp_eq;
}

void MavkaParser::Op_eqContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOp_eq(this);
}

void MavkaParser::Op_eqContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOp_eq(this);
}


std::any MavkaParser::Op_eqContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MavkaParserVisitor*>(visitor))
    return parserVisitor->visitOp_eq(this);
  else
    return visitor->visitChildren(this);
}

MavkaParser::Op_eqContext* MavkaParser::op_eq() {
  Op_eqContext *_localctx = _tracker.createInstance<Op_eqContext>(_ctx, getState());
  enterRule(_localctx, 24, MavkaParser::RuleOp_eq);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(392);
    match(MavkaParser::EQUAL);
    setState(393);
    match(MavkaParser::EQUAL);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Op_neqContext ------------------------------------------------------------------

MavkaParser::Op_neqContext::Op_neqContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MavkaParser::Op_neqContext::EXCLAMATION() {
  return getToken(MavkaParser::EXCLAMATION, 0);
}

tree::TerminalNode* MavkaParser::Op_neqContext::EQUAL() {
  return getToken(MavkaParser::EQUAL, 0);
}


size_t MavkaParser::Op_neqContext::getRuleIndex() const {
  return MavkaParser::RuleOp_neq;
}

void MavkaParser::Op_neqContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOp_neq(this);
}

void MavkaParser::Op_neqContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOp_neq(this);
}


std::any MavkaParser::Op_neqContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MavkaParserVisitor*>(visitor))
    return parserVisitor->visitOp_neq(this);
  else
    return visitor->visitChildren(this);
}

MavkaParser::Op_neqContext* MavkaParser::op_neq() {
  Op_neqContext *_localctx = _tracker.createInstance<Op_neqContext>(_ctx, getState());
  enterRule(_localctx, 26, MavkaParser::RuleOp_neq);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(395);
    match(MavkaParser::EXCLAMATION);
    setState(396);
    match(MavkaParser::EQUAL);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Op_landContext ------------------------------------------------------------------

MavkaParser::Op_landContext::Op_landContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> MavkaParser::Op_landContext::AND() {
  return getTokens(MavkaParser::AND);
}

tree::TerminalNode* MavkaParser::Op_landContext::AND(size_t i) {
  return getToken(MavkaParser::AND, i);
}


size_t MavkaParser::Op_landContext::getRuleIndex() const {
  return MavkaParser::RuleOp_land;
}

void MavkaParser::Op_landContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOp_land(this);
}

void MavkaParser::Op_landContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOp_land(this);
}


std::any MavkaParser::Op_landContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MavkaParserVisitor*>(visitor))
    return parserVisitor->visitOp_land(this);
  else
    return visitor->visitChildren(this);
}

MavkaParser::Op_landContext* MavkaParser::op_land() {
  Op_landContext *_localctx = _tracker.createInstance<Op_landContext>(_ctx, getState());
  enterRule(_localctx, 28, MavkaParser::RuleOp_land);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(398);
    match(MavkaParser::AND);
    setState(399);
    match(MavkaParser::AND);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Op_lorContext ------------------------------------------------------------------

MavkaParser::Op_lorContext::Op_lorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> MavkaParser::Op_lorContext::OR() {
  return getTokens(MavkaParser::OR);
}

tree::TerminalNode* MavkaParser::Op_lorContext::OR(size_t i) {
  return getToken(MavkaParser::OR, i);
}


size_t MavkaParser::Op_lorContext::getRuleIndex() const {
  return MavkaParser::RuleOp_lor;
}

void MavkaParser::Op_lorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOp_lor(this);
}

void MavkaParser::Op_lorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOp_lor(this);
}


std::any MavkaParser::Op_lorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MavkaParserVisitor*>(visitor))
    return parserVisitor->visitOp_lor(this);
  else
    return visitor->visitChildren(this);
}

MavkaParser::Op_lorContext* MavkaParser::op_lor() {
  Op_lorContext *_localctx = _tracker.createInstance<Op_lorContext>(_ctx, getState());
  enterRule(_localctx, 30, MavkaParser::RuleOp_lor);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(401);
    match(MavkaParser::OR);
    setState(402);
    match(MavkaParser::OR);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- GendefContext ------------------------------------------------------------------

MavkaParser::GendefContext::GendefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MavkaParser::GendefContext::ID() {
  return getToken(MavkaParser::ID, 0);
}


size_t MavkaParser::GendefContext::getRuleIndex() const {
  return MavkaParser::RuleGendef;
}

void MavkaParser::GendefContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterGendef(this);
}

void MavkaParser::GendefContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitGendef(this);
}


std::any MavkaParser::GendefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MavkaParserVisitor*>(visitor))
    return parserVisitor->visitGendef(this);
  else
    return visitor->visitChildren(this);
}

MavkaParser::GendefContext* MavkaParser::gendef() {
  GendefContext *_localctx = _tracker.createInstance<GendefContext>(_ctx, getState());
  enterRule(_localctx, 32, MavkaParser::RuleGendef);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(404);
    match(MavkaParser::ID);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExprContext ------------------------------------------------------------------

MavkaParser::ExprContext::ExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t MavkaParser::ExprContext::getRuleIndex() const {
  return MavkaParser::RuleExpr;
}

void MavkaParser::ExprContext::copyFrom(ExprContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- Expr_operationContext ------------------------------------------------------------------

MavkaParser::OperationContext* MavkaParser::Expr_operationContext::operation() {
  return getRuleContext<MavkaParser::OperationContext>(0);
}

MavkaParser::Expr_operationContext::Expr_operationContext(ExprContext *ctx) { copyFrom(ctx); }

void MavkaParser::Expr_operationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpr_operation(this);
}
void MavkaParser::Expr_operationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpr_operation(this);
}

std::any MavkaParser::Expr_operationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MavkaParserVisitor*>(visitor))
    return parserVisitor->visitExpr_operation(this);
  else
    return visitor->visitChildren(this);
}
MavkaParser::ExprContext* MavkaParser::expr() {
  ExprContext *_localctx = _tracker.createInstance<ExprContext>(_ctx, getState());
  enterRule(_localctx, 34, MavkaParser::RuleExpr);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    _localctx = _tracker.createInstance<MavkaParser::Expr_operationContext>(_localctx);
    enterOuterAlt(_localctx, 1);
    setState(406);
    operation(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Structure_defineContext ------------------------------------------------------------------

MavkaParser::Structure_defineContext::Structure_defineContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MavkaParser::Structure_defineContext::KW_STRUCTURE() {
  return getToken(MavkaParser::KW_STRUCTURE, 0);
}

std::vector<MavkaParser::NlContext *> MavkaParser::Structure_defineContext::nl() {
  return getRuleContexts<MavkaParser::NlContext>();
}

MavkaParser::NlContext* MavkaParser::Structure_defineContext::nl(size_t i) {
  return getRuleContext<MavkaParser::NlContext>(i);
}

std::vector<MavkaParser::NlsContext *> MavkaParser::Structure_defineContext::nls() {
  return getRuleContexts<MavkaParser::NlsContext>();
}

MavkaParser::NlsContext* MavkaParser::Structure_defineContext::nls(size_t i) {
  return getRuleContext<MavkaParser::NlsContext>(i);
}

tree::TerminalNode* MavkaParser::Structure_defineContext::KW_END() {
  return getToken(MavkaParser::KW_END, 0);
}

tree::TerminalNode* MavkaParser::Structure_defineContext::ID() {
  return getToken(MavkaParser::ID, 0);
}

tree::TerminalNode* MavkaParser::Structure_defineContext::KW_IS() {
  return getToken(MavkaParser::KW_IS, 0);
}

std::vector<MavkaParser::Structure_elementContext *> MavkaParser::Structure_defineContext::structure_element() {
  return getRuleContexts<MavkaParser::Structure_elementContext>();
}

MavkaParser::Structure_elementContext* MavkaParser::Structure_defineContext::structure_element(size_t i) {
  return getRuleContext<MavkaParser::Structure_elementContext>(i);
}

MavkaParser::AtomContext* MavkaParser::Structure_defineContext::atom() {
  return getRuleContext<MavkaParser::AtomContext>(0);
}


size_t MavkaParser::Structure_defineContext::getRuleIndex() const {
  return MavkaParser::RuleStructure_define;
}

void MavkaParser::Structure_defineContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStructure_define(this);
}

void MavkaParser::Structure_defineContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStructure_define(this);
}


std::any MavkaParser::Structure_defineContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MavkaParserVisitor*>(visitor))
    return parserVisitor->visitStructure_define(this);
  else
    return visitor->visitChildren(this);
}

MavkaParser::Structure_defineContext* MavkaParser::structure_define() {
  Structure_defineContext *_localctx = _tracker.createInstance<Structure_defineContext>(_ctx, getState());
  enterRule(_localctx, 36, MavkaParser::RuleStructure_define);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(408);
    match(MavkaParser::KW_STRUCTURE);
    setState(409);
    antlrcpp::downCast<Structure_defineContext *>(_localctx)->id = match(MavkaParser::ID);
    setState(412);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == MavkaParser::KW_IS) {
      setState(410);
      match(MavkaParser::KW_IS);
      setState(411);
      antlrcpp::downCast<Structure_defineContext *>(_localctx)->s_parent = atom(0);
    }
    setState(414);
    nl();
    setState(426);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == MavkaParser::ID) {
      setState(415);
      structure_element();
      setState(416);
      nls();
      setState(423);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(417);
          nl();
          setState(418);
          nls();
          setState(419);
          structure_element(); 
        }
        setState(425);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx);
      }
    }
    setState(428);
    nls();
    setState(429);
    match(MavkaParser::KW_END);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Structure_elementContext ------------------------------------------------------------------

MavkaParser::Structure_elementContext::Structure_elementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MavkaParser::ParamContext* MavkaParser::Structure_elementContext::param() {
  return getRuleContext<MavkaParser::ParamContext>(0);
}


size_t MavkaParser::Structure_elementContext::getRuleIndex() const {
  return MavkaParser::RuleStructure_element;
}

void MavkaParser::Structure_elementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStructure_element(this);
}

void MavkaParser::Structure_elementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStructure_element(this);
}


std::any MavkaParser::Structure_elementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MavkaParserVisitor*>(visitor))
    return parserVisitor->visitStructure_element(this);
  else
    return visitor->visitChildren(this);
}

MavkaParser::Structure_elementContext* MavkaParser::structure_element() {
  Structure_elementContext *_localctx = _tracker.createInstance<Structure_elementContext>(_ctx, getState());
  enterRule(_localctx, 38, MavkaParser::RuleStructure_element);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(431);
    param();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Diia_defineContext ------------------------------------------------------------------

MavkaParser::Diia_defineContext::Diia_defineContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MavkaParser::Diia_defineContext::KW_DIIA() {
  return getToken(MavkaParser::KW_DIIA, 0);
}

tree::TerminalNode* MavkaParser::Diia_defineContext::PAREN_OPEN() {
  return getToken(MavkaParser::PAREN_OPEN, 0);
}

std::vector<MavkaParser::NlsContext *> MavkaParser::Diia_defineContext::nls() {
  return getRuleContexts<MavkaParser::NlsContext>();
}

MavkaParser::NlsContext* MavkaParser::Diia_defineContext::nls(size_t i) {
  return getRuleContext<MavkaParser::NlsContext>(i);
}

tree::TerminalNode* MavkaParser::Diia_defineContext::PAREN_CLOSE() {
  return getToken(MavkaParser::PAREN_CLOSE, 0);
}

std::vector<MavkaParser::NlContext *> MavkaParser::Diia_defineContext::nl() {
  return getRuleContexts<MavkaParser::NlContext>();
}

MavkaParser::NlContext* MavkaParser::Diia_defineContext::nl(size_t i) {
  return getRuleContext<MavkaParser::NlContext>(i);
}

tree::TerminalNode* MavkaParser::Diia_defineContext::KW_END() {
  return getToken(MavkaParser::KW_END, 0);
}

std::vector<MavkaParser::Diia_paramContext *> MavkaParser::Diia_defineContext::diia_param() {
  return getRuleContexts<MavkaParser::Diia_paramContext>();
}

MavkaParser::Diia_paramContext* MavkaParser::Diia_defineContext::diia_param(size_t i) {
  return getRuleContext<MavkaParser::Diia_paramContext>(i);
}

tree::TerminalNode* MavkaParser::Diia_defineContext::KW_ASYNC() {
  return getToken(MavkaParser::KW_ASYNC, 0);
}

tree::TerminalNode* MavkaParser::Diia_defineContext::KW_SPEC() {
  return getToken(MavkaParser::KW_SPEC, 0);
}

tree::TerminalNode* MavkaParser::Diia_defineContext::ID() {
  return getToken(MavkaParser::ID, 0);
}

MavkaParser::TypeContext* MavkaParser::Diia_defineContext::type() {
  return getRuleContext<MavkaParser::TypeContext>(0);
}

MavkaParser::BodyContext* MavkaParser::Diia_defineContext::body() {
  return getRuleContext<MavkaParser::BodyContext>(0);
}

tree::TerminalNode* MavkaParser::Diia_defineContext::DOT() {
  return getToken(MavkaParser::DOT, 0);
}

std::vector<tree::TerminalNode *> MavkaParser::Diia_defineContext::COMA() {
  return getTokens(MavkaParser::COMA);
}

tree::TerminalNode* MavkaParser::Diia_defineContext::COMA(size_t i) {
  return getToken(MavkaParser::COMA, i);
}

MavkaParser::AtomContext* MavkaParser::Diia_defineContext::atom() {
  return getRuleContext<MavkaParser::AtomContext>(0);
}


size_t MavkaParser::Diia_defineContext::getRuleIndex() const {
  return MavkaParser::RuleDiia_define;
}

void MavkaParser::Diia_defineContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDiia_define(this);
}

void MavkaParser::Diia_defineContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDiia_define(this);
}


std::any MavkaParser::Diia_defineContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MavkaParserVisitor*>(visitor))
    return parserVisitor->visitDiia_define(this);
  else
    return visitor->visitChildren(this);
}

MavkaParser::Diia_defineContext* MavkaParser::diia_define() {
  Diia_defineContext *_localctx = _tracker.createInstance<Diia_defineContext>(_ctx, getState());
  enterRule(_localctx, 40, MavkaParser::RuleDiia_define);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(434);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == MavkaParser::KW_ASYNC) {
      setState(433);
      antlrcpp::downCast<Diia_defineContext *>(_localctx)->d_async = match(MavkaParser::KW_ASYNC);
    }
    setState(437);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == MavkaParser::KW_SPEC) {
      setState(436);
      antlrcpp::downCast<Diia_defineContext *>(_localctx)->d_spec = match(MavkaParser::KW_SPEC);
    }
    setState(439);
    match(MavkaParser::KW_DIIA);
    setState(446);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 24, _ctx)) {
    case 1: {
      setState(443);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 23, _ctx)) {
      case 1: {
        setState(440);
        antlrcpp::downCast<Diia_defineContext *>(_localctx)->d_structure = atom(0);
        setState(441);
        match(MavkaParser::DOT);
        break;
      }

      default:
        break;
      }
      setState(445);
      antlrcpp::downCast<Diia_defineContext *>(_localctx)->d_name = match(MavkaParser::ID);
      break;
    }

    default:
      break;
    }
    setState(448);
    match(MavkaParser::PAREN_OPEN);
    setState(449);
    nls();
    setState(461);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == MavkaParser::ID) {
      setState(450);
      diia_param();
      setState(451);
      nls();
      setState(458);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == MavkaParser::COMA) {
        setState(452);
        match(MavkaParser::COMA);
        setState(453);
        nls();
        setState(454);
        diia_param();
        setState(460);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(463);
    nls();
    setState(464);
    match(MavkaParser::PAREN_CLOSE);
    setState(466);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((((_la - 51) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 51)) & 329729) != 0)) {
      setState(465);
      antlrcpp::downCast<Diia_defineContext *>(_localctx)->d_type = type();
    }
    setState(468);
    nl();
    setState(472);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 5920008098466029900) != 0) || _la == MavkaParser::ID

    || _la == MavkaParser::STRING) {
      setState(469);
      antlrcpp::downCast<Diia_defineContext *>(_localctx)->d_body = body();
      setState(470);
      nl();
    }
    setState(474);
    nls();
    setState(475);
    match(MavkaParser::KW_END);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Diia_paramContext ------------------------------------------------------------------

MavkaParser::Diia_paramContext::Diia_paramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MavkaParser::ParamContext* MavkaParser::Diia_paramContext::param() {
  return getRuleContext<MavkaParser::ParamContext>(0);
}


size_t MavkaParser::Diia_paramContext::getRuleIndex() const {
  return MavkaParser::RuleDiia_param;
}

void MavkaParser::Diia_paramContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDiia_param(this);
}

void MavkaParser::Diia_paramContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDiia_param(this);
}


std::any MavkaParser::Diia_paramContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MavkaParserVisitor*>(visitor))
    return parserVisitor->visitDiia_param(this);
  else
    return visitor->visitChildren(this);
}

MavkaParser::Diia_paramContext* MavkaParser::diia_param() {
  Diia_paramContext *_localctx = _tracker.createInstance<Diia_paramContext>(_ctx, getState());
  enterRule(_localctx, 42, MavkaParser::RuleDiia_param);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(477);
    param();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AssignContext ------------------------------------------------------------------

MavkaParser::AssignContext::AssignContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MavkaParser::AssignContext::ID() {
  return getToken(MavkaParser::ID, 0);
}

tree::TerminalNode* MavkaParser::AssignContext::EQUAL() {
  return getToken(MavkaParser::EQUAL, 0);
}

MavkaParser::ExprContext* MavkaParser::AssignContext::expr() {
  return getRuleContext<MavkaParser::ExprContext>(0);
}

tree::TerminalNode* MavkaParser::AssignContext::COLON() {
  return getToken(MavkaParser::COLON, 0);
}


size_t MavkaParser::AssignContext::getRuleIndex() const {
  return MavkaParser::RuleAssign;
}

void MavkaParser::AssignContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAssign(this);
}

void MavkaParser::AssignContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAssign(this);
}


std::any MavkaParser::AssignContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MavkaParserVisitor*>(visitor))
    return parserVisitor->visitAssign(this);
  else
    return visitor->visitChildren(this);
}

MavkaParser::AssignContext* MavkaParser::assign() {
  AssignContext *_localctx = _tracker.createInstance<AssignContext>(_ctx, getState());
  enterRule(_localctx, 44, MavkaParser::RuleAssign);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(479);
    antlrcpp::downCast<AssignContext *>(_localctx)->id = match(MavkaParser::ID);
    setState(483);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MavkaParser::EQUAL: {
        setState(480);
        antlrcpp::downCast<AssignContext *>(_localctx)->simpleas = match(MavkaParser::EQUAL);
        break;
      }

      case MavkaParser::COLON: {
        setState(481);
        antlrcpp::downCast<AssignContext *>(_localctx)->parentas = match(MavkaParser::COLON);
        setState(482);
        match(MavkaParser::EQUAL);
        break;
      }

    default:
      throw NoViableAltException(this);
    }

    setState(485);
    antlrcpp::downCast<AssignContext *>(_localctx)->value_expr = expr();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SetContext ------------------------------------------------------------------

MavkaParser::SetContext::SetContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MavkaParser::SetContext::DOT() {
  return getToken(MavkaParser::DOT, 0);
}

tree::TerminalNode* MavkaParser::SetContext::EQUAL() {
  return getToken(MavkaParser::EQUAL, 0);
}

MavkaParser::AtomContext* MavkaParser::SetContext::atom() {
  return getRuleContext<MavkaParser::AtomContext>(0);
}

tree::TerminalNode* MavkaParser::SetContext::ID() {
  return getToken(MavkaParser::ID, 0);
}

MavkaParser::ExprContext* MavkaParser::SetContext::expr() {
  return getRuleContext<MavkaParser::ExprContext>(0);
}


size_t MavkaParser::SetContext::getRuleIndex() const {
  return MavkaParser::RuleSet;
}

void MavkaParser::SetContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSet(this);
}

void MavkaParser::SetContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSet(this);
}


std::any MavkaParser::SetContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MavkaParserVisitor*>(visitor))
    return parserVisitor->visitSet(this);
  else
    return visitor->visitChildren(this);
}

MavkaParser::SetContext* MavkaParser::set() {
  SetContext *_localctx = _tracker.createInstance<SetContext>(_ctx, getState());
  enterRule(_localctx, 46, MavkaParser::RuleSet);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(487);
    antlrcpp::downCast<SetContext *>(_localctx)->object = atom(0);
    setState(488);
    match(MavkaParser::DOT);
    setState(489);
    antlrcpp::downCast<SetContext *>(_localctx)->id = match(MavkaParser::ID);
    setState(490);
    match(MavkaParser::EQUAL);

    setState(491);
    antlrcpp::downCast<SetContext *>(_localctx)->value_expr = expr();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Position_setContext ------------------------------------------------------------------

MavkaParser::Position_setContext::Position_setContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MavkaParser::Position_setContext::BRACKET_OPEN() {
  return getToken(MavkaParser::BRACKET_OPEN, 0);
}

tree::TerminalNode* MavkaParser::Position_setContext::BRACKET_CLOSE() {
  return getToken(MavkaParser::BRACKET_CLOSE, 0);
}

tree::TerminalNode* MavkaParser::Position_setContext::EQUAL() {
  return getToken(MavkaParser::EQUAL, 0);
}

MavkaParser::AtomContext* MavkaParser::Position_setContext::atom() {
  return getRuleContext<MavkaParser::AtomContext>(0);
}

std::vector<MavkaParser::ExprContext *> MavkaParser::Position_setContext::expr() {
  return getRuleContexts<MavkaParser::ExprContext>();
}

MavkaParser::ExprContext* MavkaParser::Position_setContext::expr(size_t i) {
  return getRuleContext<MavkaParser::ExprContext>(i);
}


size_t MavkaParser::Position_setContext::getRuleIndex() const {
  return MavkaParser::RulePosition_set;
}

void MavkaParser::Position_setContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPosition_set(this);
}

void MavkaParser::Position_setContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPosition_set(this);
}


std::any MavkaParser::Position_setContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MavkaParserVisitor*>(visitor))
    return parserVisitor->visitPosition_set(this);
  else
    return visitor->visitChildren(this);
}

MavkaParser::Position_setContext* MavkaParser::position_set() {
  Position_setContext *_localctx = _tracker.createInstance<Position_setContext>(_ctx, getState());
  enterRule(_localctx, 48, MavkaParser::RulePosition_set);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(493);
    antlrcpp::downCast<Position_setContext *>(_localctx)->object = atom(0);
    setState(494);
    match(MavkaParser::BRACKET_OPEN);
    setState(495);
    antlrcpp::downCast<Position_setContext *>(_localctx)->idx = expr();
    setState(496);
    match(MavkaParser::BRACKET_CLOSE);
    setState(497);
    match(MavkaParser::EQUAL);

    setState(498);
    antlrcpp::downCast<Position_setContext *>(_localctx)->value_expr = expr();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IfContext ------------------------------------------------------------------

MavkaParser::IfContext::IfContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MavkaParser::IfContext::KW_IF() {
  return getToken(MavkaParser::KW_IF, 0);
}

std::vector<MavkaParser::NlContext *> MavkaParser::IfContext::nl() {
  return getRuleContexts<MavkaParser::NlContext>();
}

MavkaParser::NlContext* MavkaParser::IfContext::nl(size_t i) {
  return getRuleContext<MavkaParser::NlContext>(i);
}

MavkaParser::ExprContext* MavkaParser::IfContext::expr() {
  return getRuleContext<MavkaParser::ExprContext>(0);
}

tree::TerminalNode* MavkaParser::IfContext::KW_END() {
  return getToken(MavkaParser::KW_END, 0);
}

std::vector<MavkaParser::BodyContext *> MavkaParser::IfContext::body() {
  return getRuleContexts<MavkaParser::BodyContext>();
}

MavkaParser::BodyContext* MavkaParser::IfContext::body(size_t i) {
  return getRuleContext<MavkaParser::BodyContext>(i);
}

tree::TerminalNode* MavkaParser::IfContext::KW_ELSE() {
  return getToken(MavkaParser::KW_ELSE, 0);
}

MavkaParser::IfContext* MavkaParser::IfContext::if_() {
  return getRuleContext<MavkaParser::IfContext>(0);
}


size_t MavkaParser::IfContext::getRuleIndex() const {
  return MavkaParser::RuleIf;
}

void MavkaParser::IfContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIf(this);
}

void MavkaParser::IfContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIf(this);
}


std::any MavkaParser::IfContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MavkaParserVisitor*>(visitor))
    return parserVisitor->visitIf(this);
  else
    return visitor->visitChildren(this);
}

MavkaParser::IfContext* MavkaParser::if_() {
  IfContext *_localctx = _tracker.createInstance<IfContext>(_ctx, getState());
  enterRule(_localctx, 50, MavkaParser::RuleIf);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(500);
    match(MavkaParser::KW_IF);
    setState(501);
    antlrcpp::downCast<IfContext *>(_localctx)->cond = expr();
    setState(502);
    nl();
    setState(506);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 5920008098466029900) != 0) || _la == MavkaParser::ID

    || _la == MavkaParser::STRING) {
      setState(503);
      antlrcpp::downCast<IfContext *>(_localctx)->ifok = body();
      setState(504);
      nl();
    }
    setState(518);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 32, _ctx)) {
    case 1: {
      setState(513);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == MavkaParser::KW_ELSE) {
        setState(508);
        match(MavkaParser::KW_ELSE);
        setState(509);
        nl();
        setState(510);
        antlrcpp::downCast<IfContext *>(_localctx)->ifnot = body();
        setState(511);
        nl();
      }
      setState(515);
      match(MavkaParser::KW_END);
      break;
    }

    case 2: {
      setState(516);
      match(MavkaParser::KW_ELSE);
      setState(517);
      antlrcpp::downCast<IfContext *>(_localctx)->ifnotif = if_();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- WhileContext ------------------------------------------------------------------

MavkaParser::WhileContext::WhileContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MavkaParser::WhileContext::KW_WHILE() {
  return getToken(MavkaParser::KW_WHILE, 0);
}

std::vector<MavkaParser::NlContext *> MavkaParser::WhileContext::nl() {
  return getRuleContexts<MavkaParser::NlContext>();
}

MavkaParser::NlContext* MavkaParser::WhileContext::nl(size_t i) {
  return getRuleContext<MavkaParser::NlContext>(i);
}

tree::TerminalNode* MavkaParser::WhileContext::KW_END() {
  return getToken(MavkaParser::KW_END, 0);
}

MavkaParser::OperationContext* MavkaParser::WhileContext::operation() {
  return getRuleContext<MavkaParser::OperationContext>(0);
}

MavkaParser::BodyContext* MavkaParser::WhileContext::body() {
  return getRuleContext<MavkaParser::BodyContext>(0);
}


size_t MavkaParser::WhileContext::getRuleIndex() const {
  return MavkaParser::RuleWhile;
}

void MavkaParser::WhileContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterWhile(this);
}

void MavkaParser::WhileContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitWhile(this);
}


std::any MavkaParser::WhileContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MavkaParserVisitor*>(visitor))
    return parserVisitor->visitWhile(this);
  else
    return visitor->visitChildren(this);
}

MavkaParser::WhileContext* MavkaParser::while_() {
  WhileContext *_localctx = _tracker.createInstance<WhileContext>(_ctx, getState());
  enterRule(_localctx, 52, MavkaParser::RuleWhile);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(520);
    match(MavkaParser::KW_WHILE);
    setState(521);
    antlrcpp::downCast<WhileContext *>(_localctx)->cond = operation(0);
    setState(522);
    nl();
    setState(526);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 5920008098466029900) != 0) || _la == MavkaParser::ID

    || _la == MavkaParser::STRING) {
      setState(523);
      antlrcpp::downCast<WhileContext *>(_localctx)->w_body = body();
      setState(524);
      nl();
    }
    setState(528);
    match(MavkaParser::KW_END);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BodyContext ------------------------------------------------------------------

MavkaParser::BodyContext::BodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<MavkaParser::Body_elementContext *> MavkaParser::BodyContext::body_element() {
  return getRuleContexts<MavkaParser::Body_elementContext>();
}

MavkaParser::Body_elementContext* MavkaParser::BodyContext::body_element(size_t i) {
  return getRuleContext<MavkaParser::Body_elementContext>(i);
}

std::vector<MavkaParser::NlContext *> MavkaParser::BodyContext::nl() {
  return getRuleContexts<MavkaParser::NlContext>();
}

MavkaParser::NlContext* MavkaParser::BodyContext::nl(size_t i) {
  return getRuleContext<MavkaParser::NlContext>(i);
}


size_t MavkaParser::BodyContext::getRuleIndex() const {
  return MavkaParser::RuleBody;
}

void MavkaParser::BodyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBody(this);
}

void MavkaParser::BodyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBody(this);
}


std::any MavkaParser::BodyContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MavkaParserVisitor*>(visitor))
    return parserVisitor->visitBody(this);
  else
    return visitor->visitChildren(this);
}

MavkaParser::BodyContext* MavkaParser::body() {
  BodyContext *_localctx = _tracker.createInstance<BodyContext>(_ctx, getState());
  enterRule(_localctx, 54, MavkaParser::RuleBody);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(530);
    body_element();
    setState(536);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 34, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(531);
        nl();
        setState(532);
        body_element(); 
      }
      setState(538);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 34, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Body_elementContext ------------------------------------------------------------------

MavkaParser::Body_elementContext::Body_elementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MavkaParser::Structure_defineContext* MavkaParser::Body_elementContext::structure_define() {
  return getRuleContext<MavkaParser::Structure_defineContext>(0);
}

MavkaParser::Diia_defineContext* MavkaParser::Body_elementContext::diia_define() {
  return getRuleContext<MavkaParser::Diia_defineContext>(0);
}

MavkaParser::AssignContext* MavkaParser::Body_elementContext::assign() {
  return getRuleContext<MavkaParser::AssignContext>(0);
}

MavkaParser::SetContext* MavkaParser::Body_elementContext::set() {
  return getRuleContext<MavkaParser::SetContext>(0);
}

MavkaParser::Position_setContext* MavkaParser::Body_elementContext::position_set() {
  return getRuleContext<MavkaParser::Position_setContext>(0);
}

MavkaParser::IfContext* MavkaParser::Body_elementContext::if_() {
  return getRuleContext<MavkaParser::IfContext>(0);
}

MavkaParser::WhileContext* MavkaParser::Body_elementContext::while_() {
  return getRuleContext<MavkaParser::WhileContext>(0);
}

MavkaParser::ExprContext* MavkaParser::Body_elementContext::expr() {
  return getRuleContext<MavkaParser::ExprContext>(0);
}

MavkaParser::ReturnContext* MavkaParser::Body_elementContext::return_() {
  return getRuleContext<MavkaParser::ReturnContext>(0);
}

MavkaParser::TakeContext* MavkaParser::Body_elementContext::take() {
  return getRuleContext<MavkaParser::TakeContext>(0);
}


size_t MavkaParser::Body_elementContext::getRuleIndex() const {
  return MavkaParser::RuleBody_element;
}

void MavkaParser::Body_elementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBody_element(this);
}

void MavkaParser::Body_elementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBody_element(this);
}


std::any MavkaParser::Body_elementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MavkaParserVisitor*>(visitor))
    return parserVisitor->visitBody_element(this);
  else
    return visitor->visitChildren(this);
}

MavkaParser::Body_elementContext* MavkaParser::body_element() {
  Body_elementContext *_localctx = _tracker.createInstance<Body_elementContext>(_ctx, getState());
  enterRule(_localctx, 56, MavkaParser::RuleBody_element);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(549);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 35, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(539);
      structure_define();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(540);
      diia_define();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(541);
      assign();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(542);
      set();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(543);
      position_set();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(544);
      if_();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(545);
      while_();
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(546);
      expr();
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(547);
      return_();
      break;
    }

    case 10: {
      enterOuterAlt(_localctx, 10);
      setState(548);
      take();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ReturnContext ------------------------------------------------------------------

MavkaParser::ReturnContext::ReturnContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MavkaParser::ReturnContext::KW_RETURN() {
  return getToken(MavkaParser::KW_RETURN, 0);
}

MavkaParser::ExprContext* MavkaParser::ReturnContext::expr() {
  return getRuleContext<MavkaParser::ExprContext>(0);
}


size_t MavkaParser::ReturnContext::getRuleIndex() const {
  return MavkaParser::RuleReturn;
}

void MavkaParser::ReturnContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterReturn(this);
}

void MavkaParser::ReturnContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitReturn(this);
}


std::any MavkaParser::ReturnContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MavkaParserVisitor*>(visitor))
    return parserVisitor->visitReturn(this);
  else
    return visitor->visitChildren(this);
}

MavkaParser::ReturnContext* MavkaParser::return_() {
  ReturnContext *_localctx = _tracker.createInstance<ReturnContext>(_ctx, getState());
  enterRule(_localctx, 58, MavkaParser::RuleReturn);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(551);
    match(MavkaParser::KW_RETURN);
    setState(553);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((((_la - 43) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 43)) & 84559107) != 0)) {
      setState(552);
      antlrcpp::downCast<ReturnContext *>(_localctx)->value_expr = expr();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeContext ------------------------------------------------------------------

MavkaParser::TypeContext::TypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MavkaParser::AtomContext* MavkaParser::TypeContext::atom() {
  return getRuleContext<MavkaParser::AtomContext>(0);
}


size_t MavkaParser::TypeContext::getRuleIndex() const {
  return MavkaParser::RuleType;
}

void MavkaParser::TypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterType(this);
}

void MavkaParser::TypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitType(this);
}


std::any MavkaParser::TypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MavkaParserVisitor*>(visitor))
    return parserVisitor->visitType(this);
  else
    return visitor->visitChildren(this);
}

MavkaParser::TypeContext* MavkaParser::type() {
  TypeContext *_localctx = _tracker.createInstance<TypeContext>(_ctx, getState());
  enterRule(_localctx, 60, MavkaParser::RuleType);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(555);
    atom(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParamContext ------------------------------------------------------------------

MavkaParser::ParamContext::ParamContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MavkaParser::ParamContext::ID() {
  return getToken(MavkaParser::ID, 0);
}

MavkaParser::TypeContext* MavkaParser::ParamContext::type() {
  return getRuleContext<MavkaParser::TypeContext>(0);
}

tree::TerminalNode* MavkaParser::ParamContext::EQUAL() {
  return getToken(MavkaParser::EQUAL, 0);
}

MavkaParser::ExprContext* MavkaParser::ParamContext::expr() {
  return getRuleContext<MavkaParser::ExprContext>(0);
}


size_t MavkaParser::ParamContext::getRuleIndex() const {
  return MavkaParser::RuleParam;
}

void MavkaParser::ParamContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParam(this);
}

void MavkaParser::ParamContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParam(this);
}


std::any MavkaParser::ParamContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MavkaParserVisitor*>(visitor))
    return parserVisitor->visitParam(this);
  else
    return visitor->visitChildren(this);
}

MavkaParser::ParamContext* MavkaParser::param() {
  ParamContext *_localctx = _tracker.createInstance<ParamContext>(_ctx, getState());
  enterRule(_localctx, 62, MavkaParser::RuleParam);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(557);
    antlrcpp::downCast<ParamContext *>(_localctx)->id = match(MavkaParser::ID);
    setState(559);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((((_la - 51) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 51)) & 329729) != 0)) {
      setState(558);
      type();
    }
    setState(563);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == MavkaParser::EQUAL) {
      setState(561);
      match(MavkaParser::EQUAL);
      setState(562);
      expr();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TakeContext ------------------------------------------------------------------

MavkaParser::TakeContext::TakeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MavkaParser::TakeContext::KW_TAKE() {
  return getToken(MavkaParser::KW_TAKE, 0);
}

std::vector<MavkaParser::Take_elementContext *> MavkaParser::TakeContext::take_element() {
  return getRuleContexts<MavkaParser::Take_elementContext>();
}

MavkaParser::Take_elementContext* MavkaParser::TakeContext::take_element(size_t i) {
  return getRuleContext<MavkaParser::Take_elementContext>(i);
}

std::vector<tree::TerminalNode *> MavkaParser::TakeContext::DOT() {
  return getTokens(MavkaParser::DOT);
}

tree::TerminalNode* MavkaParser::TakeContext::DOT(size_t i) {
  return getToken(MavkaParser::DOT, i);
}

tree::TerminalNode* MavkaParser::TakeContext::ID() {
  return getToken(MavkaParser::ID, 0);
}


size_t MavkaParser::TakeContext::getRuleIndex() const {
  return MavkaParser::RuleTake;
}

void MavkaParser::TakeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTake(this);
}

void MavkaParser::TakeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTake(this);
}


std::any MavkaParser::TakeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MavkaParserVisitor*>(visitor))
    return parserVisitor->visitTake(this);
  else
    return visitor->visitChildren(this);
}

MavkaParser::TakeContext* MavkaParser::take() {
  TakeContext *_localctx = _tracker.createInstance<TakeContext>(_ctx, getState());
  enterRule(_localctx, 64, MavkaParser::RuleTake);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(565);
    match(MavkaParser::KW_TAKE);
    setState(567);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 39, _ctx)) {
    case 1: {
      setState(566);
      antlrcpp::downCast<TakeContext *>(_localctx)->type_id = match(MavkaParser::ID);
      break;
    }

    default:
      break;
    }
    setState(569);
    take_element();
    setState(574);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == MavkaParser::DOT) {
      setState(570);
      match(MavkaParser::DOT);
      setState(571);
      take_element();
      setState(576);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Take_elementContext ------------------------------------------------------------------

MavkaParser::Take_elementContext::Take_elementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MavkaParser::Take_elementContext::ID() {
  return getToken(MavkaParser::ID, 0);
}

tree::TerminalNode* MavkaParser::Take_elementContext::STRING() {
  return getToken(MavkaParser::STRING, 0);
}


size_t MavkaParser::Take_elementContext::getRuleIndex() const {
  return MavkaParser::RuleTake_element;
}

void MavkaParser::Take_elementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTake_element(this);
}

void MavkaParser::Take_elementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTake_element(this);
}


std::any MavkaParser::Take_elementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MavkaParserVisitor*>(visitor))
    return parserVisitor->visitTake_element(this);
  else
    return visitor->visitChildren(this);
}

MavkaParser::Take_elementContext* MavkaParser::take_element() {
  Take_elementContext *_localctx = _tracker.createInstance<Take_elementContext>(_ctx, getState());
  enterRule(_localctx, 66, MavkaParser::RuleTake_element);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(577);
    _la = _input->LA(1);
    if (!(_la == MavkaParser::ID

    || _la == MavkaParser::STRING)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NlContext ------------------------------------------------------------------

MavkaParser::NlContext::NlContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> MavkaParser::NlContext::NL() {
  return getTokens(MavkaParser::NL);
}

tree::TerminalNode* MavkaParser::NlContext::NL(size_t i) {
  return getToken(MavkaParser::NL, i);
}


size_t MavkaParser::NlContext::getRuleIndex() const {
  return MavkaParser::RuleNl;
}

void MavkaParser::NlContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNl(this);
}

void MavkaParser::NlContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNl(this);
}


std::any MavkaParser::NlContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MavkaParserVisitor*>(visitor))
    return parserVisitor->visitNl(this);
  else
    return visitor->visitChildren(this);
}

MavkaParser::NlContext* MavkaParser::nl() {
  NlContext *_localctx = _tracker.createInstance<NlContext>(_ctx, getState());
  enterRule(_localctx, 68, MavkaParser::RuleNl);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(580); 
    _errHandler->sync(this);
    alt = 1;
    do {
      switch (alt) {
        case 1: {
              setState(579);
              match(MavkaParser::NL);
              break;
            }

      default:
        throw NoViableAltException(this);
      }
      setState(582); 
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 41, _ctx);
    } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NlsContext ------------------------------------------------------------------

MavkaParser::NlsContext::NlsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> MavkaParser::NlsContext::NL() {
  return getTokens(MavkaParser::NL);
}

tree::TerminalNode* MavkaParser::NlsContext::NL(size_t i) {
  return getToken(MavkaParser::NL, i);
}


size_t MavkaParser::NlsContext::getRuleIndex() const {
  return MavkaParser::RuleNls;
}

void MavkaParser::NlsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNls(this);
}

void MavkaParser::NlsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNls(this);
}


std::any MavkaParser::NlsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MavkaParserVisitor*>(visitor))
    return parserVisitor->visitNls(this);
  else
    return visitor->visitChildren(this);
}

MavkaParser::NlsContext* MavkaParser::nls() {
  NlsContext *_localctx = _tracker.createInstance<NlsContext>(_ctx, getState());
  enterRule(_localctx, 70, MavkaParser::RuleNls);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(587);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 42, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(584);
        match(MavkaParser::NL); 
      }
      setState(589);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 42, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool MavkaParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 2: return atomSempred(antlrcpp::downCast<AtomContext *>(context), predicateIndex);
    case 6: return operationSempred(antlrcpp::downCast<OperationContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool MavkaParser::atomSempred(AtomContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 3);
    case 1: return precpred(_ctx, 2);
    case 2: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool MavkaParser::operationSempred(OperationContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 3: return precpred(_ctx, 20);
    case 4: return precpred(_ctx, 19);
    case 5: return precpred(_ctx, 18);
    case 6: return precpred(_ctx, 17);
    case 7: return precpred(_ctx, 16);
    case 8: return precpred(_ctx, 15);
    case 9: return precpred(_ctx, 14);
    case 10: return precpred(_ctx, 13);
    case 11: return precpred(_ctx, 12);
    case 12: return precpred(_ctx, 11);
    case 13: return precpred(_ctx, 10);
    case 14: return precpred(_ctx, 9);
    case 15: return precpred(_ctx, 8);
    case 16: return precpred(_ctx, 7);
    case 17: return precpred(_ctx, 6);
    case 18: return precpred(_ctx, 5);
    case 19: return precpred(_ctx, 4);
    case 20: return precpred(_ctx, 3);
    case 21: return precpred(_ctx, 2);
    case 22: return precpred(_ctx, 1);
    case 23: return precpred(_ctx, 25);

  default:
    break;
  }
  return true;
}

void MavkaParser::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  mavkaparserParserInitialize();
#else
  ::antlr4::internal::call_once(mavkaparserParserOnceFlag, mavkaparserParserInitialize);
#endif
}
