#include "../common/types.h"
extern "C" s32 D_0032dfc8;
extern "C" u8 D_0032f230;
extern "C" void func_00188958(u32,u32);
extern "C" void func_001a1950(u8*, s32, s32, s32);
extern "C" void func_001a1a20(u8*,s32,u32);
extern "C" void func_001a1aa0(u8*, s32);
extern "C" u32 func_001a3188(...);
extern "C" void func_001b7428(u8*);
extern "C" u32 func_001b74b8(...);
extern "C" u32 func_001b7508(...);
extern "C" u32 func_001b7538(...);
extern "C" s32 func_001b7658(u8*, s32, s32);

s32 func_001c0690(u8* data, u8* object) {
    u8 info[80];
    func_001b74b8(info);
    s32 first = data[2];
    s32 second = data[3];
    if (D_0032dfc8 == 3) {
        s32 kind = data[1];
        if (kind != 0 && (kind < 4 || kind == 14)) {
            first = first / 2;
            second = second / 2;
        }
    }
    *(s32*)(object + 4) += first;
    *(s32*)(object + 0x184) += second;
    func_001a1950(object, first, 0, 0);
    func_001a1a20(object, second, 0);
    s32 level = object[0x1b2] + data[4];
    if (level >= 10) {
        level = 9;
    }
    object[0x1b2] = level;
    func_001a1aa0(object, 0);
    u8* partner = *(u8**)(object + 0x244);
    if (partner != 0) {
        func_00188958((u32)partner, partner[0x12] + data[5]);
        (*(u8**)(object + 0x244))[0x11] += data[6];
        (*(u8**)(object + 0x244))[0x10] += data[7];
    }
    func_001b7508(info, first, 0x8ae2);
    func_001b7508(info, second, 0x8ae3);
    func_001b7508(info, data[4], 0x8ae4);
    func_001b7508(info, data[5], 0x8ae5);
    func_001b7508(info, data[6], 0x8ae6);
    func_001b7508(info, data[7], 0x8ae7);
    for (s32 index = 0; index < 2; index++) {
        if (*(u16*)(data + index * 2 + 8) != 0) {
            func_001a3188(*(u16*)(data + index * 2 + 8), *(s32*)(object + 0x254), 0);
            func_001b7538(info, *(u16*)(data + index * 2 + 8));
        }
    }
    if (*(u8**)(object + 0x25c) != 0) {
        func_001b7428(*(u8**)(object + 0x25c));
    }
    return func_001b7658(info, data[1], D_0032f230);
}
