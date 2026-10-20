#include "../common/types.h"
extern "C" u32 func_00239d10(s32*);
u32 func_001abf00(s32* object) { s32* next=object+1; register u32 one asm("$15")=1; asm volatile("" : "+r"(one)); u32 result=0; if(*object==one) result=func_00239d10(next); return result; }
