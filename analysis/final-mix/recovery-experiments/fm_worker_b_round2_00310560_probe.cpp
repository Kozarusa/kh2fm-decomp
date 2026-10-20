#include "../common/types.h"

// Toolchain fingerprint test: func_00310560 has the same body shape as the
// round-2 target 00310620 (same callees, same control flow, one different jal
// target). If the pinned compiler reproduces it byte-exactly apart from the
// 16-byte frame stride, the stride is a compiler-version artefact rather than
// a recoverable source construct.
extern "C" bool func_0030edb0(...);
extern "C" bool func_0030ee00(...);
extern "C" s32 func_00310518(...);

u32 func_00310560(u32 param_1)
{
  u32 uVar1;
  bool lVar1;
  lVar1 = func_0030edb0();
  uVar1 = func_00310518(param_1);
  if (lVar1 != 0) {
    func_0030ee00();
  }
  return uVar1;
}
