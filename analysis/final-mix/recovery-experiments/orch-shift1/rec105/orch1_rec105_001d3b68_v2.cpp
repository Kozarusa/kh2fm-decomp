#include "../common/types.h"
struct Node {
    u8 pad[48];
    Node* next;
};
extern "C" Node* D_01d5ba20;
extern "C" void func_001d3878(Node*);
extern "C" u32 func_00105110(...);

void func_001d3b68() {
    Node* next = D_01d5ba20;
    Node* node;
    while (node = next, node != 0) {
        next = node->next;
        if (node != 0) {
            func_001d3878(node);
            func_00105110(node);
        }
    }
}