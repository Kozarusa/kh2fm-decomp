#include "../common/types.h"
extern "C" void func_001386e0(...);
extern "C" u32 func_00138c40(...);
extern "C" u32 func_001396b0(...);
extern "C" u32 func_0013a7e8(...);
extern "C" int func_0013e678(...);
extern "C" u32 func_0014fc40(...);
extern "C" u32 func_00151d48(...);
extern "C" u32 func_001520c0(...);
extern "C" u32 func_00152100(...);
extern "C" u32 func_00239988(...);
extern "C" u32 func_00239bf8(...);
extern "C" u32 func_0023aa78(...);
extern "C" u32 func_0031a260(...);

// Preserve original registry aliases.
u32 func_00151df0(u8* object, s32 value) asm("_Z16wtarget_00151df0jjjj");

u32 func_00151df0(u8* object, s32 value) {
    if (func_00152100(object, value) != 0) {
        return func_001520c0(object, value);
    }
    *(s32*)(object + 2892) = value;
    s32 image = func_0013e678();
    u8* select = object + 48;
    u32 sqd = func_0013a7e8(0);
    func_001386e0(select, 4600, sqd, image, 17, 7);
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
        func_00239bf8(entry, 28);
        entry += 344;
    } while (count >= 0);
    func_00151d48(object);
    u32 param = func_0023aa78(object + 72);
    return func_0014fc40(object, 17, param, 4600, 7, 0);
}
