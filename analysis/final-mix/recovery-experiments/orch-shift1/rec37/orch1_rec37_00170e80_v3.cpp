#include "../common/types.h"
struct Node {
    u8 pad0[0x28];
    s32 kind;
    s32 size;
    s32 start;
    u8 pad1[0x08];
    Node* next;
};
extern "C" s32 D_0034dc9c;
extern "C" Node* D_0034dca0;
extern "C" u8 D_004fa440[];

s32 func_00170e80() {
    s32 low = D_0034dc9c;
    Node* current = 0;
    s32 high = (s32)D_004fa440;
    while (1) {
        Node* node = D_0034dca0;
        if (current != 0) {
            node = current->next;
        }
        if (node == 0) {
            return low - high;
        }
        current = node;
        if (node->kind < 10000) {
            if (node->kind < 0) {
                low = node->start;
            } else {
                high = node->start + node->size;
            }
        }
    }
}