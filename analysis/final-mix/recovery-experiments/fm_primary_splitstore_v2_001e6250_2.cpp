#include "../common/types.h"
extern "C" void func_001e60b0(void);
void func_001e6250(void) { func_001e60b0(); register u32 high asm("$15"); asm("lui %0,0x35" : "=r"(high)); register u32 base asm("$13"); asm("addiu %0,%2,0x4690; sw $0,0x4690(%2)" : "=r"(base), "=m"(*(u32*)(high+0x4690)) : "r"(high) : "memory"); register s32 end asm("$14")=-1; asm("" : : "r"(end)); *(s32*)(base+4)=end; }
