#include "../common/types.h"

#include "../common/types.h"

extern "C" volatile u32 DAT_00361f60;
asm(".globl DAT_00361f60
	DAT_00361f60 = 0x361f60
");
extern "C" void func_002ceb08(void);

void func_002e2d88(u32 param_1, u32 param_2)
{
  u32 *puVar1;
  param_2 = param_2 & 0xff;
  puVar1 = (u32 *)(long)DAT_00361f60;
  if (puVar1 != (u32 *)0) {
    func_002ceb08();
  }
  *(u8 *)((u8 *)puVar1 + 280) = param_2;
  *(u32 *)((u8 *)puVar1 + 276) = param_1;
  return;
}
