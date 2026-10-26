#include "../common/types.h"

typedef void (*Method)(u32);

void func_002ecdb0(u32 object) {
    u32 vtable = *(u32*)object;
    Method method = *(Method*)(vtable + 0x24);
    method(object);
}
