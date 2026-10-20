#include "../common/types.h"
extern "C" u8 D_004f3704[];

void func_0015cc18(s32 index, u8 a, u8 b, u8 c, u8 d) {
    u8* entry = D_004f3704 + index * 4;
    entry[0] = a;
    entry[1] = b;
    entry[2] = c;
    entry[3] = d;
}
