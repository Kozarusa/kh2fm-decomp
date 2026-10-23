#include "../common/types.h"

s32 func_002ee040(u8* object) {
    u32* vtable = *(u32**)object;
    s32 (*callback)(u8*) = (s32(*)(u8*))vtable[2];
    if (callback(object) == 0) return 0;

    s32 result = 1;
    u8* current = *(u8**)(object + 8);
    while (current != 0) {
        u8* next = *(u8**)(current + 32);
        s32 childResult = func_002ee040(current);
        s32 normalizedChild = childResult != 0;
        if (result == 0) normalizedChild = 0;
        result = normalizedChild;
        current = next;
    }
    return result;
}
