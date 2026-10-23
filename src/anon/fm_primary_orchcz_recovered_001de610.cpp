#include "../common/types.h"
struct Info {
    u8 pad[8];
    s32 flags;
};
struct Node {
    u8 pad0[0x40];
    Info* info;
    u8 pad44[0x1c];
    Node* next;
};
struct Owner {
    u8 pad[0xc];
    Node* first;
};
extern "C" bool func_001dca20(Info*);
extern "C" void func_00321ce8(Node**, Node*);
extern "C" void func_001e0058(Node*);

void func_001de610(Owner* owner) {
    Node* node = owner->first;
    while (node != 0) {
        Node* next = node->next;
        u8 bit = (node->info->flags >> 26) & 1;
        if (bit == 0) {
            if (func_001dca20(node->info)) {
                func_00321ce8(&owner->first, node);
                func_001e0058(node);
            }
        }
        node = next;
    }
}
