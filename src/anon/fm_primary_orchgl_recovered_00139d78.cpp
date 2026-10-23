#include "../common/types.h"
struct Node {
    u8 pad0[4];
    Node* next;
    u8 pad8[92];
    Node* target;
};
extern "C" Node* D_00347f80;

// Preserve original registry aliases.
u32 func_00139d78(Node* wanted) asm("_Z16u_call4_00139d78jjjj");

u32 func_00139d78(Node* wanted) {
    Node* cursor = 0;
    u32 result;
    D_00347f80->target = wanted;
    // why: the original reloads the list head after the store
    Node* head = *(Node* volatile*)&D_00347f80;
    Node** list = &head->next;
    while ((cursor = cursor == 0 ? *list : cursor->next) != 0) {
        if (cursor == wanted) {
            result = 1;
            goto done;
        }
    }
    result = 0;
done:
    return result & 0xff;
}
