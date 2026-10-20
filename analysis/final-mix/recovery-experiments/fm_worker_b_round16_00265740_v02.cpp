#include "../common/types.h"

extern "C" u32 func_00257770(void);
extern "C" void func_00139d78(u32);

u32 func_00265740(void)
{
  u32 uVar1;
  u32 uVar2;
  uVar1 = func_00257770();
  func_00139d78(uVar1);
  uVar2 = *(u32 *)(uVar1 + 0x184);
  return ((uVar2 ^ 0x8d) == 0);
}
