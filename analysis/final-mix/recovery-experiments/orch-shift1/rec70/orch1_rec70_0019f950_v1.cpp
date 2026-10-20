#include "../common/types.h"
extern "C" s32 func_001c0150(...);

void func_0019f950(u32* object, u32 value) {
    s32 count;
    *object = value;
    object[1] = 0;
    func_001c0150(object + 0x12);
    object = object + 3;
    count = 7;
    do {
        *object = 0;
        count = count - 1;
        object = object + 2;
    } while (-1 < count);
}
