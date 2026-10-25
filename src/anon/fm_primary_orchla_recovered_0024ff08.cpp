#include "../common/types.h"
extern "C" u32 D_0035ee34;
extern "C" u32 D_0035ee38;
extern "C" u32 D_0035ee3c;
extern "C" u32 D_0035ee40;
extern "C" u32 D_0035ee44;
// why: copied from fm_primary_orchef_recovered_002638e0.cpp, which calls it
extern "C" u32 func_00287bc0(void);
// why: matches the definition in fm_global_recovered_09.cpp
extern "C" void func_00287d68(void);
// why: copied from fm_primary_orchef_recovered_00263e18.cpp, which calls it
extern "C" u8 func_00287db0(void);
// why: copied from fm_primary_orcheb_recovered_002519d0.cpp, which calls it
extern "C" u32 func_0028acc8(u32);
// why: copied from fm_primary_orcheb_recovered_002519d0.cpp, which calls it
extern "C" u32 func_00139d78(...);
// why: copied from fm_primary_orchef_recovered_00263e18.cpp, which calls it
extern "C" u32 func_001039f8(void);
// why: no recovered source calls it; no argument registers are set before the call and the result is unused
extern "C" void func_0024ffe0(void);
// why: no recovered source calls it; no argument registers are set before the call and the result is unused
extern "C" void func_00250130(void);

// why: s32 because every exit returns an own constant (0 or 1)

s32 func_0024ff08() {
    u32 mode = func_00287bc0();
    func_00287d68();
    if (func_00287db0()) {
        if (!func_0028acc8(D_0035ee34)) {
            if (!func_0028acc8(D_0035ee38)) {
                if (!func_00139d78(D_0035ee3c)) {
                    if (!func_00139d78(D_0035ee40)) {
                        if (!func_00139d78(D_0035ee44)) {
                            func_001039f8();
                            return 1;
                        }
                    }
                }
            }
        }
    } else if (mode != 0) {
        if (mode == 1) {
            func_00250130();
        }
    } else {
        func_0024ffe0();
    }
    return 0;
}
