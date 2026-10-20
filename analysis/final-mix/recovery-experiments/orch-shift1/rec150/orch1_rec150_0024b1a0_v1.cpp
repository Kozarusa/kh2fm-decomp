#include "../common/types.h"
extern "C" s32 func_0024ac88();
extern "C" u8 D_00371eb8[];
extern "C" u8 D_00371ea8[];
u8* func_0024b1a0(s32 value) {
 if(value==1 && func_0024ac88()) return D_00371eb8;
 return value*6+D_00371ea8;
}
