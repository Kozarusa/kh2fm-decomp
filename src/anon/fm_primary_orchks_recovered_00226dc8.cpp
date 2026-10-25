#include "../common/types.h"
extern "C" s32 D_0035db10;
extern "C" u8 D_0035de27;
// why: copied from the call site in fm_primary_orchad_recovered_001385c0.cpp
extern "C" u32 func_00102c48(u32, u32, u32, u32);
// why: types from the accepted definition in fm_fallback_helpers.cpp; extern "C" because the isolated probe linker script defines only the plain symbol (a C++ declaration failed the link in orch1_lg368_00222080_v1)
extern "C" void func_00226d88(void);
// why: types from the accepted definition in fm_fallback_helpers.cpp; extern "C" for the same isolated-link reason
extern "C" u32 func_002282d8(void);
// why: copied from the call site in fm_primary_orchaj_recovered_00147240.cpp
extern "C" bool func_00228378(...);
// why: types from the accepted definition in fm_primary_orchjp_recovered_002bc518.cpp; extern "C" for the same isolated-link reason
extern "C" void func_002bc518();
// why: no recovered call site or definition; takes no arguments, its result is never read here
extern "C" void func_00232988(void);
// why: no recovered call site or definition; its instructions only store zero to a global
extern "C" void func_0023d230(void);
// why: no recovered call site or definition; one word argument in a0, its final tail (0015f288) only stores a byte and writes no v0
extern "C" void func_00226ce8(s32 mode);

void func_00226dc8(void) {
    if (D_0035db10 == 4) {
        return;
    }
    D_0035db10 = 4;
    func_00226d88();
    func_00232988();
    func_002bc518();
    if (func_00228378()) {
        func_0023d230();
        func_00102c48(1, func_002282d8(), (u32)func_00226ce8, 0x1000);
        return;
    }
    D_0035de27 = 1;
    func_00226ce8(0);
}
