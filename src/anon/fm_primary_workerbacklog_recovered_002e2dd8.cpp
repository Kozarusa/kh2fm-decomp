#include "../common/types.h"

asm(".globl DAT_00361f60
	DAT_00361f60 = 0x361f60
");
extern "C" u32 DAT_00361f60;
extern "C" void func_002ceb08(void);

u32 func_002e2dd8(void)
{
  u32 *puVar1;
  u32 uVar1;
  puVar1 = (u32 *)(long)DAT_00361f60;
  if (__builtin_expect(puVar1 != 0, 1)) {
    uVar1 = *(u32 *)(puVar1 + 68);
    func_002ceb08();
    uVar1 = *(u32 *)(puVar1 + 68);
  } else {
    uVar1 = *(u32 *)(puVar1 + 68);
  }
  return uVar1 > 0;
}
