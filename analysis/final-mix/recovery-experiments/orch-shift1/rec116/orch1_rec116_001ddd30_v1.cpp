#include "../common/types.h"
extern "C" u8* D_01d9e348;
extern "C" u64 func_001dde40(...);

void func_001ddd30(u8* target) {
    u8* node = 0;
    u8 found = 0;
    while (1) {
        u8* next;
        if (node != 0) {
            next = *(u8**)(node + 0x14);
        } else {
            next = D_01d9e348;
        }
        node = next;
        if (next != 0) {
            if (next == target) {
                found = 1;
                break;
            }
            continue;
        }
        break;
    }
    if (found) {
        func_001dde40(target);
    }
}
