#include "../common/types.h"
typedef unsigned int Quad __attribute__((mode(TI)));
union ScriptCell{u32 word;f32 value;Quad*quad;u8*object;};
u32 func_0018dbd8(u32*object){u32 flags=object[1];if(!(flags&2)){register u8 selected asm("$12")=0;if(flags&8)selected=1;else if(flags&16)selected=1;asm("":"+r"(selected));if(selected)return 1;if(!(flags&0x200))return 0;}return 1;}
