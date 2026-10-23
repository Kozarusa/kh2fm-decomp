#include "../common/types.h"
extern "C" s32 func_00158290();
extern "C" s32 func_0013a7e8(s32);
extern "C" s32 func_0013d7e0();
extern "C" s32 func_00139c18(u8*);
extern "C" void func_001386e0(u8*, s32, s32, s32, s32, s32);
extern "C" void func_001396b0(u8*);
extern "C" void func_0031a260(u8*, s32);
extern "C" s32 func_0017df58(s32);
extern "C" s32 func_0016c060(s32, s32*, s32*);
extern "C" void func_00154048(u8*, s32, s32, s32, s32, s32);
extern "C" void func_00139660(u8*);
extern "C" void func_00139688(u8*);

// Preserve original registry aliases.
void func_001572e8(u8* object, s32 mode, s32 value) asm("_Z16wtarget_001572e8jjjj");

void func_001572e8(u8* object, s32 mode, s32 value) {
    s32 group = func_00158290();
    s32 square = func_0013a7e8(1);
    s32 image = func_0013d7e0();
    s32 index = func_00139c18(object + 0x6c4);
    u8* entry = object + index * 0x198 + 0x6c4;
    func_001386e0(entry, 7000, square, image, mode, group);
    *(s32*)(entry + 0x188) = value;
    *(u8**)(entry + 0x18c) = object + 0x1a30;
    func_001396b0(entry);
    if (*(s32*)(entry + 0x18c) != 0) {
        *(s32*)(entry + 0x190) = 0;
        func_001396b0(entry);
        if (*(s32*)(entry + 0x190) != 0) {
            func_0031a260(entry, 0);
        }
    }
    s32 first;
    s32 second;
    second = 0;
    first = 0;
    if (func_0016c060(func_0017df58(0), &first, &second) != 0) {
        s32 slot = func_00139c18(object + 0x1390);
        u8* panel = object + slot * 0x350 + 0x1390;
        func_00154048(panel, 13000, second, first, 3, group);
        *(u8**)(panel + 0x18c) = object + index * 0x198 + 0x6c4;
        func_001396b0(panel);
        if (*(s32*)(panel + 0x18c) != 0) {
            *(s32*)(panel + 0x190) = 0;
            func_001396b0(panel);
            if (*(s32*)(panel + 0x190) != 0) {
                func_0031a260(panel, 0);
            }
        }
        u8* target = object + slot * 0x350 + 0x1390;
        func_00139660(target);
        func_00139688(target);
    }
}
