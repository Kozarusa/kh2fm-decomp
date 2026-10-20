#include "../common/types.h"
extern "C" u8* D_01c60cd8;

s32 func_0018f070(u8* target) {
    if (target == 0) {
        return 0;
    }
    u8* node = 0;
    while (1) {
        u8* next;
        if (node != 0) {
            next = *(u8**)(node + 0xc0);
        } else {
            next = D_01c60cd8;
        }
        if (next == 0) {
            return 0;
        }
        node = next;
        if (next == target) {
            return 1;
        }
    }
}
