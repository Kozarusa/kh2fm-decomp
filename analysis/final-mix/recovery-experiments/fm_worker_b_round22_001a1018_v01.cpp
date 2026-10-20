#include "../common/types.h"

extern "C" u64 func_001a0e78(void);
extern "C" u64 func_001db5a8(u32);
extern "C" void func_001a0ee0(u64,u64);
u64 func_001a1018(u32 param_1)
{
  u64 uVar1;
  u64 uVar2;
  uVar1 = func_001a0e78();
  uVar2 = func_001db5a8(param_1);
  func_001a0ee0(uVar1, uVar2);
  return uVar1;
}
