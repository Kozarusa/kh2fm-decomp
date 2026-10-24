#include "../common/types.h"
extern "C" s32 func_001b9bc8(s32);
extern "C" bool func_001c0cd8(s32);
extern "C" void func_001c1020(s32, u32);

s32 func_002edca0(s32 id, u32 replacement) {
    s32 object = 0;
    while ((object = func_001b9bc8(object)) != 0) {
        if (func_001c0cd8(object) && *(s32*)(object + 0x570) == id) {
            func_001c1020(object, replacement);
        }
    }
    return object;
}
