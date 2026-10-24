#include "../common/types.h"
extern "C" void func_00177dc8(u8*, s32, s32, s32, s32);
extern "C" void func_001befd8(u8*, u8*, s32);
extern "C" u8 D_00361d00[];

void func_002c5850(u8* object, s32 arg1, s32 arg2, s32 arg3) {
    func_00177dc8(object, arg1, 11, arg2, arg3);
    *(u8**)object = D_00361d00;
    *(s32*)(object + 0xbc4) = 0;
    *(u32*)(object + 0x588) = *(u32*)(object + 0x588) | 0x20000000;
    *(s32*)(object + 0xbd0) = 0;
    *(s32*)(object + 0xbd4) = 0;
    *(s32*)(object + 0xbd8) = 0;
    func_001befd8(*(u8**)(object + 0xb44), 0, 0);
    *(u32*)(object + 0xabc) = *(u32*)(object + 0xabc) | 0x10;
}
