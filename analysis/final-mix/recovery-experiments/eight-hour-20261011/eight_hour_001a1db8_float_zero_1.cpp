#include "../common/types.h"
extern "C" void func_001a1a20(u8*,s32,u32);
void func_001a1db8(u8* object){*(volatile f32*)(object+444)=0.0f;*(volatile f32*)(object+448)=0.0f;func_001a1a20(object,*(s32*)(object+388),0);}
