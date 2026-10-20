#include "../common/types.h"
extern "C" u8 D_01d9e8c0[];
extern "C" void func_0021fe40(void*, s32);

struct Args {
    u8* object;
    s32 second;
    u8* table;
    f32 scale;
    s16 width;
    u16 height;
    u8* inner;
};

void func_001fbab8(u8* object) {
    Args args;
    args.object = object;
    args.second = *(s32*)(object + 0x24);
    args.table = D_01d9e8c0;
    args.scale = *(f32*)(object + 0x20);
    args.width = (s16)(s32)*(f32*)(object + 0x28);
    args.height = *(u16*)(object + 0x2c);
    args.inner = object + 0x10;
    func_0021fe40(&args, 0);
}