#include "../common/types.h"
extern "C" s32 D_0034f240;

s32 func_001dc738(s32* object) {
    s32 flags = object[2];
    s32 result = 0;
    u8 bit;
    if ((flags & 0x400000) != 0) goto set;
    if ((D_0034f240 & 0x20) != 0 && object[1] != 3) goto set;
    bit = (flags >> 26) & 1;
    if (bit == 0) goto done;
set:
    result = 1;
done:
    return result;
}