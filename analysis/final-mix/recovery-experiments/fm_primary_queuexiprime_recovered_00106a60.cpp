#include "../common/types.h"
typedef unsigned int Quad __attribute__((mode(TI)));
union ScriptCell{u32 word;f32 value;Quad*quad;u8*object;};
extern "C" u8 D_0033cc44;
extern "C" s32 D_0033cc40;
extern "C" u8 D_003a8090[],D_003a7f70[];

u8* func_00106a60(u8 input) { if (input!=0 || D_0033cc44!=0) return D_003a7f70+D_0033cc40*144; return D_003a8090+D_0033cc40*144; }
