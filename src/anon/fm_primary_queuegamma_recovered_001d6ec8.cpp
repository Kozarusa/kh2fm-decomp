#include "../common/types.h"
extern "C" u32 func_001d6cc8(s64);
extern "C" u8 func_001a3570(...);

int func_001d6ec8(void)

{
  s32 lVar1;
  s32 lVar2;
  int iVar3;
  
  lVar2 = 0;
  iVar3 = 2;
  while (lVar2 = func_001d6cc8(lVar2), lVar2 != 0) {
    lVar1 = func_001a3570(*(u16 *)((int)lVar2 + 2));
    iVar3 = iVar3 + (u32)(0 < lVar1);
  }
  if (iVar3 == 6) {
    iVar3 = iVar3 + 1;
  }
  return iVar3;
}
