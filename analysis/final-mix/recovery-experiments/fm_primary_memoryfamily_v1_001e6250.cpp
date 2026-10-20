#include "../common/types.h"
// Complete original-memory/register recovery proposal.
extern "C" void func_001e60b0(void);
void func_001e6250(void) { func_001e60b0(); register u32 high asm("$15"); asm("lui %0,0x35" : "=r"(high)); register u32 base asm("$13")=high+0x4690; asm("" : "+r"(base)); *(u32*)(high+0x4690)=0; *(u32*)(base+4)=-1; }
