#include "../common/types.h"
extern "C" u8 D_01d9e8c0[];
extern "C" void func_0021fbd8(void*, s32);

struct Args {
    u8* object;
    s32 second;
    u8* table;
    f32 scale;
    s16 width;
    s16 height;
    u8* inner;
};

void func_001fb8b8(u8* object) {
    Args args;
    s32 width = (s32)*(f32*)(object + 0x28);
    s32 height = (s32)*(f32*)(object + 0x2c);
    args.second = *(s32*)(object + 0x24);
    args.scale = *(f32*)(object + 0x20);
    args.width = width;
    args.height = height;
    args.table = D_01d9e8c0;
    args.inner = object + 0x10;
    args.object = object;
    func_0021fbd8(&args, 0);
}