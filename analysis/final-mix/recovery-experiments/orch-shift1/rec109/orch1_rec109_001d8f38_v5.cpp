#include "../common/types.h"
struct Slot {
    u32 flags;
    u8 pad[0x30];
};
struct Mission {
    u8 pad[0x19c];
    Slot slots[1];
};
extern "C" bool func_001bb4a0(void);
extern "C" Mission* func_001bbcb0(void);

bool func_001d8f38(s32 index) {
    bool result;
    if (func_001bb4a0()) {
        result = false;
        u8 flag = func_001bbcb0()->slots[index].flags & 1;
        if (flag) {
            u32 bit = func_001bbcb0()->slots[index].flags & 8;
            result = bit != 0;
        }
    } else {
        result = false;
    }
    return result;
}
