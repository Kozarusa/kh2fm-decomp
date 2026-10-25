#include "../common/types.h"
extern "C" s32 D_0035ece0;
extern "C" s32 D_003718d0[];
// why: no recovered source calls or defines the next six callees; arguments are the registers each call sets in the original, results unused except func_00103570, whose v0 is passed on
extern "C" void func_0023d320();
extern "C" void func_00287910(s32, s32, s32);
extern "C" u32 func_00103570();
extern "C" void func_0028c878(u32, s32);
extern "C" void func_002425d0(s32);
extern "C" void func_00242fa0();
extern "C" u32 func_00242740(...);
// why: type copied from the definition in fm_primary_orchji_recovered_00243150.cpp; extern "C" because probe v1 with the C++ declaration failed the isolated link (the probe linker script defines only the plain symbol)
extern "C" s16* func_00243150(s32);

// why: the only exit returns the v0 of the final indirect call through the table entry; the original shows no float use (user ruling 2026-10-20 class 1)

s32 func_00242f00(s32 index) {
    s16* entry;
    func_0023d320();
    func_00242740(-1);
    func_00287910(index, 2, 0);
    func_0028c878(func_00103570(), 2);
    func_002425d0(2);
    func_00242fa0();
    if (D_0035ece0 < 0) {
        D_0035ece0 = D_003718d0[index];
    }
    entry = func_00243150(index);
    // why: original loads the handler into t7 ($15) before the jalr; probes v2 and v3 put it in v0
    register s32 (*handler)() asm("$15") = ((s32 (**)())entry)[1];
    return handler();
}
