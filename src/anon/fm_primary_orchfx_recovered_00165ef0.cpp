#include "../common/types.h"
struct Node165 {
    u8 pad0[8];
    u32 flags;
    Node165* next;
};
extern "C" Node165* D_004f41c0;

Node165* func_00165ef0(Node165* node) {
    Node165* result;
    do {
        result = D_004f41c0;
        if (node != 0) {
            result = node->next;
        }
        node = result;
        if (result == 0) {
            break;
        }
    } while ((result->flags & 2) != 0);
    return result;
}
