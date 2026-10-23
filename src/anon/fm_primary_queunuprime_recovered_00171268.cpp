#include "../common/types.h"
struct FloatGuardRecord {u8*object;f32 value;};
extern "C" f32 D_0036c498;
extern "C" void func_001ad990(f32,f32,f32,u8*);

void func_00171268(FloatGuardRecord*record){u8*object=record->object;f32 value=record->value;if(!(*(u32*)(object+0x7f8)&16)){register f32*scale asm("$15")=&D_0036c498;asm("":"+r"(scale));func_001ad990(scale[0],0.0f,value,object+0x82c);}}
