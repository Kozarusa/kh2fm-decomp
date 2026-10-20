#include "../common/types.h"
extern "C" u32 func_00257770(void);
extern "C" u32 func_00139d78(...);
extern "C" u32 func_00287bc0(void);
extern "C" s32 func_0027af58();
extern "C" u32 func_0028da70(u64,s32);
extern "C" u8 D_00373e30[];
u32 func_0027aa10() {
    register s32 object asm("$16") = func_00257770(); // why: original preserves list buffer in s0 across calls
    asm("" : "+r"(object)); // why: retains original persistent list buffer transport
    func_00139d78(object);
    u32 mode = func_00287bc0();
    s32 value = 231;
    if (mode != 16) {
        s32 index = func_0027af58();
        value = *(s16*)(D_00373e30 + index*6 + 4);
    }
    return func_0028da70(object,value);
}



