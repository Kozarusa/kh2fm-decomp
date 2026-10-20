#include "../common/types.h"
extern "C" u8 D_0036dbb0[];
extern "C" bool func_00181550(void);
extern "C" bool func_001b8958(u32);
extern "C" void func_001b8838(s32);

void func_001b8e00(s32 index) {
    s16 value;
    if (func_00181550()) {
        s16* pointer = (s16*)(D_0036dbb0 + index * 4);
        value = pointer[1];
    } else {
        value = *(s16*)(D_0036dbb0 + index * 4);
    }
    if (value >= 0) {
        if (!func_001b8958(value)) {
            func_001b8838(value);
        }
    }
}
