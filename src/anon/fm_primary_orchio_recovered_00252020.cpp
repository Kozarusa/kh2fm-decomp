#include "../common/types.h"
extern "C" u32 func_0028acc8(u32);
extern "C" u32 func_002892f8(u32);
extern "C" u32 func_00288e88(u32);
extern "C" u32 D_0035ee5c;

void func_00252020() {
    if (D_0035ee5c) {
        u32 count = func_002892f8(D_0035ee5c);
        if (!func_0028acc8(D_0035ee5c) && count) {
            func_00288e88(D_0035ee5c);
            return;
        }
    }
}
