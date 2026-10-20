#include "../common/types.h"
extern "C" s32* func_00316d08(void);
s32 func_00305ce0(void)
{
 s32* pointer=func_00316d08();
 register s32 value asm("$3");asm("addiu %0,$0,5" : "=r"(value));
 register u32 returnAddress asm("$31");asm("" : "=r"(returnAddress));
 asm volatile("sw %1,0(%2)" : "=m"(*pointer) : "r"(value),"r"(pointer),"r"(returnAddress));
 return -1;
}
