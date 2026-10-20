#include "../common/types.h"
extern "C" void func_0013a6d0(void);
extern "C" u32 func_00102c18(u32,u32,u32);
extern "C" void func_0014ae10(void);
extern "C" void func_0013a9e8(u32);
extern "C" void func_002bea00(void);
void func_0014a188(void) { func_0013a6d0(); register u32 amount asm("$5"), callback asm("$6"); asm("lui %0,1; lui %1,0x15; addiu %1,%1,-22480; ori %0,%0,0x24f8" : "=r"(amount),"=r"(callback)); register u32 first asm("$4"); asm("daddu %0,$0,$0" : "=r"(first) : "r"(amount),"r"(callback)); u32 object=func_00102c18(first,amount,callback); *(u8*)(object+4)=0; func_0014ae10(); func_0013a9e8(1); func_002bea00(); }
