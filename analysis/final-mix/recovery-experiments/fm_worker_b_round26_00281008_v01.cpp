#include "../common/types.h"

#include "../common/types.h"

extern "C" void func_001a17c8(u32);

void func_00281008(u32 param_1)
{
  u32 *puVar1;
  int iVar1;
  puVar1 = (u32 *)((u8 *)param_1 + 20);
  iVar1 = 3;
  do {
    puVar1 = (u32 *)((u8 *)puVar1 + 20);
    if (*puVar1 != 0) {
      func_001a17c8(*puVar1);
    }
    iVar1 = iVar1 - 1;
  } while (iVar1 >= 0);
  return;
}
