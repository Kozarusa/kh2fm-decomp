#include "../common/types.h"
extern "C" u8* D_0035f3fc;
extern "C" u32 D_0035f410;
extern "C" u32 func_00139d78(...);
u32 func_0028cdb8(u32 index) {
    u32 offset=index*408;
    u32 result=func_00139d78(D_0035f3fc+offset);
    if (result != 0) {
        u8* object=(u8*)(offset+(u32)D_0035f3fc);
        register u32 table asm("$14")=*(u32*)object; // why: original loads vtable into t6.
        result=((u32(*)(u8*))(*(u32*)(table+20)))(object);
        D_0035f410 |= 1u << index;
    }
    return result;
}



