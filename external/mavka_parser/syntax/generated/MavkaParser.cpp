
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
      "types", "param", "take", "take_element", "nl", "nls"
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
  	4,1,74,610,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,7,
  	21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,7,
  	28,2,29,7,29,2,30,7,30,2,31,7,31,2,32,7,32,2,33,7,33,2,34,7,34,2,35,7,
  	35,2,36,7,36,1,0,1,0,1,0,1,1,1,1,1,1,1,1,1,1,5,1,83,8,1,10,1,12,1,86,
  	9,1,1,1,1,1,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,3,2,98,8,2,1,2,1,2,3,2,102,
  	8,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,
  	2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,5,2,128,8,2,10,2,12,2,131,9,2,3,2,133,8,
  	2,1,2,1,2,1,2,5,2,138,8,2,10,2,12,2,141,9,2,1,3,1,3,1,3,1,3,1,3,1,3,1,
  	4,1,4,3,4,151,8,4,1,4,1,4,1,4,1,4,1,4,1,5,1,5,1,5,1,5,1,5,3,5,163,8,5,
  	1,5,1,5,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,5,6,178,8,6,10,6,
  	12,6,181,9,6,3,6,183,8,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,
  	1,6,1,6,1,6,1,6,1,6,1,6,1,6,5,6,203,8,6,10,6,12,6,206,9,6,3,6,208,8,6,
  	1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,5,6,222,8,6,10,6,12,6,
  	225,9,6,3,6,227,8,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,
  	6,1,6,1,6,1,6,1,6,1,6,1,6,3,6,248,8,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,
  	1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,
  	6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,
  	1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,
  	6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,
  	1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,
  	6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,
  	1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,5,
  	6,380,8,6,10,6,12,6,383,9,6,1,7,1,7,1,7,1,8,1,8,1,8,1,9,1,9,1,9,1,9,1,
  	10,1,10,1,10,1,11,1,11,1,11,1,12,1,12,1,12,1,13,1,13,1,13,1,14,1,14,1,
  	14,1,15,1,15,1,15,1,16,1,16,1,17,1,17,1,18,1,18,1,18,1,18,3,18,421,8,
  	18,1,18,1,18,1,18,1,18,1,18,1,18,1,18,5,18,430,8,18,10,18,12,18,433,9,
  	18,3,18,435,8,18,1,18,1,18,1,18,1,19,1,19,1,20,3,20,443,8,20,1,20,3,20,
  	446,8,20,1,20,1,20,1,20,1,20,3,20,452,8,20,1,20,3,20,455,8,20,1,20,1,
  	20,1,20,1,20,1,20,1,20,1,20,1,20,5,20,465,8,20,10,20,12,20,468,9,20,3,
  	20,470,8,20,1,20,1,20,1,20,3,20,475,8,20,1,20,1,20,1,20,1,20,3,20,481,
  	8,20,1,20,1,20,1,20,1,21,1,21,1,22,1,22,1,22,1,22,3,22,492,8,22,1,22,
  	1,22,1,23,1,23,1,23,1,23,1,23,1,23,1,24,1,24,1,24,1,24,1,24,1,24,1,24,
  	1,25,1,25,1,25,1,25,1,25,1,25,3,25,515,8,25,1,25,1,25,1,25,1,25,1,25,
  	3,25,522,8,25,1,25,1,25,1,25,3,25,527,8,25,1,26,1,26,1,26,1,26,1,26,1,
  	26,3,26,535,8,26,1,26,1,26,1,27,1,27,1,27,1,27,5,27,543,8,27,10,27,12,
  	27,546,9,27,1,28,1,28,1,28,1,28,1,28,1,28,1,28,1,28,1,28,1,28,3,28,558,
  	8,28,1,29,1,29,3,29,562,8,29,1,30,1,30,1,31,1,31,1,31,1,31,1,31,1,31,
  	5,31,572,8,31,10,31,12,31,575,9,31,1,32,1,32,3,32,579,8,32,1,32,1,32,
  	3,32,583,8,32,1,33,1,33,3,33,587,8,33,1,33,1,33,1,33,5,33,592,8,33,10,
  	33,12,33,595,9,33,1,34,1,34,1,35,4,35,600,8,35,11,35,12,35,601,1,36,5,
  	36,605,8,36,10,36,12,36,608,9,36,1,36,0,2,4,12,37,0,2,4,6,8,10,12,14,
  	16,18,20,22,24,26,28,30,32,34,36,38,40,42,44,46,48,50,52,54,56,58,60,
  	62,64,66,68,70,72,0,1,2,0,67,67,69,69,653,0,74,1,0,0,0,2,77,1,0,0,0,4,
  	101,1,0,0,0,6,142,1,0,0,0,8,150,1,0,0,0,10,162,1,0,0,0,12,247,1,0,0,0,
  	14,384,1,0,0,0,16,387,1,0,0,0,18,390,1,0,0,0,20,394,1,0,0,0,22,397,1,
  	0,0,0,24,400,1,0,0,0,26,403,1,0,0,0,28,406,1,0,0,0,30,409,1,0,0,0,32,
  	412,1,0,0,0,34,414,1,0,0,0,36,416,1,0,0,0,38,439,1,0,0,0,40,442,1,0,0,
  	0,42,485,1,0,0,0,44,487,1,0,0,0,46,495,1,0,0,0,48,501,1,0,0,0,50,508,
  	1,0,0,0,52,528,1,0,0,0,54,538,1,0,0,0,56,557,1,0,0,0,58,559,1,0,0,0,60,
  	563,1,0,0,0,62,565,1,0,0,0,64,576,1,0,0,0,66,584,1,0,0,0,68,596,1,0,0,
  	0,70,599,1,0,0,0,72,606,1,0,0,0,74,75,3,2,1,0,75,76,5,0,0,1,76,1,1,0,
  	0,0,77,78,3,72,36,0,78,84,3,56,28,0,79,80,3,70,35,0,80,81,3,56,28,0,81,
  	83,1,0,0,0,82,79,1,0,0,0,83,86,1,0,0,0,84,82,1,0,0,0,84,85,1,0,0,0,85,
  	87,1,0,0,0,86,84,1,0,0,0,87,88,3,72,36,0,88,3,1,0,0,0,89,90,6,2,-1,0,
  	90,91,5,51,0,0,91,92,3,72,36,0,92,93,3,34,17,0,93,94,3,72,36,0,94,95,
  	5,52,0,0,95,102,1,0,0,0,96,98,5,67,0,0,97,96,1,0,0,0,97,98,1,0,0,0,98,
  	99,1,0,0,0,99,102,5,69,0,0,100,102,5,67,0,0,101,89,1,0,0,0,101,97,1,0,
  	0,0,101,100,1,0,0,0,102,139,1,0,0,0,103,104,10,3,0,0,104,105,3,72,36,
  	0,105,106,5,42,0,0,106,107,3,72,36,0,107,108,5,67,0,0,108,138,1,0,0,0,
  	109,110,10,2,0,0,110,111,3,72,36,0,111,112,5,53,0,0,112,113,3,72,36,0,
  	113,114,3,34,17,0,114,115,3,72,36,0,115,116,5,54,0,0,116,138,1,0,0,0,
  	117,118,10,1,0,0,118,119,5,51,0,0,119,132,3,72,36,0,120,121,3,10,5,0,
  	121,129,3,72,36,0,122,123,3,72,36,0,123,124,5,61,0,0,124,125,3,72,36,
  	0,125,126,3,10,5,0,126,128,1,0,0,0,127,122,1,0,0,0,128,131,1,0,0,0,129,
  	127,1,0,0,0,129,130,1,0,0,0,130,133,1,0,0,0,131,129,1,0,0,0,132,120,1,
  	0,0,0,132,133,1,0,0,0,133,134,1,0,0,0,134,135,3,72,36,0,135,136,5,52,
  	0,0,136,138,1,0,0,0,137,103,1,0,0,0,137,109,1,0,0,0,137,117,1,0,0,0,138,
  	141,1,0,0,0,139,137,1,0,0,0,139,140,1,0,0,0,140,5,1,0,0,0,141,139,1,0,
  	0,0,142,143,5,67,0,0,143,144,3,72,36,0,144,145,5,39,0,0,145,146,3,72,
  	36,0,146,147,3,34,17,0,147,7,1,0,0,0,148,151,5,62,0,0,149,151,5,69,0,
  	0,150,148,1,0,0,0,150,149,1,0,0,0,151,152,1,0,0,0,152,153,3,72,36,0,153,
  	154,5,39,0,0,154,155,3,72,36,0,155,156,3,34,17,0,156,9,1,0,0,0,157,158,
  	5,67,0,0,158,159,3,72,36,0,159,160,5,39,0,0,160,161,3,72,36,0,161,163,
  	1,0,0,0,162,157,1,0,0,0,162,163,1,0,0,0,163,164,1,0,0,0,164,165,3,34,
  	17,0,165,11,1,0,0,0,166,167,6,6,-1,0,167,248,5,62,0,0,168,248,3,4,2,0,
  	169,170,5,51,0,0,170,182,3,72,36,0,171,179,3,6,3,0,172,173,3,72,36,0,
  	173,174,5,61,0,0,174,175,3,72,36,0,175,176,3,6,3,0,176,178,1,0,0,0,177,
  	172,1,0,0,0,178,181,1,0,0,0,179,177,1,0,0,0,179,180,1,0,0,0,180,183,1,
  	0,0,0,181,179,1,0,0,0,182,171,1,0,0,0,182,183,1,0,0,0,183,184,1,0,0,0,
  	184,185,3,72,36,0,185,186,5,52,0,0,186,248,1,0,0,0,187,188,5,53,0,0,188,
  	189,3,72,36,0,189,190,5,39,0,0,190,191,3,72,36,0,191,192,5,54,0,0,192,
  	248,1,0,0,0,193,194,5,53,0,0,194,207,3,72,36,0,195,196,3,8,4,0,196,204,
  	3,72,36,0,197,198,3,72,36,0,198,199,5,61,0,0,199,200,3,72,36,0,200,201,
  	3,8,4,0,201,203,1,0,0,0,202,197,1,0,0,0,203,206,1,0,0,0,204,202,1,0,0,
  	0,204,205,1,0,0,0,205,208,1,0,0,0,206,204,1,0,0,0,207,195,1,0,0,0,207,
  	208,1,0,0,0,208,209,1,0,0,0,209,210,3,72,36,0,210,211,5,54,0,0,211,248,
  	1,0,0,0,212,213,5,53,0,0,213,226,3,72,36,0,214,215,3,34,17,0,215,223,
  	3,72,36,0,216,217,3,72,36,0,217,218,5,61,0,0,218,219,3,72,36,0,219,220,
  	3,34,17,0,220,222,1,0,0,0,221,216,1,0,0,0,222,225,1,0,0,0,223,221,1,0,
  	0,0,223,224,1,0,0,0,224,227,1,0,0,0,225,223,1,0,0,0,226,214,1,0,0,0,226,
  	227,1,0,0,0,227,228,1,0,0,0,228,229,3,72,36,0,229,230,5,54,0,0,230,248,
  	1,0,0,0,231,232,5,60,0,0,232,233,3,72,36,0,233,234,3,12,6,24,234,248,
  	1,0,0,0,235,236,5,57,0,0,236,237,3,72,36,0,237,238,3,12,6,23,238,248,
  	1,0,0,0,239,240,5,43,0,0,240,241,3,72,36,0,241,242,3,12,6,22,242,248,
  	1,0,0,0,243,244,5,44,0,0,244,245,3,72,36,0,245,246,3,12,6,21,246,248,
  	1,0,0,0,247,166,1,0,0,0,247,168,1,0,0,0,247,169,1,0,0,0,247,187,1,0,0,
  	0,247,193,1,0,0,0,247,212,1,0,0,0,247,231,1,0,0,0,247,235,1,0,0,0,247,
  	239,1,0,0,0,247,243,1,0,0,0,248,381,1,0,0,0,249,250,10,20,0,0,250,251,
  	3,72,36,0,251,252,5,45,0,0,252,253,3,72,36,0,253,254,3,12,6,21,254,380,
  	1,0,0,0,255,256,10,19,0,0,256,257,3,72,36,0,257,258,5,46,0,0,258,259,
  	3,72,36,0,259,260,3,12,6,20,260,380,1,0,0,0,261,262,10,18,0,0,262,263,
  	3,72,36,0,263,264,5,47,0,0,264,265,3,72,36,0,265,266,3,12,6,19,266,380,
  	1,0,0,0,267,268,10,17,0,0,268,269,3,72,36,0,269,270,5,43,0,0,270,271,
  	3,72,36,0,271,272,3,12,6,18,272,380,1,0,0,0,273,274,10,16,0,0,274,275,
  	3,72,36,0,275,276,5,44,0,0,276,277,3,72,36,0,277,278,3,12,6,17,278,380,
  	1,0,0,0,279,280,10,15,0,0,280,281,3,72,36,0,281,282,3,14,7,0,282,283,
  	3,72,36,0,283,284,3,12,6,16,284,380,1,0,0,0,285,286,10,14,0,0,286,287,
  	3,72,36,0,287,288,3,16,8,0,288,289,3,72,36,0,289,290,3,12,6,15,290,380,
  	1,0,0,0,291,292,10,13,0,0,292,293,3,72,36,0,293,294,3,18,9,0,294,295,
  	3,72,36,0,295,296,3,12,6,14,296,380,1,0,0,0,297,298,10,12,0,0,298,299,
  	3,72,36,0,299,300,5,41,0,0,300,301,3,72,36,0,301,302,3,12,6,13,302,380,
  	1,0,0,0,303,304,10,11,0,0,304,305,3,72,36,0,305,306,3,20,10,0,306,307,
  	3,72,36,0,307,308,3,12,6,12,308,380,1,0,0,0,309,310,10,10,0,0,310,311,
  	3,72,36,0,311,312,5,40,0,0,312,313,3,72,36,0,313,314,3,12,6,11,314,380,
  	1,0,0,0,315,316,10,9,0,0,316,317,3,72,36,0,317,318,3,22,11,0,318,319,
  	3,72,36,0,319,320,3,12,6,10,320,380,1,0,0,0,321,322,10,8,0,0,322,323,
  	3,72,36,0,323,324,3,24,12,0,324,325,3,72,36,0,325,326,3,12,6,9,326,380,
  	1,0,0,0,327,328,10,7,0,0,328,329,3,72,36,0,329,330,3,26,13,0,330,331,
  	3,72,36,0,331,332,3,12,6,8,332,380,1,0,0,0,333,334,10,6,0,0,334,335,3,
  	72,36,0,335,336,5,49,0,0,336,337,3,72,36,0,337,338,3,12,6,7,338,380,1,
  	0,0,0,339,340,10,5,0,0,340,341,3,72,36,0,341,342,5,48,0,0,342,343,3,72,
  	36,0,343,344,3,12,6,6,344,380,1,0,0,0,345,346,10,4,0,0,346,347,3,72,36,
  	0,347,348,5,50,0,0,348,349,3,72,36,0,349,350,3,12,6,5,350,380,1,0,0,0,
  	351,352,10,3,0,0,352,353,3,72,36,0,353,354,3,28,14,0,354,355,3,72,36,
  	0,355,356,3,12,6,4,356,380,1,0,0,0,357,358,10,2,0,0,358,359,3,72,36,0,
  	359,360,3,30,15,0,360,361,3,72,36,0,361,362,3,12,6,3,362,380,1,0,0,0,
  	363,364,10,1,0,0,364,365,3,72,36,0,365,366,5,55,0,0,366,367,3,72,36,0,
  	367,368,3,12,6,0,368,369,3,72,36,0,369,370,5,56,0,0,370,371,3,72,36,0,
  	371,372,3,12,6,2,372,380,1,0,0,0,373,374,10,25,0,0,374,375,3,72,36,0,
  	375,376,5,10,0,0,376,377,3,72,36,0,377,378,3,60,30,0,378,380,1,0,0,0,
  	379,249,1,0,0,0,379,255,1,0,0,0,379,261,1,0,0,0,379,267,1,0,0,0,379,273,
  	1,0,0,0,379,279,1,0,0,0,379,285,1,0,0,0,379,291,1,0,0,0,379,297,1,0,0,
  	0,379,303,1,0,0,0,379,309,1,0,0,0,379,315,1,0,0,0,379,321,1,0,0,0,379,
  	327,1,0,0,0,379,333,1,0,0,0,379,339,1,0,0,0,379,345,1,0,0,0,379,351,1,
  	0,0,0,379,357,1,0,0,0,379,363,1,0,0,0,379,373,1,0,0,0,380,383,1,0,0,0,
  	381,379,1,0,0,0,381,382,1,0,0,0,382,13,1,0,0,0,383,381,1,0,0,0,384,385,
  	5,41,0,0,385,386,5,41,0,0,386,15,1,0,0,0,387,388,5,40,0,0,388,389,5,40,
  	0,0,389,17,1,0,0,0,390,391,5,40,0,0,391,392,5,40,0,0,392,393,5,40,0,0,
  	393,19,1,0,0,0,394,395,5,41,0,0,395,396,5,39,0,0,396,21,1,0,0,0,397,398,
  	5,40,0,0,398,399,5,39,0,0,399,23,1,0,0,0,400,401,5,39,0,0,401,402,5,39,
  	0,0,402,25,1,0,0,0,403,404,5,60,0,0,404,405,5,39,0,0,405,27,1,0,0,0,406,
  	407,5,49,0,0,407,408,5,49,0,0,408,29,1,0,0,0,409,410,5,50,0,0,410,411,
  	5,50,0,0,411,31,1,0,0,0,412,413,5,67,0,0,413,33,1,0,0,0,414,415,3,12,
  	6,0,415,35,1,0,0,0,416,417,5,3,0,0,417,420,5,67,0,0,418,419,5,12,0,0,
  	419,421,3,4,2,0,420,418,1,0,0,0,420,421,1,0,0,0,421,422,1,0,0,0,422,434,
  	3,70,35,0,423,424,3,38,19,0,424,431,3,72,36,0,425,426,3,70,35,0,426,427,
  	3,72,36,0,427,428,3,38,19,0,428,430,1,0,0,0,429,425,1,0,0,0,430,433,1,
  	0,0,0,431,429,1,0,0,0,431,432,1,0,0,0,432,435,1,0,0,0,433,431,1,0,0,0,
  	434,423,1,0,0,0,434,435,1,0,0,0,435,436,1,0,0,0,436,437,3,72,36,0,437,
  	438,5,1,0,0,438,37,1,0,0,0,439,440,3,64,32,0,440,39,1,0,0,0,441,443,5,
  	15,0,0,442,441,1,0,0,0,442,443,1,0,0,0,443,445,1,0,0,0,444,446,5,13,0,
  	0,445,444,1,0,0,0,445,446,1,0,0,0,446,447,1,0,0,0,447,454,5,2,0,0,448,
  	449,3,4,2,0,449,450,5,42,0,0,450,452,1,0,0,0,451,448,1,0,0,0,451,452,
  	1,0,0,0,452,453,1,0,0,0,453,455,5,67,0,0,454,451,1,0,0,0,454,455,1,0,
  	0,0,455,456,1,0,0,0,456,457,5,51,0,0,457,469,3,72,36,0,458,459,3,42,21,
  	0,459,466,3,72,36,0,460,461,5,61,0,0,461,462,3,72,36,0,462,463,3,42,21,
  	0,463,465,1,0,0,0,464,460,1,0,0,0,465,468,1,0,0,0,466,464,1,0,0,0,466,
  	467,1,0,0,0,467,470,1,0,0,0,468,466,1,0,0,0,469,458,1,0,0,0,469,470,1,
  	0,0,0,470,471,1,0,0,0,471,472,3,72,36,0,472,474,5,52,0,0,473,475,3,62,
  	31,0,474,473,1,0,0,0,474,475,1,0,0,0,475,476,1,0,0,0,476,480,3,70,35,
  	0,477,478,3,54,27,0,478,479,3,70,35,0,479,481,1,0,0,0,480,477,1,0,0,0,
  	480,481,1,0,0,0,481,482,1,0,0,0,482,483,3,72,36,0,483,484,5,1,0,0,484,
  	41,1,0,0,0,485,486,3,64,32,0,486,43,1,0,0,0,487,491,5,67,0,0,488,492,
  	5,39,0,0,489,490,5,56,0,0,490,492,5,39,0,0,491,488,1,0,0,0,491,489,1,
  	0,0,0,492,493,1,0,0,0,493,494,3,34,17,0,494,45,1,0,0,0,495,496,3,4,2,
  	0,496,497,5,42,0,0,497,498,5,67,0,0,498,499,5,39,0,0,499,500,3,34,17,
  	0,500,47,1,0,0,0,501,502,3,4,2,0,502,503,5,53,0,0,503,504,3,34,17,0,504,
  	505,5,54,0,0,505,506,5,39,0,0,506,507,3,34,17,0,507,49,1,0,0,0,508,509,
  	5,6,0,0,509,510,3,34,17,0,510,514,3,70,35,0,511,512,3,54,27,0,512,513,
  	3,70,35,0,513,515,1,0,0,0,514,511,1,0,0,0,514,515,1,0,0,0,515,526,1,0,
  	0,0,516,517,5,21,0,0,517,518,3,70,35,0,518,519,3,54,27,0,519,520,3,70,
  	35,0,520,522,1,0,0,0,521,516,1,0,0,0,521,522,1,0,0,0,522,523,1,0,0,0,
  	523,527,5,1,0,0,524,525,5,21,0,0,525,527,3,50,25,0,526,521,1,0,0,0,526,
  	524,1,0,0,0,527,51,1,0,0,0,528,529,5,23,0,0,529,530,3,12,6,0,530,534,
  	3,70,35,0,531,532,3,54,27,0,532,533,3,70,35,0,533,535,1,0,0,0,534,531,
  	1,0,0,0,534,535,1,0,0,0,535,536,1,0,0,0,536,537,5,1,0,0,537,53,1,0,0,
  	0,538,544,3,56,28,0,539,540,3,70,35,0,540,541,3,56,28,0,541,543,1,0,0,
  	0,542,539,1,0,0,0,543,546,1,0,0,0,544,542,1,0,0,0,544,545,1,0,0,0,545,
  	55,1,0,0,0,546,544,1,0,0,0,547,558,3,36,18,0,548,558,3,40,20,0,549,558,
  	3,44,22,0,550,558,3,46,23,0,551,558,3,48,24,0,552,558,3,50,25,0,553,558,
  	3,52,26,0,554,558,3,34,17,0,555,558,3,58,29,0,556,558,3,66,33,0,557,547,
  	1,0,0,0,557,548,1,0,0,0,557,549,1,0,0,0,557,550,1,0,0,0,557,551,1,0,0,
  	0,557,552,1,0,0,0,557,553,1,0,0,0,557,554,1,0,0,0,557,555,1,0,0,0,557,
  	556,1,0,0,0,558,57,1,0,0,0,559,561,5,14,0,0,560,562,3,34,17,0,561,560,
  	1,0,0,0,561,562,1,0,0,0,562,59,1,0,0,0,563,564,3,4,2,0,564,61,1,0,0,0,
  	565,573,3,60,30,0,566,567,3,72,36,0,567,568,5,18,0,0,568,569,3,72,36,
  	0,569,570,3,60,30,0,570,572,1,0,0,0,571,566,1,0,0,0,572,575,1,0,0,0,573,
  	571,1,0,0,0,573,574,1,0,0,0,574,63,1,0,0,0,575,573,1,0,0,0,576,578,5,
  	67,0,0,577,579,3,62,31,0,578,577,1,0,0,0,578,579,1,0,0,0,579,582,1,0,
  	0,0,580,581,5,39,0,0,581,583,3,34,17,0,582,580,1,0,0,0,582,583,1,0,0,
  	0,583,65,1,0,0,0,584,586,5,8,0,0,585,587,5,67,0,0,586,585,1,0,0,0,586,
  	587,1,0,0,0,587,588,1,0,0,0,588,593,3,68,34,0,589,590,5,42,0,0,590,592,
  	3,68,34,0,591,589,1,0,0,0,592,595,1,0,0,0,593,591,1,0,0,0,593,594,1,0,
  	0,0,594,67,1,0,0,0,595,593,1,0,0,0,596,597,7,0,0,0,597,69,1,0,0,0,598,
  	600,5,73,0,0,599,598,1,0,0,0,600,601,1,0,0,0,601,599,1,0,0,0,601,602,
  	1,0,0,0,602,71,1,0,0,0,603,605,5,73,0,0,604,603,1,0,0,0,605,608,1,0,0,
  	0,606,604,1,0,0,0,606,607,1,0,0,0,607,73,1,0,0,0,608,606,1,0,0,0,44,84,
  	97,101,129,132,137,139,150,162,179,182,204,207,223,226,247,379,381,420,
  	431,434,442,445,451,454,466,469,474,480,491,514,521,526,534,544,557,561,
  	573,578,582,586,593,601,606
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
    setState(74);
    antlrcpp::downCast<FileContext *>(_localctx)->f_program = program();
    setState(75);
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
    setState(77);
    nls();
    setState(78);
    body_element();
    setState(84);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(79);
        nl();
        setState(80);
        body_element(); 
      }
      setState(86);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx);
    }
    setState(87);
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
    setState(101);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<Atom_nestedContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;

      setState(90);
      match(MavkaParser::PAREN_OPEN);
      setState(91);
      nls();
      setState(92);
      expr();
      setState(93);
      nls();
      setState(94);
      match(MavkaParser::PAREN_CLOSE);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<Operation_stringContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(97);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == MavkaParser::ID) {
        setState(96);
        antlrcpp::downCast<Operation_stringContext *>(_localctx)->tt = match(MavkaParser::ID);
      }
      setState(99);
      match(MavkaParser::STRING);
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<Atom_subjectContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(100);
      antlrcpp::downCast<Atom_subjectContext *>(_localctx)->id = match(MavkaParser::ID);
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(139);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(137);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<Atom_getContext>(_tracker.createInstance<AtomContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->object = previousContext;
          pushNewRecursionContext(newContext, startState, RuleAtom);
          setState(103);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(104);
          nls();
          setState(105);
          match(MavkaParser::DOT);
          setState(106);
          nls();
          setState(107);
          antlrcpp::downCast<Atom_getContext *>(_localctx)->id = match(MavkaParser::ID);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<Atom_position_getContext>(_tracker.createInstance<AtomContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->object = previousContext;
          pushNewRecursionContext(newContext, startState, RuleAtom);
          setState(109);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(110);
          nls();
          setState(111);
          match(MavkaParser::BRACKET_OPEN);
          setState(112);
          nls();
          setState(113);
          antlrcpp::downCast<Atom_position_getContext *>(_localctx)->position = expr();
          setState(114);
          nls();
          setState(115);
          match(MavkaParser::BRACKET_CLOSE);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<Atom_callContext>(_tracker.createInstance<AtomContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->object = previousContext;
          pushNewRecursionContext(newContext, startState, RuleAtom);
          setState(117);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(118);
          match(MavkaParser::PAREN_OPEN);
          setState(119);
          nls();
          setState(132);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if (((((_la - 43) & ~ 0x3fULL) == 0) &&
            ((1ULL << (_la - 43)) & 84559107) != 0)) {
            setState(120);
            call_arg();
            setState(121);
            nls();
            setState(129);
            _errHandler->sync(this);
            alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx);
            while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
              if (alt == 1) {
                setState(122);
                nls();
                setState(123);
                match(MavkaParser::COMA);
                setState(124);
                nls();
                setState(125);
                call_arg(); 
              }
              setState(131);
              _errHandler->sync(this);
              alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx);
            }
          }
          setState(134);
          nls();
          setState(135);
          match(MavkaParser::PAREN_CLOSE);
          break;
        }

        default:
          break;
        } 
      }
      setState(141);
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
    setState(142);
    antlrcpp::downCast<Object_argContext *>(_localctx)->id = match(MavkaParser::ID);
    setState(143);
    nls();
    setState(144);
    match(MavkaParser::EQUAL);
    setState(145);
    nls();
    setState(146);
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
    setState(150);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MavkaParser::NUMBER: {
        setState(148);
        antlrcpp::downCast<Dict_argContext *>(_localctx)->key_number = match(MavkaParser::NUMBER);
        break;
      }

      case MavkaParser::STRING: {
        setState(149);
        antlrcpp::downCast<Dict_argContext *>(_localctx)->key_string = match(MavkaParser::STRING);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(152);
    nls();
    setState(153);
    match(MavkaParser::EQUAL);
    setState(154);
    nls();
    setState(155);
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

MavkaParser::ExprContext* MavkaParser::Call_argContext::expr() {
  return getRuleContext<MavkaParser::ExprContext>(0);
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
    enterOuterAlt(_localctx, 1);
    setState(162);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx)) {
    case 1: {
      setState(157);
      antlrcpp::downCast<Call_argContext *>(_localctx)->id = match(MavkaParser::ID);
      setState(158);
      nls();
      setState(159);
      match(MavkaParser::EQUAL);
      setState(160);
      nls();
      break;
    }

    default:
      break;
    }
    setState(164);
    expr();
   
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
//----------------- Operation_dict_emptyContext ------------------------------------------------------------------

tree::TerminalNode* MavkaParser::Operation_dict_emptyContext::BRACKET_OPEN() {
  return getToken(MavkaParser::BRACKET_OPEN, 0);
}

std::vector<MavkaParser::NlsContext *> MavkaParser::Operation_dict_emptyContext::nls() {
  return getRuleContexts<MavkaParser::NlsContext>();
}

MavkaParser::NlsContext* MavkaParser::Operation_dict_emptyContext::nls(size_t i) {
  return getRuleContext<MavkaParser::NlsContext>(i);
}

tree::TerminalNode* MavkaParser::Operation_dict_emptyContext::EQUAL() {
  return getToken(MavkaParser::EQUAL, 0);
}

tree::TerminalNode* MavkaParser::Operation_dict_emptyContext::BRACKET_CLOSE() {
  return getToken(MavkaParser::BRACKET_CLOSE, 0);
}

MavkaParser::Operation_dict_emptyContext::Operation_dict_emptyContext(OperationContext *ctx) { copyFrom(ctx); }

void MavkaParser::Operation_dict_emptyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOperation_dict_empty(this);
}
void MavkaParser::Operation_dict_emptyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOperation_dict_empty(this);
}

std::any MavkaParser::Operation_dict_emptyContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MavkaParserVisitor*>(visitor))
    return parserVisitor->visitOperation_dict_empty(this);
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
//----------------- Operation_numberContext ------------------------------------------------------------------

tree::TerminalNode* MavkaParser::Operation_numberContext::NUMBER() {
  return getToken(MavkaParser::NUMBER, 0);
}

MavkaParser::Operation_numberContext::Operation_numberContext(OperationContext *ctx) { copyFrom(ctx); }

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
    setState(247);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<Operation_numberContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;

      setState(167);
      match(MavkaParser::NUMBER);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<Operation_atomContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(168);
      atom(0);
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<Operation_objectContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(169);
      match(MavkaParser::PAREN_OPEN);
      setState(170);
      nls();
      setState(182);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == MavkaParser::ID) {
        setState(171);
        object_arg();
        setState(179);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx);
        while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
          if (alt == 1) {
            setState(172);
            nls();
            setState(173);
            match(MavkaParser::COMA);
            setState(174);
            nls();
            setState(175);
            object_arg(); 
          }
          setState(181);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx);
        }
      }
      setState(184);
      nls();
      setState(185);
      match(MavkaParser::PAREN_CLOSE);
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<Operation_dict_emptyContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(187);
      match(MavkaParser::BRACKET_OPEN);
      setState(188);
      nls();
      setState(189);
      match(MavkaParser::EQUAL);
      setState(190);
      nls();
      setState(191);
      match(MavkaParser::BRACKET_CLOSE);
      break;
    }

    case 5: {
      _localctx = _tracker.createInstance<Operation_dictContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(193);
      match(MavkaParser::BRACKET_OPEN);
      setState(194);
      nls();
      setState(207);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == MavkaParser::NUMBER

      || _la == MavkaParser::STRING) {
        setState(195);
        dict_arg();
        setState(196);
        nls();
        setState(204);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx);
        while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
          if (alt == 1) {
            setState(197);
            nls();
            setState(198);
            match(MavkaParser::COMA);
            setState(199);
            nls();
            setState(200);
            dict_arg(); 
          }
          setState(206);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx);
        }
      }
      setState(209);
      nls();
      setState(210);
      match(MavkaParser::BRACKET_CLOSE);
      break;
    }

    case 6: {
      _localctx = _tracker.createInstance<Operation_arrayContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(212);
      match(MavkaParser::BRACKET_OPEN);
      setState(213);
      nls();
      setState(226);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (((((_la - 43) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 43)) & 84559107) != 0)) {
        setState(214);
        expr();
        setState(215);
        nls();
        setState(223);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx);
        while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
          if (alt == 1) {
            setState(216);
            nls();
            setState(217);
            match(MavkaParser::COMA);
            setState(218);
            nls();
            setState(219);
            expr(); 
          }
          setState(225);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx);
        }
      }
      setState(228);
      nls();
      setState(229);
      match(MavkaParser::BRACKET_CLOSE);
      break;
    }

    case 7: {
      _localctx = _tracker.createInstance<Operation_pre_notContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(231);
      antlrcpp::downCast<Operation_pre_notContext *>(_localctx)->op = match(MavkaParser::EXCLAMATION);
      setState(232);
      nls();
      setState(233);
      antlrcpp::downCast<Operation_pre_notContext *>(_localctx)->right = operation(24);
      break;
    }

    case 8: {
      _localctx = _tracker.createInstance<Operation_pre_bw_notContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(235);
      antlrcpp::downCast<Operation_pre_bw_notContext *>(_localctx)->op = match(MavkaParser::TILDA);
      setState(236);
      nls();
      setState(237);
      antlrcpp::downCast<Operation_pre_bw_notContext *>(_localctx)->right = operation(23);
      break;
    }

    case 9: {
      _localctx = _tracker.createInstance<Operation_pre_plusContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(239);
      antlrcpp::downCast<Operation_pre_plusContext *>(_localctx)->op = match(MavkaParser::PLUS);
      setState(240);
      nls();
      setState(241);
      antlrcpp::downCast<Operation_pre_plusContext *>(_localctx)->right = operation(22);
      break;
    }

    case 10: {
      _localctx = _tracker.createInstance<Operation_pre_minusContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(243);
      antlrcpp::downCast<Operation_pre_minusContext *>(_localctx)->op = match(MavkaParser::MINUS);
      setState(244);
      nls();
      setState(245);
      antlrcpp::downCast<Operation_pre_minusContext *>(_localctx)->right = operation(21);
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(381);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(379);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<Operation_mulContext>(_tracker.createInstance<OperationContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleOperation);
          setState(249);

          if (!(precpred(_ctx, 20))) throw FailedPredicateException(this, "precpred(_ctx, 20)");
          setState(250);
          nls();
          setState(251);
          antlrcpp::downCast<Operation_mulContext *>(_localctx)->op = match(MavkaParser::MULTIPLY);
          setState(252);
          nls();
          setState(253);
          antlrcpp::downCast<Operation_mulContext *>(_localctx)->right = operation(21);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<Operation_divContext>(_tracker.createInstance<OperationContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleOperation);
          setState(255);

          if (!(precpred(_ctx, 19))) throw FailedPredicateException(this, "precpred(_ctx, 19)");
          setState(256);
          nls();
          setState(257);
          antlrcpp::downCast<Operation_divContext *>(_localctx)->op = match(MavkaParser::DIVIDE);
          setState(258);
          nls();
          setState(259);
          antlrcpp::downCast<Operation_divContext *>(_localctx)->right = operation(20);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<Operation_modContext>(_tracker.createInstance<OperationContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleOperation);
          setState(261);

          if (!(precpred(_ctx, 18))) throw FailedPredicateException(this, "precpred(_ctx, 18)");
          setState(262);
          nls();
          setState(263);
          antlrcpp::downCast<Operation_modContext *>(_localctx)->op = match(MavkaParser::MOD);
          setState(264);
          nls();
          setState(265);
          antlrcpp::downCast<Operation_modContext *>(_localctx)->right = operation(19);
          break;
        }

        case 4: {
          auto newContext = _tracker.createInstance<Operation_addContext>(_tracker.createInstance<OperationContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleOperation);
          setState(267);

          if (!(precpred(_ctx, 17))) throw FailedPredicateException(this, "precpred(_ctx, 17)");
          setState(268);
          nls();
          setState(269);
          antlrcpp::downCast<Operation_addContext *>(_localctx)->op = match(MavkaParser::PLUS);
          setState(270);
          nls();
          setState(271);
          antlrcpp::downCast<Operation_addContext *>(_localctx)->right = operation(18);
          break;
        }

        case 5: {
          auto newContext = _tracker.createInstance<Operation_subContext>(_tracker.createInstance<OperationContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleOperation);
          setState(273);

          if (!(precpred(_ctx, 16))) throw FailedPredicateException(this, "precpred(_ctx, 16)");
          setState(274);
          nls();
          setState(275);
          antlrcpp::downCast<Operation_subContext *>(_localctx)->op = match(MavkaParser::MINUS);
          setState(276);
          nls();
          setState(277);
          antlrcpp::downCast<Operation_subContext *>(_localctx)->right = operation(17);
          break;
        }

        case 6: {
          auto newContext = _tracker.createInstance<Operation_lshiftContext>(_tracker.createInstance<OperationContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleOperation);
          setState(279);

          if (!(precpred(_ctx, 15))) throw FailedPredicateException(this, "precpred(_ctx, 15)");
          setState(280);
          nls();
          setState(281);
          antlrcpp::downCast<Operation_lshiftContext *>(_localctx)->op = op_lshift();
          setState(282);
          nls();
          setState(283);
          antlrcpp::downCast<Operation_lshiftContext *>(_localctx)->right = operation(16);
          break;
        }

        case 7: {
          auto newContext = _tracker.createInstance<Operation_rshiftContext>(_tracker.createInstance<OperationContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleOperation);
          setState(285);

          if (!(precpred(_ctx, 14))) throw FailedPredicateException(this, "precpred(_ctx, 14)");
          setState(286);
          nls();
          setState(287);
          antlrcpp::downCast<Operation_rshiftContext *>(_localctx)->op = op_rshift();
          setState(288);
          nls();
          setState(289);
          antlrcpp::downCast<Operation_rshiftContext *>(_localctx)->right = operation(15);
          break;
        }

        case 8: {
          auto newContext = _tracker.createInstance<Operation_urshiftContext>(_tracker.createInstance<OperationContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleOperation);
          setState(291);

          if (!(precpred(_ctx, 13))) throw FailedPredicateException(this, "precpred(_ctx, 13)");
          setState(292);
          nls();
          setState(293);
          antlrcpp::downCast<Operation_urshiftContext *>(_localctx)->op = op_urshift();
          setState(294);
          nls();
          setState(295);
          antlrcpp::downCast<Operation_urshiftContext *>(_localctx)->right = operation(14);
          break;
        }

        case 9: {
          auto newContext = _tracker.createInstance<Operation_ltContext>(_tracker.createInstance<OperationContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleOperation);
          setState(297);

          if (!(precpred(_ctx, 12))) throw FailedPredicateException(this, "precpred(_ctx, 12)");
          setState(298);
          nls();
          setState(299);
          antlrcpp::downCast<Operation_ltContext *>(_localctx)->op = match(MavkaParser::LESSER);
          setState(300);
          nls();
          setState(301);
          antlrcpp::downCast<Operation_ltContext *>(_localctx)->right = operation(13);
          break;
        }

        case 10: {
          auto newContext = _tracker.createInstance<Operation_lteContext>(_tracker.createInstance<OperationContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleOperation);
          setState(303);

          if (!(precpred(_ctx, 11))) throw FailedPredicateException(this, "precpred(_ctx, 11)");
          setState(304);
          nls();
          setState(305);
          antlrcpp::downCast<Operation_lteContext *>(_localctx)->op = op_lte();
          setState(306);
          nls();
          setState(307);
          antlrcpp::downCast<Operation_lteContext *>(_localctx)->right = operation(12);
          break;
        }

        case 11: {
          auto newContext = _tracker.createInstance<Operation_gtContext>(_tracker.createInstance<OperationContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleOperation);
          setState(309);

          if (!(precpred(_ctx, 10))) throw FailedPredicateException(this, "precpred(_ctx, 10)");
          setState(310);
          nls();
          setState(311);
          antlrcpp::downCast<Operation_gtContext *>(_localctx)->op = match(MavkaParser::GREATER);
          setState(312);
          nls();
          setState(313);
          antlrcpp::downCast<Operation_gtContext *>(_localctx)->right = operation(11);
          break;
        }

        case 12: {
          auto newContext = _tracker.createInstance<Operation_gteContext>(_tracker.createInstance<OperationContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleOperation);
          setState(315);

          if (!(precpred(_ctx, 9))) throw FailedPredicateException(this, "precpred(_ctx, 9)");
          setState(316);
          nls();
          setState(317);
          antlrcpp::downCast<Operation_gteContext *>(_localctx)->op = op_gte();
          setState(318);
          nls();
          setState(319);
          antlrcpp::downCast<Operation_gteContext *>(_localctx)->right = operation(10);
          break;
        }

        case 13: {
          auto newContext = _tracker.createInstance<Operation_eqContext>(_tracker.createInstance<OperationContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleOperation);
          setState(321);

          if (!(precpred(_ctx, 8))) throw FailedPredicateException(this, "precpred(_ctx, 8)");
          setState(322);
          nls();
          setState(323);
          antlrcpp::downCast<Operation_eqContext *>(_localctx)->op = op_eq();
          setState(324);
          nls();
          setState(325);
          antlrcpp::downCast<Operation_eqContext *>(_localctx)->right = operation(9);
          break;
        }

        case 14: {
          auto newContext = _tracker.createInstance<Operation_neqContext>(_tracker.createInstance<OperationContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleOperation);
          setState(327);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(328);
          nls();
          setState(329);
          antlrcpp::downCast<Operation_neqContext *>(_localctx)->op = op_neq();
          setState(330);
          nls();
          setState(331);
          antlrcpp::downCast<Operation_neqContext *>(_localctx)->right = operation(8);
          break;
        }

        case 15: {
          auto newContext = _tracker.createInstance<Operation_andContext>(_tracker.createInstance<OperationContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleOperation);
          setState(333);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(334);
          nls();
          setState(335);
          antlrcpp::downCast<Operation_andContext *>(_localctx)->op = match(MavkaParser::AND);
          setState(336);
          nls();
          setState(337);
          antlrcpp::downCast<Operation_andContext *>(_localctx)->right = operation(7);
          break;
        }

        case 16: {
          auto newContext = _tracker.createInstance<Operation_xorContext>(_tracker.createInstance<OperationContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleOperation);
          setState(339);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(340);
          nls();
          setState(341);
          antlrcpp::downCast<Operation_xorContext *>(_localctx)->op = match(MavkaParser::POWER);
          setState(342);
          nls();
          setState(343);
          antlrcpp::downCast<Operation_xorContext *>(_localctx)->right = operation(6);
          break;
        }

        case 17: {
          auto newContext = _tracker.createInstance<Operation_orContext>(_tracker.createInstance<OperationContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleOperation);
          setState(345);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(346);
          nls();
          setState(347);
          antlrcpp::downCast<Operation_orContext *>(_localctx)->op = match(MavkaParser::OR);
          setState(348);
          nls();
          setState(349);
          antlrcpp::downCast<Operation_orContext *>(_localctx)->right = operation(5);
          break;
        }

        case 18: {
          auto newContext = _tracker.createInstance<Operation_landContext>(_tracker.createInstance<OperationContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleOperation);
          setState(351);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(352);
          nls();
          setState(353);
          antlrcpp::downCast<Operation_landContext *>(_localctx)->op = op_land();
          setState(354);
          nls();
          setState(355);
          antlrcpp::downCast<Operation_landContext *>(_localctx)->right = operation(4);
          break;
        }

        case 19: {
          auto newContext = _tracker.createInstance<Operation_lorContext>(_tracker.createInstance<OperationContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleOperation);
          setState(357);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(358);
          nls();
          setState(359);
          antlrcpp::downCast<Operation_lorContext *>(_localctx)->op = op_lor();
          setState(360);
          nls();
          setState(361);
          antlrcpp::downCast<Operation_lorContext *>(_localctx)->right = operation(3);
          break;
        }

        case 20: {
          auto newContext = _tracker.createInstance<Operation_ternaryContext>(_tracker.createInstance<OperationContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->cond = previousContext;
          pushNewRecursionContext(newContext, startState, RuleOperation);
          setState(363);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(364);
          nls();
          setState(365);
          match(MavkaParser::QUESTION);
          setState(366);
          nls();
          setState(367);
          antlrcpp::downCast<Operation_ternaryContext *>(_localctx)->ifok = operation(0);
          setState(368);
          nls();
          setState(369);
          match(MavkaParser::COLON);
          setState(370);
          nls();
          setState(371);
          antlrcpp::downCast<Operation_ternaryContext *>(_localctx)->ifnot = operation(2);
          break;
        }

        case 21: {
          auto newContext = _tracker.createInstance<Operation_asContext>(_tracker.createInstance<OperationContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleOperation);
          setState(373);

          if (!(precpred(_ctx, 25))) throw FailedPredicateException(this, "precpred(_ctx, 25)");
          setState(374);
          nls();
          setState(375);
          antlrcpp::downCast<Operation_asContext *>(_localctx)->op = match(MavkaParser::KW_AS);
          setState(376);
          nls();

          setState(377);
          antlrcpp::downCast<Operation_asContext *>(_localctx)->right_type = type();
          break;
        }

        default:
          break;
        } 
      }
      setState(383);
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
    setState(384);
    match(MavkaParser::LESSER);
    setState(385);
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
    setState(387);
    match(MavkaParser::GREATER);
    setState(388);
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
    setState(390);
    match(MavkaParser::GREATER);
    setState(391);
    match(MavkaParser::GREATER);
    setState(392);
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
    setState(394);
    match(MavkaParser::LESSER);
    setState(395);
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
    setState(397);
    match(MavkaParser::GREATER);
    setState(398);
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
    setState(400);
    match(MavkaParser::EQUAL);
    setState(401);
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
    setState(403);
    match(MavkaParser::EXCLAMATION);
    setState(404);
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
    setState(406);
    match(MavkaParser::AND);
    setState(407);
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
    setState(409);
    match(MavkaParser::OR);
    setState(410);
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
    setState(412);
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
    setState(414);
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
    setState(416);
    match(MavkaParser::KW_STRUCTURE);
    setState(417);
    antlrcpp::downCast<Structure_defineContext *>(_localctx)->id = match(MavkaParser::ID);
    setState(420);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == MavkaParser::KW_IS) {
      setState(418);
      match(MavkaParser::KW_IS);
      setState(419);
      antlrcpp::downCast<Structure_defineContext *>(_localctx)->s_parent = atom(0);
    }
    setState(422);
    nl();
    setState(434);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == MavkaParser::ID) {
      setState(423);
      structure_element();
      setState(424);
      nls();
      setState(431);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(425);
          nl();
          setState(426);
          nls();
          setState(427);
          structure_element(); 
        }
        setState(433);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx);
      }
    }
    setState(436);
    nls();
    setState(437);
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
    setState(439);
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

MavkaParser::TypesContext* MavkaParser::Diia_defineContext::types() {
  return getRuleContext<MavkaParser::TypesContext>(0);
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
    setState(442);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == MavkaParser::KW_ASYNC) {
      setState(441);
      antlrcpp::downCast<Diia_defineContext *>(_localctx)->d_async = match(MavkaParser::KW_ASYNC);
    }
    setState(445);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == MavkaParser::KW_SPEC) {
      setState(444);
      antlrcpp::downCast<Diia_defineContext *>(_localctx)->d_spec = match(MavkaParser::KW_SPEC);
    }
    setState(447);
    match(MavkaParser::KW_DIIA);
    setState(454);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 24, _ctx)) {
    case 1: {
      setState(451);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 23, _ctx)) {
      case 1: {
        setState(448);
        antlrcpp::downCast<Diia_defineContext *>(_localctx)->d_structure = atom(0);
        setState(449);
        match(MavkaParser::DOT);
        break;
      }

      default:
        break;
      }
      setState(453);
      antlrcpp::downCast<Diia_defineContext *>(_localctx)->d_name = match(MavkaParser::ID);
      break;
    }

    default:
      break;
    }
    setState(456);
    match(MavkaParser::PAREN_OPEN);
    setState(457);
    nls();
    setState(469);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == MavkaParser::ID) {
      setState(458);
      diia_param();
      setState(459);
      nls();
      setState(466);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == MavkaParser::COMA) {
        setState(460);
        match(MavkaParser::COMA);
        setState(461);
        nls();
        setState(462);
        diia_param();
        setState(468);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(471);
    nls();
    setState(472);
    match(MavkaParser::PAREN_CLOSE);
    setState(474);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((((_la - 51) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 51)) & 327681) != 0)) {
      setState(473);
      antlrcpp::downCast<Diia_defineContext *>(_localctx)->d_type = types();
    }
    setState(476);
    nl();
    setState(480);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 5920008098466029900) != 0) || _la == MavkaParser::ID

    || _la == MavkaParser::STRING) {
      setState(477);
      antlrcpp::downCast<Diia_defineContext *>(_localctx)->d_body = body();
      setState(478);
      nl();
    }
    setState(482);
    nls();
    setState(483);
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
    setState(485);
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
    setState(487);
    antlrcpp::downCast<AssignContext *>(_localctx)->id = match(MavkaParser::ID);
    setState(491);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MavkaParser::EQUAL: {
        setState(488);
        antlrcpp::downCast<AssignContext *>(_localctx)->simpleas = match(MavkaParser::EQUAL);
        break;
      }

      case MavkaParser::COLON: {
        setState(489);
        antlrcpp::downCast<AssignContext *>(_localctx)->parentas = match(MavkaParser::COLON);
        setState(490);
        match(MavkaParser::EQUAL);
        break;
      }

    default:
      throw NoViableAltException(this);
    }

    setState(493);
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
    setState(495);
    antlrcpp::downCast<SetContext *>(_localctx)->object = atom(0);
    setState(496);
    match(MavkaParser::DOT);
    setState(497);
    antlrcpp::downCast<SetContext *>(_localctx)->id = match(MavkaParser::ID);
    setState(498);
    match(MavkaParser::EQUAL);

    setState(499);
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
    setState(501);
    antlrcpp::downCast<Position_setContext *>(_localctx)->object = atom(0);
    setState(502);
    match(MavkaParser::BRACKET_OPEN);
    setState(503);
    antlrcpp::downCast<Position_setContext *>(_localctx)->idx = expr();
    setState(504);
    match(MavkaParser::BRACKET_CLOSE);
    setState(505);
    match(MavkaParser::EQUAL);

    setState(506);
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
    setState(508);
    match(MavkaParser::KW_IF);
    setState(509);
    antlrcpp::downCast<IfContext *>(_localctx)->cond = expr();
    setState(510);
    nl();
    setState(514);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 5920008098466029900) != 0) || _la == MavkaParser::ID

    || _la == MavkaParser::STRING) {
      setState(511);
      antlrcpp::downCast<IfContext *>(_localctx)->ifok = body();
      setState(512);
      nl();
    }
    setState(526);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 32, _ctx)) {
    case 1: {
      setState(521);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == MavkaParser::KW_ELSE) {
        setState(516);
        match(MavkaParser::KW_ELSE);
        setState(517);
        nl();
        setState(518);
        antlrcpp::downCast<IfContext *>(_localctx)->ifnot = body();
        setState(519);
        nl();
      }
      setState(523);
      match(MavkaParser::KW_END);
      break;
    }

    case 2: {
      setState(524);
      match(MavkaParser::KW_ELSE);
      setState(525);
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
    setState(528);
    match(MavkaParser::KW_WHILE);
    setState(529);
    antlrcpp::downCast<WhileContext *>(_localctx)->cond = operation(0);
    setState(530);
    nl();
    setState(534);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 5920008098466029900) != 0) || _la == MavkaParser::ID

    || _la == MavkaParser::STRING) {
      setState(531);
      antlrcpp::downCast<WhileContext *>(_localctx)->w_body = body();
      setState(532);
      nl();
    }
    setState(536);
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
    setState(538);
    body_element();
    setState(544);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 34, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(539);
        nl();
        setState(540);
        body_element(); 
      }
      setState(546);
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
    setState(557);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 35, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(547);
      structure_define();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(548);
      diia_define();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(549);
      assign();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(550);
      set();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(551);
      position_set();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(552);
      if_();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(553);
      while_();
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(554);
      expr();
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(555);
      return_();
      break;
    }

    case 10: {
      enterOuterAlt(_localctx, 10);
      setState(556);
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
    setState(559);
    match(MavkaParser::KW_RETURN);
    setState(561);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((((_la - 43) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 43)) & 84559107) != 0)) {
      setState(560);
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
    setState(563);
    atom(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypesContext ------------------------------------------------------------------

MavkaParser::TypesContext::TypesContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<MavkaParser::TypeContext *> MavkaParser::TypesContext::type() {
  return getRuleContexts<MavkaParser::TypeContext>();
}

MavkaParser::TypeContext* MavkaParser::TypesContext::type(size_t i) {
  return getRuleContext<MavkaParser::TypeContext>(i);
}

std::vector<MavkaParser::NlsContext *> MavkaParser::TypesContext::nls() {
  return getRuleContexts<MavkaParser::NlsContext>();
}

MavkaParser::NlsContext* MavkaParser::TypesContext::nls(size_t i) {
  return getRuleContext<MavkaParser::NlsContext>(i);
}

std::vector<tree::TerminalNode *> MavkaParser::TypesContext::KW_OR() {
  return getTokens(MavkaParser::KW_OR);
}

tree::TerminalNode* MavkaParser::TypesContext::KW_OR(size_t i) {
  return getToken(MavkaParser::KW_OR, i);
}


size_t MavkaParser::TypesContext::getRuleIndex() const {
  return MavkaParser::RuleTypes;
}

void MavkaParser::TypesContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTypes(this);
}

void MavkaParser::TypesContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTypes(this);
}


std::any MavkaParser::TypesContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MavkaParserVisitor*>(visitor))
    return parserVisitor->visitTypes(this);
  else
    return visitor->visitChildren(this);
}

MavkaParser::TypesContext* MavkaParser::types() {
  TypesContext *_localctx = _tracker.createInstance<TypesContext>(_ctx, getState());
  enterRule(_localctx, 62, MavkaParser::RuleTypes);

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
    setState(565);
    type();
    setState(573);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 37, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(566);
        nls();
        setState(567);
        match(MavkaParser::KW_OR);
        setState(568);
        nls();
        setState(569);
        type(); 
      }
      setState(575);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 37, _ctx);
    }
   
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

MavkaParser::TypesContext* MavkaParser::ParamContext::types() {
  return getRuleContext<MavkaParser::TypesContext>(0);
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
  enterRule(_localctx, 64, MavkaParser::RuleParam);
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
    setState(576);
    antlrcpp::downCast<ParamContext *>(_localctx)->id = match(MavkaParser::ID);
    setState(578);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((((_la - 51) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 51)) & 327681) != 0)) {
      setState(577);
      types();
    }
    setState(582);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == MavkaParser::EQUAL) {
      setState(580);
      match(MavkaParser::EQUAL);
      setState(581);
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
  enterRule(_localctx, 66, MavkaParser::RuleTake);
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
    setState(584);
    match(MavkaParser::KW_TAKE);
    setState(586);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 40, _ctx)) {
    case 1: {
      setState(585);
      antlrcpp::downCast<TakeContext *>(_localctx)->type_id = match(MavkaParser::ID);
      break;
    }

    default:
      break;
    }
    setState(588);
    take_element();
    setState(593);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == MavkaParser::DOT) {
      setState(589);
      match(MavkaParser::DOT);
      setState(590);
      take_element();
      setState(595);
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
  enterRule(_localctx, 68, MavkaParser::RuleTake_element);
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
    setState(596);
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
  enterRule(_localctx, 70, MavkaParser::RuleNl);

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
    setState(599); 
    _errHandler->sync(this);
    alt = 1;
    do {
      switch (alt) {
        case 1: {
              setState(598);
              match(MavkaParser::NL);
              break;
            }

      default:
        throw NoViableAltException(this);
      }
      setState(601); 
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 42, _ctx);
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
  enterRule(_localctx, 72, MavkaParser::RuleNls);

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
    setState(606);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 43, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(603);
        match(MavkaParser::NL); 
      }
      setState(608);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 43, _ctx);
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
