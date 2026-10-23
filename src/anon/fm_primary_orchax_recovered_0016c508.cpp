#include "../common/types.h"
typedef unsigned int Quad __attribute__((mode(TI)));
extern "C" s32 func_0016c028(s32);
extern "C" u32 func_001ce328(u64);

f32* func_0016c508(f32* result, s32 source) {
    // why: original used t0 ($8) for the quad copy temporary
    register Quad tmp asm("$8") = *(Quad*)func_0016c028(source);
    *(Quad*)result = tmp;
    asm volatile("" ::: "memory"); // why: keeps the data load after the quad store
    s32 data = *(s32*)(source + 8);
    u32 entry = func_001ce328(*(u16*)(data + 0x4e));
    result[1] = result[1] - *(f32*)(entry + 0x30);
    return result;
}
