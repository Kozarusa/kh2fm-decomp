#include "../common/types.h"
extern "C" s32 func_002282f0(s16);
extern "C" void func_00102c18(u32,u32,u32);
void func_0022dd40(u32 object) { s32 result=func_002282f0(*(s16*)(object+4)); register u32 flag asm("$4"), high asm("$5"), address asm("$6"); asm("lui %1,1; lui %2,0x23; addiu %0,$0,1; addiu %2,%2,-9168" : "=r"(flag),"=r"(high),"=r"(address)); if(!result) func_00102c18(flag,high|0x7318,address); }
