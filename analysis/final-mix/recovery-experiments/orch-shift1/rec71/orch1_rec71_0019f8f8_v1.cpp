#include "../common/types.h"
extern "C" u32 func_001c0150(...);

void func_0019f8f8(u32* object, u32 value) {
    *object = value;
    object[1] = 0;
    func_001c0150(object + 18);
    object = object + 3;
    s32 count = 7;
    do {
        *object = 0;
        count = count - 1;
        object = object + 2;
    } while (-1 < count);
}
