#include "../common/types.h"
struct Target {
    void** vtable;
};
typedef u32 (*Method)(Target*, s32, s32, u32);
extern "C" u32 func_001a1910(...);

u32 func_001a1950(u8* object, s32 arg1, s32 arg2, u32 value) {
    register u32 flag asm("$7") = value & 0xff; // why: original masks the fourth argument in place in a3
    Target* target = *(Target**)(object + 604);
    if (target == 0) {
        return func_001a1910(object, arg1, arg2, flag);
    }
    return ((Method)target->vtable[30])(target, arg1, arg2, flag);
}
