#include "../common/types.h"
extern "C" u16 D_0035ef70;
s32 func_00257fa8(s32 value) {
    // why: original keeps fallback in v0
    register s32 result asm("$2") = -1;
    s32 bits = D_0035ef70;
    s32 count = 0;
    s32 index = 0;
    do {
        u8 flag = (bits >> index) & 1;
        if (flag == 0) { } else {
            if (count != value) ++count; else { result = index;
                asm("" : "+r"(result)); // why: retain successful result in original v0
                return result; }
        }
        ++index;
    } while (index < 8);
    return result;
}






