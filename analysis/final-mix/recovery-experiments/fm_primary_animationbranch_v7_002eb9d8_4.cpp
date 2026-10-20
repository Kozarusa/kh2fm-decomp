#include "../common/types.h"
extern "C" void func_002eb6f8(f32,u32,s32);
// Conditional animation-call ordering experiment.
void func_002eb9d8(f32 incoming,u64 unused,u32 object,s32 value) { register u32 callObject asm("$4")=object; register s32 callValue asm("$5")=value; asm("" : "+r"(callObject), "+r"(callValue)); object=callObject; value=callValue; u32 flags=*(u32*)(object+0x160); register u32 animation asm("$13")=object+0x140; if(flags&4) goto compare; if(!(flags&0x10)) return; if(value==0xfc) return; compare: asm("" : "+r"(animation)); if(*(s32*)(animation+0x14)!=value) func_002eb6f8(incoming,object,value); }
