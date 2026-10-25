#include "../common/types.h"
extern "C" u32* D_0035f610;
extern "C" u32 func_00294000(u64);

s32 func_002a9e98(s32 index) {
    s32 found = 0;
    u32 object = func_00294000(3);
    if (index < 0) {
        s32 count = *(s32*)(object + 8);
        for (s32 i = 0; i < count; i++) {
            found = (D_0035f610[(u32)i >> 5] & (1 << (i & 0x1f))) != 0;
            if (found) break;
        }
    } else {
        found = (D_0035f610[(u32)index >> 5] & (1 << (index & 0x1f))) != 0;
    }
    return found;
}
