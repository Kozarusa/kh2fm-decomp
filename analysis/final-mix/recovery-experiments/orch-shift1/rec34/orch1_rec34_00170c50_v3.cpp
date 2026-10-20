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

Node* func_00170c50() {
    Node* result = (Node*)1;
    if (func_00170c38() == 0) {
        Node* current = 0;
        while (1) {
            if (current != 0) {
                result = current->next;
            } else {
                result = D_0034dca0;
            }
            if (result == 0) {
                break;
            }
            current = result;
            if (result->value >= 10000) {
                continue;
            }
            u8 kind = result->kind;
            if (kind == 0) {
                continue;
            }
            if (kind != 3) {
                result = (Node*)1;
                break;
            }
        }
    }
    return result;
}