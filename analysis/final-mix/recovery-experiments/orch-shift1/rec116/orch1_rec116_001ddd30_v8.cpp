#include "../common/types.h"
extern "C" u8* D_01d9e348;
extern "C" u64 func_001dde40(...);

void func_001ddd30(u8* target) {
    u8* node = 0;
    u8* next;
    u8 found = 0;
    asm("" : "+r"(node));  // why: stops the compiler from peeling the first iteration where node is known to be zero
    do {
        next = node ? *(u8**)(node + 0x14) : D_01d9e348;
        node = next;
        if (next == 0) {
            goto done;
        }
    } while (next != target);
    found = 1;
done:
    asm("" : "+r"(found));  // why: forces the u8 flag to be a real register value merged from both paths (original has andi 0xff)
    if (found) {
        func_001dde40(target);
    }
}
