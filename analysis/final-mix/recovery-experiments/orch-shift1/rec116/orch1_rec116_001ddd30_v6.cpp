#include "../common/types.h"
extern "C" u8* D_01d9e348;
extern "C" u64 func_001dde40(...);

void func_001ddd30(u8* target) {
    u8* node = 0;
    u8* next;
    u8 found = 0;
    do {
        next = D_01d9e348;
        if (node != 0) {
            next = *(u8**)(node + 0x14);
        }
        node = next;
        if (next == 0) {
            goto done;
        }
    } while (next != target);
    found = 1;
done:
    if (found) {
        func_001dde40(target);
    }
}
