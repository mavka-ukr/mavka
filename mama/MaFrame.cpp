#include "mama.h"

namespace mavka::mama {
  MaFrame* MaFrame::call(MaScope* scope, MaCallFrameCallData* data) {
    return new MaFrame(FRAME_TYPE_CALL, scope, {.call = data});
  }

  MaFrame* MaFrame::module(MaScope* scope, MaFrameModuleData* data) {
    return new MaFrame(FRAME_TYPE_MODULE, scope, {.module = data});
  }
} // namespace mavka::mama