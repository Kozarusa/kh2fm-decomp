#include "../common/types.h"
extern "C" u8 D_00354bf0[];
extern "C" void func_001e6000(u8*);

void func_001e60b0() {
    u8* pointer = D_00354bf0;
    while (*(s32*)(pointer + 4) >= 0) {
        func_001e6000(pointer + 40);
        func_001e6000(pointer + 56);
        pointer += 72;
    }
}
