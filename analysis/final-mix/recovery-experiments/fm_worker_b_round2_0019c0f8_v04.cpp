#include "../common/types.h"
extern "C" s32 func_0019c090(s32);

bool func_0019c0f8(s32 param_1)
{
  bool bVar1;
  s32 lVar1;
  lVar1 = func_0019c090(0);
  if (lVar1 == 0) {
    bVar1 = false;
  }
  else if ((*(u32 *)(param_1 + 0x160) & 0x20) == 0) {
    bVar1 = (*(u32 *)(*(int *)(param_1 + 0xc) + 8) & 0x200) == 0;
  }
  else {
    bVar1 = true;
  }
  return bVar1;
}
