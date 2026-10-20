#include "../common/types.h"

struct Node;
struct Vtable {
    u8 pad[0x14];
    void (*callback)(Node*);
};
struct Node {
    Vtable* vtable;
    Node* next;
    u32 pad8;
    u32 padc;
    s32 id;
};
extern "C" Node* D_00347f80;

void func_001397d8(s32 id) {
    Node* node = 0;
    while ((node = *(Node* volatile*)&(node == 0 ? D_00347f80 : node)->next) != 0) {
        if (node->id == id) {
            node->vtable->callback(node);
        }
    }
}
