#include "../common/types.h"

extern "C" s32 D_0032bb1c;
extern "C" s32 func_00170b30();
extern "C" s32 func_00106178(s32, s32);
extern "C" s32 func_001091c8(s32, s32, s32);

s32 func_00105370(s32 size, s32 flags)
{
  s32 base = func_00170b30();
  base = func_00106178(base, size);
  D_0032bb1c = base;
  return func_001091c8(base, 0x100, flags);
}
