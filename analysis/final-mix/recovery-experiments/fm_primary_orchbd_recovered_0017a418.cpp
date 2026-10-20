#include "../common/types.h"
extern "C" u32 func_001d6ae0(s32);
extern "C" u32 func_001d6b40(s32);

void func_0017a418(u8* object, s32 mode) {
    switch (mode) {
    case 1:
        func_001d6ae0(*(s32*)(object + 0xb3c));
        break;
    case 2:
        func_001d6b40(*(s32*)(object + 0xb3c));
        break;
    default:
        break;
    }
    *(u8*)(object + 0xb64) = mode;
}
