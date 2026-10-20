#include "../common/types.h"
typedef unsigned int Quad __attribute__((mode(TI)));
union ScriptCell{u32 word;f32 value;Quad*quad;u8*object;};
extern "C" u32 D_0034dca0[2],D_0034dcb8[2];
void func_00170ee8(s32 mode,s32 priority){if(priority!=65535)return;if(mode==1){D_0034dca0[0]=0;D_0034dca0[1]=0;}if(priority==65535 && mode==1){D_0034dcb8[0]=0;D_0034dcb8[1]=0;}}
