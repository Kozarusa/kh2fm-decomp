#include "../common/types.h"
extern "C" s32* func_00316d08(void);
s32 func_00305ce0(void)
{
 s32* pointer=func_00316d08();
 register s32 value asm("$3");asm("addiu %0,$0,5" : "=r"(value));
 *(u32*)pointer=value;
 return -1;
}
