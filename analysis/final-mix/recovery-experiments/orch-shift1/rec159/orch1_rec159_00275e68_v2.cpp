#include "../common/types.h"
extern "C" u32 func_00139d78(...);
extern "C" u32 func_00192048(u64);
extern "C" u8* D_0035f20c;
u32 func_00275e68(s32 value) {
    u32 result = func_00139d78(D_0035f20c+0x368);
    if (value < 0) {
        *(u32*)(D_0035f20c+0x500) = 0;
    } else {
        u8* object = D_0035f20c;
        result = func_00192048(value);
        u8* pointer = object + 0x368;
        *(u32*)(pointer+0x198) = result;
    }
    return result;
}

