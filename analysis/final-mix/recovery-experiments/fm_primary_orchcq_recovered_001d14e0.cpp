#include "../common/types.h"
extern "C" void func_00177dc8(u8*, s32, s32, s32, s32);
extern "C" void func_001befd8(u8*, u8*, s32);
extern "C" u8 D_003524b8[];
extern "C" u8 D_0036e3a8[];

void func_001d14e0(u8* object, s32 arg1, s32 arg2, s32 arg3) {
    func_00177dc8(object, arg1, 8, arg2, arg3);
    u32 flags = *(u32*)(object + 0x588);
    u8* target = *(u8**)(object + 0xb44);
    *(u32*)(object + 0x588) = flags | 0x4000000;
    *(u8**)object = D_003524b8;
    func_001befd8(target, D_0036e3a8, 2);
}
