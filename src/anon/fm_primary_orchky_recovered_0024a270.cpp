#include "../common/types.h"
extern "C" u32 func_00287bc0(void);
extern "C" void func_00287d68(void);
extern "C" u8 func_00287db0(void);
extern "C" u32 func_001039f8(void);
extern "C" u32 func_0028acc8(u32);
extern "C" u32 func_00139d78(...);
// why: no recovered source calls these two functions; their results are not used here, so they are declared from the registers (no arguments set)
extern "C" void func_0024a348(void);
extern "C" void func_0024a4d0(void);
extern "C" u32 D_0035ed70;
extern "C" u32 D_0035ed74;
extern "C" u32 D_0035ed78;
extern "C" u32 D_0035ed7c;
extern "C" u32 D_0035ed80;

s32 func_0024a270() {
    u32 mode = func_00287bc0();
    func_00287d68();
    if (func_00287db0()) {
        if (!func_0028acc8(D_0035ed70)) {
            if (!func_0028acc8(D_0035ed74)) {
                if (!func_00139d78(D_0035ed78)) {
                    if (!func_00139d78(D_0035ed7c)) {
                        if (!func_00139d78(D_0035ed80)) {
                            func_001039f8();
                            return 1;
                        }
                    }
                }
            }
        }
    } else if (mode != 0) {
        if (mode == 1) {
            func_0024a4d0();
        }
    } else {
        func_0024a348();
    }
    return 0;
}
