#include "mama.h"

namespace mavka::mama {
  MaFrame* MaFrame::call(MaScope* scope, MaCallFrameCallArgs* data) {
    return new MaFrame(FRAME_TYPE_CALL, scope, {.call = data});
  }

  MaFrame* MaFrame::module(MaScope* scope, MaFrameModuleArgs* data) {
    return new MaFrame(FRAME_TYPE_MODULE, scope, {.module = data});
  }

  MaFrame* MaFrame::try_(MaScope* scope, MaFrameTryArgs* data) {
    return new MaFrame(FRAME_TYPE_TRY, scope, {.try_ = data});
  }
} // namespace mavka::mama