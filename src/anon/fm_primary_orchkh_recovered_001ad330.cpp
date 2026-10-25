#include "../common/types.h"
extern "C" void func_001ac970(u8*, s32, s32, s32, s32, s32, s32, s32);
// why: types from the accepted definition in fm_scalar_recovered_03.cpp; extern "C" because the C++-linkage form fails the isolated probe link (rcfix16 001ad280 v2)
extern "C" void func_001ac258(u32*);
extern "C" void func_00239700(u32);
// why: types from the accepted definition in fm_primary_orchjy_recovered_001a9970.cpp; extern "C" because the C++-linkage form fails the isolated probe link (rcfix16 001ad280 v1)
extern "C" void func_001a9970(u8*, s32);
extern "C" u8 D_00350ab0[];

void func_001ad330(u8* object, s32 value) {
    u8* entry = object + 3280;
    s32 count = 3;
    func_001ac970(object, 0, 6, value, 0, 256, 52, 4);
    *(u8**)object = D_00350ab0;
    func_001ac258((u32*)(object + 2924));
    do {
        count--;
        func_00239700((u32)entry);
        entry += 344;
    } while (count != -1);
    func_001a9970(object + 12, 16);
    *(s32*)(object + 104) = 0;
    *(u32*)(object + 8) += *(u32*)(object + 96) >> 1;
}
