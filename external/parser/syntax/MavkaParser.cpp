
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
      "nl", "nls", "number", "string", "character", "identifier", "type", 
      "file", "assign", "set", "set_by_access", "structure", "structure_elements", 
      "structure_element", "structure_param", "diia", "diia_params", "diia_param", 
      "module", "if", "while", "interval", "cycle", "cycle_step", "try", 
      "throw", "chain", "take", "take_elements", "take_element", "subject_out", 
      "get_out", "generic_out", "particle", "call_args", "call_arg", "atom", 
      "molecule", "operation", "array_elements", "dict_elements", "dict_element", 
      "expr", "give", "give_element", "body", "body_element", "return_body_element", 
      "arithmetic_op_mul", "arithmetic_op_add", "bitwise_op", "logical_op", 
      "comparison_op", "assign_op"
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
      "COMA", "INTEGER", "FLOAT", "HEX", "BIN", "NUMBER", "ID", "KWID", 
      "STRING_MULTILINE", "STRING", "CHARACTER", "COMMENT", "LINE_COMMENT", 
      "MRM_DIIA", "NL", "WS"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,76,801,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,7,
  	21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,7,
  	28,2,29,7,29,2,30,7,30,2,31,7,31,2,32,7,32,2,33,7,33,2,34,7,34,2,35,7,
  	35,2,36,7,36,2,37,7,37,2,38,7,38,2,39,7,39,2,40,7,40,2,41,7,41,2,42,7,
  	42,2,43,7,43,2,44,7,44,2,45,7,45,2,46,7,46,2,47,7,47,2,48,7,48,2,49,7,
  	49,2,50,7,50,2,51,7,51,2,52,7,52,2,53,7,53,1,0,4,0,110,8,0,11,0,12,0,
  	111,1,1,5,1,115,8,1,10,1,12,1,118,9,1,1,2,1,2,1,3,1,3,1,4,1,4,1,5,1,5,
  	1,6,3,6,129,8,6,1,6,1,6,1,6,3,6,134,8,6,1,7,1,7,1,7,1,7,1,7,1,8,1,8,1,
  	8,1,8,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,10,1,10,1,10,1,10,1,10,1,10,1,10,
  	1,11,1,11,3,11,161,8,11,1,11,1,11,3,11,165,8,11,1,11,1,11,1,11,1,11,3,
  	11,171,8,11,1,11,1,11,1,11,1,12,1,12,1,12,1,12,5,12,180,8,12,10,12,12,
  	12,183,9,12,1,13,1,13,1,14,1,14,3,14,189,8,14,1,14,1,14,3,14,193,8,14,
  	1,15,3,15,196,8,15,1,15,3,15,199,8,15,1,15,1,15,1,15,1,15,3,15,205,8,
  	15,1,15,3,15,208,8,15,1,15,1,15,1,15,3,15,213,8,15,1,15,1,15,1,15,3,15,
  	218,8,15,1,15,1,15,1,15,1,15,3,15,224,8,15,1,15,1,15,1,16,1,16,1,16,1,
  	16,1,16,1,16,5,16,234,8,16,10,16,12,16,237,9,16,1,16,1,16,1,16,3,16,242,
  	8,16,1,17,1,17,3,17,246,8,17,1,17,1,17,3,17,250,8,17,1,18,1,18,3,18,254,
  	8,18,1,18,1,18,1,18,1,18,3,18,260,8,18,1,18,1,18,1,19,1,19,1,19,1,19,
  	1,19,1,19,3,19,270,8,19,1,19,1,19,1,19,1,19,1,19,3,19,277,8,19,1,19,1,
  	19,1,19,3,19,282,8,19,1,20,1,20,1,20,1,20,1,20,1,20,3,20,290,8,20,1,20,
  	1,20,1,21,1,21,1,21,1,21,1,21,3,21,299,8,21,1,21,1,21,1,21,1,21,1,21,
  	1,21,3,21,307,8,21,1,21,1,21,1,22,1,22,3,22,313,8,22,1,22,1,22,3,22,317,
  	8,22,1,22,1,22,3,22,321,8,22,3,22,323,8,22,1,22,1,22,1,22,1,22,3,22,329,
  	8,22,1,22,1,22,1,23,1,23,1,23,3,23,336,8,23,1,24,1,24,1,24,1,24,1,24,
  	3,24,343,8,24,1,24,1,24,3,24,347,8,24,1,24,1,24,1,24,1,24,3,24,353,8,
  	24,1,24,1,24,1,25,1,25,1,25,1,26,1,26,1,26,1,26,1,26,1,26,5,26,366,8,
  	26,10,26,12,26,369,9,26,1,27,1,27,3,27,373,8,27,1,27,1,27,1,27,1,27,3,
  	27,379,8,27,1,28,1,28,1,28,1,28,1,28,1,28,1,28,1,28,5,28,389,8,28,10,
  	28,12,28,392,9,28,1,28,1,28,1,28,3,28,397,8,28,1,28,1,28,1,28,1,29,1,
  	29,1,29,3,29,405,8,29,1,30,1,30,1,31,1,31,1,31,1,31,1,31,1,31,1,32,1,
  	32,1,32,1,32,1,32,1,32,1,32,1,32,1,32,1,32,5,32,425,8,32,10,32,12,32,
  	428,9,32,1,32,1,32,1,33,1,33,1,33,1,33,1,33,1,33,1,33,1,33,3,33,440,8,
  	33,1,33,1,33,1,33,1,33,1,33,1,33,1,33,1,33,1,33,1,33,1,33,1,33,1,33,1,
  	33,1,33,1,33,5,33,458,8,33,10,33,12,33,461,9,33,1,33,1,33,1,33,1,33,1,
  	33,1,33,1,33,1,33,1,33,1,33,1,33,1,33,1,33,1,33,1,33,3,33,478,8,33,1,
  	33,1,33,1,33,5,33,483,8,33,10,33,12,33,486,9,33,1,34,1,34,1,34,1,34,1,
  	34,1,34,5,34,494,8,34,10,34,12,34,497,9,34,1,34,1,34,1,34,3,34,502,8,
  	34,1,35,1,35,1,35,1,35,1,35,1,35,1,35,3,35,511,8,35,1,36,1,36,1,36,1,
  	36,3,36,517,8,36,1,37,1,37,1,37,1,37,1,37,1,37,1,37,3,37,526,8,37,1,38,
  	1,38,1,38,1,38,1,38,3,38,533,8,38,1,38,1,38,1,38,1,38,1,38,1,38,3,38,
  	541,8,38,1,38,1,38,1,38,3,38,546,8,38,1,38,1,38,1,38,1,38,1,38,1,38,1,
  	38,1,38,1,38,1,38,1,38,1,38,1,38,1,38,1,38,1,38,1,38,1,38,1,38,1,38,5,
  	38,568,8,38,10,38,12,38,571,9,38,1,39,1,39,1,39,1,39,1,39,1,39,5,39,579,
  	8,39,10,39,12,39,582,9,39,1,39,1,39,1,39,3,39,587,8,39,1,40,1,40,1,40,
  	1,40,1,40,1,40,5,40,595,8,40,10,40,12,40,598,9,40,1,40,1,40,1,40,3,40,
  	603,8,40,1,41,1,41,1,41,3,41,608,8,41,1,41,1,41,1,41,1,41,1,41,1,42,1,
  	42,1,42,1,42,1,42,1,42,1,42,1,42,1,42,1,42,1,42,1,42,1,42,1,42,1,42,4,
  	42,630,8,42,11,42,12,42,631,1,42,1,42,1,42,1,42,3,42,638,8,42,1,42,1,
  	42,1,42,3,42,643,8,42,1,42,1,42,1,42,1,42,1,42,1,42,1,42,1,42,1,42,1,
  	42,1,42,1,42,1,42,1,42,3,42,659,8,42,1,43,1,43,1,43,1,43,1,43,1,43,1,
  	43,5,43,668,8,43,10,43,12,43,671,9,43,1,44,1,44,1,44,3,44,676,8,44,1,
  	45,1,45,1,45,1,45,5,45,682,8,45,10,45,12,45,685,9,45,1,46,1,46,1,46,1,
  	46,1,46,1,46,1,46,1,46,1,46,1,46,1,46,1,46,1,46,1,46,3,46,701,8,46,1,
  	47,1,47,3,47,705,8,47,1,48,1,48,1,48,1,48,1,48,1,48,1,48,3,48,714,8,48,
  	1,49,1,49,1,50,1,50,1,50,1,50,1,50,1,50,1,50,1,50,1,50,1,50,3,50,728,
  	8,50,1,51,1,51,1,51,1,51,1,51,1,51,3,51,736,8,51,1,52,1,52,1,52,1,52,
  	1,52,1,52,1,52,1,52,1,52,1,52,1,52,1,52,1,52,1,52,1,52,1,52,1,52,1,52,
  	1,52,1,52,1,52,1,52,1,52,1,52,1,52,3,52,763,8,52,1,53,1,53,1,53,1,53,
  	1,53,1,53,1,53,1,53,1,53,1,53,1,53,1,53,1,53,1,53,1,53,1,53,1,53,1,53,
  	1,53,1,53,1,53,1,53,1,53,1,53,1,53,1,53,1,53,1,53,1,53,1,53,1,53,1,53,
  	1,53,1,53,3,53,799,8,53,1,53,0,2,66,76,54,0,2,4,6,8,10,12,14,16,18,20,
  	22,24,26,28,30,32,34,36,38,40,42,44,46,48,50,52,54,56,58,60,62,64,66,
  	68,70,72,74,76,78,80,82,84,86,88,90,92,94,96,98,100,102,104,106,0,3,1,
  	0,62,65,1,0,69,70,1,0,43,44,894,0,109,1,0,0,0,2,116,1,0,0,0,4,119,1,0,
  	0,0,6,121,1,0,0,0,8,123,1,0,0,0,10,125,1,0,0,0,12,128,1,0,0,0,14,135,
  	1,0,0,0,16,140,1,0,0,0,18,144,1,0,0,0,20,151,1,0,0,0,22,158,1,0,0,0,24,
  	175,1,0,0,0,26,184,1,0,0,0,28,186,1,0,0,0,30,195,1,0,0,0,32,227,1,0,0,
  	0,34,243,1,0,0,0,36,251,1,0,0,0,38,263,1,0,0,0,40,283,1,0,0,0,42,293,
  	1,0,0,0,44,310,1,0,0,0,46,335,1,0,0,0,48,337,1,0,0,0,50,356,1,0,0,0,52,
  	359,1,0,0,0,54,370,1,0,0,0,56,380,1,0,0,0,58,401,1,0,0,0,60,406,1,0,0,
  	0,62,408,1,0,0,0,64,414,1,0,0,0,66,439,1,0,0,0,68,487,1,0,0,0,70,510,
  	1,0,0,0,72,516,1,0,0,0,74,525,1,0,0,0,76,545,1,0,0,0,78,572,1,0,0,0,80,
  	588,1,0,0,0,82,607,1,0,0,0,84,658,1,0,0,0,86,660,1,0,0,0,88,672,1,0,0,
  	0,90,677,1,0,0,0,92,700,1,0,0,0,94,702,1,0,0,0,96,713,1,0,0,0,98,715,
  	1,0,0,0,100,727,1,0,0,0,102,735,1,0,0,0,104,762,1,0,0,0,106,798,1,0,0,
  	0,108,110,5,75,0,0,109,108,1,0,0,0,110,111,1,0,0,0,111,109,1,0,0,0,111,
  	112,1,0,0,0,112,1,1,0,0,0,113,115,5,75,0,0,114,113,1,0,0,0,115,118,1,
  	0,0,0,116,114,1,0,0,0,116,117,1,0,0,0,117,3,1,0,0,0,118,116,1,0,0,0,119,
  	120,7,0,0,0,120,5,1,0,0,0,121,122,7,1,0,0,122,7,1,0,0,0,123,124,5,71,
  	0,0,124,9,1,0,0,0,125,126,5,67,0,0,126,11,1,0,0,0,127,129,5,55,0,0,128,
  	127,1,0,0,0,128,129,1,0,0,0,129,133,1,0,0,0,130,134,3,60,30,0,131,134,
  	3,62,31,0,132,134,3,64,32,0,133,130,1,0,0,0,133,131,1,0,0,0,133,132,1,
  	0,0,0,134,13,1,0,0,0,135,136,3,2,1,0,136,137,3,90,45,0,137,138,3,2,1,
  	0,138,139,5,0,0,1,139,15,1,0,0,0,140,141,3,10,5,0,141,142,3,106,53,0,
  	142,143,3,84,42,0,143,17,1,0,0,0,144,145,3,66,33,0,145,146,5,42,0,0,146,
  	147,3,10,5,0,147,148,1,0,0,0,148,149,3,106,53,0,149,150,3,84,42,0,150,
  	19,1,0,0,0,151,152,3,66,33,0,152,153,5,53,0,0,153,154,3,84,42,0,154,155,
  	5,54,0,0,155,156,3,106,53,0,156,157,3,84,42,0,157,21,1,0,0,0,158,160,
  	5,3,0,0,159,161,3,10,5,0,160,159,1,0,0,0,160,161,1,0,0,0,161,164,1,0,
  	0,0,162,163,5,12,0,0,163,165,3,10,5,0,164,162,1,0,0,0,164,165,1,0,0,0,
  	165,166,1,0,0,0,166,170,3,0,0,0,167,168,3,24,12,0,168,169,3,0,0,0,169,
  	171,1,0,0,0,170,167,1,0,0,0,170,171,1,0,0,0,171,172,1,0,0,0,172,173,3,
  	2,1,0,173,174,5,1,0,0,174,23,1,0,0,0,175,181,3,26,13,0,176,177,3,0,0,
  	0,177,178,3,26,13,0,178,180,1,0,0,0,179,176,1,0,0,0,180,183,1,0,0,0,181,
  	179,1,0,0,0,181,182,1,0,0,0,182,25,1,0,0,0,183,181,1,0,0,0,184,185,3,
  	28,14,0,185,27,1,0,0,0,186,188,3,10,5,0,187,189,3,12,6,0,188,187,1,0,
  	0,0,188,189,1,0,0,0,189,192,1,0,0,0,190,191,5,39,0,0,191,193,3,84,42,
  	0,192,190,1,0,0,0,192,193,1,0,0,0,193,29,1,0,0,0,194,196,5,15,0,0,195,
  	194,1,0,0,0,195,196,1,0,0,0,196,198,1,0,0,0,197,199,5,13,0,0,198,197,
  	1,0,0,0,198,199,1,0,0,0,199,200,1,0,0,0,200,207,5,2,0,0,201,202,3,10,
  	5,0,202,203,5,42,0,0,203,205,1,0,0,0,204,201,1,0,0,0,204,205,1,0,0,0,
  	205,206,1,0,0,0,206,208,3,10,5,0,207,204,1,0,0,0,207,208,1,0,0,0,208,
  	209,1,0,0,0,209,210,5,51,0,0,210,212,3,2,1,0,211,213,3,32,16,0,212,211,
  	1,0,0,0,212,213,1,0,0,0,213,214,1,0,0,0,214,215,3,2,1,0,215,217,5,52,
  	0,0,216,218,3,12,6,0,217,216,1,0,0,0,217,218,1,0,0,0,218,219,1,0,0,0,
  	219,223,3,0,0,0,220,221,3,90,45,0,221,222,3,0,0,0,222,224,1,0,0,0,223,
  	220,1,0,0,0,223,224,1,0,0,0,224,225,1,0,0,0,225,226,5,1,0,0,226,31,1,
  	0,0,0,227,235,3,34,17,0,228,229,3,2,1,0,229,230,5,61,0,0,230,231,3,2,
  	1,0,231,232,3,34,17,0,232,234,1,0,0,0,233,228,1,0,0,0,234,237,1,0,0,0,
  	235,233,1,0,0,0,235,236,1,0,0,0,236,241,1,0,0,0,237,235,1,0,0,0,238,239,
  	3,2,1,0,239,240,5,61,0,0,240,242,1,0,0,0,241,238,1,0,0,0,241,242,1,0,
  	0,0,242,33,1,0,0,0,243,245,3,10,5,0,244,246,3,12,6,0,245,244,1,0,0,0,
  	245,246,1,0,0,0,246,249,1,0,0,0,247,248,5,39,0,0,248,250,3,84,42,0,249,
  	247,1,0,0,0,249,250,1,0,0,0,250,35,1,0,0,0,251,253,5,24,0,0,252,254,3,
  	10,5,0,253,252,1,0,0,0,253,254,1,0,0,0,254,255,1,0,0,0,255,259,3,0,0,
  	0,256,257,3,90,45,0,257,258,3,0,0,0,258,260,1,0,0,0,259,256,1,0,0,0,259,
  	260,1,0,0,0,260,261,1,0,0,0,261,262,5,1,0,0,262,37,1,0,0,0,263,264,5,
  	6,0,0,264,265,3,84,42,0,265,269,3,0,0,0,266,267,3,90,45,0,267,268,3,0,
  	0,0,268,270,1,0,0,0,269,266,1,0,0,0,269,270,1,0,0,0,270,281,1,0,0,0,271,
  	272,5,21,0,0,272,273,3,0,0,0,273,274,3,90,45,0,274,275,3,0,0,0,275,277,
  	1,0,0,0,276,271,1,0,0,0,276,277,1,0,0,0,277,278,1,0,0,0,278,282,5,1,0,
  	0,279,280,5,21,0,0,280,282,3,38,19,0,281,276,1,0,0,0,281,279,1,0,0,0,
  	282,39,1,0,0,0,283,284,5,23,0,0,284,285,3,76,38,0,285,289,3,0,0,0,286,
  	287,3,90,45,0,287,288,3,0,0,0,288,290,1,0,0,0,289,286,1,0,0,0,289,290,
  	1,0,0,0,290,291,1,0,0,0,291,292,5,1,0,0,292,41,1,0,0,0,293,294,5,4,0,
  	0,294,298,3,76,38,0,295,296,5,42,0,0,296,297,5,42,0,0,297,299,3,76,38,
  	0,298,295,1,0,0,0,298,299,1,0,0,0,299,300,1,0,0,0,300,301,5,10,0,0,301,
  	302,3,10,5,0,302,306,3,0,0,0,303,304,3,90,45,0,304,305,3,0,0,0,305,307,
  	1,0,0,0,306,303,1,0,0,0,306,307,1,0,0,0,307,308,1,0,0,0,308,309,5,1,0,
  	0,309,43,1,0,0,0,310,322,5,5,0,0,311,313,3,46,23,0,312,311,1,0,0,0,312,
  	313,1,0,0,0,313,314,1,0,0,0,314,316,5,61,0,0,315,317,3,46,23,0,316,315,
  	1,0,0,0,316,317,1,0,0,0,317,318,1,0,0,0,318,320,5,61,0,0,319,321,3,46,
  	23,0,320,319,1,0,0,0,320,321,1,0,0,0,321,323,1,0,0,0,322,312,1,0,0,0,
  	322,323,1,0,0,0,323,324,1,0,0,0,324,328,3,0,0,0,325,326,3,90,45,0,326,
  	327,3,0,0,0,327,329,1,0,0,0,328,325,1,0,0,0,328,329,1,0,0,0,329,330,1,
  	0,0,0,330,331,5,1,0,0,331,45,1,0,0,0,332,336,3,16,8,0,333,336,3,18,9,
  	0,334,336,3,76,38,0,335,332,1,0,0,0,335,333,1,0,0,0,335,334,1,0,0,0,336,
  	47,1,0,0,0,337,338,5,19,0,0,338,342,3,0,0,0,339,340,3,90,45,0,340,341,
  	3,0,0,0,341,343,1,0,0,0,342,339,1,0,0,0,342,343,1,0,0,0,343,344,1,0,0,
  	0,344,346,5,20,0,0,345,347,3,10,5,0,346,345,1,0,0,0,346,347,1,0,0,0,347,
  	348,1,0,0,0,348,352,3,0,0,0,349,350,3,90,45,0,350,351,3,0,0,0,351,353,
  	1,0,0,0,352,349,1,0,0,0,352,353,1,0,0,0,353,354,1,0,0,0,354,355,5,1,0,
  	0,355,49,1,0,0,0,356,357,5,22,0,0,357,358,3,84,42,0,358,51,1,0,0,0,359,
  	367,3,10,5,0,360,361,3,2,1,0,361,362,5,42,0,0,362,363,3,2,1,0,363,364,
  	3,10,5,0,364,366,1,0,0,0,365,360,1,0,0,0,366,369,1,0,0,0,367,365,1,0,
  	0,0,367,368,1,0,0,0,368,53,1,0,0,0,369,367,1,0,0,0,370,372,5,8,0,0,371,
  	373,3,10,5,0,372,371,1,0,0,0,372,373,1,0,0,0,373,374,1,0,0,0,374,378,
  	3,52,26,0,375,379,3,56,28,0,376,377,5,10,0,0,377,379,3,10,5,0,378,375,
  	1,0,0,0,378,376,1,0,0,0,378,379,1,0,0,0,379,55,1,0,0,0,380,381,5,53,0,
  	0,381,382,3,2,1,0,382,390,3,58,29,0,383,384,3,2,1,0,384,385,5,61,0,0,
  	385,386,3,2,1,0,386,387,3,58,29,0,387,389,1,0,0,0,388,383,1,0,0,0,389,
  	392,1,0,0,0,390,388,1,0,0,0,390,391,1,0,0,0,391,396,1,0,0,0,392,390,1,
  	0,0,0,393,394,3,2,1,0,394,395,5,61,0,0,395,397,1,0,0,0,396,393,1,0,0,
  	0,396,397,1,0,0,0,397,398,1,0,0,0,398,399,3,2,1,0,399,400,5,54,0,0,400,
  	57,1,0,0,0,401,404,3,10,5,0,402,403,5,10,0,0,403,405,3,10,5,0,404,402,
  	1,0,0,0,404,405,1,0,0,0,405,59,1,0,0,0,406,407,3,10,5,0,407,61,1,0,0,
  	0,408,409,3,66,33,0,409,410,3,2,1,0,410,411,5,42,0,0,411,412,3,2,1,0,
  	412,413,3,10,5,0,413,63,1,0,0,0,414,415,3,66,33,0,415,416,3,2,1,0,416,
  	417,5,41,0,0,417,418,3,2,1,0,418,426,3,12,6,0,419,420,3,2,1,0,420,421,
  	5,61,0,0,421,422,3,2,1,0,422,423,3,12,6,0,423,425,1,0,0,0,424,419,1,0,
  	0,0,425,428,1,0,0,0,426,424,1,0,0,0,426,427,1,0,0,0,427,429,1,0,0,0,428,
  	426,1,0,0,0,429,430,3,2,1,0,430,65,1,0,0,0,431,432,6,33,-1,0,432,440,
  	3,10,5,0,433,434,5,51,0,0,434,435,3,2,1,0,435,436,3,84,42,0,436,437,3,
  	2,1,0,437,438,5,52,0,0,438,440,1,0,0,0,439,431,1,0,0,0,439,433,1,0,0,
  	0,440,484,1,0,0,0,441,442,10,5,0,0,442,443,3,2,1,0,443,444,5,42,0,0,444,
  	445,3,2,1,0,445,446,3,10,5,0,446,483,1,0,0,0,447,448,10,4,0,0,448,449,
  	3,2,1,0,449,450,5,41,0,0,450,451,3,2,1,0,451,459,3,12,6,0,452,453,3,2,
  	1,0,453,454,5,61,0,0,454,455,3,2,1,0,455,456,3,12,6,0,456,458,1,0,0,0,
  	457,452,1,0,0,0,458,461,1,0,0,0,459,457,1,0,0,0,459,460,1,0,0,0,460,462,
  	1,0,0,0,461,459,1,0,0,0,462,463,3,2,1,0,463,464,5,40,0,0,464,483,1,0,
  	0,0,465,466,10,3,0,0,466,467,3,2,1,0,467,468,5,53,0,0,468,469,3,2,1,0,
  	469,470,3,84,42,0,470,471,3,2,1,0,471,472,5,54,0,0,472,483,1,0,0,0,473,
  	474,10,2,0,0,474,475,5,51,0,0,475,477,3,2,1,0,476,478,3,68,34,0,477,476,
  	1,0,0,0,477,478,1,0,0,0,478,479,1,0,0,0,479,480,3,2,1,0,480,481,5,52,
  	0,0,481,483,1,0,0,0,482,441,1,0,0,0,482,447,1,0,0,0,482,465,1,0,0,0,482,
  	473,1,0,0,0,483,486,1,0,0,0,484,482,1,0,0,0,484,485,1,0,0,0,485,67,1,
  	0,0,0,486,484,1,0,0,0,487,495,3,70,35,0,488,489,3,2,1,0,489,490,5,61,
  	0,0,490,491,3,2,1,0,491,492,3,70,35,0,492,494,1,0,0,0,493,488,1,0,0,0,
  	494,497,1,0,0,0,495,493,1,0,0,0,495,496,1,0,0,0,496,501,1,0,0,0,497,495,
  	1,0,0,0,498,499,3,2,1,0,499,500,5,61,0,0,500,502,1,0,0,0,501,498,1,0,
  	0,0,501,502,1,0,0,0,502,69,1,0,0,0,503,511,3,84,42,0,504,505,3,10,5,0,
  	505,506,3,2,1,0,506,507,5,39,0,0,507,508,3,2,1,0,508,509,3,84,42,0,509,
  	511,1,0,0,0,510,503,1,0,0,0,510,504,1,0,0,0,511,71,1,0,0,0,512,517,3,
  	66,33,0,513,517,3,4,2,0,514,517,3,6,3,0,515,517,3,8,4,0,516,512,1,0,0,
  	0,516,513,1,0,0,0,516,514,1,0,0,0,516,515,1,0,0,0,517,73,1,0,0,0,518,
  	526,3,72,36,0,519,520,5,60,0,0,520,526,3,74,37,0,521,522,5,44,0,0,522,
  	526,3,72,36,0,523,524,5,57,0,0,524,526,3,72,36,0,525,518,1,0,0,0,525,
  	519,1,0,0,0,525,521,1,0,0,0,525,523,1,0,0,0,526,75,1,0,0,0,527,528,6,
  	38,-1,0,528,546,3,74,37,0,529,530,5,53,0,0,530,532,3,2,1,0,531,533,3,
  	78,39,0,532,531,1,0,0,0,532,533,1,0,0,0,533,534,1,0,0,0,534,535,3,2,1,
  	0,535,536,5,54,0,0,536,546,1,0,0,0,537,538,5,51,0,0,538,540,3,2,1,0,539,
  	541,3,80,40,0,540,539,1,0,0,0,540,541,1,0,0,0,541,542,1,0,0,0,542,543,
  	3,2,1,0,543,544,5,52,0,0,544,546,1,0,0,0,545,527,1,0,0,0,545,529,1,0,
  	0,0,545,537,1,0,0,0,546,569,1,0,0,0,547,548,10,5,0,0,548,549,3,96,48,
  	0,549,550,3,76,38,6,550,568,1,0,0,0,551,552,10,4,0,0,552,553,3,98,49,
  	0,553,554,3,76,38,5,554,568,1,0,0,0,555,556,10,3,0,0,556,557,3,100,50,
  	0,557,558,3,76,38,4,558,568,1,0,0,0,559,560,10,2,0,0,560,561,3,104,52,
  	0,561,562,3,76,38,3,562,568,1,0,0,0,563,564,10,1,0,0,564,565,3,102,51,
  	0,565,566,3,76,38,2,566,568,1,0,0,0,567,547,1,0,0,0,567,551,1,0,0,0,567,
  	555,1,0,0,0,567,559,1,0,0,0,567,563,1,0,0,0,568,571,1,0,0,0,569,567,1,
  	0,0,0,569,570,1,0,0,0,570,77,1,0,0,0,571,569,1,0,0,0,572,580,3,84,42,
  	0,573,574,3,2,1,0,574,575,5,61,0,0,575,576,3,2,1,0,576,577,3,84,42,0,
  	577,579,1,0,0,0,578,573,1,0,0,0,579,582,1,0,0,0,580,578,1,0,0,0,580,581,
  	1,0,0,0,581,586,1,0,0,0,582,580,1,0,0,0,583,584,3,2,1,0,584,585,5,61,
  	0,0,585,587,1,0,0,0,586,583,1,0,0,0,586,587,1,0,0,0,587,79,1,0,0,0,588,
  	596,3,82,41,0,589,590,3,2,1,0,590,591,5,61,0,0,591,592,3,2,1,0,592,593,
  	3,82,41,0,593,595,1,0,0,0,594,589,1,0,0,0,595,598,1,0,0,0,596,594,1,0,
  	0,0,596,597,1,0,0,0,597,602,1,0,0,0,598,596,1,0,0,0,599,600,3,2,1,0,600,
  	601,5,61,0,0,601,603,1,0,0,0,602,599,1,0,0,0,602,603,1,0,0,0,603,81,1,
  	0,0,0,604,608,3,6,3,0,605,608,3,4,2,0,606,608,3,8,4,0,607,604,1,0,0,0,
  	607,605,1,0,0,0,607,606,1,0,0,0,608,609,1,0,0,0,609,610,3,2,1,0,610,611,
  	5,39,0,0,611,612,3,2,1,0,612,613,3,84,42,0,613,83,1,0,0,0,614,659,3,22,
  	11,0,615,659,3,30,15,0,616,659,3,36,18,0,617,618,5,7,0,0,618,659,3,76,
  	38,0,619,620,3,74,37,0,620,621,5,10,0,0,621,622,3,12,6,0,622,659,1,0,
  	0,0,623,629,3,76,38,0,624,625,3,2,1,0,625,626,5,11,0,0,626,627,3,2,1,
  	0,627,628,3,76,38,0,628,630,1,0,0,0,629,624,1,0,0,0,630,631,1,0,0,0,631,
  	629,1,0,0,0,631,632,1,0,0,0,632,659,1,0,0,0,633,659,3,76,38,0,634,635,
  	5,51,0,0,635,637,3,2,1,0,636,638,3,32,16,0,637,636,1,0,0,0,637,638,1,
  	0,0,0,638,639,1,0,0,0,639,640,3,2,1,0,640,642,5,52,0,0,641,643,3,12,6,
  	0,642,641,1,0,0,0,642,643,1,0,0,0,643,644,1,0,0,0,644,645,5,56,0,0,645,
  	646,3,2,1,0,646,647,3,84,42,0,647,659,1,0,0,0,648,649,3,76,38,0,649,650,
  	3,2,1,0,650,651,5,55,0,0,651,652,3,2,1,0,652,653,3,84,42,0,653,654,3,
  	2,1,0,654,655,5,56,0,0,655,656,3,2,1,0,656,657,3,84,42,0,657,659,1,0,
  	0,0,658,614,1,0,0,0,658,615,1,0,0,0,658,616,1,0,0,0,658,617,1,0,0,0,658,
  	619,1,0,0,0,658,623,1,0,0,0,658,633,1,0,0,0,658,634,1,0,0,0,658,648,1,
  	0,0,0,659,85,1,0,0,0,660,661,5,9,0,0,661,669,3,88,44,0,662,663,3,2,1,
  	0,663,664,5,61,0,0,664,665,3,2,1,0,665,666,3,88,44,0,666,668,1,0,0,0,
  	667,662,1,0,0,0,668,671,1,0,0,0,669,667,1,0,0,0,669,670,1,0,0,0,670,87,
  	1,0,0,0,671,669,1,0,0,0,672,675,3,10,5,0,673,674,5,10,0,0,674,676,3,10,
  	5,0,675,673,1,0,0,0,675,676,1,0,0,0,676,89,1,0,0,0,677,683,3,92,46,0,
  	678,679,3,0,0,0,679,680,3,92,46,0,680,682,1,0,0,0,681,678,1,0,0,0,682,
  	685,1,0,0,0,683,681,1,0,0,0,683,684,1,0,0,0,684,91,1,0,0,0,685,683,1,
  	0,0,0,686,701,3,38,19,0,687,701,3,40,20,0,688,701,3,42,21,0,689,701,3,
  	44,22,0,690,701,3,48,24,0,691,701,3,50,25,0,692,701,3,16,8,0,693,701,
  	3,18,9,0,694,701,3,20,10,0,695,701,3,84,42,0,696,701,3,94,47,0,697,701,
  	3,86,43,0,698,701,3,54,27,0,699,701,3,2,1,0,700,686,1,0,0,0,700,687,1,
  	0,0,0,700,688,1,0,0,0,700,689,1,0,0,0,700,690,1,0,0,0,700,691,1,0,0,0,
  	700,692,1,0,0,0,700,693,1,0,0,0,700,694,1,0,0,0,700,695,1,0,0,0,700,696,
  	1,0,0,0,700,697,1,0,0,0,700,698,1,0,0,0,700,699,1,0,0,0,701,93,1,0,0,
  	0,702,704,5,14,0,0,703,705,3,84,42,0,704,703,1,0,0,0,704,705,1,0,0,0,
  	705,95,1,0,0,0,706,714,5,45,0,0,707,714,5,46,0,0,708,714,5,47,0,0,709,
  	710,5,46,0,0,710,714,5,46,0,0,711,712,5,45,0,0,712,714,5,45,0,0,713,706,
  	1,0,0,0,713,707,1,0,0,0,713,708,1,0,0,0,713,709,1,0,0,0,713,711,1,0,0,
  	0,714,97,1,0,0,0,715,716,7,2,0,0,716,99,1,0,0,0,717,728,5,48,0,0,718,
  	728,5,50,0,0,719,728,5,49,0,0,720,721,5,41,0,0,721,728,5,41,0,0,722,723,
  	5,40,0,0,723,728,5,40,0,0,724,725,5,40,0,0,725,726,5,40,0,0,726,728,5,
  	40,0,0,727,717,1,0,0,0,727,718,1,0,0,0,727,719,1,0,0,0,727,720,1,0,0,
  	0,727,722,1,0,0,0,727,724,1,0,0,0,728,101,1,0,0,0,729,736,5,17,0,0,730,
  	736,5,18,0,0,731,732,5,50,0,0,732,736,5,50,0,0,733,734,5,49,0,0,734,736,
  	5,49,0,0,735,729,1,0,0,0,735,730,1,0,0,0,735,731,1,0,0,0,735,733,1,0,
  	0,0,736,103,1,0,0,0,737,738,5,39,0,0,738,763,5,39,0,0,739,740,5,60,0,
  	0,740,763,5,39,0,0,741,763,5,40,0,0,742,763,5,41,0,0,743,744,5,40,0,0,
  	744,763,5,39,0,0,745,746,5,41,0,0,746,763,5,39,0,0,747,763,5,12,0,0,748,
  	749,5,30,0,0,749,763,5,12,0,0,750,763,5,25,0,0,751,752,5,30,0,0,752,763,
  	5,25,0,0,753,763,5,26,0,0,754,755,5,30,0,0,755,763,5,26,0,0,756,763,5,
  	27,0,0,757,758,5,30,0,0,758,763,5,27,0,0,759,763,5,28,0,0,760,761,5,30,
  	0,0,761,763,5,28,0,0,762,737,1,0,0,0,762,739,1,0,0,0,762,741,1,0,0,0,
  	762,742,1,0,0,0,762,743,1,0,0,0,762,745,1,0,0,0,762,747,1,0,0,0,762,748,
  	1,0,0,0,762,750,1,0,0,0,762,751,1,0,0,0,762,753,1,0,0,0,762,754,1,0,0,
  	0,762,756,1,0,0,0,762,757,1,0,0,0,762,759,1,0,0,0,762,760,1,0,0,0,763,
  	105,1,0,0,0,764,799,5,32,0,0,765,799,5,39,0,0,766,767,5,43,0,0,767,799,
  	5,39,0,0,768,769,5,44,0,0,769,799,5,39,0,0,770,771,5,45,0,0,771,799,5,
  	39,0,0,772,773,5,46,0,0,773,799,5,39,0,0,774,775,5,47,0,0,775,799,5,39,
  	0,0,776,777,5,46,0,0,777,778,5,46,0,0,778,799,5,39,0,0,779,780,5,45,0,
  	0,780,781,5,45,0,0,781,799,5,39,0,0,782,783,5,48,0,0,783,799,5,39,0,0,
  	784,785,5,50,0,0,785,799,5,39,0,0,786,787,5,49,0,0,787,799,5,39,0,0,788,
  	789,5,41,0,0,789,790,5,41,0,0,790,799,5,39,0,0,791,792,5,40,0,0,792,793,
  	5,40,0,0,793,799,5,39,0,0,794,795,5,40,0,0,795,796,5,40,0,0,796,797,5,
  	40,0,0,797,799,5,39,0,0,798,764,1,0,0,0,798,765,1,0,0,0,798,766,1,0,0,
  	0,798,768,1,0,0,0,798,770,1,0,0,0,798,772,1,0,0,0,798,774,1,0,0,0,798,
  	776,1,0,0,0,798,779,1,0,0,0,798,782,1,0,0,0,798,784,1,0,0,0,798,786,1,
  	0,0,0,798,788,1,0,0,0,798,791,1,0,0,0,798,794,1,0,0,0,799,107,1,0,0,0,
  	79,111,116,128,133,160,164,170,181,188,192,195,198,204,207,212,217,223,
  	235,241,245,249,253,259,269,276,281,289,298,306,312,316,320,322,328,335,
  	342,346,352,367,372,378,390,396,404,426,439,459,477,482,484,495,501,510,
  	516,525,532,540,545,567,569,580,586,596,602,607,631,637,642,658,669,675,
  	683,700,704,713,727,735,762,798
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
  enterRule(_localctx, 0, MavkaParser::RuleNl);

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
    setState(109); 
    _errHandler->sync(this);
    alt = 1;
    do {
      switch (alt) {
        case 1: {
              setState(108);
              match(MavkaParser::NL);
              break;
            }

      default:
        throw NoViableAltException(this);
      }
      setState(111); 
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx);
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
  enterRule(_localctx, 2, MavkaParser::RuleNls);

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
    setState(116);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(113);
        match(MavkaParser::NL); 
      }
      setState(118);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NumberContext ------------------------------------------------------------------

MavkaParser::NumberContext::NumberContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MavkaParser::NumberContext::INTEGER() {
  return getToken(MavkaParser::INTEGER, 0);
}

tree::TerminalNode* MavkaParser::NumberContext::FLOAT() {
  return getToken(MavkaParser::FLOAT, 0);
}

tree::TerminalNode* MavkaParser::NumberContext::HEX() {
  return getToken(MavkaParser::HEX, 0);
}

tree::TerminalNode* MavkaParser::NumberContext::BIN() {
  return getToken(MavkaParser::BIN, 0);
}


size_t MavkaParser::NumberContext::getRuleIndex() const {
  return MavkaParser::RuleNumber;
}

void MavkaParser::NumberContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNumber(this);
}

void MavkaParser::NumberContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNumber(this);
}


std::any MavkaParser::NumberContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MavkaParserVisitor*>(visitor))
    return parserVisitor->visitNumber(this);
  else
    return visitor->visitChildren(this);
}

MavkaParser::NumberContext* MavkaParser::number() {
  NumberContext *_localctx = _tracker.createInstance<NumberContext>(_ctx, getState());
  enterRule(_localctx, 4, MavkaParser::RuleNumber);
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
    setState(119);
    _la = _input->LA(1);
    if (!(((((_la - 62) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 62)) & 15) != 0))) {
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

//----------------- StringContext ------------------------------------------------------------------

MavkaParser::StringContext::StringContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MavkaParser::StringContext::STRING() {
  return getToken(MavkaParser::STRING, 0);
}

tree::TerminalNode* MavkaParser::StringContext::STRING_MULTILINE() {
  return getToken(MavkaParser::STRING_MULTILINE, 0);
}


size_t MavkaParser::StringContext::getRuleIndex() const {
  return MavkaParser::RuleString;
}

void MavkaParser::StringContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterString(this);
}

void MavkaParser::StringContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitString(this);
}


std::any MavkaParser::StringContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MavkaParserVisitor*>(visitor))
    return parserVisitor->visitString(this);
  else
    return visitor->visitChildren(this);
}

MavkaParser::StringContext* MavkaParser::string() {
  StringContext *_localctx = _tracker.createInstance<StringContext>(_ctx, getState());
  enterRule(_localctx, 6, MavkaParser::RuleString);
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
    setState(121);
    _la = _input->LA(1);
    if (!(_la == MavkaParser::STRING_MULTILINE

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

//----------------- CharacterContext ------------------------------------------------------------------

MavkaParser::CharacterContext::CharacterContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MavkaParser::CharacterContext::CHARACTER() {
  return getToken(MavkaParser::CHARACTER, 0);
}


size_t MavkaParser::CharacterContext::getRuleIndex() const {
  return MavkaParser::RuleCharacter;
}

void MavkaParser::CharacterContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCharacter(this);
}

void MavkaParser::CharacterContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCharacter(this);
}


std::any MavkaParser::CharacterContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MavkaParserVisitor*>(visitor))
    return parserVisitor->visitCharacter(this);
  else
    return visitor->visitChildren(this);
}

MavkaParser::CharacterContext* MavkaParser::character() {
  CharacterContext *_localctx = _tracker.createInstance<CharacterContext>(_ctx, getState());
  enterRule(_localctx, 8, MavkaParser::RuleCharacter);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(123);
    match(MavkaParser::CHARACTER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IdentifierContext ------------------------------------------------------------------

MavkaParser::IdentifierContext::IdentifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MavkaParser::IdentifierContext::ID() {
  return getToken(MavkaParser::ID, 0);
}


size_t MavkaParser::IdentifierContext::getRuleIndex() const {
  return MavkaParser::RuleIdentifier;
}

void MavkaParser::IdentifierContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIdentifier(this);
}

void MavkaParser::IdentifierContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIdentifier(this);
}


std::any MavkaParser::IdentifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MavkaParserVisitor*>(visitor))
    return parserVisitor->visitIdentifier(this);
  else
    return visitor->visitChildren(this);
}

MavkaParser::IdentifierContext* MavkaParser::identifier() {
  IdentifierContext *_localctx = _tracker.createInstance<IdentifierContext>(_ctx, getState());
  enterRule(_localctx, 10, MavkaParser::RuleIdentifier);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(125);
    match(MavkaParser::ID);
   
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

MavkaParser::Subject_outContext* MavkaParser::TypeContext::subject_out() {
  return getRuleContext<MavkaParser::Subject_outContext>(0);
}

MavkaParser::Get_outContext* MavkaParser::TypeContext::get_out() {
  return getRuleContext<MavkaParser::Get_outContext>(0);
}

MavkaParser::Generic_outContext* MavkaParser::TypeContext::generic_out() {
  return getRuleContext<MavkaParser::Generic_outContext>(0);
}

tree::TerminalNode* MavkaParser::TypeContext::QUESTION() {
  return getToken(MavkaParser::QUESTION, 0);
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
  enterRule(_localctx, 12, MavkaParser::RuleType);
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
    setState(128);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == MavkaParser::QUESTION) {
      setState(127);
      antlrcpp::downCast<TypeContext *>(_localctx)->t_nullable = match(MavkaParser::QUESTION);
    }
    setState(133);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
    case 1: {
      setState(130);
      subject_out();
      break;
    }

    case 2: {
      setState(131);
      get_out();
      break;
    }

    case 3: {
      setState(132);
      generic_out();
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

//----------------- FileContext ------------------------------------------------------------------

MavkaParser::FileContext::FileContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<MavkaParser::NlsContext *> MavkaParser::FileContext::nls() {
  return getRuleContexts<MavkaParser::NlsContext>();
}

MavkaParser::NlsContext* MavkaParser::FileContext::nls(size_t i) {
  return getRuleContext<MavkaParser::NlsContext>(i);
}

MavkaParser::BodyContext* MavkaParser::FileContext::body() {
  return getRuleContext<MavkaParser::BodyContext>(0);
}

tree::TerminalNode* MavkaParser::FileContext::EOF() {
  return getToken(MavkaParser::EOF, 0);
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
  enterRule(_localctx, 14, MavkaParser::RuleFile);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(135);
    nls();
    setState(136);
    body();
    setState(137);
    nls();
    setState(138);
    match(MavkaParser::EOF);
   
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

MavkaParser::Assign_opContext* MavkaParser::AssignContext::assign_op() {
  return getRuleContext<MavkaParser::Assign_opContext>(0);
}

MavkaParser::IdentifierContext* MavkaParser::AssignContext::identifier() {
  return getRuleContext<MavkaParser::IdentifierContext>(0);
}

MavkaParser::ExprContext* MavkaParser::AssignContext::expr() {
  return getRuleContext<MavkaParser::ExprContext>(0);
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
  enterRule(_localctx, 16, MavkaParser::RuleAssign);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(140);
    antlrcpp::downCast<AssignContext *>(_localctx)->as_identifier = identifier();
    setState(141);
    assign_op();
    setState(142);
    antlrcpp::downCast<AssignContext *>(_localctx)->as_value = expr();
   
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

MavkaParser::Assign_opContext* MavkaParser::SetContext::assign_op() {
  return getRuleContext<MavkaParser::Assign_opContext>(0);
}

MavkaParser::ParticleContext* MavkaParser::SetContext::particle() {
  return getRuleContext<MavkaParser::ParticleContext>(0);
}

MavkaParser::ExprContext* MavkaParser::SetContext::expr() {
  return getRuleContext<MavkaParser::ExprContext>(0);
}

tree::TerminalNode* MavkaParser::SetContext::DOT() {
  return getToken(MavkaParser::DOT, 0);
}

MavkaParser::IdentifierContext* MavkaParser::SetContext::identifier() {
  return getRuleContext<MavkaParser::IdentifierContext>(0);
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
  enterRule(_localctx, 18, MavkaParser::RuleSet);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(144);
    antlrcpp::downCast<SetContext *>(_localctx)->s_left = particle(0);

    setState(145);
    match(MavkaParser::DOT);
    setState(146);
    antlrcpp::downCast<SetContext *>(_localctx)->s_id = identifier();
    setState(148);
    assign_op();
    setState(149);
    antlrcpp::downCast<SetContext *>(_localctx)->s_value = expr();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Set_by_accessContext ------------------------------------------------------------------

MavkaParser::Set_by_accessContext::Set_by_accessContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MavkaParser::Set_by_accessContext::BRACKET_OPEN() {
  return getToken(MavkaParser::BRACKET_OPEN, 0);
}

tree::TerminalNode* MavkaParser::Set_by_accessContext::BRACKET_CLOSE() {
  return getToken(MavkaParser::BRACKET_CLOSE, 0);
}

MavkaParser::Assign_opContext* MavkaParser::Set_by_accessContext::assign_op() {
  return getRuleContext<MavkaParser::Assign_opContext>(0);
}

MavkaParser::ParticleContext* MavkaParser::Set_by_accessContext::particle() {
  return getRuleContext<MavkaParser::ParticleContext>(0);
}

std::vector<MavkaParser::ExprContext *> MavkaParser::Set_by_accessContext::expr() {
  return getRuleContexts<MavkaParser::ExprContext>();
}

MavkaParser::ExprContext* MavkaParser::Set_by_accessContext::expr(size_t i) {
  return getRuleContext<MavkaParser::ExprContext>(i);
}


size_t MavkaParser::Set_by_accessContext::getRuleIndex() const {
  return MavkaParser::RuleSet_by_access;
}

void MavkaParser::Set_by_accessContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSet_by_access(this);
}

void MavkaParser::Set_by_accessContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSet_by_access(this);
}


std::any MavkaParser::Set_by_accessContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MavkaParserVisitor*>(visitor))
    return parserVisitor->visitSet_by_access(this);
  else
    return visitor->visitChildren(this);
}

MavkaParser::Set_by_accessContext* MavkaParser::set_by_access() {
  Set_by_accessContext *_localctx = _tracker.createInstance<Set_by_accessContext>(_ctx, getState());
  enterRule(_localctx, 20, MavkaParser::RuleSet_by_access);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(151);
    antlrcpp::downCast<Set_by_accessContext *>(_localctx)->s_left = particle(0);
    setState(152);
    match(MavkaParser::BRACKET_OPEN);
    setState(153);
    antlrcpp::downCast<Set_by_accessContext *>(_localctx)->s_id = expr();
    setState(154);
    match(MavkaParser::BRACKET_CLOSE);
    setState(155);
    assign_op();
    setState(156);
    antlrcpp::downCast<Set_by_accessContext *>(_localctx)->s_value = expr();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StructureContext ------------------------------------------------------------------

MavkaParser::StructureContext::StructureContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MavkaParser::StructureContext::KW_STRUCTURE() {
  return getToken(MavkaParser::KW_STRUCTURE, 0);
}

std::vector<MavkaParser::NlContext *> MavkaParser::StructureContext::nl() {
  return getRuleContexts<MavkaParser::NlContext>();
}

MavkaParser::NlContext* MavkaParser::StructureContext::nl(size_t i) {
  return getRuleContext<MavkaParser::NlContext>(i);
}

MavkaParser::NlsContext* MavkaParser::StructureContext::nls() {
  return getRuleContext<MavkaParser::NlsContext>(0);
}

tree::TerminalNode* MavkaParser::StructureContext::KW_END() {
  return getToken(MavkaParser::KW_END, 0);
}

tree::TerminalNode* MavkaParser::StructureContext::KW_IS() {
  return getToken(MavkaParser::KW_IS, 0);
}

std::vector<MavkaParser::IdentifierContext *> MavkaParser::StructureContext::identifier() {
  return getRuleContexts<MavkaParser::IdentifierContext>();
}

MavkaParser::IdentifierContext* MavkaParser::StructureContext::identifier(size_t i) {
  return getRuleContext<MavkaParser::IdentifierContext>(i);
}

MavkaParser::Structure_elementsContext* MavkaParser::StructureContext::structure_elements() {
  return getRuleContext<MavkaParser::Structure_elementsContext>(0);
}


size_t MavkaParser::StructureContext::getRuleIndex() const {
  return MavkaParser::RuleStructure;
}

void MavkaParser::StructureContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStructure(this);
}

void MavkaParser::StructureContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStructure(this);
}


std::any MavkaParser::StructureContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MavkaParserVisitor*>(visitor))
    return parserVisitor->visitStructure(this);
  else
    return visitor->visitChildren(this);
}

MavkaParser::StructureContext* MavkaParser::structure() {
  StructureContext *_localctx = _tracker.createInstance<StructureContext>(_ctx, getState());
  enterRule(_localctx, 22, MavkaParser::RuleStructure);
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
    setState(158);
    match(MavkaParser::KW_STRUCTURE);
    setState(160);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == MavkaParser::ID) {
      setState(159);
      antlrcpp::downCast<StructureContext *>(_localctx)->s_name = identifier();
    }
    setState(164);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == MavkaParser::KW_IS) {
      setState(162);
      match(MavkaParser::KW_IS);
      setState(163);
      antlrcpp::downCast<StructureContext *>(_localctx)->s_parent = identifier();
    }
    setState(166);
    nl();
    setState(170);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == MavkaParser::ID) {
      setState(167);
      antlrcpp::downCast<StructureContext *>(_localctx)->s_elements = structure_elements();
      setState(168);
      nl();
    }
    setState(172);
    nls();
    setState(173);
    match(MavkaParser::KW_END);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Structure_elementsContext ------------------------------------------------------------------

MavkaParser::Structure_elementsContext::Structure_elementsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<MavkaParser::Structure_elementContext *> MavkaParser::Structure_elementsContext::structure_element() {
  return getRuleContexts<MavkaParser::Structure_elementContext>();
}

MavkaParser::Structure_elementContext* MavkaParser::Structure_elementsContext::structure_element(size_t i) {
  return getRuleContext<MavkaParser::Structure_elementContext>(i);
}

std::vector<MavkaParser::NlContext *> MavkaParser::Structure_elementsContext::nl() {
  return getRuleContexts<MavkaParser::NlContext>();
}

MavkaParser::NlContext* MavkaParser::Structure_elementsContext::nl(size_t i) {
  return getRuleContext<MavkaParser::NlContext>(i);
}


size_t MavkaParser::Structure_elementsContext::getRuleIndex() const {
  return MavkaParser::RuleStructure_elements;
}

void MavkaParser::Structure_elementsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStructure_elements(this);
}

void MavkaParser::Structure_elementsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStructure_elements(this);
}


std::any MavkaParser::Structure_elementsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MavkaParserVisitor*>(visitor))
    return parserVisitor->visitStructure_elements(this);
  else
    return visitor->visitChildren(this);
}

MavkaParser::Structure_elementsContext* MavkaParser::structure_elements() {
  Structure_elementsContext *_localctx = _tracker.createInstance<Structure_elementsContext>(_ctx, getState());
  enterRule(_localctx, 24, MavkaParser::RuleStructure_elements);

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
    setState(175);
    structure_element();
    setState(181);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(176);
        nl();
        setState(177);
        structure_element(); 
      }
      setState(183);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx);
    }
   
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

MavkaParser::Structure_paramContext* MavkaParser::Structure_elementContext::structure_param() {
  return getRuleContext<MavkaParser::Structure_paramContext>(0);
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
  enterRule(_localctx, 26, MavkaParser::RuleStructure_element);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(184);
    structure_param();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Structure_paramContext ------------------------------------------------------------------

MavkaParser::Structure_paramContext::Structure_paramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MavkaParser::IdentifierContext* MavkaParser::Structure_paramContext::identifier() {
  return getRuleContext<MavkaParser::IdentifierContext>(0);
}

tree::TerminalNode* MavkaParser::Structure_paramContext::EQUAL() {
  return getToken(MavkaParser::EQUAL, 0);
}

MavkaParser::TypeContext* MavkaParser::Structure_paramContext::type() {
  return getRuleContext<MavkaParser::TypeContext>(0);
}

MavkaParser::ExprContext* MavkaParser::Structure_paramContext::expr() {
  return getRuleContext<MavkaParser::ExprContext>(0);
}


size_t MavkaParser::Structure_paramContext::getRuleIndex() const {
  return MavkaParser::RuleStructure_param;
}

void MavkaParser::Structure_paramContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStructure_param(this);
}

void MavkaParser::Structure_paramContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStructure_param(this);
}


std::any MavkaParser::Structure_paramContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MavkaParserVisitor*>(visitor))
    return parserVisitor->visitStructure_param(this);
  else
    return visitor->visitChildren(this);
}

MavkaParser::Structure_paramContext* MavkaParser::structure_param() {
  Structure_paramContext *_localctx = _tracker.createInstance<Structure_paramContext>(_ctx, getState());
  enterRule(_localctx, 28, MavkaParser::RuleStructure_param);
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
    setState(186);
    antlrcpp::downCast<Structure_paramContext *>(_localctx)->sp_name = identifier();
    setState(188);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((((_la - 51) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 51)) & 65553) != 0)) {
      setState(187);
      antlrcpp::downCast<Structure_paramContext *>(_localctx)->sp_type = type();
    }
    setState(192);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == MavkaParser::EQUAL) {
      setState(190);
      match(MavkaParser::EQUAL);
      setState(191);
      antlrcpp::downCast<Structure_paramContext *>(_localctx)->sp_value = expr();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DiiaContext ------------------------------------------------------------------

MavkaParser::DiiaContext::DiiaContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MavkaParser::DiiaContext::KW_DIIA() {
  return getToken(MavkaParser::KW_DIIA, 0);
}

tree::TerminalNode* MavkaParser::DiiaContext::PAREN_OPEN() {
  return getToken(MavkaParser::PAREN_OPEN, 0);
}

std::vector<MavkaParser::NlsContext *> MavkaParser::DiiaContext::nls() {
  return getRuleContexts<MavkaParser::NlsContext>();
}

MavkaParser::NlsContext* MavkaParser::DiiaContext::nls(size_t i) {
  return getRuleContext<MavkaParser::NlsContext>(i);
}

tree::TerminalNode* MavkaParser::DiiaContext::PAREN_CLOSE() {
  return getToken(MavkaParser::PAREN_CLOSE, 0);
}

std::vector<MavkaParser::NlContext *> MavkaParser::DiiaContext::nl() {
  return getRuleContexts<MavkaParser::NlContext>();
}

MavkaParser::NlContext* MavkaParser::DiiaContext::nl(size_t i) {
  return getRuleContext<MavkaParser::NlContext>(i);
}

tree::TerminalNode* MavkaParser::DiiaContext::KW_END() {
  return getToken(MavkaParser::KW_END, 0);
}

tree::TerminalNode* MavkaParser::DiiaContext::KW_ASYNC() {
  return getToken(MavkaParser::KW_ASYNC, 0);
}

tree::TerminalNode* MavkaParser::DiiaContext::KW_SPEC() {
  return getToken(MavkaParser::KW_SPEC, 0);
}

std::vector<MavkaParser::IdentifierContext *> MavkaParser::DiiaContext::identifier() {
  return getRuleContexts<MavkaParser::IdentifierContext>();
}

MavkaParser::IdentifierContext* MavkaParser::DiiaContext::identifier(size_t i) {
  return getRuleContext<MavkaParser::IdentifierContext>(i);
}

MavkaParser::Diia_paramsContext* MavkaParser::DiiaContext::diia_params() {
  return getRuleContext<MavkaParser::Diia_paramsContext>(0);
}

MavkaParser::TypeContext* MavkaParser::DiiaContext::type() {
  return getRuleContext<MavkaParser::TypeContext>(0);
}

MavkaParser::BodyContext* MavkaParser::DiiaContext::body() {
  return getRuleContext<MavkaParser::BodyContext>(0);
}

tree::TerminalNode* MavkaParser::DiiaContext::DOT() {
  return getToken(MavkaParser::DOT, 0);
}


size_t MavkaParser::DiiaContext::getRuleIndex() const {
  return MavkaParser::RuleDiia;
}

void MavkaParser::DiiaContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDiia(this);
}

void MavkaParser::DiiaContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDiia(this);
}


std::any MavkaParser::DiiaContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MavkaParserVisitor*>(visitor))
    return parserVisitor->visitDiia(this);
  else
    return visitor->visitChildren(this);
}

MavkaParser::DiiaContext* MavkaParser::diia() {
  DiiaContext *_localctx = _tracker.createInstance<DiiaContext>(_ctx, getState());
  enterRule(_localctx, 30, MavkaParser::RuleDiia);
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
    setState(195);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == MavkaParser::KW_ASYNC) {
      setState(194);
      antlrcpp::downCast<DiiaContext *>(_localctx)->d_async = match(MavkaParser::KW_ASYNC);
    }
    setState(198);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == MavkaParser::KW_SPEC) {
      setState(197);
      antlrcpp::downCast<DiiaContext *>(_localctx)->d_spec = match(MavkaParser::KW_SPEC);
    }
    setState(200);
    match(MavkaParser::KW_DIIA);
    setState(207);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == MavkaParser::ID) {
      setState(204);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx)) {
      case 1: {
        setState(201);
        antlrcpp::downCast<DiiaContext *>(_localctx)->d_structure = identifier();
        setState(202);
        match(MavkaParser::DOT);
        break;
      }

      default:
        break;
      }
      setState(206);
      antlrcpp::downCast<DiiaContext *>(_localctx)->d_name = identifier();
    }
    setState(209);
    match(MavkaParser::PAREN_OPEN);
    setState(210);
    nls();
    setState(212);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == MavkaParser::ID) {
      setState(211);
      antlrcpp::downCast<DiiaContext *>(_localctx)->d_params = diia_params();
    }
    setState(214);
    nls();
    setState(215);
    match(MavkaParser::PAREN_CLOSE);
    setState(217);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((((_la - 51) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 51)) & 65553) != 0)) {
      setState(216);
      antlrcpp::downCast<DiiaContext *>(_localctx)->d_type = type();
    }
    setState(219);
    nl();
    setState(223);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & -3303372734460271620) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 64)) & 2283) != 0)) {
      setState(220);
      antlrcpp::downCast<DiiaContext *>(_localctx)->d_body = body();
      setState(221);
      nl();
    }
    setState(225);
    match(MavkaParser::KW_END);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Diia_paramsContext ------------------------------------------------------------------

MavkaParser::Diia_paramsContext::Diia_paramsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<MavkaParser::Diia_paramContext *> MavkaParser::Diia_paramsContext::diia_param() {
  return getRuleContexts<MavkaParser::Diia_paramContext>();
}

MavkaParser::Diia_paramContext* MavkaParser::Diia_paramsContext::diia_param(size_t i) {
  return getRuleContext<MavkaParser::Diia_paramContext>(i);
}

std::vector<MavkaParser::NlsContext *> MavkaParser::Diia_paramsContext::nls() {
  return getRuleContexts<MavkaParser::NlsContext>();
}

MavkaParser::NlsContext* MavkaParser::Diia_paramsContext::nls(size_t i) {
  return getRuleContext<MavkaParser::NlsContext>(i);
}

std::vector<tree::TerminalNode *> MavkaParser::Diia_paramsContext::COMA() {
  return getTokens(MavkaParser::COMA);
}

tree::TerminalNode* MavkaParser::Diia_paramsContext::COMA(size_t i) {
  return getToken(MavkaParser::COMA, i);
}


size_t MavkaParser::Diia_paramsContext::getRuleIndex() const {
  return MavkaParser::RuleDiia_params;
}

void MavkaParser::Diia_paramsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDiia_params(this);
}

void MavkaParser::Diia_paramsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDiia_params(this);
}


std::any MavkaParser::Diia_paramsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MavkaParserVisitor*>(visitor))
    return parserVisitor->visitDiia_params(this);
  else
    return visitor->visitChildren(this);
}

MavkaParser::Diia_paramsContext* MavkaParser::diia_params() {
  Diia_paramsContext *_localctx = _tracker.createInstance<Diia_paramsContext>(_ctx, getState());
  enterRule(_localctx, 32, MavkaParser::RuleDiia_params);

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
    setState(227);
    diia_param();
    setState(235);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(228);
        nls();
        setState(229);
        match(MavkaParser::COMA);
        setState(230);
        nls();
        setState(231);
        diia_param(); 
      }
      setState(237);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx);
    }
    setState(241);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx)) {
    case 1: {
      setState(238);
      nls();
      setState(239);
      match(MavkaParser::COMA);
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

//----------------- Diia_paramContext ------------------------------------------------------------------

MavkaParser::Diia_paramContext::Diia_paramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MavkaParser::IdentifierContext* MavkaParser::Diia_paramContext::identifier() {
  return getRuleContext<MavkaParser::IdentifierContext>(0);
}

tree::TerminalNode* MavkaParser::Diia_paramContext::EQUAL() {
  return getToken(MavkaParser::EQUAL, 0);
}

MavkaParser::TypeContext* MavkaParser::Diia_paramContext::type() {
  return getRuleContext<MavkaParser::TypeContext>(0);
}

MavkaParser::ExprContext* MavkaParser::Diia_paramContext::expr() {
  return getRuleContext<MavkaParser::ExprContext>(0);
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
  enterRule(_localctx, 34, MavkaParser::RuleDiia_param);
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
    setState(243);
    antlrcpp::downCast<Diia_paramContext *>(_localctx)->p_name = identifier();
    setState(245);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((((_la - 51) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 51)) & 65553) != 0)) {
      setState(244);
      antlrcpp::downCast<Diia_paramContext *>(_localctx)->p_type = type();
    }
    setState(249);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == MavkaParser::EQUAL) {
      setState(247);
      match(MavkaParser::EQUAL);
      setState(248);
      antlrcpp::downCast<Diia_paramContext *>(_localctx)->p_value = expr();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ModuleContext ------------------------------------------------------------------

MavkaParser::ModuleContext::ModuleContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MavkaParser::ModuleContext::KW_MODULE() {
  return getToken(MavkaParser::KW_MODULE, 0);
}

std::vector<MavkaParser::NlContext *> MavkaParser::ModuleContext::nl() {
  return getRuleContexts<MavkaParser::NlContext>();
}

MavkaParser::NlContext* MavkaParser::ModuleContext::nl(size_t i) {
  return getRuleContext<MavkaParser::NlContext>(i);
}

tree::TerminalNode* MavkaParser::ModuleContext::KW_END() {
  return getToken(MavkaParser::KW_END, 0);
}

MavkaParser::IdentifierContext* MavkaParser::ModuleContext::identifier() {
  return getRuleContext<MavkaParser::IdentifierContext>(0);
}

MavkaParser::BodyContext* MavkaParser::ModuleContext::body() {
  return getRuleContext<MavkaParser::BodyContext>(0);
}


size_t MavkaParser::ModuleContext::getRuleIndex() const {
  return MavkaParser::RuleModule;
}

void MavkaParser::ModuleContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterModule(this);
}

void MavkaParser::ModuleContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitModule(this);
}


std::any MavkaParser::ModuleContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MavkaParserVisitor*>(visitor))
    return parserVisitor->visitModule(this);
  else
    return visitor->visitChildren(this);
}

MavkaParser::ModuleContext* MavkaParser::module() {
  ModuleContext *_localctx = _tracker.createInstance<ModuleContext>(_ctx, getState());
  enterRule(_localctx, 36, MavkaParser::RuleModule);
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
    setState(251);
    match(MavkaParser::KW_MODULE);
    setState(253);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == MavkaParser::ID) {
      setState(252);
      antlrcpp::downCast<ModuleContext *>(_localctx)->m_name = identifier();
    }
    setState(255);
    nl();
    setState(259);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & -3303372734460271620) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 64)) & 2283) != 0)) {
      setState(256);
      antlrcpp::downCast<ModuleContext *>(_localctx)->m_body = body();
      setState(257);
      nl();
    }
    setState(261);
    match(MavkaParser::KW_END);
   
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
  enterRule(_localctx, 38, MavkaParser::RuleIf);
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
    setState(263);
    match(MavkaParser::KW_IF);
    setState(264);
    antlrcpp::downCast<IfContext *>(_localctx)->i_value = expr();
    setState(265);
    nl();
    setState(269);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & -3303372734460271620) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 64)) & 2283) != 0)) {
      setState(266);
      antlrcpp::downCast<IfContext *>(_localctx)->i_body = body();
      setState(267);
      nl();
    }
    setState(281);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 25, _ctx)) {
    case 1: {
      setState(276);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == MavkaParser::KW_ELSE) {
        setState(271);
        match(MavkaParser::KW_ELSE);
        setState(272);
        nl();
        setState(273);
        antlrcpp::downCast<IfContext *>(_localctx)->i_else_body = body();
        setState(274);
        nl();
      }
      setState(278);
      match(MavkaParser::KW_END);
      break;
    }

    case 2: {
      setState(279);
      match(MavkaParser::KW_ELSE);
      setState(280);
      antlrcpp::downCast<IfContext *>(_localctx)->i_else_if = if_();
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
  enterRule(_localctx, 40, MavkaParser::RuleWhile);
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
    setState(283);
    match(MavkaParser::KW_WHILE);
    setState(284);
    antlrcpp::downCast<WhileContext *>(_localctx)->w_value = operation(0);
    setState(285);
    nl();
    setState(289);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & -3303372734460271620) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 64)) & 2283) != 0)) {
      setState(286);
      antlrcpp::downCast<WhileContext *>(_localctx)->w_body = body();
      setState(287);
      nl();
    }
    setState(291);
    match(MavkaParser::KW_END);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IntervalContext ------------------------------------------------------------------

MavkaParser::IntervalContext::IntervalContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MavkaParser::IntervalContext::KW_FOR() {
  return getToken(MavkaParser::KW_FOR, 0);
}

tree::TerminalNode* MavkaParser::IntervalContext::KW_AS() {
  return getToken(MavkaParser::KW_AS, 0);
}

std::vector<MavkaParser::NlContext *> MavkaParser::IntervalContext::nl() {
  return getRuleContexts<MavkaParser::NlContext>();
}

MavkaParser::NlContext* MavkaParser::IntervalContext::nl(size_t i) {
  return getRuleContext<MavkaParser::NlContext>(i);
}

tree::TerminalNode* MavkaParser::IntervalContext::KW_END() {
  return getToken(MavkaParser::KW_END, 0);
}

std::vector<MavkaParser::OperationContext *> MavkaParser::IntervalContext::operation() {
  return getRuleContexts<MavkaParser::OperationContext>();
}

MavkaParser::OperationContext* MavkaParser::IntervalContext::operation(size_t i) {
  return getRuleContext<MavkaParser::OperationContext>(i);
}

MavkaParser::IdentifierContext* MavkaParser::IntervalContext::identifier() {
  return getRuleContext<MavkaParser::IdentifierContext>(0);
}

std::vector<tree::TerminalNode *> MavkaParser::IntervalContext::DOT() {
  return getTokens(MavkaParser::DOT);
}

tree::TerminalNode* MavkaParser::IntervalContext::DOT(size_t i) {
  return getToken(MavkaParser::DOT, i);
}

MavkaParser::BodyContext* MavkaParser::IntervalContext::body() {
  return getRuleContext<MavkaParser::BodyContext>(0);
}


size_t MavkaParser::IntervalContext::getRuleIndex() const {
  return MavkaParser::RuleInterval;
}

void MavkaParser::IntervalContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInterval(this);
}

void MavkaParser::IntervalContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInterval(this);
}


std::any MavkaParser::IntervalContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MavkaParserVisitor*>(visitor))
    return parserVisitor->visitInterval(this);
  else
    return visitor->visitChildren(this);
}

MavkaParser::IntervalContext* MavkaParser::interval() {
  IntervalContext *_localctx = _tracker.createInstance<IntervalContext>(_ctx, getState());
  enterRule(_localctx, 42, MavkaParser::RuleInterval);
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
    setState(293);
    match(MavkaParser::KW_FOR);
    setState(294);
    antlrcpp::downCast<IntervalContext *>(_localctx)->i_left = operation(0);
    setState(298);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == MavkaParser::DOT) {
      setState(295);
      match(MavkaParser::DOT);
      setState(296);
      match(MavkaParser::DOT);
      setState(297);
      antlrcpp::downCast<IntervalContext *>(_localctx)->i_right = operation(0);
    }
    setState(300);
    match(MavkaParser::KW_AS);
    setState(301);
    antlrcpp::downCast<IntervalContext *>(_localctx)->i_id = identifier();
    setState(302);
    nl();
    setState(306);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & -3303372734460271620) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 64)) & 2283) != 0)) {
      setState(303);
      antlrcpp::downCast<IntervalContext *>(_localctx)->e_body = body();
      setState(304);
      nl();
    }
    setState(308);
    match(MavkaParser::KW_END);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CycleContext ------------------------------------------------------------------

MavkaParser::CycleContext::CycleContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MavkaParser::CycleContext::KW_CYCLE() {
  return getToken(MavkaParser::KW_CYCLE, 0);
}

std::vector<MavkaParser::NlContext *> MavkaParser::CycleContext::nl() {
  return getRuleContexts<MavkaParser::NlContext>();
}

MavkaParser::NlContext* MavkaParser::CycleContext::nl(size_t i) {
  return getRuleContext<MavkaParser::NlContext>(i);
}

tree::TerminalNode* MavkaParser::CycleContext::KW_END() {
  return getToken(MavkaParser::KW_END, 0);
}

std::vector<tree::TerminalNode *> MavkaParser::CycleContext::COMA() {
  return getTokens(MavkaParser::COMA);
}

tree::TerminalNode* MavkaParser::CycleContext::COMA(size_t i) {
  return getToken(MavkaParser::COMA, i);
}

MavkaParser::BodyContext* MavkaParser::CycleContext::body() {
  return getRuleContext<MavkaParser::BodyContext>(0);
}

std::vector<MavkaParser::Cycle_stepContext *> MavkaParser::CycleContext::cycle_step() {
  return getRuleContexts<MavkaParser::Cycle_stepContext>();
}

MavkaParser::Cycle_stepContext* MavkaParser::CycleContext::cycle_step(size_t i) {
  return getRuleContext<MavkaParser::Cycle_stepContext>(i);
}


size_t MavkaParser::CycleContext::getRuleIndex() const {
  return MavkaParser::RuleCycle;
}

void MavkaParser::CycleContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCycle(this);
}

void MavkaParser::CycleContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCycle(this);
}


std::any MavkaParser::CycleContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MavkaParserVisitor*>(visitor))
    return parserVisitor->visitCycle(this);
  else
    return visitor->visitChildren(this);
}

MavkaParser::CycleContext* MavkaParser::cycle() {
  CycleContext *_localctx = _tracker.createInstance<CycleContext>(_ctx, getState());
  enterRule(_localctx, 44, MavkaParser::RuleCycle);
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
    setState(310);
    match(MavkaParser::KW_CYCLE);
    setState(322);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((((_la - 44) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 44)) & 247407233) != 0)) {
      setState(312);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (((((_la - 44) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 44)) & 247276161) != 0)) {
        setState(311);
        antlrcpp::downCast<CycleContext *>(_localctx)->c_a = cycle_step();
      }
      setState(314);
      match(MavkaParser::COMA);
      setState(316);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (((((_la - 44) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 44)) & 247276161) != 0)) {
        setState(315);
        antlrcpp::downCast<CycleContext *>(_localctx)->c_b = cycle_step();
      }
      setState(318);
      match(MavkaParser::COMA);
      setState(320);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (((((_la - 44) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 44)) & 247276161) != 0)) {
        setState(319);
        antlrcpp::downCast<CycleContext *>(_localctx)->c_c = cycle_step();
      }
    }
    setState(324);
    nl();
    setState(328);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & -3303372734460271620) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 64)) & 2283) != 0)) {
      setState(325);
      antlrcpp::downCast<CycleContext *>(_localctx)->c_body = body();
      setState(326);
      nl();
    }
    setState(330);
    match(MavkaParser::KW_END);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Cycle_stepContext ------------------------------------------------------------------

MavkaParser::Cycle_stepContext::Cycle_stepContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MavkaParser::AssignContext* MavkaParser::Cycle_stepContext::assign() {
  return getRuleContext<MavkaParser::AssignContext>(0);
}

MavkaParser::SetContext* MavkaParser::Cycle_stepContext::set() {
  return getRuleContext<MavkaParser::SetContext>(0);
}

MavkaParser::OperationContext* MavkaParser::Cycle_stepContext::operation() {
  return getRuleContext<MavkaParser::OperationContext>(0);
}


size_t MavkaParser::Cycle_stepContext::getRuleIndex() const {
  return MavkaParser::RuleCycle_step;
}

void MavkaParser::Cycle_stepContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCycle_step(this);
}

void MavkaParser::Cycle_stepContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCycle_step(this);
}


std::any MavkaParser::Cycle_stepContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MavkaParserVisitor*>(visitor))
    return parserVisitor->visitCycle_step(this);
  else
    return visitor->visitChildren(this);
}

MavkaParser::Cycle_stepContext* MavkaParser::cycle_step() {
  Cycle_stepContext *_localctx = _tracker.createInstance<Cycle_stepContext>(_ctx, getState());
  enterRule(_localctx, 46, MavkaParser::RuleCycle_step);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(335);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 34, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(332);
      assign();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(333);
      set();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(334);
      operation(0);
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

//----------------- TryContext ------------------------------------------------------------------

MavkaParser::TryContext::TryContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MavkaParser::TryContext::KW_TRY() {
  return getToken(MavkaParser::KW_TRY, 0);
}

std::vector<MavkaParser::NlContext *> MavkaParser::TryContext::nl() {
  return getRuleContexts<MavkaParser::NlContext>();
}

MavkaParser::NlContext* MavkaParser::TryContext::nl(size_t i) {
  return getRuleContext<MavkaParser::NlContext>(i);
}

tree::TerminalNode* MavkaParser::TryContext::KW_CATCH() {
  return getToken(MavkaParser::KW_CATCH, 0);
}

tree::TerminalNode* MavkaParser::TryContext::KW_END() {
  return getToken(MavkaParser::KW_END, 0);
}

std::vector<MavkaParser::BodyContext *> MavkaParser::TryContext::body() {
  return getRuleContexts<MavkaParser::BodyContext>();
}

MavkaParser::BodyContext* MavkaParser::TryContext::body(size_t i) {
  return getRuleContext<MavkaParser::BodyContext>(i);
}

MavkaParser::IdentifierContext* MavkaParser::TryContext::identifier() {
  return getRuleContext<MavkaParser::IdentifierContext>(0);
}


size_t MavkaParser::TryContext::getRuleIndex() const {
  return MavkaParser::RuleTry;
}

void MavkaParser::TryContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTry(this);
}

void MavkaParser::TryContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTry(this);
}


std::any MavkaParser::TryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MavkaParserVisitor*>(visitor))
    return parserVisitor->visitTry(this);
  else
    return visitor->visitChildren(this);
}

MavkaParser::TryContext* MavkaParser::try_() {
  TryContext *_localctx = _tracker.createInstance<TryContext>(_ctx, getState());
  enterRule(_localctx, 48, MavkaParser::RuleTry);
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
    setState(337);
    match(MavkaParser::KW_TRY);
    setState(338);
    nl();
    setState(342);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & -3303372734460271620) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 64)) & 2283) != 0)) {
      setState(339);
      antlrcpp::downCast<TryContext *>(_localctx)->t_body = body();
      setState(340);
      nl();
    }
    setState(344);
    match(MavkaParser::KW_CATCH);
    setState(346);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == MavkaParser::ID) {
      setState(345);
      antlrcpp::downCast<TryContext *>(_localctx)->t_name = identifier();
    }
    setState(348);
    nl();
    setState(352);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & -3303372734460271620) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 64)) & 2283) != 0)) {
      setState(349);
      antlrcpp::downCast<TryContext *>(_localctx)->t_catch_body = body();
      setState(350);
      nl();
    }
    setState(354);
    match(MavkaParser::KW_END);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ThrowContext ------------------------------------------------------------------

MavkaParser::ThrowContext::ThrowContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MavkaParser::ThrowContext::KW_THROW() {
  return getToken(MavkaParser::KW_THROW, 0);
}

MavkaParser::ExprContext* MavkaParser::ThrowContext::expr() {
  return getRuleContext<MavkaParser::ExprContext>(0);
}


size_t MavkaParser::ThrowContext::getRuleIndex() const {
  return MavkaParser::RuleThrow;
}

void MavkaParser::ThrowContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterThrow(this);
}

void MavkaParser::ThrowContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitThrow(this);
}


std::any MavkaParser::ThrowContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MavkaParserVisitor*>(visitor))
    return parserVisitor->visitThrow(this);
  else
    return visitor->visitChildren(this);
}

MavkaParser::ThrowContext* MavkaParser::throw_() {
  ThrowContext *_localctx = _tracker.createInstance<ThrowContext>(_ctx, getState());
  enterRule(_localctx, 50, MavkaParser::RuleThrow);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(356);
    match(MavkaParser::KW_THROW);
    setState(357);
    antlrcpp::downCast<ThrowContext *>(_localctx)->t_value = expr();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ChainContext ------------------------------------------------------------------

MavkaParser::ChainContext::ChainContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<MavkaParser::IdentifierContext *> MavkaParser::ChainContext::identifier() {
  return getRuleContexts<MavkaParser::IdentifierContext>();
}

MavkaParser::IdentifierContext* MavkaParser::ChainContext::identifier(size_t i) {
  return getRuleContext<MavkaParser::IdentifierContext>(i);
}

std::vector<MavkaParser::NlsContext *> MavkaParser::ChainContext::nls() {
  return getRuleContexts<MavkaParser::NlsContext>();
}

MavkaParser::NlsContext* MavkaParser::ChainContext::nls(size_t i) {
  return getRuleContext<MavkaParser::NlsContext>(i);
}

std::vector<tree::TerminalNode *> MavkaParser::ChainContext::DOT() {
  return getTokens(MavkaParser::DOT);
}

tree::TerminalNode* MavkaParser::ChainContext::DOT(size_t i) {
  return getToken(MavkaParser::DOT, i);
}


size_t MavkaParser::ChainContext::getRuleIndex() const {
  return MavkaParser::RuleChain;
}

void MavkaParser::ChainContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterChain(this);
}

void MavkaParser::ChainContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitChain(this);
}


std::any MavkaParser::ChainContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MavkaParserVisitor*>(visitor))
    return parserVisitor->visitChain(this);
  else
    return visitor->visitChildren(this);
}

MavkaParser::ChainContext* MavkaParser::chain() {
  ChainContext *_localctx = _tracker.createInstance<ChainContext>(_ctx, getState());
  enterRule(_localctx, 52, MavkaParser::RuleChain);

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
    setState(359);
    identifier();
    setState(367);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 38, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(360);
        nls();
        setState(361);
        match(MavkaParser::DOT);
        setState(362);
        nls();
        setState(363);
        identifier(); 
      }
      setState(369);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 38, _ctx);
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

MavkaParser::ChainContext* MavkaParser::TakeContext::chain() {
  return getRuleContext<MavkaParser::ChainContext>(0);
}

std::vector<MavkaParser::IdentifierContext *> MavkaParser::TakeContext::identifier() {
  return getRuleContexts<MavkaParser::IdentifierContext>();
}

MavkaParser::IdentifierContext* MavkaParser::TakeContext::identifier(size_t i) {
  return getRuleContext<MavkaParser::IdentifierContext>(i);
}

MavkaParser::Take_elementsContext* MavkaParser::TakeContext::take_elements() {
  return getRuleContext<MavkaParser::Take_elementsContext>(0);
}

tree::TerminalNode* MavkaParser::TakeContext::KW_AS() {
  return getToken(MavkaParser::KW_AS, 0);
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
  enterRule(_localctx, 54, MavkaParser::RuleTake);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(370);
    match(MavkaParser::KW_TAKE);
    setState(372);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 39, _ctx)) {
    case 1: {
      setState(371);
      antlrcpp::downCast<TakeContext *>(_localctx)->t_repo = identifier();
      break;
    }

    default:
      break;
    }
    setState(374);
    antlrcpp::downCast<TakeContext *>(_localctx)->t_chain = chain();
    setState(378);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MavkaParser::BRACKET_OPEN: {
        setState(375);
        antlrcpp::downCast<TakeContext *>(_localctx)->t_elements = take_elements();
        break;
      }

      case MavkaParser::KW_AS: {
        setState(376);
        match(MavkaParser::KW_AS);
        setState(377);
        antlrcpp::downCast<TakeContext *>(_localctx)->t_as = identifier();
        break;
      }

      case MavkaParser::EOF:
      case MavkaParser::NL: {
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

//----------------- Take_elementsContext ------------------------------------------------------------------

MavkaParser::Take_elementsContext::Take_elementsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MavkaParser::Take_elementsContext::BRACKET_OPEN() {
  return getToken(MavkaParser::BRACKET_OPEN, 0);
}

std::vector<MavkaParser::NlsContext *> MavkaParser::Take_elementsContext::nls() {
  return getRuleContexts<MavkaParser::NlsContext>();
}

MavkaParser::NlsContext* MavkaParser::Take_elementsContext::nls(size_t i) {
  return getRuleContext<MavkaParser::NlsContext>(i);
}

std::vector<MavkaParser::Take_elementContext *> MavkaParser::Take_elementsContext::take_element() {
  return getRuleContexts<MavkaParser::Take_elementContext>();
}

MavkaParser::Take_elementContext* MavkaParser::Take_elementsContext::take_element(size_t i) {
  return getRuleContext<MavkaParser::Take_elementContext>(i);
}

tree::TerminalNode* MavkaParser::Take_elementsContext::BRACKET_CLOSE() {
  return getToken(MavkaParser::BRACKET_CLOSE, 0);
}

std::vector<tree::TerminalNode *> MavkaParser::Take_elementsContext::COMA() {
  return getTokens(MavkaParser::COMA);
}

tree::TerminalNode* MavkaParser::Take_elementsContext::COMA(size_t i) {
  return getToken(MavkaParser::COMA, i);
}


size_t MavkaParser::Take_elementsContext::getRuleIndex() const {
  return MavkaParser::RuleTake_elements;
}

void MavkaParser::Take_elementsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTake_elements(this);
}

void MavkaParser::Take_elementsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTake_elements(this);
}


std::any MavkaParser::Take_elementsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MavkaParserVisitor*>(visitor))
    return parserVisitor->visitTake_elements(this);
  else
    return visitor->visitChildren(this);
}

MavkaParser::Take_elementsContext* MavkaParser::take_elements() {
  Take_elementsContext *_localctx = _tracker.createInstance<Take_elementsContext>(_ctx, getState());
  enterRule(_localctx, 56, MavkaParser::RuleTake_elements);

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
    setState(380);
    match(MavkaParser::BRACKET_OPEN);
    setState(381);
    nls();
    setState(382);
    take_element();
    setState(390);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 41, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(383);
        nls();
        setState(384);
        match(MavkaParser::COMA);
        setState(385);
        nls();
        setState(386);
        take_element(); 
      }
      setState(392);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 41, _ctx);
    }
    setState(396);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 42, _ctx)) {
    case 1: {
      setState(393);
      nls();
      setState(394);
      match(MavkaParser::COMA);
      break;
    }

    default:
      break;
    }
    setState(398);
    nls();
    setState(399);
    match(MavkaParser::BRACKET_CLOSE);
   
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

std::vector<MavkaParser::IdentifierContext *> MavkaParser::Take_elementContext::identifier() {
  return getRuleContexts<MavkaParser::IdentifierContext>();
}

MavkaParser::IdentifierContext* MavkaParser::Take_elementContext::identifier(size_t i) {
  return getRuleContext<MavkaParser::IdentifierContext>(i);
}

tree::TerminalNode* MavkaParser::Take_elementContext::KW_AS() {
  return getToken(MavkaParser::KW_AS, 0);
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
  enterRule(_localctx, 58, MavkaParser::RuleTake_element);
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
    setState(401);
    antlrcpp::downCast<Take_elementContext *>(_localctx)->te_name = identifier();
    setState(404);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == MavkaParser::KW_AS) {
      setState(402);
      match(MavkaParser::KW_AS);
      setState(403);
      antlrcpp::downCast<Take_elementContext *>(_localctx)->te_as = identifier();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Subject_outContext ------------------------------------------------------------------

MavkaParser::Subject_outContext::Subject_outContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MavkaParser::IdentifierContext* MavkaParser::Subject_outContext::identifier() {
  return getRuleContext<MavkaParser::IdentifierContext>(0);
}


size_t MavkaParser::Subject_outContext::getRuleIndex() const {
  return MavkaParser::RuleSubject_out;
}

void MavkaParser::Subject_outContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSubject_out(this);
}

void MavkaParser::Subject_outContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSubject_out(this);
}


std::any MavkaParser::Subject_outContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MavkaParserVisitor*>(visitor))
    return parserVisitor->visitSubject_out(this);
  else
    return visitor->visitChildren(this);
}

MavkaParser::Subject_outContext* MavkaParser::subject_out() {
  Subject_outContext *_localctx = _tracker.createInstance<Subject_outContext>(_ctx, getState());
  enterRule(_localctx, 60, MavkaParser::RuleSubject_out);

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
    identifier();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Get_outContext ------------------------------------------------------------------

MavkaParser::Get_outContext::Get_outContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<MavkaParser::NlsContext *> MavkaParser::Get_outContext::nls() {
  return getRuleContexts<MavkaParser::NlsContext>();
}

MavkaParser::NlsContext* MavkaParser::Get_outContext::nls(size_t i) {
  return getRuleContext<MavkaParser::NlsContext>(i);
}

tree::TerminalNode* MavkaParser::Get_outContext::DOT() {
  return getToken(MavkaParser::DOT, 0);
}

MavkaParser::ParticleContext* MavkaParser::Get_outContext::particle() {
  return getRuleContext<MavkaParser::ParticleContext>(0);
}

MavkaParser::IdentifierContext* MavkaParser::Get_outContext::identifier() {
  return getRuleContext<MavkaParser::IdentifierContext>(0);
}


size_t MavkaParser::Get_outContext::getRuleIndex() const {
  return MavkaParser::RuleGet_out;
}

void MavkaParser::Get_outContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterGet_out(this);
}

void MavkaParser::Get_outContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitGet_out(this);
}


std::any MavkaParser::Get_outContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MavkaParserVisitor*>(visitor))
    return parserVisitor->visitGet_out(this);
  else
    return visitor->visitChildren(this);
}

MavkaParser::Get_outContext* MavkaParser::get_out() {
  Get_outContext *_localctx = _tracker.createInstance<Get_outContext>(_ctx, getState());
  enterRule(_localctx, 62, MavkaParser::RuleGet_out);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(408);
    antlrcpp::downCast<Get_outContext *>(_localctx)->g_left = particle(0);
    setState(409);
    nls();
    setState(410);
    match(MavkaParser::DOT);
    setState(411);
    nls();
    setState(412);
    antlrcpp::downCast<Get_outContext *>(_localctx)->g_id = identifier();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Generic_outContext ------------------------------------------------------------------

MavkaParser::Generic_outContext::Generic_outContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<MavkaParser::NlsContext *> MavkaParser::Generic_outContext::nls() {
  return getRuleContexts<MavkaParser::NlsContext>();
}

MavkaParser::NlsContext* MavkaParser::Generic_outContext::nls(size_t i) {
  return getRuleContext<MavkaParser::NlsContext>(i);
}

tree::TerminalNode* MavkaParser::Generic_outContext::LESSER() {
  return getToken(MavkaParser::LESSER, 0);
}

std::vector<MavkaParser::TypeContext *> MavkaParser::Generic_outContext::type() {
  return getRuleContexts<MavkaParser::TypeContext>();
}

MavkaParser::TypeContext* MavkaParser::Generic_outContext::type(size_t i) {
  return getRuleContext<MavkaParser::TypeContext>(i);
}

MavkaParser::ParticleContext* MavkaParser::Generic_outContext::particle() {
  return getRuleContext<MavkaParser::ParticleContext>(0);
}

std::vector<tree::TerminalNode *> MavkaParser::Generic_outContext::COMA() {
  return getTokens(MavkaParser::COMA);
}

tree::TerminalNode* MavkaParser::Generic_outContext::COMA(size_t i) {
  return getToken(MavkaParser::COMA, i);
}


size_t MavkaParser::Generic_outContext::getRuleIndex() const {
  return MavkaParser::RuleGeneric_out;
}

void MavkaParser::Generic_outContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterGeneric_out(this);
}

void MavkaParser::Generic_outContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitGeneric_out(this);
}


std::any MavkaParser::Generic_outContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MavkaParserVisitor*>(visitor))
    return parserVisitor->visitGeneric_out(this);
  else
    return visitor->visitChildren(this);
}

MavkaParser::Generic_outContext* MavkaParser::generic_out() {
  Generic_outContext *_localctx = _tracker.createInstance<Generic_outContext>(_ctx, getState());
  enterRule(_localctx, 64, MavkaParser::RuleGeneric_out);

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
    setState(414);
    antlrcpp::downCast<Generic_outContext *>(_localctx)->g_left = particle(0);
    setState(415);
    nls();
    setState(416);
    match(MavkaParser::LESSER);
    setState(417);
    nls();
    setState(418);
    type();
    setState(426);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 44, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(419);
        nls();
        setState(420);
        match(MavkaParser::COMA);
        setState(421);
        nls();
        setState(422);
        type(); 
      }
      setState(428);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 44, _ctx);
    }
    setState(429);
    nls();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParticleContext ------------------------------------------------------------------

MavkaParser::ParticleContext::ParticleContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t MavkaParser::ParticleContext::getRuleIndex() const {
  return MavkaParser::RuleParticle;
}

void MavkaParser::ParticleContext::copyFrom(ParticleContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- CallContext ------------------------------------------------------------------

tree::TerminalNode* MavkaParser::CallContext::PAREN_OPEN() {
  return getToken(MavkaParser::PAREN_OPEN, 0);
}

std::vector<MavkaParser::NlsContext *> MavkaParser::CallContext::nls() {
  return getRuleContexts<MavkaParser::NlsContext>();
}

MavkaParser::NlsContext* MavkaParser::CallContext::nls(size_t i) {
  return getRuleContext<MavkaParser::NlsContext>(i);
}

tree::TerminalNode* MavkaParser::CallContext::PAREN_CLOSE() {
  return getToken(MavkaParser::PAREN_CLOSE, 0);
}

MavkaParser::ParticleContext* MavkaParser::CallContext::particle() {
  return getRuleContext<MavkaParser::ParticleContext>(0);
}

MavkaParser::Call_argsContext* MavkaParser::CallContext::call_args() {
  return getRuleContext<MavkaParser::Call_argsContext>(0);
}

MavkaParser::CallContext::CallContext(ParticleContext *ctx) { copyFrom(ctx); }

void MavkaParser::CallContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCall(this);
}
void MavkaParser::CallContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCall(this);
}

std::any MavkaParser::CallContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MavkaParserVisitor*>(visitor))
    return parserVisitor->visitCall(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AccessContext ------------------------------------------------------------------

std::vector<MavkaParser::NlsContext *> MavkaParser::AccessContext::nls() {
  return getRuleContexts<MavkaParser::NlsContext>();
}

MavkaParser::NlsContext* MavkaParser::AccessContext::nls(size_t i) {
  return getRuleContext<MavkaParser::NlsContext>(i);
}

tree::TerminalNode* MavkaParser::AccessContext::BRACKET_OPEN() {
  return getToken(MavkaParser::BRACKET_OPEN, 0);
}

MavkaParser::ExprContext* MavkaParser::AccessContext::expr() {
  return getRuleContext<MavkaParser::ExprContext>(0);
}

tree::TerminalNode* MavkaParser::AccessContext::BRACKET_CLOSE() {
  return getToken(MavkaParser::BRACKET_CLOSE, 0);
}

MavkaParser::ParticleContext* MavkaParser::AccessContext::particle() {
  return getRuleContext<MavkaParser::ParticleContext>(0);
}

MavkaParser::AccessContext::AccessContext(ParticleContext *ctx) { copyFrom(ctx); }

void MavkaParser::AccessContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAccess(this);
}
void MavkaParser::AccessContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAccess(this);
}

std::any MavkaParser::AccessContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MavkaParserVisitor*>(visitor))
    return parserVisitor->visitAccess(this);
  else
    return visitor->visitChildren(this);
}
//----------------- SubjectContext ------------------------------------------------------------------

MavkaParser::IdentifierContext* MavkaParser::SubjectContext::identifier() {
  return getRuleContext<MavkaParser::IdentifierContext>(0);
}

MavkaParser::SubjectContext::SubjectContext(ParticleContext *ctx) { copyFrom(ctx); }

void MavkaParser::SubjectContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSubject(this);
}
void MavkaParser::SubjectContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSubject(this);
}

std::any MavkaParser::SubjectContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MavkaParserVisitor*>(visitor))
    return parserVisitor->visitSubject(this);
  else
    return visitor->visitChildren(this);
}
//----------------- GetContext ------------------------------------------------------------------

std::vector<MavkaParser::NlsContext *> MavkaParser::GetContext::nls() {
  return getRuleContexts<MavkaParser::NlsContext>();
}

MavkaParser::NlsContext* MavkaParser::GetContext::nls(size_t i) {
  return getRuleContext<MavkaParser::NlsContext>(i);
}

tree::TerminalNode* MavkaParser::GetContext::DOT() {
  return getToken(MavkaParser::DOT, 0);
}

MavkaParser::ParticleContext* MavkaParser::GetContext::particle() {
  return getRuleContext<MavkaParser::ParticleContext>(0);
}

MavkaParser::IdentifierContext* MavkaParser::GetContext::identifier() {
  return getRuleContext<MavkaParser::IdentifierContext>(0);
}

MavkaParser::GetContext::GetContext(ParticleContext *ctx) { copyFrom(ctx); }

void MavkaParser::GetContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterGet(this);
}
void MavkaParser::GetContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitGet(this);
}

std::any MavkaParser::GetContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MavkaParserVisitor*>(visitor))
    return parserVisitor->visitGet(this);
  else
    return visitor->visitChildren(this);
}
//----------------- NestedContext ------------------------------------------------------------------

tree::TerminalNode* MavkaParser::NestedContext::PAREN_OPEN() {
  return getToken(MavkaParser::PAREN_OPEN, 0);
}

std::vector<MavkaParser::NlsContext *> MavkaParser::NestedContext::nls() {
  return getRuleContexts<MavkaParser::NlsContext>();
}

MavkaParser::NlsContext* MavkaParser::NestedContext::nls(size_t i) {
  return getRuleContext<MavkaParser::NlsContext>(i);
}

tree::TerminalNode* MavkaParser::NestedContext::PAREN_CLOSE() {
  return getToken(MavkaParser::PAREN_CLOSE, 0);
}

MavkaParser::ExprContext* MavkaParser::NestedContext::expr() {
  return getRuleContext<MavkaParser::ExprContext>(0);
}

MavkaParser::NestedContext::NestedContext(ParticleContext *ctx) { copyFrom(ctx); }

void MavkaParser::NestedContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNested(this);
}
void MavkaParser::NestedContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNested(this);
}

std::any MavkaParser::NestedContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MavkaParserVisitor*>(visitor))
    return parserVisitor->visitNested(this);
  else
    return visitor->visitChildren(this);
}
//----------------- GenericContext ------------------------------------------------------------------

std::vector<MavkaParser::NlsContext *> MavkaParser::GenericContext::nls() {
  return getRuleContexts<MavkaParser::NlsContext>();
}

MavkaParser::NlsContext* MavkaParser::GenericContext::nls(size_t i) {
  return getRuleContext<MavkaParser::NlsContext>(i);
}

tree::TerminalNode* MavkaParser::GenericContext::LESSER() {
  return getToken(MavkaParser::LESSER, 0);
}

std::vector<MavkaParser::TypeContext *> MavkaParser::GenericContext::type() {
  return getRuleContexts<MavkaParser::TypeContext>();
}

MavkaParser::TypeContext* MavkaParser::GenericContext::type(size_t i) {
  return getRuleContext<MavkaParser::TypeContext>(i);
}

tree::TerminalNode* MavkaParser::GenericContext::GREATER() {
  return getToken(MavkaParser::GREATER, 0);
}

MavkaParser::ParticleContext* MavkaParser::GenericContext::particle() {
  return getRuleContext<MavkaParser::ParticleContext>(0);
}

std::vector<tree::TerminalNode *> MavkaParser::GenericContext::COMA() {
  return getTokens(MavkaParser::COMA);
}

tree::TerminalNode* MavkaParser::GenericContext::COMA(size_t i) {
  return getToken(MavkaParser::COMA, i);
}

MavkaParser::GenericContext::GenericContext(ParticleContext *ctx) { copyFrom(ctx); }

void MavkaParser::GenericContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterGeneric(this);
}
void MavkaParser::GenericContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitGeneric(this);
}

std::any MavkaParser::GenericContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MavkaParserVisitor*>(visitor))
    return parserVisitor->visitGeneric(this);
  else
    return visitor->visitChildren(this);
}

MavkaParser::ParticleContext* MavkaParser::particle() {
   return particle(0);
}

MavkaParser::ParticleContext* MavkaParser::particle(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  MavkaParser::ParticleContext *_localctx = _tracker.createInstance<ParticleContext>(_ctx, parentState);
  MavkaParser::ParticleContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 66;
  enterRecursionRule(_localctx, 66, MavkaParser::RuleParticle, precedence);

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
    setState(439);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MavkaParser::ID: {
        _localctx = _tracker.createInstance<SubjectContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;

        setState(432);
        identifier();
        break;
      }

      case MavkaParser::PAREN_OPEN: {
        _localctx = _tracker.createInstance<NestedContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(433);
        match(MavkaParser::PAREN_OPEN);
        setState(434);
        nls();
        setState(435);
        antlrcpp::downCast<NestedContext *>(_localctx)->n_value = expr();
        setState(436);
        nls();
        setState(437);
        match(MavkaParser::PAREN_CLOSE);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(484);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 49, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(482);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 48, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<GetContext>(_tracker.createInstance<ParticleContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->g_left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleParticle);
          setState(441);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(442);
          nls();
          setState(443);
          match(MavkaParser::DOT);
          setState(444);
          nls();
          setState(445);
          antlrcpp::downCast<GetContext *>(_localctx)->g_id = identifier();
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<GenericContext>(_tracker.createInstance<ParticleContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->g_left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleParticle);
          setState(447);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(448);
          nls();
          setState(449);
          match(MavkaParser::LESSER);
          setState(450);
          nls();
          setState(451);
          type();
          setState(459);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 46, _ctx);
          while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
            if (alt == 1) {
              setState(452);
              nls();
              setState(453);
              match(MavkaParser::COMA);
              setState(454);
              nls();
              setState(455);
              type(); 
            }
            setState(461);
            _errHandler->sync(this);
            alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 46, _ctx);
          }
          setState(462);
          nls();
          setState(463);
          match(MavkaParser::GREATER);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<AccessContext>(_tracker.createInstance<ParticleContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->a_left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleParticle);
          setState(465);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(466);
          nls();
          setState(467);
          match(MavkaParser::BRACKET_OPEN);
          setState(468);
          nls();
          setState(469);
          expr();
          setState(470);
          nls();
          setState(471);
          match(MavkaParser::BRACKET_CLOSE);
          break;
        }

        case 4: {
          auto newContext = _tracker.createInstance<CallContext>(_tracker.createInstance<ParticleContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->c_value = previousContext;
          pushNewRecursionContext(newContext, startState, RuleParticle);
          setState(473);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(474);
          match(MavkaParser::PAREN_OPEN);
          setState(475);
          nls();
          setState(477);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if ((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & -3303372734473396084) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
            ((1ULL << (_la - 64)) & 235) != 0)) {
            setState(476);
            antlrcpp::downCast<CallContext *>(_localctx)->c_args = call_args();
          }
          setState(479);
          nls();
          setState(480);
          match(MavkaParser::PAREN_CLOSE);
          break;
        }

        default:
          break;
        } 
      }
      setState(486);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 49, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- Call_argsContext ------------------------------------------------------------------

MavkaParser::Call_argsContext::Call_argsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<MavkaParser::Call_argContext *> MavkaParser::Call_argsContext::call_arg() {
  return getRuleContexts<MavkaParser::Call_argContext>();
}

MavkaParser::Call_argContext* MavkaParser::Call_argsContext::call_arg(size_t i) {
  return getRuleContext<MavkaParser::Call_argContext>(i);
}

std::vector<MavkaParser::NlsContext *> MavkaParser::Call_argsContext::nls() {
  return getRuleContexts<MavkaParser::NlsContext>();
}

MavkaParser::NlsContext* MavkaParser::Call_argsContext::nls(size_t i) {
  return getRuleContext<MavkaParser::NlsContext>(i);
}

std::vector<tree::TerminalNode *> MavkaParser::Call_argsContext::COMA() {
  return getTokens(MavkaParser::COMA);
}

tree::TerminalNode* MavkaParser::Call_argsContext::COMA(size_t i) {
  return getToken(MavkaParser::COMA, i);
}


size_t MavkaParser::Call_argsContext::getRuleIndex() const {
  return MavkaParser::RuleCall_args;
}

void MavkaParser::Call_argsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCall_args(this);
}

void MavkaParser::Call_argsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCall_args(this);
}


std::any MavkaParser::Call_argsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MavkaParserVisitor*>(visitor))
    return parserVisitor->visitCall_args(this);
  else
    return visitor->visitChildren(this);
}

MavkaParser::Call_argsContext* MavkaParser::call_args() {
  Call_argsContext *_localctx = _tracker.createInstance<Call_argsContext>(_ctx, getState());
  enterRule(_localctx, 68, MavkaParser::RuleCall_args);

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
    setState(487);
    call_arg();
    setState(495);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 50, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(488);
        nls();
        setState(489);
        match(MavkaParser::COMA);
        setState(490);
        nls();
        setState(491);
        call_arg(); 
      }
      setState(497);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 50, _ctx);
    }
    setState(501);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 51, _ctx)) {
    case 1: {
      setState(498);
      nls();
      setState(499);
      match(MavkaParser::COMA);
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

MavkaParser::IdentifierContext* MavkaParser::Call_argContext::identifier() {
  return getRuleContext<MavkaParser::IdentifierContext>(0);
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
  enterRule(_localctx, 70, MavkaParser::RuleCall_arg);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(510);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 52, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(503);
      antlrcpp::downCast<Call_argContext *>(_localctx)->ca_expr = expr();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(504);
      antlrcpp::downCast<Call_argContext *>(_localctx)->ca_id = identifier();
      setState(505);
      nls();
      setState(506);
      match(MavkaParser::EQUAL);
      setState(507);
      nls();
      setState(508);
      antlrcpp::downCast<Call_argContext *>(_localctx)->ca_expr = expr();
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

//----------------- Atom_particleContext ------------------------------------------------------------------

MavkaParser::ParticleContext* MavkaParser::Atom_particleContext::particle() {
  return getRuleContext<MavkaParser::ParticleContext>(0);
}

MavkaParser::Atom_particleContext::Atom_particleContext(AtomContext *ctx) { copyFrom(ctx); }

void MavkaParser::Atom_particleContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAtom_particle(this);
}
void MavkaParser::Atom_particleContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAtom_particle(this);
}

std::any MavkaParser::Atom_particleContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MavkaParserVisitor*>(visitor))
    return parserVisitor->visitAtom_particle(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Atom_characterContext ------------------------------------------------------------------

MavkaParser::CharacterContext* MavkaParser::Atom_characterContext::character() {
  return getRuleContext<MavkaParser::CharacterContext>(0);
}

MavkaParser::Atom_characterContext::Atom_characterContext(AtomContext *ctx) { copyFrom(ctx); }

void MavkaParser::Atom_characterContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAtom_character(this);
}
void MavkaParser::Atom_characterContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAtom_character(this);
}

std::any MavkaParser::Atom_characterContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MavkaParserVisitor*>(visitor))
    return parserVisitor->visitAtom_character(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Atom_numberContext ------------------------------------------------------------------

MavkaParser::NumberContext* MavkaParser::Atom_numberContext::number() {
  return getRuleContext<MavkaParser::NumberContext>(0);
}

MavkaParser::Atom_numberContext::Atom_numberContext(AtomContext *ctx) { copyFrom(ctx); }

void MavkaParser::Atom_numberContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAtom_number(this);
}
void MavkaParser::Atom_numberContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAtom_number(this);
}

std::any MavkaParser::Atom_numberContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MavkaParserVisitor*>(visitor))
    return parserVisitor->visitAtom_number(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Atom_stringContext ------------------------------------------------------------------

MavkaParser::StringContext* MavkaParser::Atom_stringContext::string() {
  return getRuleContext<MavkaParser::StringContext>(0);
}

MavkaParser::Atom_stringContext::Atom_stringContext(AtomContext *ctx) { copyFrom(ctx); }

void MavkaParser::Atom_stringContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAtom_string(this);
}
void MavkaParser::Atom_stringContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAtom_string(this);
}

std::any MavkaParser::Atom_stringContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MavkaParserVisitor*>(visitor))
    return parserVisitor->visitAtom_string(this);
  else
    return visitor->visitChildren(this);
}
MavkaParser::AtomContext* MavkaParser::atom() {
  AtomContext *_localctx = _tracker.createInstance<AtomContext>(_ctx, getState());
  enterRule(_localctx, 72, MavkaParser::RuleAtom);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(516);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MavkaParser::PAREN_OPEN:
      case MavkaParser::ID: {
        _localctx = _tracker.createInstance<MavkaParser::Atom_particleContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(512);
        particle(0);
        break;
      }

      case MavkaParser::INTEGER:
      case MavkaParser::FLOAT:
      case MavkaParser::HEX:
      case MavkaParser::BIN: {
        _localctx = _tracker.createInstance<MavkaParser::Atom_numberContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(513);
        number();
        break;
      }

      case MavkaParser::STRING_MULTILINE:
      case MavkaParser::STRING: {
        _localctx = _tracker.createInstance<MavkaParser::Atom_stringContext>(_localctx);
        enterOuterAlt(_localctx, 3);
        setState(514);
        string();
        break;
      }

      case MavkaParser::CHARACTER: {
        _localctx = _tracker.createInstance<MavkaParser::Atom_characterContext>(_localctx);
        enterOuterAlt(_localctx, 4);
        setState(515);
        character();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MoleculeContext ------------------------------------------------------------------

MavkaParser::MoleculeContext::MoleculeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t MavkaParser::MoleculeContext::getRuleIndex() const {
  return MavkaParser::RuleMolecule;
}

void MavkaParser::MoleculeContext::copyFrom(MoleculeContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- Molecule_atomContext ------------------------------------------------------------------

MavkaParser::AtomContext* MavkaParser::Molecule_atomContext::atom() {
  return getRuleContext<MavkaParser::AtomContext>(0);
}

MavkaParser::Molecule_atomContext::Molecule_atomContext(MoleculeContext *ctx) { copyFrom(ctx); }

void MavkaParser::Molecule_atomContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMolecule_atom(this);
}
void MavkaParser::Molecule_atomContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMolecule_atom(this);
}

std::any MavkaParser::Molecule_atomContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MavkaParserVisitor*>(visitor))
    return parserVisitor->visitMolecule_atom(this);
  else
    return visitor->visitChildren(this);
}
//----------------- NotContext ------------------------------------------------------------------

tree::TerminalNode* MavkaParser::NotContext::EXCLAMATION() {
  return getToken(MavkaParser::EXCLAMATION, 0);
}

MavkaParser::MoleculeContext* MavkaParser::NotContext::molecule() {
  return getRuleContext<MavkaParser::MoleculeContext>(0);
}

MavkaParser::NotContext::NotContext(MoleculeContext *ctx) { copyFrom(ctx); }

void MavkaParser::NotContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNot(this);
}
void MavkaParser::NotContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNot(this);
}

std::any MavkaParser::NotContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MavkaParserVisitor*>(visitor))
    return parserVisitor->visitNot(this);
  else
    return visitor->visitChildren(this);
}
//----------------- NegativeContext ------------------------------------------------------------------

tree::TerminalNode* MavkaParser::NegativeContext::MINUS() {
  return getToken(MavkaParser::MINUS, 0);
}

MavkaParser::AtomContext* MavkaParser::NegativeContext::atom() {
  return getRuleContext<MavkaParser::AtomContext>(0);
}

MavkaParser::NegativeContext::NegativeContext(MoleculeContext *ctx) { copyFrom(ctx); }

void MavkaParser::NegativeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNegative(this);
}
void MavkaParser::NegativeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNegative(this);
}

std::any MavkaParser::NegativeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MavkaParserVisitor*>(visitor))
    return parserVisitor->visitNegative(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Bitwise_notContext ------------------------------------------------------------------

tree::TerminalNode* MavkaParser::Bitwise_notContext::TILDA() {
  return getToken(MavkaParser::TILDA, 0);
}

MavkaParser::AtomContext* MavkaParser::Bitwise_notContext::atom() {
  return getRuleContext<MavkaParser::AtomContext>(0);
}

MavkaParser::Bitwise_notContext::Bitwise_notContext(MoleculeContext *ctx) { copyFrom(ctx); }

void MavkaParser::Bitwise_notContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBitwise_not(this);
}
void MavkaParser::Bitwise_notContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBitwise_not(this);
}

std::any MavkaParser::Bitwise_notContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MavkaParserVisitor*>(visitor))
    return parserVisitor->visitBitwise_not(this);
  else
    return visitor->visitChildren(this);
}
MavkaParser::MoleculeContext* MavkaParser::molecule() {
  MoleculeContext *_localctx = _tracker.createInstance<MoleculeContext>(_ctx, getState());
  enterRule(_localctx, 74, MavkaParser::RuleMolecule);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(525);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MavkaParser::PAREN_OPEN:
      case MavkaParser::INTEGER:
      case MavkaParser::FLOAT:
      case MavkaParser::HEX:
      case MavkaParser::BIN:
      case MavkaParser::ID:
      case MavkaParser::STRING_MULTILINE:
      case MavkaParser::STRING:
      case MavkaParser::CHARACTER: {
        _localctx = _tracker.createInstance<MavkaParser::Molecule_atomContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(518);
        atom();
        break;
      }

      case MavkaParser::EXCLAMATION: {
        _localctx = _tracker.createInstance<MavkaParser::NotContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(519);
        match(MavkaParser::EXCLAMATION);
        setState(520);
        antlrcpp::downCast<NotContext *>(_localctx)->n_value = molecule();
        break;
      }

      case MavkaParser::MINUS: {
        _localctx = _tracker.createInstance<MavkaParser::NegativeContext>(_localctx);
        enterOuterAlt(_localctx, 3);
        setState(521);
        match(MavkaParser::MINUS);
        setState(522);
        antlrcpp::downCast<NegativeContext *>(_localctx)->n_value = atom();
        break;
      }

      case MavkaParser::TILDA: {
        _localctx = _tracker.createInstance<MavkaParser::Bitwise_notContext>(_localctx);
        enterOuterAlt(_localctx, 4);
        setState(523);
        match(MavkaParser::TILDA);
        setState(524);
        antlrcpp::downCast<Bitwise_notContext *>(_localctx)->bn_value = atom();
        break;
      }

    default:
      throw NoViableAltException(this);
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

//----------------- AddContext ------------------------------------------------------------------

std::vector<MavkaParser::OperationContext *> MavkaParser::AddContext::operation() {
  return getRuleContexts<MavkaParser::OperationContext>();
}

MavkaParser::OperationContext* MavkaParser::AddContext::operation(size_t i) {
  return getRuleContext<MavkaParser::OperationContext>(i);
}

MavkaParser::Arithmetic_op_addContext* MavkaParser::AddContext::arithmetic_op_add() {
  return getRuleContext<MavkaParser::Arithmetic_op_addContext>(0);
}

MavkaParser::AddContext::AddContext(OperationContext *ctx) { copyFrom(ctx); }

void MavkaParser::AddContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAdd(this);
}
void MavkaParser::AddContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAdd(this);
}

std::any MavkaParser::AddContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MavkaParserVisitor*>(visitor))
    return parserVisitor->visitAdd(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ComparisonContext ------------------------------------------------------------------

std::vector<MavkaParser::OperationContext *> MavkaParser::ComparisonContext::operation() {
  return getRuleContexts<MavkaParser::OperationContext>();
}

MavkaParser::OperationContext* MavkaParser::ComparisonContext::operation(size_t i) {
  return getRuleContext<MavkaParser::OperationContext>(i);
}

MavkaParser::Comparison_opContext* MavkaParser::ComparisonContext::comparison_op() {
  return getRuleContext<MavkaParser::Comparison_opContext>(0);
}

MavkaParser::ComparisonContext::ComparisonContext(OperationContext *ctx) { copyFrom(ctx); }

void MavkaParser::ComparisonContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterComparison(this);
}
void MavkaParser::ComparisonContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitComparison(this);
}

std::any MavkaParser::ComparisonContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MavkaParserVisitor*>(visitor))
    return parserVisitor->visitComparison(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ArrayContext ------------------------------------------------------------------

tree::TerminalNode* MavkaParser::ArrayContext::BRACKET_OPEN() {
  return getToken(MavkaParser::BRACKET_OPEN, 0);
}

std::vector<MavkaParser::NlsContext *> MavkaParser::ArrayContext::nls() {
  return getRuleContexts<MavkaParser::NlsContext>();
}

MavkaParser::NlsContext* MavkaParser::ArrayContext::nls(size_t i) {
  return getRuleContext<MavkaParser::NlsContext>(i);
}

tree::TerminalNode* MavkaParser::ArrayContext::BRACKET_CLOSE() {
  return getToken(MavkaParser::BRACKET_CLOSE, 0);
}

MavkaParser::Array_elementsContext* MavkaParser::ArrayContext::array_elements() {
  return getRuleContext<MavkaParser::Array_elementsContext>(0);
}

MavkaParser::ArrayContext::ArrayContext(OperationContext *ctx) { copyFrom(ctx); }

void MavkaParser::ArrayContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArray(this);
}
void MavkaParser::ArrayContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArray(this);
}

std::any MavkaParser::ArrayContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MavkaParserVisitor*>(visitor))
    return parserVisitor->visitArray(this);
  else
    return visitor->visitChildren(this);
}
//----------------- MulContext ------------------------------------------------------------------

std::vector<MavkaParser::OperationContext *> MavkaParser::MulContext::operation() {
  return getRuleContexts<MavkaParser::OperationContext>();
}

MavkaParser::OperationContext* MavkaParser::MulContext::operation(size_t i) {
  return getRuleContext<MavkaParser::OperationContext>(i);
}

MavkaParser::Arithmetic_op_mulContext* MavkaParser::MulContext::arithmetic_op_mul() {
  return getRuleContext<MavkaParser::Arithmetic_op_mulContext>(0);
}

MavkaParser::MulContext::MulContext(OperationContext *ctx) { copyFrom(ctx); }

void MavkaParser::MulContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMul(this);
}
void MavkaParser::MulContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMul(this);
}

std::any MavkaParser::MulContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MavkaParserVisitor*>(visitor))
    return parserVisitor->visitMul(this);
  else
    return visitor->visitChildren(this);
}
//----------------- BitwiseContext ------------------------------------------------------------------

std::vector<MavkaParser::OperationContext *> MavkaParser::BitwiseContext::operation() {
  return getRuleContexts<MavkaParser::OperationContext>();
}

MavkaParser::OperationContext* MavkaParser::BitwiseContext::operation(size_t i) {
  return getRuleContext<MavkaParser::OperationContext>(i);
}

MavkaParser::Bitwise_opContext* MavkaParser::BitwiseContext::bitwise_op() {
  return getRuleContext<MavkaParser::Bitwise_opContext>(0);
}

MavkaParser::BitwiseContext::BitwiseContext(OperationContext *ctx) { copyFrom(ctx); }

void MavkaParser::BitwiseContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBitwise(this);
}
void MavkaParser::BitwiseContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBitwise(this);
}

std::any MavkaParser::BitwiseContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MavkaParserVisitor*>(visitor))
    return parserVisitor->visitBitwise(this);
  else
    return visitor->visitChildren(this);
}
//----------------- DictContext ------------------------------------------------------------------

tree::TerminalNode* MavkaParser::DictContext::PAREN_OPEN() {
  return getToken(MavkaParser::PAREN_OPEN, 0);
}

std::vector<MavkaParser::NlsContext *> MavkaParser::DictContext::nls() {
  return getRuleContexts<MavkaParser::NlsContext>();
}

MavkaParser::NlsContext* MavkaParser::DictContext::nls(size_t i) {
  return getRuleContext<MavkaParser::NlsContext>(i);
}

tree::TerminalNode* MavkaParser::DictContext::PAREN_CLOSE() {
  return getToken(MavkaParser::PAREN_CLOSE, 0);
}

MavkaParser::Dict_elementsContext* MavkaParser::DictContext::dict_elements() {
  return getRuleContext<MavkaParser::Dict_elementsContext>(0);
}

MavkaParser::DictContext::DictContext(OperationContext *ctx) { copyFrom(ctx); }

void MavkaParser::DictContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDict(this);
}
void MavkaParser::DictContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDict(this);
}

std::any MavkaParser::DictContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MavkaParserVisitor*>(visitor))
    return parserVisitor->visitDict(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Operation_moleculeContext ------------------------------------------------------------------

MavkaParser::MoleculeContext* MavkaParser::Operation_moleculeContext::molecule() {
  return getRuleContext<MavkaParser::MoleculeContext>(0);
}

MavkaParser::Operation_moleculeContext::Operation_moleculeContext(OperationContext *ctx) { copyFrom(ctx); }

void MavkaParser::Operation_moleculeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOperation_molecule(this);
}
void MavkaParser::Operation_moleculeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOperation_molecule(this);
}

std::any MavkaParser::Operation_moleculeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MavkaParserVisitor*>(visitor))
    return parserVisitor->visitOperation_molecule(this);
  else
    return visitor->visitChildren(this);
}
//----------------- LogicalContext ------------------------------------------------------------------

std::vector<MavkaParser::OperationContext *> MavkaParser::LogicalContext::operation() {
  return getRuleContexts<MavkaParser::OperationContext>();
}

MavkaParser::OperationContext* MavkaParser::LogicalContext::operation(size_t i) {
  return getRuleContext<MavkaParser::OperationContext>(i);
}

MavkaParser::Logical_opContext* MavkaParser::LogicalContext::logical_op() {
  return getRuleContext<MavkaParser::Logical_opContext>(0);
}

MavkaParser::LogicalContext::LogicalContext(OperationContext *ctx) { copyFrom(ctx); }

void MavkaParser::LogicalContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLogical(this);
}
void MavkaParser::LogicalContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLogical(this);
}

std::any MavkaParser::LogicalContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MavkaParserVisitor*>(visitor))
    return parserVisitor->visitLogical(this);
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
  size_t startState = 76;
  enterRecursionRule(_localctx, 76, MavkaParser::RuleOperation, precedence);

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
    setState(545);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 57, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<Operation_moleculeContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;

      setState(528);
      molecule();
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<ArrayContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(529);
      match(MavkaParser::BRACKET_OPEN);
      setState(530);
      nls();
      setState(532);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & -3303372734473396084) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 64)) & 235) != 0)) {
        setState(531);
        array_elements();
      }
      setState(534);
      nls();
      setState(535);
      match(MavkaParser::BRACKET_CLOSE);
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<DictContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(537);
      match(MavkaParser::PAREN_OPEN);
      setState(538);
      nls();
      setState(540);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (((((_la - 62) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 62)) & 911) != 0)) {
        setState(539);
        dict_elements();
      }
      setState(542);
      nls();
      setState(543);
      match(MavkaParser::PAREN_CLOSE);
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(569);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 59, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(567);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 58, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<MulContext>(_tracker.createInstance<OperationContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->a_left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleOperation);
          setState(547);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(548);
          antlrcpp::downCast<MulContext *>(_localctx)->a_operation = arithmetic_op_mul();
          setState(549);
          antlrcpp::downCast<MulContext *>(_localctx)->a_right = operation(6);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<AddContext>(_tracker.createInstance<OperationContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->a_left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleOperation);
          setState(551);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(552);
          antlrcpp::downCast<AddContext *>(_localctx)->a_operation = arithmetic_op_add();
          setState(553);
          antlrcpp::downCast<AddContext *>(_localctx)->a_right = operation(5);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<BitwiseContext>(_tracker.createInstance<OperationContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->b_left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleOperation);
          setState(555);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(556);
          antlrcpp::downCast<BitwiseContext *>(_localctx)->b_operation = bitwise_op();
          setState(557);
          antlrcpp::downCast<BitwiseContext *>(_localctx)->b_right = operation(4);
          break;
        }

        case 4: {
          auto newContext = _tracker.createInstance<ComparisonContext>(_tracker.createInstance<OperationContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->c_left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleOperation);
          setState(559);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(560);
          antlrcpp::downCast<ComparisonContext *>(_localctx)->c_operation = comparison_op();
          setState(561);
          antlrcpp::downCast<ComparisonContext *>(_localctx)->c_right = operation(3);
          break;
        }

        case 5: {
          auto newContext = _tracker.createInstance<LogicalContext>(_tracker.createInstance<OperationContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->t_left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleOperation);
          setState(563);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(564);
          antlrcpp::downCast<LogicalContext *>(_localctx)->t_operation = logical_op();
          setState(565);
          antlrcpp::downCast<LogicalContext *>(_localctx)->t_right = operation(2);
          break;
        }

        default:
          break;
        } 
      }
      setState(571);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 59, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- Array_elementsContext ------------------------------------------------------------------

MavkaParser::Array_elementsContext::Array_elementsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<MavkaParser::ExprContext *> MavkaParser::Array_elementsContext::expr() {
  return getRuleContexts<MavkaParser::ExprContext>();
}

MavkaParser::ExprContext* MavkaParser::Array_elementsContext::expr(size_t i) {
  return getRuleContext<MavkaParser::ExprContext>(i);
}

std::vector<MavkaParser::NlsContext *> MavkaParser::Array_elementsContext::nls() {
  return getRuleContexts<MavkaParser::NlsContext>();
}

MavkaParser::NlsContext* MavkaParser::Array_elementsContext::nls(size_t i) {
  return getRuleContext<MavkaParser::NlsContext>(i);
}

std::vector<tree::TerminalNode *> MavkaParser::Array_elementsContext::COMA() {
  return getTokens(MavkaParser::COMA);
}

tree::TerminalNode* MavkaParser::Array_elementsContext::COMA(size_t i) {
  return getToken(MavkaParser::COMA, i);
}


size_t MavkaParser::Array_elementsContext::getRuleIndex() const {
  return MavkaParser::RuleArray_elements;
}

void MavkaParser::Array_elementsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArray_elements(this);
}

void MavkaParser::Array_elementsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArray_elements(this);
}


std::any MavkaParser::Array_elementsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MavkaParserVisitor*>(visitor))
    return parserVisitor->visitArray_elements(this);
  else
    return visitor->visitChildren(this);
}

MavkaParser::Array_elementsContext* MavkaParser::array_elements() {
  Array_elementsContext *_localctx = _tracker.createInstance<Array_elementsContext>(_ctx, getState());
  enterRule(_localctx, 78, MavkaParser::RuleArray_elements);

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
    setState(572);
    expr();
    setState(580);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 60, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(573);
        nls();
        setState(574);
        match(MavkaParser::COMA);
        setState(575);
        nls();
        setState(576);
        expr(); 
      }
      setState(582);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 60, _ctx);
    }
    setState(586);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 61, _ctx)) {
    case 1: {
      setState(583);
      nls();
      setState(584);
      match(MavkaParser::COMA);
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

//----------------- Dict_elementsContext ------------------------------------------------------------------

MavkaParser::Dict_elementsContext::Dict_elementsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<MavkaParser::Dict_elementContext *> MavkaParser::Dict_elementsContext::dict_element() {
  return getRuleContexts<MavkaParser::Dict_elementContext>();
}

MavkaParser::Dict_elementContext* MavkaParser::Dict_elementsContext::dict_element(size_t i) {
  return getRuleContext<MavkaParser::Dict_elementContext>(i);
}

std::vector<MavkaParser::NlsContext *> MavkaParser::Dict_elementsContext::nls() {
  return getRuleContexts<MavkaParser::NlsContext>();
}

MavkaParser::NlsContext* MavkaParser::Dict_elementsContext::nls(size_t i) {
  return getRuleContext<MavkaParser::NlsContext>(i);
}

std::vector<tree::TerminalNode *> MavkaParser::Dict_elementsContext::COMA() {
  return getTokens(MavkaParser::COMA);
}

tree::TerminalNode* MavkaParser::Dict_elementsContext::COMA(size_t i) {
  return getToken(MavkaParser::COMA, i);
}


size_t MavkaParser::Dict_elementsContext::getRuleIndex() const {
  return MavkaParser::RuleDict_elements;
}

void MavkaParser::Dict_elementsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDict_elements(this);
}

void MavkaParser::Dict_elementsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDict_elements(this);
}


std::any MavkaParser::Dict_elementsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MavkaParserVisitor*>(visitor))
    return parserVisitor->visitDict_elements(this);
  else
    return visitor->visitChildren(this);
}

MavkaParser::Dict_elementsContext* MavkaParser::dict_elements() {
  Dict_elementsContext *_localctx = _tracker.createInstance<Dict_elementsContext>(_ctx, getState());
  enterRule(_localctx, 80, MavkaParser::RuleDict_elements);

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
    setState(588);
    dict_element();
    setState(596);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 62, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(589);
        nls();
        setState(590);
        match(MavkaParser::COMA);
        setState(591);
        nls();
        setState(592);
        dict_element(); 
      }
      setState(598);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 62, _ctx);
    }
    setState(602);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 63, _ctx)) {
    case 1: {
      setState(599);
      nls();
      setState(600);
      match(MavkaParser::COMA);
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

//----------------- Dict_elementContext ------------------------------------------------------------------

MavkaParser::Dict_elementContext::Dict_elementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<MavkaParser::NlsContext *> MavkaParser::Dict_elementContext::nls() {
  return getRuleContexts<MavkaParser::NlsContext>();
}

MavkaParser::NlsContext* MavkaParser::Dict_elementContext::nls(size_t i) {
  return getRuleContext<MavkaParser::NlsContext>(i);
}

tree::TerminalNode* MavkaParser::Dict_elementContext::EQUAL() {
  return getToken(MavkaParser::EQUAL, 0);
}

MavkaParser::ExprContext* MavkaParser::Dict_elementContext::expr() {
  return getRuleContext<MavkaParser::ExprContext>(0);
}

MavkaParser::StringContext* MavkaParser::Dict_elementContext::string() {
  return getRuleContext<MavkaParser::StringContext>(0);
}

MavkaParser::NumberContext* MavkaParser::Dict_elementContext::number() {
  return getRuleContext<MavkaParser::NumberContext>(0);
}

MavkaParser::CharacterContext* MavkaParser::Dict_elementContext::character() {
  return getRuleContext<MavkaParser::CharacterContext>(0);
}


size_t MavkaParser::Dict_elementContext::getRuleIndex() const {
  return MavkaParser::RuleDict_element;
}

void MavkaParser::Dict_elementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDict_element(this);
}

void MavkaParser::Dict_elementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDict_element(this);
}


std::any MavkaParser::Dict_elementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MavkaParserVisitor*>(visitor))
    return parserVisitor->visitDict_element(this);
  else
    return visitor->visitChildren(this);
}

MavkaParser::Dict_elementContext* MavkaParser::dict_element() {
  Dict_elementContext *_localctx = _tracker.createInstance<Dict_elementContext>(_ctx, getState());
  enterRule(_localctx, 82, MavkaParser::RuleDict_element);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(607);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MavkaParser::STRING_MULTILINE:
      case MavkaParser::STRING: {
        setState(604);
        antlrcpp::downCast<Dict_elementContext *>(_localctx)->de_string = string();
        break;
      }

      case MavkaParser::INTEGER:
      case MavkaParser::FLOAT:
      case MavkaParser::HEX:
      case MavkaParser::BIN: {
        setState(605);
        antlrcpp::downCast<Dict_elementContext *>(_localctx)->de_number = number();
        break;
      }

      case MavkaParser::CHARACTER: {
        setState(606);
        antlrcpp::downCast<Dict_elementContext *>(_localctx)->de_character = character();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(609);
    nls();
    setState(610);
    match(MavkaParser::EQUAL);
    setState(611);
    nls();
    setState(612);
    antlrcpp::downCast<Dict_elementContext *>(_localctx)->de_value = expr();
   
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

//----------------- Expr_structureContext ------------------------------------------------------------------

MavkaParser::StructureContext* MavkaParser::Expr_structureContext::structure() {
  return getRuleContext<MavkaParser::StructureContext>(0);
}

MavkaParser::Expr_structureContext::Expr_structureContext(ExprContext *ctx) { copyFrom(ctx); }

void MavkaParser::Expr_structureContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpr_structure(this);
}
void MavkaParser::Expr_structureContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpr_structure(this);
}

std::any MavkaParser::Expr_structureContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MavkaParserVisitor*>(visitor))
    return parserVisitor->visitExpr_structure(this);
  else
    return visitor->visitChildren(this);
}
//----------------- WaitContext ------------------------------------------------------------------

tree::TerminalNode* MavkaParser::WaitContext::KW_WAIT() {
  return getToken(MavkaParser::KW_WAIT, 0);
}

MavkaParser::OperationContext* MavkaParser::WaitContext::operation() {
  return getRuleContext<MavkaParser::OperationContext>(0);
}

MavkaParser::WaitContext::WaitContext(ExprContext *ctx) { copyFrom(ctx); }

void MavkaParser::WaitContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterWait(this);
}
void MavkaParser::WaitContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitWait(this);
}

std::any MavkaParser::WaitContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MavkaParserVisitor*>(visitor))
    return parserVisitor->visitWait(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AsContext ------------------------------------------------------------------

tree::TerminalNode* MavkaParser::AsContext::KW_AS() {
  return getToken(MavkaParser::KW_AS, 0);
}

MavkaParser::MoleculeContext* MavkaParser::AsContext::molecule() {
  return getRuleContext<MavkaParser::MoleculeContext>(0);
}

MavkaParser::TypeContext* MavkaParser::AsContext::type() {
  return getRuleContext<MavkaParser::TypeContext>(0);
}

MavkaParser::AsContext::AsContext(ExprContext *ctx) { copyFrom(ctx); }

void MavkaParser::AsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAs(this);
}
void MavkaParser::AsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAs(this);
}

std::any MavkaParser::AsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MavkaParserVisitor*>(visitor))
    return parserVisitor->visitAs(this);
  else
    return visitor->visitChildren(this);
}
//----------------- FunctionContext ------------------------------------------------------------------

tree::TerminalNode* MavkaParser::FunctionContext::PAREN_OPEN() {
  return getToken(MavkaParser::PAREN_OPEN, 0);
}

std::vector<MavkaParser::NlsContext *> MavkaParser::FunctionContext::nls() {
  return getRuleContexts<MavkaParser::NlsContext>();
}

MavkaParser::NlsContext* MavkaParser::FunctionContext::nls(size_t i) {
  return getRuleContext<MavkaParser::NlsContext>(i);
}

tree::TerminalNode* MavkaParser::FunctionContext::PAREN_CLOSE() {
  return getToken(MavkaParser::PAREN_CLOSE, 0);
}

tree::TerminalNode* MavkaParser::FunctionContext::COLON() {
  return getToken(MavkaParser::COLON, 0);
}

MavkaParser::ExprContext* MavkaParser::FunctionContext::expr() {
  return getRuleContext<MavkaParser::ExprContext>(0);
}

MavkaParser::Diia_paramsContext* MavkaParser::FunctionContext::diia_params() {
  return getRuleContext<MavkaParser::Diia_paramsContext>(0);
}

MavkaParser::TypeContext* MavkaParser::FunctionContext::type() {
  return getRuleContext<MavkaParser::TypeContext>(0);
}

MavkaParser::FunctionContext::FunctionContext(ExprContext *ctx) { copyFrom(ctx); }

void MavkaParser::FunctionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunction(this);
}
void MavkaParser::FunctionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunction(this);
}

std::any MavkaParser::FunctionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MavkaParserVisitor*>(visitor))
    return parserVisitor->visitFunction(this);
  else
    return visitor->visitChildren(this);
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
//----------------- GodContext ------------------------------------------------------------------

std::vector<MavkaParser::OperationContext *> MavkaParser::GodContext::operation() {
  return getRuleContexts<MavkaParser::OperationContext>();
}

MavkaParser::OperationContext* MavkaParser::GodContext::operation(size_t i) {
  return getRuleContext<MavkaParser::OperationContext>(i);
}

std::vector<MavkaParser::NlsContext *> MavkaParser::GodContext::nls() {
  return getRuleContexts<MavkaParser::NlsContext>();
}

MavkaParser::NlsContext* MavkaParser::GodContext::nls(size_t i) {
  return getRuleContext<MavkaParser::NlsContext>(i);
}

std::vector<tree::TerminalNode *> MavkaParser::GodContext::KW_TA() {
  return getTokens(MavkaParser::KW_TA);
}

tree::TerminalNode* MavkaParser::GodContext::KW_TA(size_t i) {
  return getToken(MavkaParser::KW_TA, i);
}

MavkaParser::GodContext::GodContext(ExprContext *ctx) { copyFrom(ctx); }

void MavkaParser::GodContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterGod(this);
}
void MavkaParser::GodContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitGod(this);
}

std::any MavkaParser::GodContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MavkaParserVisitor*>(visitor))
    return parserVisitor->visitGod(this);
  else
    return visitor->visitChildren(this);
}
//----------------- TernaryContext ------------------------------------------------------------------

std::vector<MavkaParser::NlsContext *> MavkaParser::TernaryContext::nls() {
  return getRuleContexts<MavkaParser::NlsContext>();
}

MavkaParser::NlsContext* MavkaParser::TernaryContext::nls(size_t i) {
  return getRuleContext<MavkaParser::NlsContext>(i);
}

tree::TerminalNode* MavkaParser::TernaryContext::QUESTION() {
  return getToken(MavkaParser::QUESTION, 0);
}

tree::TerminalNode* MavkaParser::TernaryContext::COLON() {
  return getToken(MavkaParser::COLON, 0);
}

MavkaParser::OperationContext* MavkaParser::TernaryContext::operation() {
  return getRuleContext<MavkaParser::OperationContext>(0);
}

std::vector<MavkaParser::ExprContext *> MavkaParser::TernaryContext::expr() {
  return getRuleContexts<MavkaParser::ExprContext>();
}

MavkaParser::ExprContext* MavkaParser::TernaryContext::expr(size_t i) {
  return getRuleContext<MavkaParser::ExprContext>(i);
}

MavkaParser::TernaryContext::TernaryContext(ExprContext *ctx) { copyFrom(ctx); }

void MavkaParser::TernaryContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTernary(this);
}
void MavkaParser::TernaryContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTernary(this);
}

std::any MavkaParser::TernaryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MavkaParserVisitor*>(visitor))
    return parserVisitor->visitTernary(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Expr_diiaContext ------------------------------------------------------------------

MavkaParser::DiiaContext* MavkaParser::Expr_diiaContext::diia() {
  return getRuleContext<MavkaParser::DiiaContext>(0);
}

MavkaParser::Expr_diiaContext::Expr_diiaContext(ExprContext *ctx) { copyFrom(ctx); }

void MavkaParser::Expr_diiaContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpr_diia(this);
}
void MavkaParser::Expr_diiaContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpr_diia(this);
}

std::any MavkaParser::Expr_diiaContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MavkaParserVisitor*>(visitor))
    return parserVisitor->visitExpr_diia(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Expr_moduleContext ------------------------------------------------------------------

MavkaParser::ModuleContext* MavkaParser::Expr_moduleContext::module() {
  return getRuleContext<MavkaParser::ModuleContext>(0);
}

MavkaParser::Expr_moduleContext::Expr_moduleContext(ExprContext *ctx) { copyFrom(ctx); }

void MavkaParser::Expr_moduleContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpr_module(this);
}
void MavkaParser::Expr_moduleContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpr_module(this);
}

std::any MavkaParser::Expr_moduleContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MavkaParserVisitor*>(visitor))
    return parserVisitor->visitExpr_module(this);
  else
    return visitor->visitChildren(this);
}
MavkaParser::ExprContext* MavkaParser::expr() {
  ExprContext *_localctx = _tracker.createInstance<ExprContext>(_ctx, getState());
  enterRule(_localctx, 84, MavkaParser::RuleExpr);
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
    setState(658);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 68, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<MavkaParser::Expr_structureContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(614);
      structure();
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<MavkaParser::Expr_diiaContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(615);
      diia();
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<MavkaParser::Expr_moduleContext>(_localctx);
      enterOuterAlt(_localctx, 3);
      setState(616);
      module();
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<MavkaParser::WaitContext>(_localctx);
      enterOuterAlt(_localctx, 4);
      setState(617);
      match(MavkaParser::KW_WAIT);
      setState(618);
      antlrcpp::downCast<WaitContext *>(_localctx)->e_value = operation(0);
      break;
    }

    case 5: {
      _localctx = _tracker.createInstance<MavkaParser::AsContext>(_localctx);
      enterOuterAlt(_localctx, 5);
      setState(619);
      antlrcpp::downCast<AsContext *>(_localctx)->a_left = molecule();
      setState(620);
      match(MavkaParser::KW_AS);
      setState(621);
      antlrcpp::downCast<AsContext *>(_localctx)->a_type = type();
      break;
    }

    case 6: {
      _localctx = _tracker.createInstance<MavkaParser::GodContext>(_localctx);
      enterOuterAlt(_localctx, 6);
      setState(623);
      operation(0);
      setState(629); 
      _errHandler->sync(this);
      alt = 1;
      do {
        switch (alt) {
          case 1: {
                setState(624);
                nls();
                setState(625);
                match(MavkaParser::KW_TA);
                setState(626);
                nls();
                setState(627);
                operation(0);
                break;
              }

        default:
          throw NoViableAltException(this);
        }
        setState(631); 
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 65, _ctx);
      } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
      break;
    }

    case 7: {
      _localctx = _tracker.createInstance<MavkaParser::Expr_operationContext>(_localctx);
      enterOuterAlt(_localctx, 7);
      setState(633);
      operation(0);
      break;
    }

    case 8: {
      _localctx = _tracker.createInstance<MavkaParser::FunctionContext>(_localctx);
      enterOuterAlt(_localctx, 8);
      setState(634);
      match(MavkaParser::PAREN_OPEN);
      setState(635);
      nls();
      setState(637);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == MavkaParser::ID) {
        setState(636);
        antlrcpp::downCast<FunctionContext *>(_localctx)->f_params = diia_params();
      }
      setState(639);
      nls();
      setState(640);
      match(MavkaParser::PAREN_CLOSE);
      setState(642);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (((((_la - 51) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 51)) & 65553) != 0)) {
        setState(641);
        antlrcpp::downCast<FunctionContext *>(_localctx)->f_type = type();
      }
      setState(644);
      match(MavkaParser::COLON);
      setState(645);
      nls();
      setState(646);
      antlrcpp::downCast<FunctionContext *>(_localctx)->f_body = expr();
      break;
    }

    case 9: {
      _localctx = _tracker.createInstance<MavkaParser::TernaryContext>(_localctx);
      enterOuterAlt(_localctx, 9);
      setState(648);
      antlrcpp::downCast<TernaryContext *>(_localctx)->t_value = operation(0);
      setState(649);
      nls();
      setState(650);
      match(MavkaParser::QUESTION);
      setState(651);
      nls();
      setState(652);
      antlrcpp::downCast<TernaryContext *>(_localctx)->t_positive = expr();
      setState(653);
      nls();
      setState(654);
      match(MavkaParser::COLON);
      setState(655);
      nls();
      setState(656);
      antlrcpp::downCast<TernaryContext *>(_localctx)->t_negative = expr();
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

//----------------- GiveContext ------------------------------------------------------------------

MavkaParser::GiveContext::GiveContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MavkaParser::GiveContext::KW_GIVE() {
  return getToken(MavkaParser::KW_GIVE, 0);
}

std::vector<MavkaParser::Give_elementContext *> MavkaParser::GiveContext::give_element() {
  return getRuleContexts<MavkaParser::Give_elementContext>();
}

MavkaParser::Give_elementContext* MavkaParser::GiveContext::give_element(size_t i) {
  return getRuleContext<MavkaParser::Give_elementContext>(i);
}

std::vector<MavkaParser::NlsContext *> MavkaParser::GiveContext::nls() {
  return getRuleContexts<MavkaParser::NlsContext>();
}

MavkaParser::NlsContext* MavkaParser::GiveContext::nls(size_t i) {
  return getRuleContext<MavkaParser::NlsContext>(i);
}

std::vector<tree::TerminalNode *> MavkaParser::GiveContext::COMA() {
  return getTokens(MavkaParser::COMA);
}

tree::TerminalNode* MavkaParser::GiveContext::COMA(size_t i) {
  return getToken(MavkaParser::COMA, i);
}


size_t MavkaParser::GiveContext::getRuleIndex() const {
  return MavkaParser::RuleGive;
}

void MavkaParser::GiveContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterGive(this);
}

void MavkaParser::GiveContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitGive(this);
}


std::any MavkaParser::GiveContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MavkaParserVisitor*>(visitor))
    return parserVisitor->visitGive(this);
  else
    return visitor->visitChildren(this);
}

MavkaParser::GiveContext* MavkaParser::give() {
  GiveContext *_localctx = _tracker.createInstance<GiveContext>(_ctx, getState());
  enterRule(_localctx, 86, MavkaParser::RuleGive);

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
    setState(660);
    match(MavkaParser::KW_GIVE);
    setState(661);
    give_element();
    setState(669);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 69, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(662);
        nls();
        setState(663);
        match(MavkaParser::COMA);
        setState(664);
        nls();
        setState(665);
        give_element(); 
      }
      setState(671);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 69, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Give_elementContext ------------------------------------------------------------------

MavkaParser::Give_elementContext::Give_elementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<MavkaParser::IdentifierContext *> MavkaParser::Give_elementContext::identifier() {
  return getRuleContexts<MavkaParser::IdentifierContext>();
}

MavkaParser::IdentifierContext* MavkaParser::Give_elementContext::identifier(size_t i) {
  return getRuleContext<MavkaParser::IdentifierContext>(i);
}

tree::TerminalNode* MavkaParser::Give_elementContext::KW_AS() {
  return getToken(MavkaParser::KW_AS, 0);
}


size_t MavkaParser::Give_elementContext::getRuleIndex() const {
  return MavkaParser::RuleGive_element;
}

void MavkaParser::Give_elementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterGive_element(this);
}

void MavkaParser::Give_elementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitGive_element(this);
}


std::any MavkaParser::Give_elementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MavkaParserVisitor*>(visitor))
    return parserVisitor->visitGive_element(this);
  else
    return visitor->visitChildren(this);
}

MavkaParser::Give_elementContext* MavkaParser::give_element() {
  Give_elementContext *_localctx = _tracker.createInstance<Give_elementContext>(_ctx, getState());
  enterRule(_localctx, 88, MavkaParser::RuleGive_element);
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
    setState(672);
    antlrcpp::downCast<Give_elementContext *>(_localctx)->ge_name = identifier();
    setState(675);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == MavkaParser::KW_AS) {
      setState(673);
      match(MavkaParser::KW_AS);
      setState(674);
      antlrcpp::downCast<Give_elementContext *>(_localctx)->ge_as = identifier();
    }
   
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
  enterRule(_localctx, 90, MavkaParser::RuleBody);

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
    setState(677);
    body_element();
    setState(683);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 71, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(678);
        nl();
        setState(679);
        body_element(); 
      }
      setState(685);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 71, _ctx);
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

MavkaParser::IfContext* MavkaParser::Body_elementContext::if_() {
  return getRuleContext<MavkaParser::IfContext>(0);
}

MavkaParser::WhileContext* MavkaParser::Body_elementContext::while_() {
  return getRuleContext<MavkaParser::WhileContext>(0);
}

MavkaParser::IntervalContext* MavkaParser::Body_elementContext::interval() {
  return getRuleContext<MavkaParser::IntervalContext>(0);
}

MavkaParser::CycleContext* MavkaParser::Body_elementContext::cycle() {
  return getRuleContext<MavkaParser::CycleContext>(0);
}

MavkaParser::TryContext* MavkaParser::Body_elementContext::try_() {
  return getRuleContext<MavkaParser::TryContext>(0);
}

MavkaParser::ThrowContext* MavkaParser::Body_elementContext::throw_() {
  return getRuleContext<MavkaParser::ThrowContext>(0);
}

MavkaParser::AssignContext* MavkaParser::Body_elementContext::assign() {
  return getRuleContext<MavkaParser::AssignContext>(0);
}

MavkaParser::SetContext* MavkaParser::Body_elementContext::set() {
  return getRuleContext<MavkaParser::SetContext>(0);
}

MavkaParser::Set_by_accessContext* MavkaParser::Body_elementContext::set_by_access() {
  return getRuleContext<MavkaParser::Set_by_accessContext>(0);
}

MavkaParser::ExprContext* MavkaParser::Body_elementContext::expr() {
  return getRuleContext<MavkaParser::ExprContext>(0);
}

MavkaParser::Return_body_elementContext* MavkaParser::Body_elementContext::return_body_element() {
  return getRuleContext<MavkaParser::Return_body_elementContext>(0);
}

MavkaParser::GiveContext* MavkaParser::Body_elementContext::give() {
  return getRuleContext<MavkaParser::GiveContext>(0);
}

MavkaParser::TakeContext* MavkaParser::Body_elementContext::take() {
  return getRuleContext<MavkaParser::TakeContext>(0);
}

MavkaParser::NlsContext* MavkaParser::Body_elementContext::nls() {
  return getRuleContext<MavkaParser::NlsContext>(0);
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
  enterRule(_localctx, 92, MavkaParser::RuleBody_element);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(700);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 72, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(686);
      if_();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(687);
      while_();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(688);
      interval();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(689);
      cycle();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(690);
      try_();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(691);
      throw_();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(692);
      assign();
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(693);
      set();
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(694);
      set_by_access();
      break;
    }

    case 10: {
      enterOuterAlt(_localctx, 10);
      setState(695);
      expr();
      break;
    }

    case 11: {
      enterOuterAlt(_localctx, 11);
      setState(696);
      return_body_element();
      break;
    }

    case 12: {
      enterOuterAlt(_localctx, 12);
      setState(697);
      give();
      break;
    }

    case 13: {
      enterOuterAlt(_localctx, 13);
      setState(698);
      take();
      break;
    }

    case 14: {
      enterOuterAlt(_localctx, 14);
      setState(699);
      nls();
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

//----------------- Return_body_elementContext ------------------------------------------------------------------

MavkaParser::Return_body_elementContext::Return_body_elementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MavkaParser::Return_body_elementContext::KW_RETURN() {
  return getToken(MavkaParser::KW_RETURN, 0);
}

MavkaParser::ExprContext* MavkaParser::Return_body_elementContext::expr() {
  return getRuleContext<MavkaParser::ExprContext>(0);
}


size_t MavkaParser::Return_body_elementContext::getRuleIndex() const {
  return MavkaParser::RuleReturn_body_element;
}

void MavkaParser::Return_body_elementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterReturn_body_element(this);
}

void MavkaParser::Return_body_elementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitReturn_body_element(this);
}


std::any MavkaParser::Return_body_elementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MavkaParserVisitor*>(visitor))
    return parserVisitor->visitReturn_body_element(this);
  else
    return visitor->visitChildren(this);
}

MavkaParser::Return_body_elementContext* MavkaParser::return_body_element() {
  Return_body_elementContext *_localctx = _tracker.createInstance<Return_body_elementContext>(_ctx, getState());
  enterRule(_localctx, 94, MavkaParser::RuleReturn_body_element);
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
    setState(702);
    match(MavkaParser::KW_RETURN);
    setState(704);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & -3303372734473396084) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 64)) & 235) != 0)) {
      setState(703);
      antlrcpp::downCast<Return_body_elementContext *>(_localctx)->rbl_value = expr();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Arithmetic_op_mulContext ------------------------------------------------------------------

MavkaParser::Arithmetic_op_mulContext::Arithmetic_op_mulContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> MavkaParser::Arithmetic_op_mulContext::MULTIPLY() {
  return getTokens(MavkaParser::MULTIPLY);
}

tree::TerminalNode* MavkaParser::Arithmetic_op_mulContext::MULTIPLY(size_t i) {
  return getToken(MavkaParser::MULTIPLY, i);
}

std::vector<tree::TerminalNode *> MavkaParser::Arithmetic_op_mulContext::DIVIDE() {
  return getTokens(MavkaParser::DIVIDE);
}

tree::TerminalNode* MavkaParser::Arithmetic_op_mulContext::DIVIDE(size_t i) {
  return getToken(MavkaParser::DIVIDE, i);
}

tree::TerminalNode* MavkaParser::Arithmetic_op_mulContext::MOD() {
  return getToken(MavkaParser::MOD, 0);
}


size_t MavkaParser::Arithmetic_op_mulContext::getRuleIndex() const {
  return MavkaParser::RuleArithmetic_op_mul;
}

void MavkaParser::Arithmetic_op_mulContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArithmetic_op_mul(this);
}

void MavkaParser::Arithmetic_op_mulContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArithmetic_op_mul(this);
}


std::any MavkaParser::Arithmetic_op_mulContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MavkaParserVisitor*>(visitor))
    return parserVisitor->visitArithmetic_op_mul(this);
  else
    return visitor->visitChildren(this);
}

MavkaParser::Arithmetic_op_mulContext* MavkaParser::arithmetic_op_mul() {
  Arithmetic_op_mulContext *_localctx = _tracker.createInstance<Arithmetic_op_mulContext>(_ctx, getState());
  enterRule(_localctx, 96, MavkaParser::RuleArithmetic_op_mul);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(713);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 74, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(706);
      match(MavkaParser::MULTIPLY);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(707);
      match(MavkaParser::DIVIDE);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(708);
      match(MavkaParser::MOD);
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(709);
      match(MavkaParser::DIVIDE);
      setState(710);
      match(MavkaParser::DIVIDE);
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(711);
      match(MavkaParser::MULTIPLY);
      setState(712);
      match(MavkaParser::MULTIPLY);
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

//----------------- Arithmetic_op_addContext ------------------------------------------------------------------

MavkaParser::Arithmetic_op_addContext::Arithmetic_op_addContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MavkaParser::Arithmetic_op_addContext::PLUS() {
  return getToken(MavkaParser::PLUS, 0);
}

tree::TerminalNode* MavkaParser::Arithmetic_op_addContext::MINUS() {
  return getToken(MavkaParser::MINUS, 0);
}


size_t MavkaParser::Arithmetic_op_addContext::getRuleIndex() const {
  return MavkaParser::RuleArithmetic_op_add;
}

void MavkaParser::Arithmetic_op_addContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArithmetic_op_add(this);
}

void MavkaParser::Arithmetic_op_addContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArithmetic_op_add(this);
}


std::any MavkaParser::Arithmetic_op_addContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MavkaParserVisitor*>(visitor))
    return parserVisitor->visitArithmetic_op_add(this);
  else
    return visitor->visitChildren(this);
}

MavkaParser::Arithmetic_op_addContext* MavkaParser::arithmetic_op_add() {
  Arithmetic_op_addContext *_localctx = _tracker.createInstance<Arithmetic_op_addContext>(_ctx, getState());
  enterRule(_localctx, 98, MavkaParser::RuleArithmetic_op_add);
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
    setState(715);
    _la = _input->LA(1);
    if (!(_la == MavkaParser::PLUS

    || _la == MavkaParser::MINUS)) {
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

//----------------- Bitwise_opContext ------------------------------------------------------------------

MavkaParser::Bitwise_opContext::Bitwise_opContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MavkaParser::Bitwise_opContext::POWER() {
  return getToken(MavkaParser::POWER, 0);
}

tree::TerminalNode* MavkaParser::Bitwise_opContext::OR() {
  return getToken(MavkaParser::OR, 0);
}

tree::TerminalNode* MavkaParser::Bitwise_opContext::AND() {
  return getToken(MavkaParser::AND, 0);
}

std::vector<tree::TerminalNode *> MavkaParser::Bitwise_opContext::LESSER() {
  return getTokens(MavkaParser::LESSER);
}

tree::TerminalNode* MavkaParser::Bitwise_opContext::LESSER(size_t i) {
  return getToken(MavkaParser::LESSER, i);
}

std::vector<tree::TerminalNode *> MavkaParser::Bitwise_opContext::GREATER() {
  return getTokens(MavkaParser::GREATER);
}

tree::TerminalNode* MavkaParser::Bitwise_opContext::GREATER(size_t i) {
  return getToken(MavkaParser::GREATER, i);
}


size_t MavkaParser::Bitwise_opContext::getRuleIndex() const {
  return MavkaParser::RuleBitwise_op;
}

void MavkaParser::Bitwise_opContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBitwise_op(this);
}

void MavkaParser::Bitwise_opContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBitwise_op(this);
}


std::any MavkaParser::Bitwise_opContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MavkaParserVisitor*>(visitor))
    return parserVisitor->visitBitwise_op(this);
  else
    return visitor->visitChildren(this);
}

MavkaParser::Bitwise_opContext* MavkaParser::bitwise_op() {
  Bitwise_opContext *_localctx = _tracker.createInstance<Bitwise_opContext>(_ctx, getState());
  enterRule(_localctx, 100, MavkaParser::RuleBitwise_op);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(727);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 75, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(717);
      match(MavkaParser::POWER);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(718);
      match(MavkaParser::OR);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(719);
      match(MavkaParser::AND);
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(720);
      match(MavkaParser::LESSER);
      setState(721);
      match(MavkaParser::LESSER);
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(722);
      match(MavkaParser::GREATER);
      setState(723);
      match(MavkaParser::GREATER);
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(724);
      match(MavkaParser::GREATER);
      setState(725);
      match(MavkaParser::GREATER);
      setState(726);
      match(MavkaParser::GREATER);
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

//----------------- Logical_opContext ------------------------------------------------------------------

MavkaParser::Logical_opContext::Logical_opContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MavkaParser::Logical_opContext::KW_AND() {
  return getToken(MavkaParser::KW_AND, 0);
}

tree::TerminalNode* MavkaParser::Logical_opContext::KW_OR() {
  return getToken(MavkaParser::KW_OR, 0);
}

std::vector<tree::TerminalNode *> MavkaParser::Logical_opContext::OR() {
  return getTokens(MavkaParser::OR);
}

tree::TerminalNode* MavkaParser::Logical_opContext::OR(size_t i) {
  return getToken(MavkaParser::OR, i);
}

std::vector<tree::TerminalNode *> MavkaParser::Logical_opContext::AND() {
  return getTokens(MavkaParser::AND);
}

tree::TerminalNode* MavkaParser::Logical_opContext::AND(size_t i) {
  return getToken(MavkaParser::AND, i);
}


size_t MavkaParser::Logical_opContext::getRuleIndex() const {
  return MavkaParser::RuleLogical_op;
}

void MavkaParser::Logical_opContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLogical_op(this);
}

void MavkaParser::Logical_opContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLogical_op(this);
}


std::any MavkaParser::Logical_opContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MavkaParserVisitor*>(visitor))
    return parserVisitor->visitLogical_op(this);
  else
    return visitor->visitChildren(this);
}

MavkaParser::Logical_opContext* MavkaParser::logical_op() {
  Logical_opContext *_localctx = _tracker.createInstance<Logical_opContext>(_ctx, getState());
  enterRule(_localctx, 102, MavkaParser::RuleLogical_op);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(735);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MavkaParser::KW_AND: {
        enterOuterAlt(_localctx, 1);
        setState(729);
        match(MavkaParser::KW_AND);
        break;
      }

      case MavkaParser::KW_OR: {
        enterOuterAlt(_localctx, 2);
        setState(730);
        match(MavkaParser::KW_OR);
        break;
      }

      case MavkaParser::OR: {
        enterOuterAlt(_localctx, 3);
        setState(731);
        match(MavkaParser::OR);
        setState(732);
        match(MavkaParser::OR);
        break;
      }

      case MavkaParser::AND: {
        enterOuterAlt(_localctx, 4);
        setState(733);
        match(MavkaParser::AND);
        setState(734);
        match(MavkaParser::AND);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Comparison_opContext ------------------------------------------------------------------

MavkaParser::Comparison_opContext::Comparison_opContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> MavkaParser::Comparison_opContext::EQUAL() {
  return getTokens(MavkaParser::EQUAL);
}

tree::TerminalNode* MavkaParser::Comparison_opContext::EQUAL(size_t i) {
  return getToken(MavkaParser::EQUAL, i);
}

tree::TerminalNode* MavkaParser::Comparison_opContext::EXCLAMATION() {
  return getToken(MavkaParser::EXCLAMATION, 0);
}

tree::TerminalNode* MavkaParser::Comparison_opContext::GREATER() {
  return getToken(MavkaParser::GREATER, 0);
}

tree::TerminalNode* MavkaParser::Comparison_opContext::LESSER() {
  return getToken(MavkaParser::LESSER, 0);
}

tree::TerminalNode* MavkaParser::Comparison_opContext::KW_IS() {
  return getToken(MavkaParser::KW_IS, 0);
}

tree::TerminalNode* MavkaParser::Comparison_opContext::KW_NOT() {
  return getToken(MavkaParser::KW_NOT, 0);
}

tree::TerminalNode* MavkaParser::Comparison_opContext::KW_EQ_WORD() {
  return getToken(MavkaParser::KW_EQ_WORD, 0);
}

tree::TerminalNode* MavkaParser::Comparison_opContext::KW_GR_WORD() {
  return getToken(MavkaParser::KW_GR_WORD, 0);
}

tree::TerminalNode* MavkaParser::Comparison_opContext::KW_SM_WORD() {
  return getToken(MavkaParser::KW_SM_WORD, 0);
}

tree::TerminalNode* MavkaParser::Comparison_opContext::KW_HAS_WORD() {
  return getToken(MavkaParser::KW_HAS_WORD, 0);
}


size_t MavkaParser::Comparison_opContext::getRuleIndex() const {
  return MavkaParser::RuleComparison_op;
}

void MavkaParser::Comparison_opContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterComparison_op(this);
}

void MavkaParser::Comparison_opContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitComparison_op(this);
}


std::any MavkaParser::Comparison_opContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MavkaParserVisitor*>(visitor))
    return parserVisitor->visitComparison_op(this);
  else
    return visitor->visitChildren(this);
}

MavkaParser::Comparison_opContext* MavkaParser::comparison_op() {
  Comparison_opContext *_localctx = _tracker.createInstance<Comparison_opContext>(_ctx, getState());
  enterRule(_localctx, 104, MavkaParser::RuleComparison_op);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(762);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 77, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(737);
      match(MavkaParser::EQUAL);
      setState(738);
      match(MavkaParser::EQUAL);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(739);
      match(MavkaParser::EXCLAMATION);
      setState(740);
      match(MavkaParser::EQUAL);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(741);
      match(MavkaParser::GREATER);
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(742);
      match(MavkaParser::LESSER);
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(743);
      match(MavkaParser::GREATER);
      setState(744);
      match(MavkaParser::EQUAL);
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(745);
      match(MavkaParser::LESSER);
      setState(746);
      match(MavkaParser::EQUAL);
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(747);
      match(MavkaParser::KW_IS);
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(748);
      match(MavkaParser::KW_NOT);
      setState(749);
      match(MavkaParser::KW_IS);
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(750);
      match(MavkaParser::KW_EQ_WORD);
      break;
    }

    case 10: {
      enterOuterAlt(_localctx, 10);
      setState(751);
      match(MavkaParser::KW_NOT);
      setState(752);
      match(MavkaParser::KW_EQ_WORD);
      break;
    }

    case 11: {
      enterOuterAlt(_localctx, 11);
      setState(753);
      match(MavkaParser::KW_GR_WORD);
      break;
    }

    case 12: {
      enterOuterAlt(_localctx, 12);
      setState(754);
      match(MavkaParser::KW_NOT);
      setState(755);
      match(MavkaParser::KW_GR_WORD);
      break;
    }

    case 13: {
      enterOuterAlt(_localctx, 13);
      setState(756);
      match(MavkaParser::KW_SM_WORD);
      break;
    }

    case 14: {
      enterOuterAlt(_localctx, 14);
      setState(757);
      match(MavkaParser::KW_NOT);
      setState(758);
      match(MavkaParser::KW_SM_WORD);
      break;
    }

    case 15: {
      enterOuterAlt(_localctx, 15);
      setState(759);
      match(MavkaParser::KW_HAS_WORD);
      break;
    }

    case 16: {
      enterOuterAlt(_localctx, 16);
      setState(760);
      match(MavkaParser::KW_NOT);
      setState(761);
      match(MavkaParser::KW_HAS_WORD);
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

//----------------- Assign_opContext ------------------------------------------------------------------

MavkaParser::Assign_opContext::Assign_opContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MavkaParser::Assign_opContext::KW_TSE() {
  return getToken(MavkaParser::KW_TSE, 0);
}

tree::TerminalNode* MavkaParser::Assign_opContext::EQUAL() {
  return getToken(MavkaParser::EQUAL, 0);
}

tree::TerminalNode* MavkaParser::Assign_opContext::PLUS() {
  return getToken(MavkaParser::PLUS, 0);
}

tree::TerminalNode* MavkaParser::Assign_opContext::MINUS() {
  return getToken(MavkaParser::MINUS, 0);
}

std::vector<tree::TerminalNode *> MavkaParser::Assign_opContext::MULTIPLY() {
  return getTokens(MavkaParser::MULTIPLY);
}

tree::TerminalNode* MavkaParser::Assign_opContext::MULTIPLY(size_t i) {
  return getToken(MavkaParser::MULTIPLY, i);
}

std::vector<tree::TerminalNode *> MavkaParser::Assign_opContext::DIVIDE() {
  return getTokens(MavkaParser::DIVIDE);
}

tree::TerminalNode* MavkaParser::Assign_opContext::DIVIDE(size_t i) {
  return getToken(MavkaParser::DIVIDE, i);
}

tree::TerminalNode* MavkaParser::Assign_opContext::MOD() {
  return getToken(MavkaParser::MOD, 0);
}

tree::TerminalNode* MavkaParser::Assign_opContext::POWER() {
  return getToken(MavkaParser::POWER, 0);
}

tree::TerminalNode* MavkaParser::Assign_opContext::OR() {
  return getToken(MavkaParser::OR, 0);
}

tree::TerminalNode* MavkaParser::Assign_opContext::AND() {
  return getToken(MavkaParser::AND, 0);
}

std::vector<tree::TerminalNode *> MavkaParser::Assign_opContext::LESSER() {
  return getTokens(MavkaParser::LESSER);
}

tree::TerminalNode* MavkaParser::Assign_opContext::LESSER(size_t i) {
  return getToken(MavkaParser::LESSER, i);
}

std::vector<tree::TerminalNode *> MavkaParser::Assign_opContext::GREATER() {
  return getTokens(MavkaParser::GREATER);
}

tree::TerminalNode* MavkaParser::Assign_opContext::GREATER(size_t i) {
  return getToken(MavkaParser::GREATER, i);
}


size_t MavkaParser::Assign_opContext::getRuleIndex() const {
  return MavkaParser::RuleAssign_op;
}

void MavkaParser::Assign_opContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAssign_op(this);
}

void MavkaParser::Assign_opContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MavkaParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAssign_op(this);
}


std::any MavkaParser::Assign_opContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MavkaParserVisitor*>(visitor))
    return parserVisitor->visitAssign_op(this);
  else
    return visitor->visitChildren(this);
}

MavkaParser::Assign_opContext* MavkaParser::assign_op() {
  Assign_opContext *_localctx = _tracker.createInstance<Assign_opContext>(_ctx, getState());
  enterRule(_localctx, 106, MavkaParser::RuleAssign_op);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(798);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 78, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(764);
      match(MavkaParser::KW_TSE);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(765);
      match(MavkaParser::EQUAL);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(766);
      match(MavkaParser::PLUS);
      setState(767);
      match(MavkaParser::EQUAL);
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(768);
      match(MavkaParser::MINUS);
      setState(769);
      match(MavkaParser::EQUAL);
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(770);
      match(MavkaParser::MULTIPLY);
      setState(771);
      match(MavkaParser::EQUAL);
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(772);
      match(MavkaParser::DIVIDE);
      setState(773);
      match(MavkaParser::EQUAL);
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(774);
      match(MavkaParser::MOD);
      setState(775);
      match(MavkaParser::EQUAL);
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(776);
      match(MavkaParser::DIVIDE);
      setState(777);
      match(MavkaParser::DIVIDE);
      setState(778);
      match(MavkaParser::EQUAL);
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(779);
      match(MavkaParser::MULTIPLY);
      setState(780);
      match(MavkaParser::MULTIPLY);
      setState(781);
      match(MavkaParser::EQUAL);
      break;
    }

    case 10: {
      enterOuterAlt(_localctx, 10);
      setState(782);
      match(MavkaParser::POWER);
      setState(783);
      match(MavkaParser::EQUAL);
      break;
    }

    case 11: {
      enterOuterAlt(_localctx, 11);
      setState(784);
      match(MavkaParser::OR);
      setState(785);
      match(MavkaParser::EQUAL);
      break;
    }

    case 12: {
      enterOuterAlt(_localctx, 12);
      setState(786);
      match(MavkaParser::AND);
      setState(787);
      match(MavkaParser::EQUAL);
      break;
    }

    case 13: {
      enterOuterAlt(_localctx, 13);
      setState(788);
      match(MavkaParser::LESSER);
      setState(789);
      match(MavkaParser::LESSER);
      setState(790);
      match(MavkaParser::EQUAL);
      break;
    }

    case 14: {
      enterOuterAlt(_localctx, 14);
      setState(791);
      match(MavkaParser::GREATER);
      setState(792);
      match(MavkaParser::GREATER);
      setState(793);
      match(MavkaParser::EQUAL);
      break;
    }

    case 15: {
      enterOuterAlt(_localctx, 15);
      setState(794);
      match(MavkaParser::GREATER);
      setState(795);
      match(MavkaParser::GREATER);
      setState(796);
      match(MavkaParser::GREATER);
      setState(797);
      match(MavkaParser::EQUAL);
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

bool MavkaParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 33: return particleSempred(antlrcpp::downCast<ParticleContext *>(context), predicateIndex);
    case 38: return operationSempred(antlrcpp::downCast<OperationContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool MavkaParser::particleSempred(ParticleContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 5);
    case 1: return precpred(_ctx, 4);
    case 2: return precpred(_ctx, 3);
    case 3: return precpred(_ctx, 2);

  default:
    break;
  }
  return true;
}

bool MavkaParser::operationSempred(OperationContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 4: return precpred(_ctx, 5);
    case 5: return precpred(_ctx, 4);
    case 6: return precpred(_ctx, 3);
    case 7: return precpred(_ctx, 2);
    case 8: return precpred(_ctx, 1);

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
