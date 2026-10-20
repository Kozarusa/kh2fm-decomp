#include "../common/types.h"
struct Node {
    u8 pad0[0x40];
    s32 value;
    u8 pad44[4];
    s32 field48;
    u8 pad4c[0x10];
    u32 flags;
    Node* next;
};
struct Owner {
    u8 pad[0xc];
    Node* first;
};
extern "C" u32 func_001dc700(s32, s8);

void func_001de508(Owner* owner, s32 value) {
    Node* node = owner->first;
    while (node != 0) {
        Node* next = node->next;
        if (node->value == value) {
            node->field48 = 0;
            node->flags = node->flags & 0xfffffffe;
            func_001dc700(value, 0);
            return;
        }
        node = next;
    }
}
