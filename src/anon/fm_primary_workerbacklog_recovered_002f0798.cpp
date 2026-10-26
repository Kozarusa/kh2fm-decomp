#include "../common/types.h"

typedef void (*Method)(u32);
extern "C" u32 func_0010c7e8(u32);

void func_002f0798(u32* param_1) {
    u32 first = *param_1;
    u32 target = func_0010c7e8(*(u32*)(first + 4));
    Method method = *(Method*)(*(u32*)target + 0x28);
    method(target);
}
