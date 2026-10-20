#include "../common/types.h"
extern "C" u32 func_001d30f8(void*, u32, u32);
extern "C" u8 func_00227118(s32);

void func_00196e98(u8* object, u32 value) {
    if (value != 0) {
        u32 type = func_00227118(*(s32*)(object + 4));
        u32 mode;
        if (type != 2) {
            mode = 2;
        } else {
            mode = 3;
        }
        func_001d30f8(object + 0x40, mode, value);
    }
}
