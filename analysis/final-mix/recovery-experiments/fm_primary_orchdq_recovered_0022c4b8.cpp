#include "../common/types.h"
extern "C" u32 func_002fee78(...);
extern "C" s32 func_002ff3fc(...);
extern "C" s32 D_0033caf4;
extern "C" u8 D_00371190[];
extern "C" u8 D_01dad960[];

u8* func_0022c4b8(u32 value) {
    u8* pointer = D_01dad960;
    func_002fee78(pointer, D_00371190, D_0033caf4, value);
    func_002ff3fc(pointer);
    return pointer;
}
