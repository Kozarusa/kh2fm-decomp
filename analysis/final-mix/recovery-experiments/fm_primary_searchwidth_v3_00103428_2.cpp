#include "../common/types.h"
extern "C" s16 D_00369d98[];
// Signed table search with original-width comparison.
u32 func_00103428(s64 value) { s32 count=0; s32 offset=0; if(D_00369d98[0]>=0) { do { s16* item=(s16*)((u32)D_00369d98+offset); if(value==*item) return 1; ++count; offset=count*2; } while(*(s16*)((u32)D_00369d98+offset)>=0); } return 0; }
