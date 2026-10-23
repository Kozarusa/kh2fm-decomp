#include "../common/types.h"
extern "C" s32 func_001b7818(u64);

// Preserve original registry aliases.
u32 func_00188fe0(u32 object,u64 key) asm("_Z16ctarget_00188fe0jjjj");

u32 func_00188fe0(u32 object,u64 key){s32 index=func_001b7818(key);if(index)return object+index*276-276;return 0;}
