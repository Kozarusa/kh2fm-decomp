#include "../common/types.h"
extern "C" bool func_00138470(void);
extern "C" u32 func_00138440(void);
extern "C" u32 func_001382e0(void);
extern "C" u8 func_00287db0(void);
extern "C" u32 func_001039f8(void);
extern "C" u32 func_0017a798(void);
extern "C" u32 func_00287da0(void);
s32 func_00263e18() {
    if (!func_00138470() && !func_00138440()) func_001382e0();
    if (func_00287db0()) {
        func_001039f8();
        return 1;
    }
    if (func_00138470()) {
        func_0017a798();
        func_00287da0();
    }
    return 0;
}
