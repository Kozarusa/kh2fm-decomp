#include "../common/types.h"

extern "C" s32 func_00102c18(s32, u32, u32);
/* (lui a2,0x1e / addiu a2,a2,-9608) is the pair for 0x1dda78 and
   (lui t7,0x1e / addiu t7,t7,-9424) for 0x1ddb30 - the no-carry value, which is
   also what Ghidra prints. */
extern "C" char func_001dda78;
extern "C" char func_001ddb30;

void func_001618b8(void)
{
  s32 iVar1;
  iVar1 = func_00102c18(1, 93000, (u32)(long)&func_001dda78);
  *(u32 *)(iVar1 + 0x30) = (u32)(long)&func_001ddb30;
  return;
}
