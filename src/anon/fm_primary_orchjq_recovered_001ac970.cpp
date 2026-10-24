#include "../common/types.h"
extern "C" u8 D_00350bb0[];
extern "C" u8 D_0034e8a8[];
extern "C" u8 D_00350a38[];
extern "C" void func_001ac378(u8*, s32, s32, s32, s32, s32, s32);
extern "C" void func_002395b8(u8*);
extern "C" void func_001abd90(u32*);
extern "C" void func_001ac028(u8*);
extern "C" u32 func_00239700(...);
extern "C" u32 func_001ab810(...);
extern "C" u32 func_001ab800(...);
extern "C" u32 func_00239988(...);
extern "C" u32 func_00239bf8(...);
extern "C" u32 func_001aa668(u8*, u8*);

u32 func_001ac970(u8* object, s32 text, s32 styleIndex, s32 base, s32 priority, s32 first, s32 second, s32 kind) {
    func_001ac378(object, text, styleIndex, base, priority, first, second);
    *(u8**)object = D_00350bb0;
    func_002395b8(object + 132);
    *(s32*)(object + 476) = kind;
    *(u8**)(object + 132) = D_0034e8a8;
    func_001abd90((u32*)(object + 480));
    *(s32*)(object + 1192) = 0;
    func_001ac028(object + 1196);

    u8* entry = object + 1544;
    s32 count = 3;
    do {
        count--;
        func_00239700(entry);
        entry += 344;
    } while (count != -1);

    *(s32*)(object + 2920) = 0;
    {
        u32 font = func_001ab810();
        func_00239988(object + 132, font, func_001ab800());
    }
    func_00239bf8(object + 132, D_00350a38[*(s32*)(object + 476) * 3]);
    s32 index;
    for (index = 0; index < 4; index++) {
        u32 font = func_001ab810();
        func_00239988(object + 1544 + index * 344, font, func_001ab800());
    }

    return func_001aa668(object + 12, object);
}
