#include "../common/types.h"
extern "C" s32 D_0032b91c;
extern "C" u8 D_0032ba28;
extern "C" void func_001037f8(void);
extern "C" void func_00102788(s64,s64,s64,s64);
void func_001037b8(void){register s32 high asm("$6")=0x50000;asm("" : "+r"(high));func_00102788(D_0032b91c,0,high|0x910,(s32)&func_001037f8);D_0032ba28=1;}
