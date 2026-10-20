#include "../common/types.h"
struct Node {
    u8 pad0[4];
    Node* next;
    u8 pad8[92];
    Node* target;
};
extern "C" Node* D_00347f80;

u8 func_00139d78(Node* wanted) {
    Node* cursor = 0;
    Node* node;
    D_00347f80->target = wanted;
    while (1) {
        if (cursor == 0) {
            node = D_00347f80->next;
        } else {
            node = cursor->next;
        }
        cursor = node;
        if (node == 0) {
            return 0;
        }
        if (node == wanted) {
            return 1;
        }
    }
}
