#include "../common/types.h"
extern "C" u8* D_01d9e348;
extern "C" u64 func_001dde40(...);

void func_001ddd30(u8* target) {
    u8* node = 0;
    u8 found;
    while (1) {
        u8* next = node ? *(u8**)(node + 0x14) : D_01d9e348;
        if (next == 0) {
            found = 0;
            break;
        }
        node = next;
        if (next == target) {
            found = 1;
            break;
        }
    }
    if (found) {
        func_001dde40(target);
    }
}
