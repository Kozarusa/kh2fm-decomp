#include "../common/types.h"
extern "C" f32 D_0036e5f8;
extern "C" void func_001c71f8(f32);

void func_001d7730(s32 object) {
    f32 *address = &D_0036e5f8;
    // why: forces the address to be formed before the load
    asm("" : "+r"(address));
    func_001c71f8(*address);
    s32 *pointer = *(s32**)(object + 0x50);
    ((void (*)(s32*, s32))(*(s32**)pointer)[0x58 / 4])(pointer, object);
}