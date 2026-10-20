#include "../common/types.h"
extern "C" u64 func_00209178(...);

void func_002092e0(s32 object, s32* other, s32 context) {
    if (*other == *(s32*)(object + 0xc)) {
        func_00209178(other, object + *(s32*)(*(s32*)(context + 0xc) + 8) + 0xa0);
    }
}