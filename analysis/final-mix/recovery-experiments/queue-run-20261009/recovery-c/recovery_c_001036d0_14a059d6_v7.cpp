#include "../common/types.h"
extern "C" u32 D_0032ba14,D_0032ba18;
extern "C" u8 D_0032ba30,D_01f18014;
extern "C" u32 func_00106178(u8*,s32);
void func_001036d0(u8*base,s32 bytes){if(!base)base=&D_01f18014;register s32 adjusted asm("$16")=bytes-0x68000;register u8*next asm("$17")=base+adjusted;asm("" : "+r"(adjusted),"+r"(next));D_0032ba14=func_00106178(base,adjusted);D_0032ba18=func_00106178(next,0x68000);D_0032ba30=1;}
