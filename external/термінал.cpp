extern "C" {
#include <locale.h>
#include <stdlib.h>
#include "isocline/include/isocline.h"

static void completer(ic_completion_env_t* cenv, const char* input) {}

static void highlighter(ic_highlight_env_t* henv,
                        const char* input,
                        void* arg) {}

void запустити_інтерактивний_термінал(void* data,
                                      void (*run)(void* data,
                                                  unsigned char* value)) {
  setlocale(LC_ALL, "C.UTF-8");
  ic_set_default_completer(&completer, NULL);
  ic_set_default_highlighter(highlighter, NULL);
  ic_enable_auto_tab(true);
  ic_set_prompt_marker(" ", nullptr);
  ic_set_history(nullptr, 200);
  unsigned char* input;
  while ((input = (unsigned char*)ic_readline("\e[0m—")) != nullptr) {
    run(data, input);
    free(input);
  }
}
}