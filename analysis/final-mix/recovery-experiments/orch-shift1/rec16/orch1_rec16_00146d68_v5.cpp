#include "../common/types.h"
typedef unsigned int Quad __attribute__((mode(TI)));

struct Node {
    u8 pad0[0x40];
    Quad source[4];
    Quad dest[4];
    u8 pad1[0x110 - 0xc0];
    Node* next;
};

struct Holder {
    u8 pad0[4];
    u8* table;
    u8 pad1[8];
    s32 count;
    u8 pad2[0x5360 - 0x14];
    s32 cleared;
};

void func_00146d68(Holder* holder) {
    holder->cleared = 0;
    s32 count = holder->count;
    if (count > 0) {
        Node** slot = (Node**)(holder->table + 0x2c);
        do {
            Node* node = *slot;
            if (node == 0) {
                *slot = 0;
            } else {
                do {
                    Quad* source = node->source;
                    Quad* dest = node->dest;
                    // why: keeps the pointer comparison from being folded away
                    asm("" : "+r"(dest));
                    if (dest != source) {
                        Quad a = source[0];
                        Quad b = source[1];
                        Quad c = source[2];
                        Quad e = source[3];
                        dest[0] = a;
                        dest[1] = b;
                        dest[2] = c;
                        dest[3] = e;
                    }
                    node = node->next;
                } while (node != 0);
                *slot = 0;
            }
            count--;
            slot += 12;
        } while (count != 0);
    }
}


