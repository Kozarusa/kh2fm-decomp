#include "../common/types.h"
extern "C" bool func_001bb4a0(void);
extern "C" u32 func_001bbcb0(void);

s32 func_001d8898(s32 index) {
    if (func_001bb4a0()) {
        u32 base = func_001bbcb0();
        base += index * 0x38;
        u32 flags = *(u32*)(base + 0xf4);
        u8 flag = flags & 1;
        if (flag) {
            base = func_001bbcb0();
            base += index * 0x38;
            u32 bits = *(u32*)(base + 0xf4) & 8;
            return 0 < bits;
        }
    }
    return 0;
}
