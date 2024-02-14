#include "mama.h"

namespace mavka::mama {
  MaCallFrame* MaCallFrame::call(MaScope* scope, MaCallFrameCallArgs* data) {
    return new MaCallFrame(CF_TYPE_CALL, scope, {.call = data});
  }

  MaCallFrame* MaCallFrame::module(MaScope* scope,
                                   MaCallFrameModuleArgs* data) {
    return new MaCallFrame(CF_TYPE_MODULE, scope, {.module = data});
  }

  MaCallFrame* MaCallFrame::try_(MaScope* scope, MaCallFrameTryArgs* data) {
    return new MaCallFrame(CF_TYPE_TRY, scope, {.try_ = data});
  }
} // namespace mavka::mama