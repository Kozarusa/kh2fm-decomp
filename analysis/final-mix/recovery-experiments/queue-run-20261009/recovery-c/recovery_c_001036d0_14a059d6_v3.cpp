#include "../common/types.h"
extern "C" u32 D_0032ba14,D_0032ba18;
extern "C" u8 D_0032ba30;
extern "C" u32 func_00106178(u8*,s32);
void func_001036d0(u8*base,s32 bytes){if(!base)base=(u8*)0x1f18014;bytes-=0x68000;D_0032ba14=func_00106178(base,bytes);D_0032ba18=func_00106178(base+bytes,0x68000);D_0032ba30=1;}
