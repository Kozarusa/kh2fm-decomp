#include "../common/types.h"
extern "C" u8 D_00157160[];
extern "C" u8* func_00102c18(s32, s32, u8*);
extern "C" u32 func_00156030(u8*);
extern "C" s32 func_00158290(u8*);
extern "C" s32 func_0013a7e8(s32);
extern "C" s32 func_0013d7e0();
extern "C" s32 func_00139c18(u8*);
extern "C" void func_001386e0(u8*, s32, s32, s32, s32, s32);
extern "C" void func_001396b0(u8*);
extern "C" void func_0031a260(u8*, s32);
extern "C" s32 func_00155f40(u8*);
extern "C" s32 func_00155fc0(u8*);
extern "C" u32 func_00138c10(u8*, s32);

u32 func_001571c0(u8* object) {
    u8* task = func_00102c18(1, 0x19258, D_00157160);
    *(u8**)(task + 4) = object;
    u32 result = func_00156030(object);
    if (result != 0) {
        return result;
    }
    s32 group = func_00158290(object);
    s32 square = func_0013a7e8(1);
    s32 image = func_0013d7e0();
    s32 index = func_00139c18(object + 0xd24);
    u8* entry = object + index * 0x198 + 0xd24;
    func_001386e0(entry, 7000, square, image, 130, group);
    *(u8**)(entry + 0x18c) = object + 0x1a30;
    func_001396b0(entry);
    if (*(s32*)(entry + 0x18c) != 0) {
        *(s32*)(entry + 0x190) = 0;
        func_001396b0(entry);
        if (*(s32*)(entry + 0x190) != 0) {
            func_0031a260(entry, 0);
        }
    }
    func_00138c10(object + 0x2d80, func_00155f40(object));
    result = func_00138c10(object + 0x2f1c, func_00155fc0(object));
    object[0x3cf7] = 1;
    return result;
}
