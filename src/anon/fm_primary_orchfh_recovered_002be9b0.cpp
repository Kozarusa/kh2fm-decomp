#include "../common/types.h"
typedef void (*Method)(s32);
extern "C" s32 func_002be908(s32);
extern "C" s32 func_002c1dc0();

s32 func_002be9b0() {
    s32 object = 0;
    while ((object = func_002be908(object)) != 0) {
        Method method = *(Method*)(*(s32*)object + 0x7c);
        method(object);
    }
    return func_002c1dc0();
}
