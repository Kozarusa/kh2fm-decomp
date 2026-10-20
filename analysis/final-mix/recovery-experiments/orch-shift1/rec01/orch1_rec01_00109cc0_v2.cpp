#include "../common/types.h"
struct Node {
    u8 pad[16];
    Node* next;
};
extern "C" Node* D_0033cc78[];
extern "C" Node* D_0033cc90[];

void func_00109cc0(s32 index, Node* node) {
    if (D_0033cc90[index] == 0) {
        D_0033cc78[index] = node;
    } else {
        D_0033cc90[index]->next = node;
    }
    D_0033cc90[index] = node;
}
