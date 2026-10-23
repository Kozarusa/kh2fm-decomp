#include "../common/types.h"
extern "C" u32 func_0017df58(s32);
extern "C" u32 func_0019baa8(s32);

u32 func_001c9df8() { s32 i=0; u32 result; while(true) { s32 value=func_0017df58(i); i++; if(value && func_0019baa8(value)) { result=1; break; } if(i>1) { result=0; break; }} asm("" : "+r"(result)); return result; }
