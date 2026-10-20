#include "../common/types.h"
extern "C" void func_00308650(void);
void func_00308cd0(void)
{
 func_00308650();
 register u32 high asm("$2");asm("lui %0,0x36" : "=r"(high));
 u32* pointer=(u32*)(high+0x60dc);
 u32 zero=0;
 register u32 returnAddress asm("$31");asm("" : "=r"(returnAddress));
 asm ("sw %1,0(%2)" : "=m"(*pointer) : "r"(zero),"r"(pointer),"r"(returnAddress));
}
