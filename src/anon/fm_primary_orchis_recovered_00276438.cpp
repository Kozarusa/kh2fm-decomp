#include "../common/types.h"
extern "C" u32 D_0035f200;
extern "C" s32 func_002892f8(u32);
extern "C" u32 func_0028acc8(u32);
extern "C" u32 func_00288e88(u32);

void func_00276438() {
    if (D_0035f200 != 0) {
        s32 count = func_002892f8(D_0035f200);
        u32 result = func_0028acc8(D_0035f200);
        if (result == 0 && count != 0) {
            func_00288e88(D_0035f200);
            return;
        }
    }
}
