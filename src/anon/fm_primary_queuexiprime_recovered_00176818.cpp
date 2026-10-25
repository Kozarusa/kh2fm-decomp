#include "../common/types.h"
typedef unsigned int Quad __attribute__((mode(TI)));
union ScriptCell{u32 word;f32 value;Quad*quad;u8*object;};
extern "C" void func_0017f540(u8*,s32,f32,f32);extern "C" void func_001842c0(u8*);

void func_00176818(u8*object){if(!(*(u32*)(object+0x168)&16)){func_0017f540(object+0x140,4,16.0f,0.0f);}func_001842c0(object);}
