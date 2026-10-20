#include "../common/types.h"
extern "C" bool func_001bb4a0(void);
extern "C" u8* func_001bbcb0(void);

u16 func_001bbec0(void) {
    u16 result = 0;
    if (func_001bb4a0()) {
        u8* object = func_001bbcb0();
        result = *(u16*)(*(u8**)(object + 8) + 4) >> 11 & 1;
    }
    return result;
}