#ifndef MA_FRAME_H
#define MA_FRAME_H

enum MaArgsType { MA_ARGS_NAMED, MA_ARGS_POSITIONED };

struct MaArgs {
  MaArgsType type;
  std::unordered_map<std::string, MaCell> named;
  std::vector<MaCell> positioned;
};

#define ARGS_SET(a, name, value) (a).v.args->named.insert({(name), (value)});
#define ARGS_PUSH(a, value) (a).v.args->positioned.push_back((value));
#define ARGS_GET(args, index, name, default_value)                          \
  ((args)->type == MA_ARGS_NAMED                                            \
       ? ((args)->named.contains((name)) ? (args)->named[(name)]            \
                                         : (default_value))                 \
       : ((args)->positioned.size() > (index) ? (args)->positioned[(index)] \
                                              : (default_value)))

struct MaFrame {
  MaScope* scope;
  MaObject* object;
  MaInstructionLocation* location;
  std::stack<MaCell> stack;
};

#endif // MA_FRAME_H