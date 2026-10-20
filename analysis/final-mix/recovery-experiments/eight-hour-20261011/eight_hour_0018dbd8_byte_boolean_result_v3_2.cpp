#include "../common/types.h"
typedef unsigned int Quad __attribute__((mode(TI)));
union ScriptCell{u32 word;f32 value;Quad*quad;u8*object;};
u32 func_0018dbd8(u32*object){u32 flags=object[1];register u32 result asm("$2")=0;asm("":"+r"(result));if(!(flags&2)){register bool selected asm("$12")=0;if(flags&8)selected=1;else if(flags&16)selected=1;asm("":"+r"(selected));u8 test=selected;asm("":"+r"(test));if(test)result=1;else if(flags&0x200)result=1;return result;}result=1;return result;}
