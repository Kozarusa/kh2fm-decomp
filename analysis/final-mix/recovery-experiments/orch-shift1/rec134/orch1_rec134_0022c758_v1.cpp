#include "../common/types.h"
extern "C" u32 func_001de4b0(s32,u64,s32);
extern "C" s32 D_0035de84;
extern "C" u32 D_0035de88;
s32 func_0022c758() {
    u32 value = 0;
    do {
        value = func_001de4b0(D_0035de84, 0, value);
        if (!value) return 0;
    } while (D_0035de88 != value);
    return 1;
}
