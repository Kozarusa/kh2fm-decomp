#include "../common/types.h"
extern "C" s32* D_01d5ba98;
extern "C" u32 func_001d6da8(...);

s32 func_001d6e60() {
    s32 count = D_01d5ba98[1];
    u16 buffer[count + 1];
    func_001d6da8(buffer);
    return buffer[0] != 0;
}
