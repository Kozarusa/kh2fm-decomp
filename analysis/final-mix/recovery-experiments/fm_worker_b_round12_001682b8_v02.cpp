#include "../common/types.h"

extern "C" u32 func_001adf00(void);
extern "C" void func_003058a0(u32);

u32 func_001682b8(void)
{
  s32 iVar1;
  iVar1 = func_001adf00();
  func_003058a0(0);
  return iVar1;
}
