#include "../common/types.h"
extern "C" u8 D_01c60d10[];
extern "C" u32 D_0034e948;
extern "C" u32 func_001cd7a8(u8*);
extern "C" u32 func_00190878(void*,u32,u32);

u32 func_00190a28(void* object, u8* other) {
    u32 value = 0;
    if ((*(u32*)(other + 264) & 0x800) == 0) {
        value = func_001cd7a8(D_01c60d10);
    }
    if (value == 0) {
        value = D_0034e948;
    }
    return func_00190878(object, value, 0);
}
