#include "../common/types.h"
struct Pair {
    s16 first;
    s16 second;
};
extern "C" Pair D_0036dbb0[];
extern "C" bool func_00181550(void);
extern "C" bool func_001b8958(u32);
extern "C" void func_001b8838(s32);

void func_001b8e00(s32 index) {
    s16 value;
    Pair* entry = &D_0036dbb0[index];
    if (func_00181550()) {
        value = entry->second;
    } else {
        value = entry->first;
    }
    if (value >= 0) {
        if (!func_001b8958(value)) {
            func_001b8838(value);
        }
    }
}
