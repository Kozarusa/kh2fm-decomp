#include "../common/types.h"
struct Slot4 {
    u8 b[4];
};
extern "C" u8 D_0032e020[];
// why: copied from the definition-site callers in fm_primary_orchjb_recovered_001a8d40.cpp
extern "C" u32 func_001a8bf8(u8* object, s32 index);
// why: copied from fm_primary_orchjb_recovered_001a8d40.cpp, which calls it
extern "C" u32 func_001a8c60(u8* object, s32 index, u32 value);
// why: copied from the calling sources fm_primary_orchjx_recovered_001a2d78.cpp and fm_primary_orchiy_recovered_0017e720.cpp
extern "C" u8* func_001a8c10(s32, s32);
// why: copied from fm_primary_orchjo_recovered_001a3188.cpp, which calls it and uses the result
extern "C" s32 func_00188fe0(...);
// why: no accepted source declares this callee; its exits leave entry or stale v0, so it is declared void
extern "C" void func_001d9630(u8* list, s32 count);

void func_001d94f8(Slot4 slots, u8* other) {
    s32 i;
    s32 j;
    s32 k;
    u8* record;
    u16* flags;

    for (i = 0; i < 4; i++) {
        // why: the original makes this call and discards its result before the inner loop
        func_001a8bf8(slots.b, i);
        for (j = 0; j < 4; j++) {
            if (func_001a8bf8(slots.b, i) == func_001a8bf8(other, j)) {
                func_001a8c60(slots.b, i, 18);
                break;
            }
        }
    }
    // why: j is reused as the counter so the original keeps it in s1 (v2 with i put it in s2)
    for (j = 0; j < 4; j++) {
        if (func_001a8bf8(slots.b, j) != 18) {
            record = (u8*)func_00188fe0(D_0032e020, func_001a8c10((s32)slots.b, j));
            func_001d9630(record + 20, 8);
            func_001d9630(record + 36, 8);
            func_001d9630(record + 52, 8);
            // why: base at +80 with index offset 2 gives the original addiu 80 plus lhu 4(s0) (v1 with +84 folded it)
            flags = (u16*)(record + 80);
            for (k = 0; k < 80; k++) {
                flags[k + 2] &= 0x7fff;
            }
        }
    }
}
