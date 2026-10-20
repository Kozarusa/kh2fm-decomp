#include "../common/types.h"

s32 func_002b81b8(s32 value, s32 object, s32 index, s32 count) {
    volatile s32* frame = (volatile s32*)__builtin_frame_address(0);
    frame[0] = value;
    frame[1] = object;
    frame[2] = index;
    frame[3] = count;
    return 0;
}
