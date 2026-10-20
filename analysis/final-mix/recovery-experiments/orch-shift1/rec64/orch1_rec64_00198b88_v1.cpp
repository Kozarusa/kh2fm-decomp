#include "../common/types.h"
extern "C" void func_00198dc0(u8*);

void func_00198b88() {
    u8* pointer = (u8*)0x01c61b48;
    do {
        func_00198dc0(pointer);
        pointer += 88;
    } while ((s32)pointer < 0x01c620c8);
}
