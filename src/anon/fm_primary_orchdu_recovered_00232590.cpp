#include "../common/types.h"
extern "C" u8 D_0035e359;
extern "C" u8 D_003712f0[];
extern "C" u64 func_00227120(...);
extern "C" u64 func_002ff538(...);
extern "C" s64 func_002283e0();

void func_00232590() {
    D_0035e359 = 0;
    if (func_002283e0() != 0) {
        u64 value = func_00227120();
        if (func_002ff538(value, D_003712f0, 12) == 0) {
            D_0035e359 = 1;
        }
    }
}
