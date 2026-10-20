#include "../common/types.h"
extern "C" u64 func_00227120(...);
extern "C" u64 func_002ff538(...);
extern "C" char D_00370cd8;
extern "C" char D_00370ce8;
extern "C" char D_00370cf8;
extern "C" char D_00370d08;
extern "C" char D_00370d18;

u32 func_00224c20(void)

{
  u64 uVar1;
  s64 lVar2;
  u32 uVar3;
  
  uVar1 = func_00227120();
  lVar2 = func_002ff538(uVar1,(s32)(long)&D_00370cd8,0xc);
  uVar3 = 1;
  if (lVar2 != 0) {
    uVar1 = func_00227120();
    lVar2 = func_002ff538(uVar1,(s32)(long)&D_00370ce8,0xc);
    uVar3 = 2;
    if (lVar2 != 0) {
      uVar1 = func_00227120();
      lVar2 = func_002ff538(uVar1,(s32)(long)&D_00370cf8,0xc);
      uVar3 = 3;
      if (lVar2 != 0) {
        uVar1 = func_00227120();
        lVar2 = func_002ff538(uVar1,(s32)(long)&D_00370d08,0xc);
        uVar3 = 4;
        if (lVar2 != 0) {
          uVar1 = func_00227120();
          lVar2 = func_002ff538(uVar1,(s32)(long)&D_00370d18,0xc);
          uVar3 = 5;
          if (lVar2 != 0) {
            uVar3 = 0xffffffff;
          }
        }
      }
    }
  }
  return uVar3;
}
