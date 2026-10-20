#include "../common/types.h"
extern "C" bool func_001bb4a0(void);
extern "C" u32 func_001bbcb0(void);

u32 func_001bbf00(void) {
    u32 result = 0;
    if (func_001bb4a0()) {
        u32 object = func_001bbcb0();
        u32 flags = *(u16*)(*(u32*)(object + 8) + 4);
        result = (flags >> 12) & 1;
    }
    return result;
}
