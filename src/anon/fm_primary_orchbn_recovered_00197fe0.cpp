#include "../common/types.h"

extern "C" u8 D_00350388[];
extern "C" void func_00169398(u32*, u32, u32*, s32, s32);

void func_00197fe0(u32* object, u32* source, s32 third, s32 fourth) {
    func_00169398(object, *source | 0x40000000, source, third, fourth);
    *object = (u32)D_00350388;
    object[0x162] = object[0x162] | 0x20;
}
