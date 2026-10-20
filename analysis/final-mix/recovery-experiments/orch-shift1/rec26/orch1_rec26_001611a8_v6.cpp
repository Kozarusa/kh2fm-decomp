#include "../common/types.h"
extern "C" u8* D_004f3b38;
extern "C" void func_00160488(u8* object, u32 red, u32 green, u32 blue);

void func_001611a8(u8 red, u8 green, u8 blue) {
    u8* node = 0;
    u8* next;
    for (;;) {
        if (node != 0) {
            goto advance;
        }
        next = D_004f3b38;
    join:
        node = next;
        if (next == 0) {
            return;
        }
        func_00160488(next, red, green, blue);
        continue;
    advance:
        next = *(u8**)(node + 0x80);
        goto join;
    }
}