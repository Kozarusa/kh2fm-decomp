#include "../common/types.h"
extern "C" u8 D_01d48d94;
extern "C" s32 D_01d48d90;
extern "C" u8 D_001b89d0[];
extern "C" u32 func_001db610(...);

void func_001b8988(s32* object, u8 value) {
    u8* pointer = &D_01d48d94;
    *pointer = value;
    s32 offset = object[3];
    if (offset != 0) {
        func_001db610(D_01d48d90 + offset, D_001b89d0, 0);
    }
}
