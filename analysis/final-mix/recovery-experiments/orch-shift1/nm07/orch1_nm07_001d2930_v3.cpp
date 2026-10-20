#include "../common/types.h"
extern "C" s32 D_00352668;
extern "C" u8 D_0036e3d0[];
extern "C" void func_001a5420(s32, u8*, u32);

void func_001d2930(u32 argument, s32 count) {
    if (D_00352668 == 0) {
        return;
    }
    if (count <= 0) {
        return;
    }
    u8* table = D_0036e3d0;
    s32 remaining = count;
    do {
        remaining--;
        func_001a5420(D_00352668, table, argument);
    } while (remaining != 0);
}
