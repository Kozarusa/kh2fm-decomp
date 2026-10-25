#include "../common/types.h"
// why: vtable of this widget class, stored at offset 0 (002ee5d8 sibling pattern)
extern "C" u8 D_00361980[];
// why: copied from the accepted caller 002be340 of 001050d8
extern "C" u32 func_001050d8(u64);
// why: copied from the accepted definitions of 001ad0f8 and 001ad330 and the accepted call site of 002edf28 in 002ee5d8
extern "C" void func_001ad0f8(u8* object, s32 first, s32 second);
extern "C" void func_001ad330(u8* object, s32 value);
extern "C" void func_002edf28(u32*);

void func_002bec88(u32* object, s32 kind, s32 value)
{
    func_002edf28(object);
    object[10] = 0;
    object[0] = (u32)D_00361980;
    switch (kind) {
    case 0: {
        u8* child = (u8*)func_001050d8(0xb6c);
        s32* layout;
        func_001ad0f8(child, value, 0);
        object[9] = (u32)child;
        *(s32*)(child + 100) = 2;
        layout = (s32*)object[9];
        layout[1] = 256;
        layout[2] = 48;
        break;
    }
    case 1: {
        u8* child = (u8*)func_001050d8(0x1230);
        func_001ad330(child, value);
        object[9] = (u32)child;
        break;
    }
    }
}
