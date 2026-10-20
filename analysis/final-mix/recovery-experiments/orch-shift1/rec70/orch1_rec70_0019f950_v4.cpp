#include "../common/types.h"
extern "C" s32 func_001c0150(...);

void func_0019f950(u32* object, u32 value) {
    s32 count;
    // why: original copies the object pointer into s0 before the first store
    register u32* cursor asm("$16") = object;
    asm("" : "+r"(cursor));
    *cursor = value;
    cursor[1] = 0;
    func_001c0150(object + 0x12);
    cursor = cursor + 3;
    count = 7;
    do {
        *cursor = 0;
        count = count - 1;
        cursor = cursor + 2;
    } while (-1 < count);
}
