#include "../common/types.h"
// Provisional compiler proposal; types remain subject to original-byte proof.
extern "C" u8 D_0034a458;

void func_0014fba0(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  u16 *puVar4;
  
  iVar1 = 0;
  asm("" : "+r"(iVar1));
  iVar3 = iVar1*2;
  while( true ) {
    iVar2 = 2;
    puVar4 = (u16 *)(&D_0034a458 + iVar1 * 6);
    do {
      *puVar4 = 0;
      iVar2 = iVar2 + -1;
      puVar4 = puVar4 + 1;
    } while (-1 < iVar2);
    iVar1 = iVar1 + 1;
    if (0x12 < iVar1) break;
    asm("" : "+r"(iVar1));
  }
  return;
}

