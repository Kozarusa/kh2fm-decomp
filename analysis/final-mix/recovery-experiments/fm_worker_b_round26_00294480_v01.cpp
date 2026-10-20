#include "../common/types.h"

#include "../common/types.h"

extern "C" u32 func_00181500(u32);
extern "C" u32 func_001a3570(u32);

u32 func_00294480(u32 param_1)
{
  int iVar1;
  u32 uVar1;
  if (*(u8 *)((u8 *)param_1 + 6) == 2) {
    uVar1 = func_001a3570(*(u16 *)(param_1));
    iVar1 = (0 < uVar1);
  }
  else {
    uVar1 = func_00181500(*(u16 *)(param_1));
    iVar1 = (uVar1 != 0);
  }
  return iVar1;
}
