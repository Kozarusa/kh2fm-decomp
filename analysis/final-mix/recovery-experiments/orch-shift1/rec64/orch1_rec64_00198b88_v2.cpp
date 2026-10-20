#include "../common/types.h"
extern "C" u8 D_01c61b48[];
extern "C" void func_00198dc0(u8*);

void func_00198b88() {
    u8* pointer = D_01c61b48;
    u8* end = D_01c61b48 + 1408;
    do {
        func_00198dc0(pointer);
        pointer += 88;
    } while (pointer < end);
}
