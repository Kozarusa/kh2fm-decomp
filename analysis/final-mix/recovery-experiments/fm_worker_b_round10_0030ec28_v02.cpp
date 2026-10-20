#include "../common/types.h"

extern "C" u64 func_00305a30(...);

bool func_0030ec28(void)
{
  u64 uVar1;
  u64 uVar2;
  uVar1 = func_00305a30(4);
  uVar2 = 0x10000;
  return (uVar1 & uVar2) != 0;
}
