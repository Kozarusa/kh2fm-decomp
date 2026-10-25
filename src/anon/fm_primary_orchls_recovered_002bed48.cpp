#include "../common/types.h"
extern "C" u8 D_00361980[];
// why: AREA::Alloc(u32); its accepted definition is void but the original returns the allocator callback's v0, which this function uses as the new block; extern "C" plain name because the probe linker script defines only the plain symbol
extern "C" u8* func_001050d8(u32 size);
// why: types from the accepted definitions 002edf28, 001ad0f8, 001ad330; extern "C" because the C++-linkage forms fail the isolated probe link
extern "C" void func_002edf28(u32 object);
extern "C" void func_001ad0f8(u8* object, s32 first, s32 second);
extern "C" void func_001ad330(u8* object, s32 value);

void func_002bed48(u32* object, s32 type, s32 value) {
    func_002edf28((u32)object);
    object[10] = 0;
    object[0] = (u32)D_00361980;
    switch (type) {
    case 0: {
        u8* area = func_001050d8(2924);
        func_001ad0f8(area, value, 0);
        object[9] = (u32)area;
        *(s32*)(area + 100) = 2;
        u8* block = (u8*)object[9];
        *(s32*)(block + 4) = 256;
        *(s32*)(block + 8) = 48;
        break;
    }
    case 1: {
        u8* area = func_001050d8(4656);
        func_001ad330(area, value);
        object[9] = (u32)area;
        break;
    }
    }
}
