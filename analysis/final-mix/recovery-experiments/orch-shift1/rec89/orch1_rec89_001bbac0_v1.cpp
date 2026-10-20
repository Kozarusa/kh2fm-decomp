#include "../common/types.h"
extern "C" bool func_001bb4a0(void);
extern "C" void func_001c11a8(s32);
extern "C" u8* D_01d49320;

void func_001bbac0(void) {
    if (func_001bb4a0()) {
        u8 mode = *(*(u8**)(D_01d49320 + 8) + 8);
        if (mode != 0) {
            func_001c11a8(mode);
        }
    }
}
