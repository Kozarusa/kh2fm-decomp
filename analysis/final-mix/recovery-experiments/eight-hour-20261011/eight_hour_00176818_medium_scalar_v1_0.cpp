#include "../common/types.h"
typedef unsigned int Quad __attribute__((mode(TI)));
union ScriptCell{u32 word;f32 value;Quad*quad;u8*object;};
extern "C" f32 D_0036c4c0;extern "C" void func_0017f540(u8*,s32,f32,f32);extern "C" void func_001842c0(u8*);
void func_00176818(u8*object){if(!(*(u32*)(object+0x168)&16)){register f32*coefficient asm("$15")=&D_0036c4c0;asm("":"+r"(coefficient));func_0017f540(object+0x140,4,*coefficient,0.0f);}func_001842c0(object);}
