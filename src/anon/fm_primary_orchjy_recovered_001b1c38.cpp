#include "../common/types.h"
struct Slot {
    u32 head;
    u32 tail;
    f32 x;
    f32 y;
    u8 state[24];
};
extern "C" s32 D_01d44100;
extern "C" Slot D_01d44108[16];
// why: types copied from the accepted definition in misc_3.cpp; its C++ linkage failed the isolated probe link (v2), so extern "C" is added
extern "C" void func_0031a830(void*);
extern "C" void func_003200c0(u32*);

// Preserve original registry aliases.
void func_001b1c38(int initialize, s64 priority) asm("_Z16wtarget_001b1c38jjjj");

void func_001b1c38(int initialize, s64 priority) {
    if (priority == 0xffff && initialize == 1) {
        register s32* next asm("$14") = &D_01d44100; // why: original forms the D_01d44100 address in t6 (sibling 001b26e0 binds the same pattern)
        asm volatile("" : "+r"(next)); // why: original forms the full D_01d44100 address before both stores and stores the second word through it (as sibling 001b26e0)
        D_01d44100 = 0;
        next[1] = 0;
    }
    if (priority == 0xffff && initialize == 1) {
        Slot* slot = D_01d44108;
        s32 count = 15;
        register f32 zero asm("$f20") = 0.0f; // why: original keeps the 0.0f stored into each slot in callee-saved $f20 across the calls
        do {
            slot->x = zero;
            slot->y = zero;
            count--;
            func_0031a830(slot->state);
            slot++;
        } while (count != -1);
        func_003200c0((u32*)D_01d44108);
    }
}
