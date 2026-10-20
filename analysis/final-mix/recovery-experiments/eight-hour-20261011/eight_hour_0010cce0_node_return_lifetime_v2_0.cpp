#include "../common/types.h"
typedef unsigned int Quad __attribute__((mode(TI)));
union ScriptCell{u32 word;f32 value;Quad*quad;u8*object;};
extern "C" u8*func_001b9bc8(u8*);extern "C" u32 func_00112d28(u8*);
u8*func_0010cce0(u8*node){for(;;){u8*current=func_001b9bc8(node);node=current;asm("":"+r"(node));if(!current)return node;if(func_00112d28(current))return node;}}
