#include "../common/types.h"
extern "C" u8* D_01c60cd8;

s32 func_0018f070(u8* target) {
    s32 result = 0;
    if (target != 0) {
        u8* node = 0;
        u8* next;
        do {
            next = node ? *(u8**)(node + 0xc0) : D_01c60cd8;
            if (next == 0) {
                result = 0;
                break;
            }
            result = 1;
            node = next;
        } while (next != target);
    }
    return result;
}
