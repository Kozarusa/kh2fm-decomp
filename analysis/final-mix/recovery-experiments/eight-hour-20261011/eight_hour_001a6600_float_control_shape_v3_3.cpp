#include "../common/types.h"
extern "C" f32 func_001826e0();
extern "C" f32 D_0036d5c4;
u32 func_001a6600(f32 value){f32 boundary=func_001826e0();register f32*offset asm("$15")=&D_0036d5c4;asm("":"+r"(offset));u32 result=0;if(__builtin_expect(value<=boundary+*offset,1))result=1;return result;}

