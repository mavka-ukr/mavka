#include "mama.h"

namespace mavka::mama {
  MaFrame* MaFrame::call(MaScope* scope, MaCallFrameCallData* data) {
    return new MaFrame(FRAME_TYPE_CALL, scope, {.call = data});
  }

  MaFrame* MaFrame::module(MaScope* scope, MaFrameModuleData* data) {
    return new MaFrame(FRAME_TYPE_MODULE, scope, {.module = data});
  }

  MaFrame* MaFrame::try_(MaScope* scope, MaFrameTryData* data) {
    return new MaFrame(FRAME_TYPE_TRY, scope, {.try_ = data});
  }
} // namespace mavka::mama