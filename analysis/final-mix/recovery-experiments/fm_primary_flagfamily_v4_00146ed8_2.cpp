#include "../common/types.h"
// Provisional recovery; complete-range proof is required.

u32 func_00146ed8(u64 param_1,int param_2)

{
  u32 uVar1;
  u32 uVar2;
  
  register u32 raw asm("$15")=*(u8 *)(param_2+0xeb);
  asm volatile("" : "+r"(raw));
  if ((u8)raw == '\0') {
    uVar2 = *(u32 *)(param_2 + 0xf8);
  }
  else {
    uVar2 = *(u32 *)(param_2 + 0xf8);
    if ((-1 < (s8)raw) && ((uVar2 & 0x10) != 0)) {
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

