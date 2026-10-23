#include "../common/types.h"
extern "C" u32 func_002ba2e8(u64, u64);

void func_001bd5b0(u8* object, s32 index, u8 flag) {
    s32* cursor = *(s32**)(object + 0x8c0);
    if (cursor == 0) {
        *(s32**)(object + 0x8c0) = (s32*)(object + 0x9e8);
    } else {
        *(s32**)(object + 0x8c0) = cursor + 1;
    }
    **(s32**)(object + 0x8c0) = (s32)(object + index * 0x74 + 0x24);
    if (flag != 0) {
        func_002ba2e8(3, 0);
    }
}
