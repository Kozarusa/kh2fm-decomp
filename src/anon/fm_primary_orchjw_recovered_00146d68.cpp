#include "../common/types.h"
typedef unsigned int Quad __attribute__((mode(TI)));

struct Matrix {
    Quad row[4];
    Matrix& operator=(const Matrix& other) {
        if (this != &other) {
            // why: 64-byte matrix copy through t0-t3, lq/sq copy primitive as in accepted 001604f8 and 002c20f8; plain Block copy interleaved (v1, v2)
            asm volatile("lq $8,0(%1); lq $9,16(%1); lq $10,32(%1); lq $11,48(%1); sq $8,0(%0); sq $9,16(%0); sq $10,32(%0); sq $11,48(%0)"
                         : : "r"(this), "r"(&other) : "$8", "$9", "$10", "$11", "memory");
        }
        return *this;
    }
};

struct Node {
    u8 pad0[0x40];
    Matrix source;
    Matrix dest;
    u8 pad1[0x110 - 0xc0];
    Node* next;
};

struct Entry {
    u8 pad0[0x2c];
    Node* head;
};

struct Holder {
    u8 pad0[4];
    Entry* table;
    u8 pad1[8];
    s32 count;
    u8 pad2[0x5360 - 0x14];
    s32 cleared;
};

void func_00146d68(Holder* holder) {
    holder->cleared = 0;
    Entry* table = holder->table;
    s32 count = holder->count;
    for (s32 index = 0; index < count; index++) {
        Node* node = table[index].head;
        while (node != 0) {
            node->dest = node->source;
            node = node->next;
        }
        table[index].head = 0;
    }
}
