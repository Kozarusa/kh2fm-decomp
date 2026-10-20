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
extern "C" Node* D_00352b58;
extern "C" bool func_001dc9e0(Info*);
extern "C" void func_001dfa38(Node*);

void func_001de590(Owner* owner) {
    Node* node = owner->first;
    while (node != 0) {
        Node* next = node->next;
        if (func_001dc9e0(node->info)) {
            u8 bit = (node->info->flags >> 26) & 1;
            if (bit == 0) {
                D_00352b58 = node;
                func_001dfa38(node);
                D_00352b58 = 0;
            }
        }
        node = next;
    }
}
