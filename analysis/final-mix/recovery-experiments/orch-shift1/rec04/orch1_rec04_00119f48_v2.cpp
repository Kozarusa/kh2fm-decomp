#include "../common/types.h"
extern "C" f32 D_0036a898;
extern "C" s64 func_00112c48();
extern "C" f32 func_00112c28();
extern "C" f32 func_00112c38();

s32 func_00119f48(u64 flags) {
    u64 masked = flags & 0x200;
    if (func_00112c48() >= 0 && masked == 0) {
        f32 sum = func_00112c28() + D_0036a898;
        f32 limit = func_00112c38();
        if (limit <= sum) {
            return 1;
        }
        return 0;
    }
    return 0;
}

