#include "../common/types.h"

extern "C" u8 D_003503e0[];
extern "C" u8 D_00350e48[];
extern "C" void func_00169398(u32*, u32, u32*, s32, s32);
extern "C" void func_001d56f0(u8*);
extern "C" u32 func_00168b38(void*, u32, s32);
extern "C" u32 func_001dddd0(u32, u32);
extern "C" s32 func_00170d18(u32);
extern "C" void func_001b2f38(u8*, s32, u8);
extern "C" void func_0017ebe8(void*, s32);
extern "C" void func_00195858(u8*, s32);

void func_001980d0(u8* object, u32* source, s32 third, s32 fourth) {
    u8* link = object + 2492;
    u8* data = object + 1952;
    func_00169398((u32*)object, *source, source, third, fourth);
    *(s32*)(object + 2484) = 0;
    *(s32*)(object + 2488) = 0;
    *(s32*)object = (s32)D_003503e0;
    *(s32*)(link + 8) = -1;
    *(s32*)(link + 20) = 0x1800;
    *(s32*)(link + 4) = 0;
    *(s32*)(link + 12) = 0;
    *(s32*)(link + 16) = 0;
    *(s32*)(object + 2492) = (s32)D_00350e48;
    func_001d56f0(object + 2524);
    func_001d56f0(object + 2536);
    *(u32*)(object + 1416) |= 1;
    if (*(u32*)(data + 16) != 0) {
        u8* entry = (u8*)func_00168b38((void*)*(u32*)(data + 16), 18, 0);
        if (entry != 0 && *(u32*)(entry + 8) != 0) {
            func_001dddd0((u32)(object + 128), *(u32*)(entry + 8));
        }
        entry = (u8*)func_00168b38((void*)*(u32*)(data + 16), 34, 0);
        if (entry != 0) {
            s32 value = *(s32*)(entry + 8);
            if (value != 0) {
                *(s32*)(link + 12) = 0;
                *(s32*)(link + 8) = -1;
                *(s32*)(link + 20) = 0x1800;
                *(s32*)(link + 16) = 0;
                *(u8**)(link + 28) = (u8*)value;
                *(s32*)(object + 2492) = (s32)D_00350e48;
                *(s32*)(link + 4) = 2;
                *(s32*)(object + 2488) = (s32)link;
            }
        }
        *(s32*)(object + 2484) = func_00170d18(*(u32*)(data + 16));
        entry = (u8*)func_00168b38((void*)*(u32*)(data + 16), 38, 0);
        if (entry != 0) {
            s32 value = *(s32*)(entry + 8);
            if (value != 0) {
                u8* track = object + 2048;
                func_001b2f38(track, value, (*(u16*)((u8*)source + 72) >> 6) & 1);
                *(s32*)(object + 1548) = *(s32*)(track + 12);
            }
        }
    }
    if (*(s32*)(data + 20) != 0) {
        func_0017ebe8(object + 320, *(s32*)(data + 20));
    }
    u16 count = *(u16*)(*(u8**)(object + 8) + 78);
    if (count != 0) {
        func_00195858(object + 272, count);
    }
}
