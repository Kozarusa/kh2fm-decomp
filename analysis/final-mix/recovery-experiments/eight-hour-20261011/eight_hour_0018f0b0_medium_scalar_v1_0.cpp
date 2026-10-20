#include "../common/types.h"
typedef unsigned int Quad __attribute__((mode(TI)));
union ScriptCell{u32 word;f32 value;Quad*quad;u8*object;};
extern "C" f32 D_0036ccd8,D_01c60cd0;extern "C" u32 D_01c60cd8[2];
void func_0018f0b0(s32 mode,s32 priority){if(priority!=65535)return;if(mode==1){register f32*value asm("$15")=&D_0036ccd8;asm("":"+r"(value));D_01c60cd0=*value;}if(priority==65535 && mode==1){D_01c60cd8[0]=0;D_01c60cd8[1]=0;}}
