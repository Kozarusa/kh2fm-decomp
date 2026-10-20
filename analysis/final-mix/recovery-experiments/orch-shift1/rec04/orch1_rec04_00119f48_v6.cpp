#include "../common/types.h"
extern "C" f32 D_0036a898[];
extern "C" s64 func_00112c48();
extern "C" f32 func_00112c28();
extern "C" f32 func_00112c38();

s32 func_00119f48(u64 flags) {
    s64 status = func_00112c48();
    if (status >= 0 && (flags & 0x200) == 0) {
        f32 first = func_00112c28();
        f32* offset = D_0036a898;
        f32 sum = first + *offset;
        f32 limit = func_00112c38();
        if (limit <= sum) {
            return 1;
        }
        return 0;
    }
    return 0;
}
