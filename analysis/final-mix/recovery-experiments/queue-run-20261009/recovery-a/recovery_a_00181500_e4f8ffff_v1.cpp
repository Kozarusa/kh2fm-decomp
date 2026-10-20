#include "../common/types.h"
extern "C" char D_0032d7c0;

bool func_00181500(s64 param_1)

{
  bool bVar1;
  u32 uVar2;
  
  uVar2 = (u32)param_1;
  bVar1 = false;
  if (param_1 != 0xffff) {
    bVar1 = (*(u32 *)(((uVar2 & 0x3ff) >> 5) * 4 + ((int)uVar2 >> 10) * 0x20 + (s32)(long)&D_0032d7c0) &
            1 << (uVar2 & 0x1f)) != 0;
  }
  return bVar1;
}
