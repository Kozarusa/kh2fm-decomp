#include "../common/types.h"
extern "C" s32 D_00350c88;
extern "C" u8 D_00350ca0[];
extern "C" void func_001ae620(void);
extern "C" void func_001ae650(void);
extern "C" u64 func_001ae678(...);
extern "C" u64 func_002f79c8(...);
extern "C" s32 func_002f7be8(s32, u32, u32, u8*);
extern "C" s32 func_002f7dc8(void);

s32 func_001ae4c0(s32 sector, u32 count, u32 data) {
    s32 result;
    while (1) {
        if (func_002f79c8(1) != 2 || func_002f7be8(sector, count, data, D_00350ca0) != 1) {
            func_001ae678();
            continue;
        }
        func_001ae620();
        result = func_002f7dc8();
        D_00350c88 = result;
        if (result == 0) {
            break;
        }
        func_001ae650();
    }
    return result;
}
