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
    u8 result;
    D_00347f80->target = wanted;
    Node** list = &D_00347f80->next;
    while (1) {
        if (cursor == 0) {
            node = *list;
        } else {
            node = cursor->next;
        }
        cursor = node;
        if (node == 0) {
            result = 0;
            break;
        }
        if (node == wanted) {
            result = 1;
            break;
        }
    }
    return result;
}
