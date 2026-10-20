#include "../common/types.h"
// Complete-range proposal; independent original-byte verification required.
extern "C" s16 D_00369d98[]; u32 func_00103428(s32 value) { s32 index=0; if(D_00369d98[0]>=0) { s16* item=D_00369d98; do { if(value==*item) return 1; ++index; item=D_00369d98+index; } while(D_00369d98[index]>=0); } return 0; }
