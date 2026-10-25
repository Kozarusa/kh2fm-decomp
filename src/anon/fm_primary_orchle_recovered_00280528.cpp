#include "../common/types.h"
extern "C" u8* D_0035f260;
extern "C" u32 D_0035f264;
extern "C" u8 func_00253918(void);
extern "C" u32 func_002537c8(s32);
extern "C" void func_00236c38(u32*);
extern "C" u32 func_00103570();
// why: copied exactly from the accepted call site in fm_primary_orchky_recovered_0023eea0.cpp
extern "C" void func_00236a58(...);
extern "C" void func_002805d0();

// why: void per DEVIATIONS #36; the tail call into 002805d0 leaves a stale v0 (its own instructions never write v0)

void func_00280528() {
    if (func_00253918() != 0) {
        return;
    }
    if (*(s8*)(D_0035f260 + 7) < 0) {
        return;
    }
    *(s8*)(D_0035f260 + 7) = -1;
    u32* entry = (u32*)D_0035f260;
    *entry = func_002537c8(6);
    if (*(s8*)(D_0035f260 + 6) >= 0) {
        return;
    }
    func_00236c38((u32*)D_0035f264);
    u32 allocator = func_00103570();
    func_00236a58(D_0035f264, *(u32*)D_0035f260, allocator);
    func_002805d0();
}
