#include "../common/types.h"
#include "../kn/fvector.hpp"
extern "C" s32 D_00350cc8;
extern "C" s32 D_00350ccc;
extern "C" f32 D_0036e3fc;
extern "C" const void* D_0036e400[9];
extern "C" bool func_0019ba60(s32);
extern "C" s32 func_0016c028(s32);
extern "C" kn::FVector* func_001dc5f8(u32);
extern "C" bool func_001dc9e0(s32);

void func_001d3148(s32* state) {
    // why: named label table keeps the switch targets while the dispatch reads the original table D_0036e400, pattern of accepted func_001815d0
    static const void* targets[9] asm("fm_switch_table_001d3148") = {
        &&finish, &&finish, &&attach, &&follow, &&effect, &&finish, &&finish, &&track, &&track_effect};
    kn::FVector* position;
    kn::FVector* destination;
    u32 index = state[0];
    if (index >= 9) goto finish;
    goto *D_0036e400[index];
attach:
    if (func_0019ba60(state[1])) {
        u8* matrix = (u8*)(state + 4);
        u8* source = (u8*)(state[1] + 0x6b0);
        if (matrix != source) {
            // why: 64-byte matrix copy through t0-t3, lq/sq copy primitive as in accepted 001604f8; the plain Quad struct copy (v4) failed at 33 differing words (lq/sq interleaved, t4-t7 registers)
            asm volatile("lq $8,0(%1); lq $9,16(%1); lq $10,32(%1); lq $11,48(%1); sq $8,0(%0); sq $9,16(%0); sq $10,32(%0); sq $11,48(%0)"
                         : : "r"(matrix), "r"(source) : "$8", "$9", "$10", "$11", "memory");
        }
    }
    state[0] = 0;
finish:
    return;
follow:
    if (func_0019ba60(state[1])) {
        u8* matrix = (u8*)(state + 4);
        u8* source = (u8*)(state[1] + 0x40);
        if (matrix != source) {
            // why: 64-byte matrix copy through t0-t3, lq/sq copy primitive as in accepted 001604f8; the plain Quad struct copy (v4) failed at 33 differing words (lq/sq interleaved, t4-t7 registers)
            asm volatile("lq $8,0(%1); lq $9,16(%1); lq $10,32(%1); lq $11,48(%1); sq $8,0(%0); sq $9,16(%0); sq $10,32(%0); sq $11,48(%0)"
                         : : "r"(matrix), "r"(source) : "$8", "$9", "$10", "$11", "memory");
        }
    }
    state[0] = 7;
track:
    if (!func_0019ba60(state[1])) {
        state[0] = 0;
        return;
    }
    destination = (kn::FVector*)(state + 16);
    position = (kn::FVector*)func_0016c028(state[1]);
copy:
    *destination = *position;
    {
        f32* limit = &D_0036e3fc;
        asm("" : "+r"(limit)); // why: original forms the full address before the load
        *(f32*)&destination->w = *limit;
    }
    return;
effect:
    if (func_0019ba60(D_00350cc8)) {
        u8* matrix = (u8*)(state + 4);
        u8* source = (u8*)(D_00350cc8 + 0x40);
        if (matrix != source) {
            // why: 64-byte matrix copy through t0-t3, lq/sq copy primitive as in accepted 001604f8; the plain Quad struct copy (v4) failed at 33 differing words (lq/sq interleaved, t4-t7 registers)
            asm volatile("lq $8,0(%1); lq $9,16(%1); lq $10,32(%1); lq $11,48(%1); sq $8,0(%0); sq $9,16(%0); sq $10,32(%0); sq $11,48(%0)"
                         : : "r"(matrix), "r"(source) : "$8", "$9", "$10", "$11", "memory");
        }
    }
    state[0] = 8;
track_effect:
    if (D_00350ccc == 0 || !func_001dc9e0(D_00350ccc)) {
        state[0] = 0;
        return;
    }
    destination = (kn::FVector*)(state + 16);
    position = func_001dc5f8(D_00350ccc);
    goto copy;
}
