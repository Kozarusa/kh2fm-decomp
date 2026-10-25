#include "../common/types.h"
// Declarations copied from fm_primary_orchir_recovered_0026c9f0.cpp.
extern "C" s32 func_00287cd0();
extern "C" s32 func_00287c30();
extern "C" s32 func_00287c00(s32);
// Declaration from the definition in fm_primary_orchfc_recovered_002b4fb8.cpp.
extern "C" u32 func_002b4fb8();
// Declaration from the definition in fm_primary_orchkx_recovered_002417a0.cpp.
extern "C" void func_002417a0(void);
// Declaration copied from fm_primary_oneword_recovered_00232510.cpp.
extern "C" u32 func_00287bc0(...);
// Declaration copied from fm_primary_oneword_recovered_0023a9c0.cpp.
extern "C" u32 func_00287cc0(u32);
// why: no recovered source calls these; derived from registers (result tested in v0)
extern "C" s32 func_00287c10(void);
extern "C" u32 func_00233e60(void);
// why: no recovered source calls these; derived from registers (one word argument in a0, result unused)
extern "C" void func_00233e70(s32);
extern "C" void func_00287d20(s32);
extern "C" void func_00240bb0(s32);
// why: no recovered source calls these; derived from registers (no arguments, result unused)
extern "C" void func_002b4ee0(void);
// why: no recovered source calls this; derived from registers (address in a0, zero in a1)
extern "C" void func_002b5188(u8*, s32);
extern "C" u8 D_00372ea0[];

void func_0025af70(void) {
    s32 state = func_00287cd0();
    if (state == 2) {
        if (func_002b4fb8() != 0) {
            return;
        }
        if (func_00287c10() == 1) {
            func_00233e70(0);
            if (func_00233e60() == 0) {
                return;
            }
        }
        func_00287c30();
        func_00287d20(0);
        if (func_00287bc0() == 12) {
            func_002b5188(D_00372ea0, 0);
        }
        return;
    }
    if (state == 0) {
        func_00287cc0(1);
    }
    func_00240bb0(8000);
    func_002417a0();
    func_002b4ee0();
    func_00287c00(12);
    func_00287cc0(2);
}
