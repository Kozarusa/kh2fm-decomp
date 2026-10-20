#include "../common/types.h"

asm(".globl DAT_00351d28
	DAT_00351d28 = 0x351d38
");
extern "C" char DAT_00351d28;
extern "C" u64 func_001c23a8(u32,u32,u32,u32,u32,u32,u32);

void func_001c6ea0(u32 param_1, u32 param_2, u32 param_3, u32 param_4)
{
  func_001c23a8(param_1, param_2, 0, 1, 0, param_4, param_3);
  *(u32 *)param_1 = (u32)(long)&DAT_00351d28;
  return;
}
