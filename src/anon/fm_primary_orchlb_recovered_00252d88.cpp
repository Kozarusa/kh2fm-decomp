#include "../common/types.h"
extern "C" u32 D_0035eea4;
extern "C" s16* D_0035ee90[];
extern "C" u32 func_00139d78(...);
extern "C" u32 func_0023f0c0(...);
extern "C" u32 func_00287bc0(...);
extern "C" u32 func_00287bd0(...);

void func_00252d88() {
    s32 result = 0;
    func_00139d78(D_0035eea4);
    s32 num = func_0023f0c0(D_0035eea4);
    if (num != 0) {
        result = 4;
        if (num != 1) {
            s32 i;
            result = -1;
            for (i = 0; i < 3; i++) {
                s16* entry = D_0035ee90[i];
                s32 j;
                for (j = 0; j < 3; j++) {
                    if (num == *entry++) {
                        result = i + 1;
                        break;
                    }
                }
                if (result >= 0) break;
            }
        }
    }
    if (func_00287bc0() != (u32)result) func_00287bd0(result, 0);
}
