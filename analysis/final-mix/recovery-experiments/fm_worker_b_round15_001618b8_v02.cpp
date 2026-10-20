#include "../common/types.h"

extern "C" s32 func_00102c18(s32, u32, u32);
/* constants materialised through the relocation path (lui %hi / addiu %lo);
   the assembler pair is self-consistent, so the symbol sits at the TRUE address */
extern "C" char func_001eda78;
extern "C" char func_001edb30;

void func_001618b8(void)
{
  s32 iVar1;
  iVar1 = func_00102c18(1, 93000, (u32)(long)&func_001eda78);
  *(u32 *)(iVar1 + 0x30) = (u32)(long)&func_001edb30;
  return;
}
