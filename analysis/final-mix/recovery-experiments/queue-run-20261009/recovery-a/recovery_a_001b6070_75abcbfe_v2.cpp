#include "../common/types.h"
extern "C" u32 func_001a8bf8(s32,s32);
extern "C" bool func_001c8db8(void*,s64);
extern "C" s32 func_001a8bd0(u64);
extern "C" u32 func_001b58a8(void);
extern "C" char D_00351ec0;

bool func_001b6070(void)

{
  s64 lVar1;
  u64 uVar2;
  bool bVar3;
  
  lVar1 = func_001b58a8();
  bVar3 = false;
  if (lVar1 == 0) {
    bVar3 = false;
    uVar2 = func_001a8bd0(0xffffffffffffffff);
    lVar1 = func_001a8bf8(uVar2,3);
    if (lVar1 != 0x12) {
      lVar1 = func_001c8db8((s32)(long)&D_00351ec0,0);
      bVar3 = lVar1 == 0;
    }
  }
  return bVar3;
}
