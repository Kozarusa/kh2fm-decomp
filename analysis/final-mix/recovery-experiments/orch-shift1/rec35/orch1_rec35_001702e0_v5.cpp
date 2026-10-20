#include "../common/types.h"
struct Node {
    u8 pad0[0x30];
    s32 key;
    u8 pad1[8];
    Node* next;
};
extern "C" Node* D_0034dca0;

Node* func_001702e0(s32 value) {
    Node* previous = 0;
    Node* node;
    while ((node = previous == 0 ? D_0034dca0 : previous->next) != 0) {
        if (node->key == value) {
            return node;
        }
        previous = node;
    }
    return 0;
}