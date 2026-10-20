#include "../common/types.h"
// Complete-range proposal; independent original-byte verification required.
extern "C" s16 D_00369da8[]; s16 func_001033d8(s16 value) { s16 result=-1; s32 index=0; if(D_00369da8[0]>=0) { s16* item=D_00369da8; do { if(*item==value) result=item[1]; ++index; item=D_00369da8+index*2; } while(D_00369da8[index*2]>=0); } return result; }
