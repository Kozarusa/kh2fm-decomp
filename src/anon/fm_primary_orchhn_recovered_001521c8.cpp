#include "../common/types.h"
extern "C" void func_001386e0(...);
extern "C" u32 func_00138c40(...);
extern "C" u32 func_001396b0(...);
extern "C" u32 func_0013a7e8(...);
extern "C" int func_0013e678(...);
extern "C" u32 func_0014fc40(...);
extern "C" u32 func_00152120(...);
extern "C" u32 func_00152498(...);
extern "C" u32 func_001524e8(...);
extern "C" u32 func_00239988(...);
extern "C" u32 func_00239bf8(...);
extern "C" u32 func_0023aa78(...);
extern "C" u32 func_0031a260(...);

// Preserve original registry aliases.
u32 func_001521c8(u8* object, s32 value) asm("_Z16wtarget_001521c8jjjj");

u32 func_001521c8(u8* object, s32 value) {
    if (func_001524e8(object, value) != 0) {
        return func_00152498(object, value);
    }
    *(s32*)(object + 2892) = value;
    s32 image = func_0013e678();
    u8* select = object + 48;
    u32 sqd = func_0013a7e8(0);
    func_001386e0(select, 4500, sqd, image, 48, 7);
    *(s32*)(select + 396) = 0;
    func_001396b0(select);
    if (*(s32*)(select + 396) != 0) {
        *(s32*)(select + 400) = 0;
        func_001396b0(select);
        if (*(s32*)(select + 400) != 0) {
            func_0031a260(select, 0);
        }
    }
    func_00138c40(select, 0, *(s32*)(object + 36));
    u8* entry = object + 456;
    s32 count = 6;
    do {
        count--;
        func_00239988(entry, sqd, image);
        func_00239bf8(entry, 38);
        entry += 344;
    } while (count >= 0);
    func_00152120(object);
    u32 param = func_0023aa78(object + 72);
    return func_0014fc40(object, 14, param, 4500, 7, 0);
}
