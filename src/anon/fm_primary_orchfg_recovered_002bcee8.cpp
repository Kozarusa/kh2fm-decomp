#include "../common/types.h"
extern "C" s32 D_00361768[];
extern "C" u32 func_002bc470(s32);

u32 func_002bcee8(s32* out) {
    s32 count = 26;
    s32* source = D_00361768;
    u32 result;
    do {
        count = count - 1;
        out[0] = *source;
        out[1] = -1;
        out[2] = 0;
        result = func_002bc470(*source);
        out = out + 3;
        source = source + 1;
    } while (count >= 0);
    return result;
}
