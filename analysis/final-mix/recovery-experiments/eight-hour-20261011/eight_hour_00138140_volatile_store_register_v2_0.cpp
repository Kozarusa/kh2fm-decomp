#include "../common/types.h"
typedef unsigned int Quad __attribute__((mode(TI)));
union ScriptCell{u32 word;f32 value;Quad*quad;u8*object;};
extern "C" u32 D_00347d64;extern "C" void func_00138140(){func_001398d0(13);func_001397d8(13);volatile u32*group=(u32*)D_00347d64;u32 one=1;group[13]=0;group[8]=one;group[12]=0;register volatile u32*next asm("$14")=(u32*)D_00347d64;next[2672]=one;next[2674]=0;next[2673]=0;}
