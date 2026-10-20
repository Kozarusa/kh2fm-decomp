#include "../common/types.h"
extern "C" u32 D_0035f5d0;
extern "C" u32 func_00276c18(...);
u32 func_002a0360(void)
{
  u32 result;
  u32 flag;
  flag = (*(s8 *)D_0035f5d0 > 0);
  asm volatile (""); // why: preserves prior attempt scheduling
  result = func_00276c18();
  return flag != 0 ? 1 : result;
}
