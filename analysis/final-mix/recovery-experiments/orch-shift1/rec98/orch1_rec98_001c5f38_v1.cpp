#include "../common/types.h"
extern "C" u8 D_00351680[];
extern "C" void func_001c5e88();

u32 func_001c5f38(u8* object) {
    s32 count = *(s32*)(D_00351680 + object[0x52] * 32 + 20);
    u32 result = 0;
    if (count > 0) {
        func_001c5e88();
        result = 1;
    }
    return result;
}
