#include "../common/types.h"
extern "C" void* D_0036a3ac[];

u64 func_00109f58(u32 kind, s32 flag, u8 value) {
    // why: the original jump table lives at D_0036a3ac; a computed goto reads it directly.
    static void* targets[] = {&&both, &&compare, &&plain, &&fallback};
    if (kind >= 12) {
        goto fallback;
    }
    goto *D_0036a3ac[kind];
both:
    if (flag == 0) {
        return 0x8000000044ULL;
    }
compare: {
    u64 result = 42;
    if (value != 0x80) {
        result = 0x8000000044ULL;
    }
    return result;
}
plain:
    return 0x8000000044ULL;
fallback:
    return 0x44;
}
