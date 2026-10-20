#include "../common/types.h"
struct Link {
    u8 pad[0x14];
    Link* next;
};
extern "C" Link* D_01d9e348;
extern "C" void func_001e01e8(Link*, s32, u32);

void func_001e0230(s32 first, u32 second) {
    Link* node = 0;
repeat:
    {
        Link* next;
        if (node == 0) {
            next = D_01d9e348;
        } else {
            next = node->next;
        }
        node = next;
        if (next != 0) goto call;
        return;
call:
        func_001e01e8(next, first, second);
        goto repeat;
    }
}
