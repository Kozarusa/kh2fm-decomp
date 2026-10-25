#include "../common/types.h"
extern "C" u32 func_00287bc0(void);
extern "C" u8 func_00287db0(void);
extern "C" u32 func_001039f8(void);
extern "C" void func_00287d68(void);
extern "C" u32 func_0028acc8(u32);
extern "C" u32 func_00139d78(...);
// why: no recovered source calls these two; derived from registers (no arguments, result unused)
extern "C" void func_0024d7a0(void);
extern "C" void func_0024d910(void);
extern "C" u32 D_0035edcc;
extern "C" u32 D_0035edd0;
extern "C" u32 D_0035edd4;
extern "C" u32 D_0035edd8;
extern "C" u32 D_0035eddc;

s32 func_0024d6c8(void) {
    u32 mode = func_00287bc0();
    func_00287d68();
    if (func_00287db0()) {
        if (func_0028acc8(D_0035edcc) || func_0028acc8(D_0035edd0) || func_00139d78(D_0035edd4) ||
            func_00139d78(D_0035edd8) || func_00139d78(D_0035eddc)) return 0;
        func_001039f8();
        return 1;
    }
    if (mode != 0) {
        if (mode == 1) func_0024d910();
    } else {
        func_0024d7a0();
    }
    return 0;
}
