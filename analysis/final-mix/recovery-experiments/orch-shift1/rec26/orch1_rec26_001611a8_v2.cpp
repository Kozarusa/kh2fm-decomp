#include "../common/types.h"
extern "C" u8* D_004f3b38;
extern "C" void func_00160488(u8* object, u32 red, u32 green, u32 blue);

void func_001611a8(u8 red, u8 green, u8 blue) {
    u8* node = 0;
    u8* next;
    for (;;) {
        next = D_004f3b38;
        if (node != 0) {
            next = *(u8**)(node + 0x80);
        }
        if (next == 0) {
            return;
        }
        func_00160488(next, red, green, blue);
        node = next;
    }
}