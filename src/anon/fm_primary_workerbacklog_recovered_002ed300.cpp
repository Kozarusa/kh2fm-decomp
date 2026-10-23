#include "../common/types.h"

extern "C" void func_001c23a8(u32,u32,u32,u32,u32,u32,u32);
extern "C" u32 DAT_00363748;
asm(".globl DAT_00363748
	DAT_00363748 = 0x363748
");
extern "C" char func_00363758;

void func_002ed300(u32 param_1, u32 param_2, u32 param_3)
{
  func_001c23a8(param_1, param_2, 0, 1, 0, 128, param_3);
  *(u32 *)param_1 = (u32)(long)&func_00363758;
  DAT_00363748 = param_1;
  return;
}
