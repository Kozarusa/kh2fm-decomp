#include "../common/types.h"
extern "C" s32 D_0035eeb4;
extern "C" s32 D_0035f3d4;
extern "C" s16 D_01dae6a8[];
// why: return type from fm_primary_oneword_recovered_00253538.cpp (uses the result); the
// s16 parameter there makes the caller sign-extend a0 (probes v1 and v2), while the original
// passes a0 unchanged, so the parameter is a full word here.
extern "C" u32 func_00253330(s32);
// Declaration from the definition in fm_primary_addresspair_recovered_00258dc8.cpp.
extern "C" void func_00258dc8(void);
// Declarations copied from the SubMenu::Exit call sites in tozawa/sub_menu.cpp.
extern "C" u32 func_0028ca78(...);
extern "C" u32 func_00287a28(...);
extern "C" u32 func_00242790(...);
// Declaration copied from fm_primary_orchip_recovered_0027bf20.cpp.
extern "C" void func_0028d068(u32 index, s32 mode);
// why: f32 because its original chain (func_0014ce30 tail to func_0014ce88) leaves a div.s
// result in $f0 with no later call and writes no v0; no recovered source defines it, and
// the u32 declaration in tozawa/sub_menu.cpp names a v0 the chain never writes. extern "C"
// because the isolated probe linker script defines only the plain symbol.
extern "C" f32 func_0023d368(void);

f32 func_002530f0(s32 mode) {
    u32 object = func_00253330(mode);
    (*(void (**)(void))(object + 8))();
    D_0035eeb4 = -1;
    func_00258dc8();
    func_0028ca78();
    func_00287a28();
    D_0035f3d4 = D_01dae6a8[0];
    if (D_01dae6a8[1] >= 0) {
        func_0028d068(D_01dae6a8[1], -1);
    }
    if (mode != 9) {
        func_00242790();
    }
    return func_0023d368();
}
