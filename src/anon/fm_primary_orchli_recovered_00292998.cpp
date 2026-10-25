#include "../common/types.h"
extern "C" u32 func_002fde18(void*,u8,u32);
extern "C" s32 D_0035f4bc;
extern "C" s32 D_0035f4d4;
extern "C" s16 D_0035f4d8;
extern "C" s32 D_0035f4dc;
extern "C" s16 D_0035f4e0;
extern "C" u8 D_0035f4e2;

// why: the only exit leaves the direct v0 of func_002fde18 (no later call); the accepted caller fm_primary_orches_recovered_00292a58.cpp also declares this function u32

u32 func_00292998() {
    u32 result;
    s32 index;
    D_0035f4e0 = 0;
    result = func_002fde18((void*)D_0035f4dc, 0, D_0035f4bc << 2);
    index = *(s16*)(D_0035f4e0 * 4 + D_0035f4dc + 2);
    D_0035f4d8 = index;
    if (D_0035f4e2 != 0) {
        *(s32*)(index * 16 + D_0035f4d4) = 0;
        asm volatile("" ::: "memory"); // why: original reloads the index and table after each store
        register s32 second asm("$14") = D_0035f4d8 * 16 + D_0035f4d4; // why: original forms this slot address in t6
        *(s32*)(second + 4) = 0;
        asm volatile("" ::: "memory"); // why: original reloads the index and table after each store
        *(s32*)(D_0035f4d8 * 16 + D_0035f4d4 + 12) = 0;
        asm volatile("" ::: "memory"); // why: original reloads the index and table after each store
        register s32 fourth asm("$14") = D_0035f4d8 * 16 + D_0035f4d4; // why: original forms this slot address in t6
        *(s32*)(fourth + 8) = 0;
    }
    return result;
}
