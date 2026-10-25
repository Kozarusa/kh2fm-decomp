#include "../common/types.h"
extern "C" u32 func_00287bc0(void);
extern "C" void func_00287d68(void);
extern "C" u8 func_00287db0(void);
extern "C" u32 func_001039f8(void);
extern "C" u32 func_0028acc8(u32);
extern "C" u32 func_00139d78(...);
// why: no recovered source calls these two functions; their results are not used here, so they are declared from the registers (no arguments set)
extern "C" void func_0024be68(void);
extern "C" void func_0024bfb8(void);
extern "C" u32 D_0035eda8;
extern "C" u32 D_0035edac;
extern "C" u32 D_0035edb0;
extern "C" u32 D_0035edb4;
extern "C" u32 D_0035edb8;

s32 func_0024bd90() {
    u32 mode = func_00287bc0();
    func_00287d68();
    if (func_00287db0()) {
        if (!func_0028acc8(D_0035eda8)) {
            if (!func_0028acc8(D_0035edac)) {
                if (!func_00139d78(D_0035edb0)) {
                    if (!func_00139d78(D_0035edb4)) {
                        if (!func_00139d78(D_0035edb8)) {
                            func_001039f8();
                            return 1;
                        }
                    }
                }
            }
        }
    } else if (mode != 0) {
        if (mode == 1) {
            func_0024bfb8();
        }
    } else {
        func_0024be68();
    }
    return 0;
}
