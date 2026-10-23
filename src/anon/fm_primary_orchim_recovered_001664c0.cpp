#include "../common/types.h"
extern "C" u8 D_004f41d0[];
extern "C" void func_00166148(u8*, s32, s32);
extern "C" void func_002f2aa0(u8*, s32, u32, s32, s32, s32, s32, s32);
extern "C" void func_003058a0(u32);
extern "C" void func_002f25a0(u32, u32);
extern "C" s32 func_002f2d60(u8*, u32);

void func_001664c0(u8* object) {
    u8* pointer = object + 16;
    u8* source = pointer + *(u16*)(pointer + 12);
    if ((u32)(pointer[19] - 6) < 2) {
        return;
    }
    func_00166148(object, 0x2800, 0x3500);
    u32 shift = 0;
    u32 width = 0;
    u32 height = 0;
    switch (pointer[19]) {
    case 4:
        shift = *(u16*)(pointer + 20) >> 7;
        width = *(u16*)(pointer + 20) >> 1;
        height = *(u16*)(pointer + 22) >> 2;
        pointer[19] = 6;
        break;
    case 5:
        shift = *(u16*)(pointer + 20) >> 7;
        width = *(u16*)(pointer + 20) >> 1;
        height = *(u16*)(pointer + 22) >> 1;
        pointer[19] = 7;
        break;
    }
    func_002f2aa0(D_004f41d0, 0x2800, (s16)shift, 0, 0, 0, (s16)width, (s16)height);
    func_003058a0(0);
    func_002f25a0(0, 0);
    func_002f2d60(D_004f41d0, (u32)source);
}
