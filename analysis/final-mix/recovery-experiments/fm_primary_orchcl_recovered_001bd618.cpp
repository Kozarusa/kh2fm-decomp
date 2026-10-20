#include "../common/types.h"
extern "C" u32 func_002ba2e8(u64, u64);

void func_001bd618(u8* object, u8 flag) {
    **(s32**)(object + 0x8c0) = 0;
    // why: original reloads the cursor after the store
    s32 cursor = *(volatile s32*)(object + 0x8c0);
    if (cursor == (s32)(object + 0x9e8)) {
        *(s32*)(object + 0x8c0) = 0;
    } else {
        *(s32*)(object + 0x8c0) = cursor - 4;
    }
    if (flag != 0) {
        func_002ba2e8(4, 0);
    }
}
