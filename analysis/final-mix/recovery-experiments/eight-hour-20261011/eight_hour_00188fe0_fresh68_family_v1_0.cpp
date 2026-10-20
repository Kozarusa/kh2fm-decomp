#include "../common/types.h"
extern "C" s32 func_001b7818(u64);
u8* func_00188fe0(u8*object,u64 key){s32 index=func_001b7818(key);if(!index)return 0;return object+index*276-276;}
