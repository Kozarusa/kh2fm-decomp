#include "../common/types.h"
extern "C" u32 func_0028da70(u64,s32);
extern "C" s8 D_0035f24c;
extern "C" s32 D_0035f244;
extern "C" u8 D_00374050[];
u32 func_0027ead0() {
    register s32 object asm("$4") = D_0035f244; // why: original object load goes directly to a0
    asm("" : "+r"(object)); // why: retains original early object argument load
    register u8* pointer asm("$12") = D_00374050+D_0035f24c*6; // why: original table address is transported in t4
    return func_0028da70(object,*(s16*)(pointer+4));
}





