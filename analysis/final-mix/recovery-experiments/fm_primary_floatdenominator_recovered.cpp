#include "../common/types.h"
// Complete-range proposal; independent original-byte verification required.
extern "C" s32 func_002fea18(void); extern "C" f32 D_0036a09c;

f32 func_00106558(f32 value) { s32 result=func_002fea18(); register f32* denominator asm("$15")=&D_0036a09c; asm("" : "+r"(denominator)); register f32 scale asm("$f1")=*denominator; return (value*(f32)result)/scale; }
