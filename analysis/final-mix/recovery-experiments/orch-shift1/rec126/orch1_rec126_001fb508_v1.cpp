#include "../common/types.h"
extern "C" u8 D_01d9e8c0[];
extern "C" void func_0021fa28(void*, s32);

struct Args {
    u8* object;
    s32 second;
    u8* table;
    f32 scale;
    u8* inner;
};

void func_001fb508(u8* object) {
    Args args;
    args.object = object;
    args.second = *(s32*)(object + 0x24);
    args.table = D_01d9e8c0;
    args.scale = *(f32*)(object + 0x20);
    args.inner = object + 0x10;
    func_0021fa28(&args, 0);
}