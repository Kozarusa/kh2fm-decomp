#include "../common/types.h"
extern "C" u8* func_0018bae8(u8*, u8*);
extern "C" u8* func_0018bc60(u8*, s32);

u8* func_0018b8e0(u8* object, u8* volatile* out) {
    u8* other = func_0018bc60(object, 0);
    if (other == 0) {
        return 0;
    }
    if ((*(u32*)(other + 0x588) & 8) == 0) {
        return 0;
    }
    if (*(other + 0xa70) != 0) {
        return 0;
    }
    u8* first = func_0018bae8(object, other);
    u8* second = func_0018bae8(other, object);
    if (first != 0) {
        if (second != 0) {
            out[1] = second;
            out[0] = first;
            return other;
        }
    }
    return 0;
}
