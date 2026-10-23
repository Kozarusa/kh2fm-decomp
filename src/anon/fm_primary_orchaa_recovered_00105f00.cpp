#include "../common/types.h"
extern "C" s32 D_0033cbb8[];
extern "C" s32 func_002ff3fc(...);
extern "C" u64 func_002ff538(...);

s32 func_00105f00(u64 value) {
    s32 result = 0;
    if (func_002ff3fc() == 2) {
        s32 *table = D_0033cbb8;
        for (s32 index = 0; index < 19; index++) {
            if (func_002ff538(value, *table++, 2) == 0) {
                return index;
            }
        }
    }
    return result;
}
