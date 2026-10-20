#include "../common/types.h"
// Complete-range proposal; independent original-byte verification required.
extern "C" s16 D_00369da8[];
s64 func_001033d8(s64 value) { s64 result=-1; s32 index=0; if(D_00369da8[0]>=0) { s16* item=D_00369da8; do { if(*item==value) result=item[1]; ++index; item+=2; } while(*item>=0); } return result; }
