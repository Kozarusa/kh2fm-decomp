// func_001705a8: exact form found by the KH2FM permuter (orchestration/tools/kh2perm) from an earlier
// attempt or a same-shape accepted sibling. Names and types are provisional.
#include "../common/types.h"
struct Node {
    u8 pad0[40];
    s32 value;
    u8 pad1[16];
    Node* next;
};
struct List {
    Node* head;
    Node* tail;
};
extern "C" List D_0034dca0;
extern "C" List D_0034dcb8;
extern "C" void func_0031e328(List*, Node*);
extern "C" void func_00170188(Node*);

void func_001705a8() {
    D_0034dcb8.head = 0;
    D_0034dcb8.tail = 0;
    Node * node = D_0034dca0.head;
    while (node != 0)
    {
        Node * next = node->next;
        s32 flag = node->value >= 10000;
        if (flag != 0)
        {
            func_0031e328(& D_0034dca0, node);
            if (D_0034dcb8.tail == 0)
            {
                D_0034dcb8.tail = node;
                D_0034dcb8.head = node;
                node->next = 0;
            }
            else
            {
                D_0034dcb8.tail->next = node;
                node->next = 0;
                D_0034dcb8.tail = node;
            }
        }
        node = next;
    }
    node = D_0034dcb8.head;
    while (node != 0)
    {
        Node * next = node->next;
        func_00170188(node);
        node = next;
    }
}
