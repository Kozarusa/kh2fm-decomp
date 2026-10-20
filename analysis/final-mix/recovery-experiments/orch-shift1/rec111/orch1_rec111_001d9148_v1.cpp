#include "../common/types.h"
extern "C" bool func_001bb4a0(void);
extern "C" u32 func_001bbcb0(void);

u32 func_001d9148(u32 index) {
    if (!func_001bb4a0()) {
        return 0;
    }
    u32 offset = index << 6;
    if (!((*(u32*)(func_001bbcb0() + offset + 620) & 1) & 0xff)) {
        return 0;
    }
    return *(u32*)(func_001bbcb0() + offset + 664);
}
