#include "../common/types.h"
extern "C" s32 func_0019c090(...);

u32 func_0019c0f8(s32 param_1)
{
  u32 lVar1;
  s32 lVar2;
  lVar1 = 0;
  lVar2 = func_0019c090();
  if (lVar2 != 0) {
    if ((*(u32 *)(param_1 + 0x160) & 0x20) == 0) {
      lVar1 = (*(u32 *)(*(int *)(param_1 + 0xc) + 8) & 0x200) == 0;
    }
  }
  return lVar1;
}
