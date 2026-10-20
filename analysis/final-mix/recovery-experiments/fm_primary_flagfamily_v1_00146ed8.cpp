#include "../common/types.h"
// Provisional recovery; complete-range proof is required.

u32 func_00146ed8(u64 param_1,int param_2)

{
  u32 uVar1;
  u32 uVar2;
  
  if (*(char *)(param_2 + 0xeb) == '\0') {
    uVar2 = *(u32 *)(param_2 + 0xf8);
  }
  else {
    uVar2 = *(u32 *)(param_2 + 0xf8);
    if ((-1 < *(char *)(param_2 + 0xeb)) && ((uVar2 & 0x10) != 0)) {
      uVar1 = 1;
      uVar2 = uVar2 & 0xfffff7ff;
      goto LAB_00146f0c;
    }
  }
  uVar2 = uVar2 | 0x800;
  uVar1 = 0;
LAB_00146f0c:
  *(u32 *)(param_2 + 0xf8) = uVar2;
  return uVar1;
}

