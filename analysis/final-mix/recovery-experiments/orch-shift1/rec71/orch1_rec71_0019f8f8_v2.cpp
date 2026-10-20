#include "../common/types.h"
extern "C" u32 func_001c0150(...);

void func_0019f8f8(u32* object, u32 value) {
    u32* base = object;
    *base = value;
    base[1] = 0;
    func_001c0150(base + 18);
    u32* cursor = base + 3;
    s32 count = 7;
    do {
        *cursor = 0;
        count = count - 1;
        cursor = cursor + 2;
    } while (-1 < count);
}
