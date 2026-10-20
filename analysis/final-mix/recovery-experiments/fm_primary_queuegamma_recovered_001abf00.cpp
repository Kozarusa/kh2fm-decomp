#include "../common/types.h"
extern "C" u32 func_00239d10(s32*);

u32 func_001abf00(s32* p) {
s32 one=1; asm("" : "+r"(one));
u32 result=0;
if (*p==one) result=func_00239d10(p+1); return result; }
