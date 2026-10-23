#include "../common/types.h"

s32 func_0028ac98(s16*p,s32 i){register s32 index asm("$14")=i*8;register s32 base asm("$15")=(i==*p?*(s32*)((char*)p+0x30):*(s32*)((char*)p+0x2c)); register s32 result asm("$2");asm("addu %0,%1,%2" : "=r"(result) : "r"(base),"r"(index));return result;}
