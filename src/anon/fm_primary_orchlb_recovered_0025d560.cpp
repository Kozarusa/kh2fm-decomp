#include "../common/types.h"
extern "C" s16* D_0035f64c;
extern "C" u32 D_0035f6c4;
extern "C" u16 D_00372f40[];
// why: declaration copied from the call in fm_primary_orcheg_recovered_0026e5b8.cpp
extern "C" u32 func_00287bc0(void);
// why: types copied from the definition in fm_primary_orchem_recovered_0028b040.cpp; extern "C" because probe v1 with the asm-label declaration failed the isolated link (the probe linker script defines only the plain symbol)
extern "C" s32 func_0028b040(s16* object);
// why: types copied from the definition in fm_scalar_recovered_06.cpp (parameters renamed); extern "C" because probe v1 with the asm-label declaration failed the isolated link (the probe linker script defines only the plain symbol)
extern "C" void func_00263a58(s64 value, u8 flag);
// why: types copied from the definition in fm_primary_orchfc_recovered_002b6338.cpp; extern "C" because probe v1 with the C++ declaration failed the isolated link (the probe linker script defines only the plain symbol)
extern "C" u64 func_002b6338(u32 first, u32 second, u32 third, u32 flag);
// why: no recovered source defines it or uses its result; parameters are the registers the original sets (the callee masks a1 with 0xff)
extern "C" void func_00263a90(u32, u8);
// why: declaration copied from the call in fm_primary_orchef_recovered_00263cc0.cpp
extern "C" u32 func_00263d28();

// why: void per DEVIATIONS #36: the tail calls into func_00263a58 are stale-b (its accepted definition in fm_scalar_recovered_06.cpp is void), the other tails into func_00263a90 and func_00263d28 are final-callee exits, and no path holds a float

void func_0025d560() {
    u32 mode = func_00287bc0();
    if (mode == 0) {
        // why: original forms the table entry address in t6 ($14); probes v2 and v3 put it in v0
        register u16* entry asm("$14") = &D_00372f40[func_0028b040(D_0035f64c)];
        func_00263a58(*entry, 1);
        return;
    }
    if (mode == 19) {
        func_00263a58(0x8a82, 1);
        return;
    }
    if (mode == 1) {
        func_002b6338(D_0035f6c4, 0x200, 0xb85a, func_0028b040(D_0035f64c));
        func_00263a90(D_0035f6c4, 1);
        return;
    }
    if (mode == 12) {
        func_00263a58(0x8aa1, 1);
        return;
    }
    func_00263d28();
}
