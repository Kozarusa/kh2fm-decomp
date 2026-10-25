#include "../common/types.h"
extern "C" u32* D_0035f620;
extern "C" s32 D_0035f628;
extern "C" s32 D_0035f62c;
// why: copied from the accepted call site in fm_primary_threeword_recovered_002a6368.cpp
extern "C" u32 func_00294000(u64);
// why: copied from the accepted call site in fm_primary_orchex_recovered_002a6878.cpp
extern "C" bool func_002944d0(void*);

// why: every exit leaves a callee v0 (func_00294000 when the list is empty, else the last func_002944d0), so the last computed result is returned

u32 func_002ad580(void) {
    u32 index = 0;
    u32 result = func_00294000(6);
    u32 object = result;
    D_0035f628 += *(s32*)(object + 8);
    u8* list = (u8*)(object + 16);
    if (*(s32*)(object + 8) > 0) {
        // why: the original keeps the list header in s5 across the loop calls
        register s32* header asm("$21") = (s32*)object;
        do {
            result = func_002944d0(list + index * 8);
            u32 word = index >> 5;
            u32 bit = index & 0x1f;
            index++;
            if (result) {
                u32* bits = (u32*)((u8*)D_0035f620 + 132);
                bits += word;
                *bits |= 1 << bit;
                D_0035f62c++;
            }
        } while ((s32)index < header[2]);
    }
    return result;
}
