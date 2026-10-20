#include "../common/types.h"
// Complete-range register/address correction proposal.
extern "C" void func_00308650(void); extern "C" u32 D_003660dc;
void func_00308cd0(void) { func_00308650(); register u32* destination asm("$2")=&D_003660dc; asm("lui %0,%%hi(D_003660dc)" : "=r"(destination)); *(u32*)((u32)destination+0x60dc)=0; }
