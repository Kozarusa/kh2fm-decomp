#include "../common/types.h"
struct Info {
    u8 pad[4];
    u8 key;
};
struct Node {
    u8 pad0[0x40];
    s32 value;
    Info* info;
    u8 pad48[0x18];
    Node* next;
};
struct Owner {
    u8 pad[0xc];
    Node* first;
};

s32 func_001de4b0(Owner* owner, s32 key, s32 value) {
    Node* node = owner->first;
    s32 matched = 0;
    while (node != 0) {
        Node* next = node->next;
        if (key < 0 || node->info->key == key) {
            if (value == 0 || matched) {
                return node->value;
            }
            matched = node->value == value;
        }
        node = next;
    }
    return 0;
}
