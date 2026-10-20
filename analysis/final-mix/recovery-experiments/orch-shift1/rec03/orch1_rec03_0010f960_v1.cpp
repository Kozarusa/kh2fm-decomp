#include "../common/types.h"
extern "C" void func_0016bd60(void*, s32);

void func_0010f960(u8* object) {
    if (*(s32*)(*(u8**)(object + 0xc) + 4) == 0x1f) {
        func_0016bd60(object, 0x20);
        return;
    }
    *(u32*)(object + 0xb7c) |= 0x4000;
}
