#include "../common/types.h"
extern "C" bool func_001bb4a0(void);
extern "C" u8* func_001bbcb0(void);

u32 func_001bc050(void) {
    u32 result = 0;
    if (func_001bb4a0()) {
        u8* object = func_001bbcb0();
        u32 half = *(u16*)(*(u8**)(object + 8) + 4);
        result = (half >> 14) & 1;
    }
    return result;
}
