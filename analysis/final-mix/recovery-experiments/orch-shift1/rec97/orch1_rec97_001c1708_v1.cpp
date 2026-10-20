#include "../common/types.h"
extern "C" u32 func_001c1890(...);

void func_001c1708(u8* object) {
    u8* node = *(u8**)(object + 0xc);
    while (node != 0) {
        u8* current = node;
        node = *(u8**)(node + 0x24);
        if (current != 0) {
            func_001c1890(current);
        }
    }
}