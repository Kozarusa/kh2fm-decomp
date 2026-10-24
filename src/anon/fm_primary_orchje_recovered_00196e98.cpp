#include "../common/types.h"
extern "C" u32 func_001d30f8(void*, u32, u32);
extern "C" u8 func_00227118(s32);

void func_00196e98(u8* object, u32 value) {
    if (value != 0) {
        if (func_00227118(*(s32*)(object + 4)) == 2) {
            func_001d30f8(object + 0x40, 3, value);
        } else {
            func_001d30f8(object + 0x40, 2, value);
        }
    }
}
