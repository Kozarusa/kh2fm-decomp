#include "../common/types.h"
extern "C" u32 func_00287bc0(void);
extern "C" void func_00287d68(void);
extern "C" u8 func_00287db0(void);
extern "C" u32 func_001039f8(void);
extern "C" u32 func_0028acc8(u32);
extern "C" u32 func_00139d78(...);
// why: no recovered source calls these two functions; their results are not used here, so they are declared from the registers (no arguments set)
extern "C" void func_002489d8(void);
extern "C" void func_00248b38(void);
extern "C" u32 D_0035ed4c;
extern "C" u32 D_0035ed50;
extern "C" u32 D_0035ed54;
extern "C" u32 D_0035ed58;
extern "C" u32 D_0035ed5c;

s32 func_00248900() {
    u32 mode = func_00287bc0();
    func_00287d68();
    if (func_00287db0()) {
        if (!func_0028acc8(D_0035ed4c)) {
            if (!func_0028acc8(D_0035ed50)) {
                if (!func_00139d78(D_0035ed54)) {
                    if (!func_00139d78(D_0035ed58)) {
                        if (!func_00139d78(D_0035ed5c)) {
                            func_001039f8();
                            return 1;
                        }
                    }
                }
            }
        }
    } else if (mode != 0) {
        if (mode == 1) {
            func_00248b38();
        }
    } else {
        func_002489d8();
    }
    return 0;
}
