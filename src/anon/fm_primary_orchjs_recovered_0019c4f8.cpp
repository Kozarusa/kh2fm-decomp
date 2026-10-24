#include "../common/types.h"
extern "C" u32 func_0019c6f0(...);

bool func_0019c4f8(u8* object) {
    bool result = false;
    u32 flags = *(u32*)(object + 0x7f8);
    register u32 enabled asm("$14") = flags & 0x400; // why: original computes the 0x400 test into t6 before the 0x4 test
    if (!(flags & 4)) {
        if (!enabled) {
            result = true;
            goto done;
        }
        if (*(u32*)(object + 0x108) & 0x40) {
            result = true;
            goto done;
        }
        if (*(u32*)(object + 0x160) & 0x8000000) {
            result = true;
            goto done;
        }
        if (func_0019c6f0(object) != 0) {
            result = true;
            goto done;
        }
        if (!(*(u32*)(*(u8**)(object + 0xc) + 8) & 0x2000)) {
            goto done;
        }
    }
    result = true;
done:
    return result;
}
