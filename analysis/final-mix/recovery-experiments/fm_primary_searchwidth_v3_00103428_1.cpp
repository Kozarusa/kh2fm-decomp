#include "../common/types.h"
extern "C" s16 D_00369d98[];
// Signed table search with original-width comparison.
u32 func_00103428(s64 value) { s32 index=0; if(D_00369d98[0]>=0) { s16* item=D_00369d98; do { if(value==*item) return 1; ++index; item=D_00369d98+index; } while(D_00369d98[index]>=0); } return 0; }
