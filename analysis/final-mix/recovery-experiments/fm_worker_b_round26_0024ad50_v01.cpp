#include "../common/types.h"

extern "C" u32 func_001d56c8(int);
extern "C" u32 func_00276c18(void);

u32 func_0024ad50(void)
{
  int iVar1;
  u32 uVar1;
  iVar1 = 0;
  uVar1 = func_001d56c8(10);
  if ((*(u8 *)uVar1 < 2) && (func_00276c18() != 0)) {
    iVar1 = 1;
  }
  return iVar1;
}
