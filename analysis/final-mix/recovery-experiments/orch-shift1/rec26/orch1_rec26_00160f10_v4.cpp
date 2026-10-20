#include "../common/types.h"
struct Node {
    u8 pad0[0x80];
    Node* next;
    u8 pad1[0x1a8 - 0x84];
    s32 key;
};
extern "C" Node* D_004f3b38;
extern "C" void func_001604d8(Node*);

void func_00160f10(s32 value) {
    Node* node = 0;
    Node* next;
    while ((node = next = node ? node->next : D_004f3b38) != 0) {
        if (next->key == value) {
            func_001604d8(next);
        }
    }
}