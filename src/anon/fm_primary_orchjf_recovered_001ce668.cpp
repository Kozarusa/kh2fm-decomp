#include "../common/types.h"
struct Triple {
    s32 first;
    s32 second;
    f32 third;
};
struct Vector {
    s32 first;
    f32 second;
    f32 third;
};
extern "C" Vector D_01d5b9e0;
extern "C" Triple D_01d5b9f0;
extern "C" f32 D_0036e2ec;

// Preserve original registry aliases.
void func_001ce668(u32 mode, u32 id) asm("_Z16wtarget_001ce668jjjj");

void func_001ce668(u32 mode, u32 id) {
    if (id == 0xffff && mode == 1) {
        D_01d5b9e0.first = 0;
        D_01d5b9e0.second = 0.0f;
        D_01d5b9e0.third = 0.0f;
    }
    if (id == 0xffff && mode == 1) {
        // why: original keeps the float source address in t5
        register f32* source asm("$13") = &D_0036e2ec;
        asm("" : "+r"(source)); // why: original loads the float through a formed address
        // why: original keeps the object base in t6
        register Triple* block asm("$14") = &D_01d5b9f0;
        D_01d5b9f0.first = 0;
        block->second = 0;
        block->third = *source;
    }
}
