#include "../common/types.h"
typedef unsigned int Quad __attribute__((mode(TI)));
extern "C" u8* D_0034ed04;
extern "C" s32 D_0034ed00;
extern "C" u8 D_01c60588[];
extern "C" s32 func_00186078(s32);
extern "C" bool func_0019ba60(u64);
extern "C" s32 func_0016c028(s32);
extern "C" void func_00182980(u8*, Quad*);

s32 func_00182c60() {
    s32 entry = 0;
    while ((entry = func_00186078(entry)) != 0) {
        *(u32*)((u8*)entry + 0xaa8) |= 0x10000;
    }
    if (func_0019ba60((s32)D_0034ed04) && !(*(u32*)(D_0034ed04 + 0x7f8) & 4)) {
        Quad buffer;
        Quad* source = (Quad*)func_0016c028((s32)D_0034ed04);
        if (&buffer != source) {
            register Quad value asm("$8") = *source; // why: original copies the quad through t0
            buffer = value;
        }
        if (*(u32*)(D_0034ed04 + 0x588) & 0x80) {
            *(s32*)(D_0034ed04 + 0xb4c) = -1;
        }
        s32 index = 0;
        if (index < D_0034ed00) {
            u8* pointer = D_01c60588;
            do {
                func_00182980(pointer, &buffer);
                index++;
                pointer += 12;
            } while (index < D_0034ed00);
        }
    }
    entry = 0;
    while ((entry = func_00186078(entry)) != 0) {
        if (*(u32*)((u8*)entry + 0xaa8) & 0x10000) {
            *(s32*)((u8*)entry + 0xaa8) = -1;
        }
    }
    return entry;
}
