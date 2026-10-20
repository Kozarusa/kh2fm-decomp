#include "../common/types.h"
extern "C" s32 func_001c0150(...);

void func_0019f950(u32* object, u32 value) {
    s32 count;
    u32* cursor = object;
    *cursor = value;
    cursor[1] = 0;
    func_001c0150(cursor + 0x12);
    cursor = cursor + 3;
    count = 7;
    do {
        *cursor = 0;
        count = count - 1;
        cursor = cursor + 2;
    } while (-1 < count);
}
