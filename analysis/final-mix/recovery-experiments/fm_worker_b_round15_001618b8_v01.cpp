#include "../common/types.h"

extern "C" s32 func_00102c18(s32, u32, u32);
extern "C" char func_01dda78;
extern "C" char func_01ddb30;

void func_001618b8(void)
{
  s32 iVar1;
  iVar1 = func_00102c18(1, 93000, (u32)(long)&func_01dda78);
  *(u32 *)(iVar1 + 0x30) = (u32)(long)&func_01ddb30;
  return;
}
