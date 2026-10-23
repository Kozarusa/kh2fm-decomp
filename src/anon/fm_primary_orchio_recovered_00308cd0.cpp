#include "../common/types.h"
extern "C" void func_00308650(void);
extern "C" u32 D_003660dc;

u32 func_00308cd0(void)
{
 func_00308650();
 register u32 base asm("$2") = 0x00360000; // why: original global-address high part uses v0; C replaces forbidden emitted lui asm
 *(u32*)(base+0x60dc)=0;
 return base;
}
