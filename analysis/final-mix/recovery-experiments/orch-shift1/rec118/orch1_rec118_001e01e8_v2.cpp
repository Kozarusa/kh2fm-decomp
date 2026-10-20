#include "../common/types.h"

void func_001e01e8(s32 object, s32 expected, u32 replacement) {
    s32 node = *(s32*)(object + 0xc);
    while (node != 0) {
        s32 next;
        if (((*(u32*)(*(s32*)(node + 0x44) + 0x10) & 0x200) == 0) &&
            (*(s32*)(node + 0x48) == expected)) {
            *(u32*)(node + 0x48) = replacement;
        }
        if (node == 0) {
            next = *(s32*)(object + 0xc);
        } else {
            next = *(s32*)(node + 0x60);
        }
        node = next;
    }
}
