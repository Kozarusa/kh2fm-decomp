#include "../common/types.h"
extern "C" u32 func_00305a30(u32);
bool func_0030ec28(void)
{
  u32 result=func_00305a30(4);
  register u32 mask asm("$3")=0x10000;
  asm volatile("" : "+r"(mask));
  return (result&mask)!=0;
}
