#include "../common/types.h"

#include "../common/types.h"

extern "C" u32 func_00252110(void);
extern "C" u32 func_001a6d08(u32);
extern "C" char func_00372600;

u32 func_00252710(void)
{
  u32 uVar1;
  s32 iVar1;
  iVar1 = 0;
  uVar1 = func_00252110();
  uVar1 = uVar1 + (u32)(long)&func_00372600;
  uVar1 = *(u8 *)uVar1;
  if (uVar1 != 0) {
    iVar1 = (func_001a6d08(uVar1) != 0);
  }
  return iVar1;
}
