#include "../common/types.h"
extern "C" s32 func_0019c090(s32);

u32 func_0019c0f8(u32 param_1)
{
  u32 uVar1;
  uVar1 = func_0019c090(0);
  if (uVar1 == 0) {
    uVar1 = 0;
  }
  else if ((*(u32 *)(param_1 + 0x160) & 0x20) == 0) {
    uVar1 = (*(u32 *)(*(int *)(param_1 + 0xc) + 8) & 0x200) == 0;
  }
  return uVar1;
}
