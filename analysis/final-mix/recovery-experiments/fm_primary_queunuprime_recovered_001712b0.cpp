#include "../common/types.h"
struct FloatGuardRecord {u8*object;f32 value;};
extern "C" f32 D_0036c49c;
extern "C" void func_001ad990(f32,f32,f32,u8*);

void func_001712b0(FloatGuardRecord*record){u8*object=record->object;f32 value=record->value;if(!(*(u32*)(object+0x7f8)&16)){register f32*scale asm("$15")=&D_0036c49c;asm("":"+r"(scale));func_001ad990(0.0f,scale[0],value,object+0x82c);}}
