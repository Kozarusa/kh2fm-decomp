#include "../common/types.h"
struct Node {
    u8 pad0;
    u8 kind;
    u8 pad2[0x26];
    s32 value;
    u8 pad2c[0x10];
    Node* next;
};
extern "C" Node* D_0034dca0[];
extern "C" s32 func_00170c38();

s32 func_00170c50() {
    if (func_00170c38() != 0) {
        return 1;
    }
    Node* node = 0;
    while ((node = (node == 0) ? D_0034dca0[0] : node->next) != 0) {
        bool high = node->value >= 10000;
        if (high) {
            continue;
        }
        u8 kind = node->kind;
        if (kind == 0) {
            continue;
        }
        if (kind != 3) {
            return 1;
        }
    }
    return 0;
}
