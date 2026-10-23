#include "../common/types.h"

asm(".globl SYM_01e3bc40
	SYM_01e3bc40 = 0x1e3bc40
");
asm(".globl SYM_00375400
	SYM_00375400 = 0x375400
");
asm(".globl DAT_0034caf4
	DAT_0034caf4 = 0x34caf4
");
extern "C" char SYM_01e3bc40;
extern "C" char SYM_00375400;
extern "C" volatile u32 DAT_0034caf4;
extern "C" void func_002fee78(u32,u32,u32,u32);

u32 func_002beb90(u32 param_1, u32 param_2, u32 param_3, u32 param_4)
{
  u32 uVar1;
  uVar1 = (u32)(long)&SYM_01e3bc40;
  func_002fee78(uVar1, (u32)(long)&SYM_00375400, DAT_0034caf4, param_4);
  return uVar1;
}
