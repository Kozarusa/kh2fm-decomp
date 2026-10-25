#include "../common/types.h"
// Declaration copied from fm_oct7_extended_recovered_00.cpp.
extern "C" u32 func_00139d78(...);
// Declaration copied from fm_primary_orchky_recovered_0024e158.cpp.
extern "C" void func_0028d980(u8*, u32, u32, u32, u32, s32, s32, s32, s32);
// Declaration copied from fm_primary_orchky_recovered_0024e158.cpp.
extern "C" u64 func_00139620(...);
// why: a word global, so the word stores through it may alias it and the original reloads it
extern "C" u32 D_0035f034;
extern "C" u32 D_0035ef68;
extern "C" u32 D_0035ef64;
extern "C" u32 D_0035f03c;
extern "C" s16 D_00372a00[];

void func_00257458(u32 value, s32 second) {
    if (func_00139d78(D_0035f034) != 0) {
        u32 object = D_0035f034;
        (*(void (**)(u32))(*(u32*)object + 20))(object);
    }
    s16* table;
    if (second == 0) {
        table = D_00372a00;
    } else {
        table = D_00372a00 + 4;
    }
    func_0028d980((u8*)D_0035f034, 0x7546, D_0035ef68, D_0035ef64, D_0035f03c, table[0], table[2], -1, 0);
    *(u32*)(D_0035f034 + 408) = value;
    func_00139620(D_0035f034);
    *(s32*)(D_0035f034 + 432) = 2;
    u32 part = D_0035f034 + 24;
    *(u32*)(part + 184) |= 8;
}
