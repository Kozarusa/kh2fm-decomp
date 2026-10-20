#include "../common/types.h"
typedef unsigned int Quad __attribute__((mode(TI)));
union ScriptCell{u32 word;f32 value;Quad*quad;u8*object;};
extern "C" u32 D_00347d64;extern "C" void func_001398d0(s32);extern "C" void func_001397d8(s32);
void func_00138140(){func_001398d0(13);func_001397d8(13);volatile u32*group=(u32*)D_00347d64;group[13]=0;group[8]=1;group[12]=0;group=(u32*)D_00347d64;group[2672]=1;group[2674]=0;group[2673]=0;}
