#include "../common/types.h"
extern "C" s32 func_001b7818(u64);
u8* func_00188fe0(u8*object,u64 key){s32 index=func_001b7818(key);if(!index)return 0;register s32 stride asm("$15")=276;asm("":"+r"(stride));return object+index*stride-276;}
