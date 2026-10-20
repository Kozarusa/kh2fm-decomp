#include "../common/types.h"
extern "C" void func_00308650(void);
void func_00308cd0(void)
{
 func_00308650();
 register u32 high asm("$2");asm("lui %0,0x36" : "=r"(high));
 u32* pointer=(u32*)(high+0x60dc);
 u32 zero=0;
 *(u32*)pointer=zero;
}
