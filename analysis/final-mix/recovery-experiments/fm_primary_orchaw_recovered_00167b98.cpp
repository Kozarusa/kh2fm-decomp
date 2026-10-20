#include "../common/types.h"
extern "C" u8 D_0034d3c0[];
extern "C" void func_002f4a78();
extern "C" void func_002f5c70(s32);
extern "C" void func_00167728(u8*, s32);

void func_00167b98(void) {
    s32 index = 0;
    func_002f4a78();
    func_002f5c70(0);
    u8 *pointer = D_0034d3c0;
    do {
        func_00167728(pointer, index);
        index = index + 1;
        pointer = pointer + 0x180;
    } while (index < 2);
}
