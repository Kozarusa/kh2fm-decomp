#include "../common/types.h"
extern "C" u32 func_0017df58(s32);
extern "C" u32 func_0019baa8(s32);
u32 func_001c9df8() { u32 i=0; while (true) { s32 value=func_0017df58(i); i++; if(value && func_0019baa8(value)) break; if(i>1) return 0; } return 1; }
