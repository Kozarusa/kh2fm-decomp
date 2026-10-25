#include "../common/types.h"
extern "C" u32 D_0035ed00;
extern "C" s8* D_0035ed10;
extern "C" u32 D_0035ece8;
extern "C" s8 D_00371958[];
// why: copied from the call site in fm_primary_orcham_recovered_0014f5d0.cpp
extern "C" s32 func_00139d78(u32);
// why: copied from the call site in fm_primary_orchdx_recovered_00241320.cpp
extern "C" u32 func_002fde18(...);
// why: copied from the call site in fm_primary_orchiq_recovered_0024a048.cpp
extern "C" u32 func_002891e8(...);
// why: no recovered source calls this; derived from registers (a0 the func_002891e8 result, v0 tested by bnez)
extern "C" s32 func_00244ee8(u32);
// why: copied from the call site in fm_primary_aliashelpers_recovered_0013b4b0.cpp
extern "C" void func_00139858(s32);
// why: copied from the call site in fm_primary_queuexiprime_recovered_00138140.cpp
extern "C" void func_001398d0(s32);
// why: copied from the call site in fm_primary_orchdz_recovered_00244a10.cpp
extern "C" s32 func_001d56c8(...);
// why: copied from the call site in fm_primary_orchfj_recovered_002c2598.cpp
extern "C" u32 func_00192048(u32);
// why: parameter types copied from the accepted definition in fm_primary_orchjq_recovered_00192cc0.cpp; extern "C" because the C++ form failed the isolated link in v1 (the probe linker script defines only the plain symbol)
extern "C" s8* func_00192cc0(s8* buffer, const s8* format, ...);
// why: no recovered source uses this result; derived from registers (a0 the func_00192cc0 result, v0 added to the buffer)
extern "C" s32 func_00192b30(s8*);
// why: no recovered source uses this result; derived from registers (a0 the func_00192048 result, a1 the buffer), it returns its v0 (addiu v0,v0,1)
extern "C" s32 func_00192c90(u32, s8*);

// why: every exit is a direct callee result (func_00139d78 zero, or the tail func_00192c90 result)

s32 func_00244b38() {
    s32 active = func_00139d78(D_0035ed00);
    if (active == 0) {
        return active;
    }
    func_002fde18(D_0035ed10, 0, 32);
    if (func_00244ee8(func_002891e8(D_0035ece8)) == 0) {
        func_001398d0(100);
    } else {
        func_00139858(100);
    }
    s8* buffer = D_0035ed10;
    u8* score = (u8*)func_001d56c8(8);
    if (*score != 3) {
        return func_00192c90(func_00192048(0xcb9b), buffer);
    }
    s32 size = func_00192b30(func_00192cc0(buffer, D_00371958, *(s32*)(score + 4)));
    return func_00192c90(func_00192048(0xcb98), buffer + size);
}
