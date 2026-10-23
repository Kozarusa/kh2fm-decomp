#include "../common/types.h"
extern "C" s32 D_0032b96c;
extern "C" u32 func_00102818(s64,u64,u64,u64,s32);

u32 func_00102c48(u64 a,u64 b,u64 c,s32 d){register u64 aa asm("$14")=a;register u64 bb asm("$13")=b;register u64 cc asm("$12")=c;register s32 dd asm("$8")=d;asm("" : "+r"(aa),"+r"(bb),"+r"(cc),"+r"(dd));return func_00102818(D_0032b96c,aa,bb,cc,dd);}
