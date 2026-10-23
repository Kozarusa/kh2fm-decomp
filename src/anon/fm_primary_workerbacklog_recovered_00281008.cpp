#include "../common/types.h"

// Preserve original registry aliases.
void func_00281008(u32 param_1) asm("_Z13func_00281008Pv");

#include "../common/types.h"

extern "C" void func_001a17c8(u32);

void func_00281008(u32 param_1)
{
  u32 *puVar1;
  u32 uVar1;
  int iVar1;
  puVar1 = (u32 *)((u8 *)param_1 + 20);
  iVar1 = 3;
  do {
    uVar1 = *puVar1;
    puVar1 = (u32 *)((u8 *)puVar1 + 20);
    if (uVar1 != 0) {
      func_001a17c8(uVar1);
    }
    iVar1 = iVar1 - 1;
  } while (iVar1 >= 0);
  return;
}
