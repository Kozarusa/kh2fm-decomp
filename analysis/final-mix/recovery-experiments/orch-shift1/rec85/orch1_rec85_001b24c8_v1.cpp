#include "../common/types.h"
struct Node {
    u8 data[24];
    struct Node* next;
};
extern "C" Node* D_01d48c80;
extern "C" void func_001b2488(u8*);
extern "C" void func_00105110(u32*);

void func_001b24c8() {
    Node* node = D_01d48c80;
    while (node != 0) {
        Node* next = node->next;
        if (node != 0) {
            func_001b2488((u8*)node);
            func_00105110((u32*)node);
        }
        node = next;
    }
}
