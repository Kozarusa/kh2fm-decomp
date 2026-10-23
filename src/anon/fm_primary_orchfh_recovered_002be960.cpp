#include "../common/types.h"
typedef void (*Method)(s32);
extern "C" s32 func_002be908(s32);

s32 func_002be960() {
    s32 object = 0;
    while ((object = func_002be908(object)) != 0) {
        Method method = *(Method*)(*(s32*)object + 0x80);
        method(object);
    }
    return object;
}
