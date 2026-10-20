#include "../common/types.h"

#include "../common/types.h"

extern "C" u32 func_001819c0(u32);
extern "C" u32 func_001bd590(u32);

u32 func_001bdcd0(u32 param_1)
{
  int iVar1;
  iVar1 = 0;
  if (func_001819c0(param_1) != 0) {
    if (func_001bd590(param_1) != 0) {
      iVar1 = 1;
    }
  }
  return iVar1;
}
