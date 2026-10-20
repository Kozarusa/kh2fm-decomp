#include "../common/types.h"
extern "C" s32 *func_00316d08(void);
s32 func_00305e20(void)
{
  register s32 *pointer asm("$2")=func_00316d08();
  register s32 value asm("$3");
  asm("addiu %0,$0,5" : "=r"(value) : "r"(pointer));
  *pointer=value;
  return -1;
}
