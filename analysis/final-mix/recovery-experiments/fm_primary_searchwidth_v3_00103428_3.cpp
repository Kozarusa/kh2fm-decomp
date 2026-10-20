#include "../common/types.h"
extern "C" s16 D_00369d98[];
// Signed table search with original-width comparison.
u32 func_00103428(s32 value) { s32 count=0; s32 offset=0; s64 entry=D_00369d98[0]; if(entry>=0) { do { s16* item=(s16*)((u32)D_00369d98+offset); entry=*item; asm("" : "+r"(entry)); if(value==entry) return 1; ++count; offset=count*2; entry=*(s16*)((u32)D_00369d98+offset); } while(entry>=0); } return 0; }
