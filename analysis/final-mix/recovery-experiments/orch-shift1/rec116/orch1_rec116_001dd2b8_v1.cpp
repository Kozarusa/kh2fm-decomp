#include "../common/types.h"
extern "C" u8 D_00352af0;
extern "C" u8 D_00352af1;
extern "C" u32 func_00106a18(...);
extern "C" u32 func_00106a60(...);
extern "C" void func_001dd320(u32, u32, u32);

void func_001dd2b8() {
    if (D_00352af1 == 0 && D_00352af0 != 0) {
        u32 first = func_00106a18(0);
        u32 second = func_00106a60(0);
        func_001dd320(first, second, 1);
    }
}
