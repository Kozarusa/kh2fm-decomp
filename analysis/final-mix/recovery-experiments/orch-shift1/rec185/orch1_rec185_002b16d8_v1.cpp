#include "../common/types.h"
extern "C" u8* D_0035f634;
s32 func_002b16d8() {
    s32 second = *(s32*)(D_0035f634 + 23292);
    s32 first = *(s32*)(D_0035f634 + 22012);
    return first == 126 && second == 129;
}
