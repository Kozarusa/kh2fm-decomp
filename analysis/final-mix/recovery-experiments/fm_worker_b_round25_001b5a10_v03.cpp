#include "../common/types.h"

#include "../common/types.h"

extern "C" volatile u32 DAT_01d58cb0;
asm(".globl DAT_01d58cb0
	DAT_01d58cb0 = 0x1d58cb0
");
extern "C" u32 func_001b5cb8(u32);

u32 func_001b5a10(void)
{
  volatile u32 *puVar1;
  u32 uVar1;
  uVar1 = 0;
  puVar1 = (volatile u32 *)(long)&DAT_01d58cb0;
  if (*puVar1 != 0) {
    func_001b5cb8((u32)(long)puVar1);
    if (uVar1 == 0) {
      uVar1 = (u32)(long)puVar1 + 24;
    }
    else {
      uVar1 = *(u32 *)((u8 *)(long)puVar1 + 12) + 128;
    }
  }
  return uVar1;
}
