#include "../common/types.h"
extern "C" s32 func_001afee8(u32,u32);

s32 func_001b0148(u32 unused,u32 param_2,s32 param_3,u32 param_4) {
 register u32 first asm("$4") = param_2;
 register u32 second asm("$5") = param_4;
 asm volatile("" : "+r"(first), "+r"(second));
 if (param_3 < 0) { if(param_3 == -3) return func_001afee8(first,second); return -1; }
 return param_3;
}
