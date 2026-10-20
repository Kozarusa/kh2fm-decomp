#include "../common/types.h"
typedef unsigned int Quad __attribute__((mode(TI)));
union ScriptCell{u32 word;f32 value;Quad*quad;u8*object;};
extern "C" void func_0011c4b0(u32*,u8*,u32);extern "C" void func_0011c4e8(u32*,u8*,u32,u32,u32,u32,f32);
void func_00161598(ScriptCell*object){u8*child=object[17].object;u8*block=child+512;u32 state=object[18].word;u32*receiver=*(u32**)(child+448);if(state)func_0011c4e8(receiver,block,state,0,0,0,object[19].value);else func_0011c4b0(receiver,block,state);}
