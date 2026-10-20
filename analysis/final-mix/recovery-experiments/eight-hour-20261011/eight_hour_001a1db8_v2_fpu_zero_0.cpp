#include "../common/types.h"
extern "C" void func_001a1a20(u8*,s32,u32);
void func_001a1db8(u8* object){register f32 zero asm("$f0")=0.0f;asm("" : "+f"(zero));*(f32*)(object+444)=zero;*(f32*)(object+448)=zero;func_001a1a20(object,*(s32*)(object+388),0);}
