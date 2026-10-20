#include "../common/types.h"
extern "C" void func_00308650(void);
extern "C" u32 D_003660dc;
void func_00308cd0(void) { func_00308650(); register u32 base asm("$2"); asm("lui %0,0x36" : "=r"(base)); *(volatile u32*)(base+0x60dc)=0; }
