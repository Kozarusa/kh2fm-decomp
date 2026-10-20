#include "../common/types.h"
struct Node {
    Node* next;
    s32 second;
    s32 third;
    s32 first;
    f32 value;
    Node* link;
};
extern "C" Node* D_01c62140;

void func_001995b8(s32 from, s32 to) {
    Node* previous = 0;
    while (1) {
        Node* node;
        if (previous != 0) {
            node = previous->link;
        } else {
            node = *(Node* volatile*)&D_01c62140; // why: original loads head only on this path
        }
        if (node == 0) {
            break;
        }
        previous = node;
        if (node->first == from) {
            node->first = to;
        }
    }
}
