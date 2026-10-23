#include "../common/types.h"
extern "C" s32 D_00351f30;
extern "C" u32 D_01d49980[];
extern "C" s32 func_001c9d88(u32);

s32 func_001c9c00() {
    s32 index = 0;
    if (D_00351f30 > 0) {
        u32* pointer = D_01d49980;
        do {
            s32 ok = func_001c9d88(*pointer);
            pointer = pointer + 1;
            if (ok == 0) {
                return 0;
            }
            index = index + 1;
        } while (index < D_00351f30);
    }
    return 1;
}
