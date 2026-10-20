#include "../common/types.h"

asm(".globl DAT_001d58cb0
	DAT_001d58cb0 = 0x1d58cb0
");
extern "C" char func_001b4340;
extern "C" char func_001b43e0;
extern "C" u32 func_00102c18(u32, u32, u32);
extern "C" u32 DAT_001d58cb0;

u32 func_001b4300(void)
{
  u32 iVar1;
  DAT_001d58cb0 = 0;
  iVar1 = func_00102c18(1, 20600, (u32)(long)&func_001b4340);
  *(u32 *)((u8 *)iVar1 + 48) = (u32)(long)&func_001b43e0;
  return iVar1;
}
