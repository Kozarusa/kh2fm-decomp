#include "../common/types.h"
extern "C" u8 D_00350e8c;
extern "C" u32 D_0034f240;
extern "C" bool func_0019c590(int arg1);
extern "C" u32 func_0019c768(...);
extern "C" u32 func_002be5f8();

u32 func_0019c650(u8* object) {
    register u32 result asm("$17") = 0; // why: original keeps the result in s1 and the object in s0
    u32 flags = *(u32*)(object + 0x10c);
    register u32 hidden asm("$14") = flags & 0x200; // why: original computes the 0x200 test into t6 before the 0x80 test
    if (!(flags & 0x80)) {
        if (hidden) {
            result = 1;
            goto done;
        }
        if (D_00350e8c) {
            result = 1;
            goto done;
        }
        if (func_0019c590((int)object)) {
            result = 1;
            goto done;
        }
        if (D_0034f240 & 0x1000) {
            result = 1;
            goto done;
        }
        if (func_0019c768(object) != 0) {
            result = 1;
            goto done;
        }
        if (func_002be5f8() == 0) {
            goto done;
        }
    }
    result = 1;
done:
    return result;
}
