#include "../common/types.h"
extern "C" u32 func_001d6ae0(s32);
extern "C" u32 func_001d6b40(s32);

void func_0017a418(u8* object, s32 mode) {
    if (mode != 1) {
        if (mode != 2) {
            *(u8*)(object + 0xb64) = mode;
        } else {
            func_001d6b40(*(s32*)(object + 0xb3c));
            *(u8*)(object + 0xb64) = mode;
        }
    } else {
        func_001d6ae0(*(s32*)(object + 0xb3c));
        *(u8*)(object + 0xb64) = mode;
    }
}