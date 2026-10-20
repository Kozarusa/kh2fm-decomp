#include "../common/types.h"
extern "C" void func_00177dc8(u8*, s32, s32, s32, s32);
extern "C" void func_001d56f0(u8*);
extern "C" u8 D_003521e0[];

void func_001ced10(u8* object, s32 arg1, s32 arg2, s32 arg3) {
    func_00177dc8(object, arg1, 0, arg2, arg3);
    *(s32*)(object + 0xb68) = 0;
    *(s32*)(object + 0xb70) = 0;
    *(u8**)object = D_003521e0;
    func_001d56f0(object + 0xb74);
    *(u32*)(object + 0x58c) = *(u32*)(object + 0x58c) | 4;
}
