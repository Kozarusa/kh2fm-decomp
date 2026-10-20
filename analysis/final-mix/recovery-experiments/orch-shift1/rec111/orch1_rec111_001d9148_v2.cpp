#include "../common/types.h"
extern "C" bool func_001bb4a0(void);
extern "C" u32 func_001bbcb0(void);

u32 func_001d9148(u32 index) {
    u32 result = 0;
    u32 offset = index << 6;
    if (func_001bb4a0()) {
        result = 0;
        u32 flags = *(u32*)(func_001bbcb0() + offset + 620);
        u8 flag = flags & 1;
        if (flag) {
            result = *(u32*)(func_001bbcb0() + offset + 664);
        }
    }
    return result;
}
