#include "../common/types.h"
extern "C" u32 func_00239d10(s32*);
u32 func_001abf00(s32* p) {
s32 one=1; asm("" : "+r"(one));
register u32 result asm("$2")=0; asm("" : "+r"(result));
if (*p==one) result=func_00239d10(p+1); return result; }
