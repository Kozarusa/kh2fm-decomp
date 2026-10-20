#include "../common/types.h"
extern "C" u32 func_002ba2e8(u64, u64);

void func_001bd618(u8* object, u8 flag) {
    **(s32**)(object + 0x8c0) = 0;
    if (*(s32**)(object + 0x8c0) == (s32*)(object + 0x9e8)) {
        *(s32**)(object + 0x8c0) = 0;
    } else {
        *(s32**)(object + 0x8c0) = *(s32**)(object + 0x8c0) - 1;
    }
    if (flag != 0) {
        func_002ba2e8(4, 0);
    }
}
