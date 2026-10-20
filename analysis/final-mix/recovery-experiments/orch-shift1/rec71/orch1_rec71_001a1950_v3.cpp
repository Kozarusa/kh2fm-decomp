#include "../common/types.h"
struct Target {
    void** vtable;
};
typedef void (*Method)(Target*, s32, s32, u32);
extern "C" void func_001a1910(u8*, s32, s32, u32);

void func_001a1950(u8* object, s32 arg1, s32 arg2, u32 flag) {
    Target* target = *(Target**)(object + 604);
    flag = flag & 0xff;
    if (target == 0) {
        func_001a1910(object, arg1, arg2, flag);
        return;
    }
    ((Method)target->vtable[30])(target, arg1, arg2, flag);
}
