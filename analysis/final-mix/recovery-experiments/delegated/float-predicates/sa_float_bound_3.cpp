#include "../common/types.h"
u32 func_0010f6f8(f32 fraction,u32 object) { register u32 result asm("$2")=0; if(!(*(u32*)(object+0x7f8)&4)) { u32 owner=*(u32*)(object+0x48c); if(owner) { register s32 bound asm("$14")=*(s32*)(owner+0x180); register s32 value asm("$15")=(s32)((f32)*(s32*)(owner+0x184)*fraction); asm("" : : "r"(bound),"r"(value)); register s32 test asm("$14")=bound<value; asm("" : "+r"(test)); if(test) result=1; else result=0; } } return result; }

