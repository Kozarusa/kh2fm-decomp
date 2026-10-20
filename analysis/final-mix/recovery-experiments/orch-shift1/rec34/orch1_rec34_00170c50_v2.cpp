#include "../common/types.h"
struct Node {
    u8 pad0;
    u8 kind;
    u8 pad2[0x26];
    s32 value;
    u8 pad2c[0x10];
    Node* next;
};
extern "C" Node* D_0034dca0;
extern "C" s32 func_00170c38();

s32 func_00170c50() {
    if (func_00170c38() == 0) {
        Node* current = 0;
        Node* node;
        do {
            node = D_0034dca0;
            if (current != 0) {
                node = current->next;
            }
            if (node == 0) {
                return 0;
            }
            current = node;
        } while (node->value >= 10000 || node->kind == 0 || node->kind == 3);
    }
    return 1;
}