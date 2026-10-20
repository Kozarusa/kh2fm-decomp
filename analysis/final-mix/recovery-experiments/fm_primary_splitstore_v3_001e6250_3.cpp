#include "../common/types.h"
extern "C" void func_001e60b0(void);
void func_001e6250(void) { func_001e60b0(); register u32 high asm("$15"); asm("lui %0,0x35" : "=r"(high)); register u32 base asm("$13"); asm volatile("addiu %0,%1,0x4690" : "=r"(base) : "r"(high)); *(u32*)(high+0x4690)=0; register s32 end asm("$14"); asm("addiu %0,$0,-1" : "=r"(end) : "r"(base)); *(s32*)(base+4)=end; }
