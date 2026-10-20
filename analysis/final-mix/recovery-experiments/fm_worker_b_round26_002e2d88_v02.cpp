#include "../common/types.h"

#include "../common/types.h"

extern "C" volatile u32 DAT_00361f60;
asm(".globl DAT_00361f60
	DAT_00361f60 = 0x361f60
");
extern "C" void func_002ceb08(void);

void func_002e2d88(u32 param_1, u32 param_2)
{
  volatile u32 *puVar1;
  volatile u8 *puVar2;
  param_2 = param_2 & 0xff;
  puVar1 = (volatile u32 *)(long)DAT_00361f60;
  puVar2 = (volatile u8 *)(long)puVar1;
  if (puVar1 != (volatile u32 *)0) {
    func_002ceb08();
  }
  puVar2[280] = param_2;
  puVar1[69] = param_1;
  return;
}
