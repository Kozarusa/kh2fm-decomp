#include "../common/types.h"
struct Owner;
extern "C" u64 D_0034c710;
extern "C" u8 D_0034c70c;
extern "C" u8 D_0034c6f0[];
extern "C" void func_00143248();
extern "C" void func_00160e50(s32);
extern "C" s32 func_001de4b0(Owner*, s32, s32);
extern "C" s32 func_001dc9e0(s32);
extern "C" void func_001dcc48(s32);

s32 func_0015f548() {
    s32 index;
    s32 group;
    s32 effect;

    func_00143248();
    for (index = 0; index < 64; index++) {
        u64 mask = (u64)1 << index;
        if (D_0034c710 & mask) {
            func_00160e50(index);
        }
    }
    effect = 0;
    if (D_0034c70c == 1) {
        for (group = 0; group < 64; group++) {
            while ((effect = func_001de4b0((Owner*)D_0034c6f0, group, effect)) != 0) {
                if (func_001dc9e0(effect)) {
                    func_001dcc48(effect);
                }
            }
        }
    }
    register s32 result asm("$2"); // why: every exit returns the last callee result already in v0
    asm("" : "=r"(result)); // why: callee leaves the result in v0
    return result;
}
