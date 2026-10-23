#include "../common/types.h"
extern "C" bool func_001bb4a0(void);
extern "C" u32 func_001bbcb0(void);

u32 func_001bc130(void) {
    u32 result = 0;
    if (func_001bb4a0()) {
        u32 object = func_001bbcb0();
        u32 flags = *(u16*)(*(u32*)(object + 8) + 4);
        u8 flag = (flags >> 2) & 1;
        if (flag) {
            result = 1;
        }
    } else {
        result = 1;
    }
    return result;
}
