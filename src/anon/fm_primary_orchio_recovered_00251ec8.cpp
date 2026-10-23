#include "../common/types.h"
extern "C" u32 func_00139d78(...);
extern "C" u32 func_0023f5b8(...);
extern "C" u8* D_0035ee64;
extern "C" u32 D_00372668[];

void func_00251ec8(s32 index) {
    if (D_0035ee64) {
        if (func_00139d78(D_0035ee64)) {
            u32 item = D_00372668[index];
            func_0023f5b8(D_0035ee64, item, 0);
            return;
        }
    }
}
