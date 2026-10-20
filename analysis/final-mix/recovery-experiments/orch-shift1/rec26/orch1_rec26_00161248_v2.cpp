#include "../common/types.h"
extern "C" u8* D_004f3b38;
extern "C" void func_00160940(u8* object, s32 value, f32 scale);

void func_00161248(s32 value, f32 scale) {
    u8* node = 0;
    u8* next;
    for (;;) {
        if (node != 0) {
            goto advance;
        }
        next = D_004f3b38;
    join:
        node = next;
        if (next != 0) {
            goto body;
        }
        return;
    body:
        func_00160940(next, value, scale);
        continue;
    advance:
        next = *(u8**)(node + 0x80);
        goto join;
    }
}