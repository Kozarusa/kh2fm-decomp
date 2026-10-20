#include "../common/types.h"
extern "C" char D_003513a8;
extern "C" void func_001980d0(u32, u32, u32, u32);
extern "C" u32 func_0016a020(s32);

void func_001c2338(u32 object, u32 arg1, u32 arg2) {
    u32* words = (u32*)object;
    func_001980d0(object, arg1, 9, arg2);
    words[0] = (u32)(long)&D_003513a8;
    words[0x162] = words[0x162] | 0x80000;
    *(u8*)(object + 0x3af) = 0x40;
    if (func_0016a020(object) == 0x4a1) {
        words[0x1da] = words[0x1da] | 0x10;
    }
}
