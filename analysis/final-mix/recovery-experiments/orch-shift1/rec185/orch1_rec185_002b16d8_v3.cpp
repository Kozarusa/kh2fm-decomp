#include "../common/types.h"
extern "C" u8* D_0035f634;
s32 func_002b16d8() {
    register s32 second asm("$13") = *(s32*)(D_0035f634 + 23292); // why: original second field occupies t5
    asm("" : "+r"(second)); // why: original loads second field before testing first field
    s32 first = *(s32*)(D_0035f634 + 22012);
    return first == 126 && second == 129;
}


