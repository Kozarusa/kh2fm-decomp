#include "../common/types.h"
typedef s32 (*Func)(s32*, s32, s32, s32, s32, s32, s32, s32);

s32 func_001231f8(s32* object, s32 a, s32 b, s32 c, s32 d, u8 flag, s32 extra) {
    Func function = *(Func*)(*object + 0x4c);
    return function(object, a, b, c, d, 0, flag, extra);
}
