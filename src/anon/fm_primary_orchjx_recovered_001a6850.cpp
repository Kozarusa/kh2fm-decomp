#include "../common/types.h"
struct Target {
    u8 pad0[0x588];
    u32 flags;
};
struct Object {
    u8 pad0[0x1c];
    u32 flags;
    u8 pad20[0x18];
    Target* target;
};
struct Node {
    Object* object;
    u8 pad4[8];
    Node* next;
};
extern "C" Node* D_01c6cb20;
extern "C" bool func_0019ba60(u64);

s32 func_001a6850() {
    Node* node;
    for (node = D_01c6cb20; node != 0; node = node->next) {
        Object* object = node->object;
        if (object->flags & 4) {
            continue;
        }
        Target* target = object->target;
        if (!func_0019ba60((u64)target)) {
            continue;
        }
        u32 flags = target->flags;
        if (!(flags & 0x4000)) {
            continue;
        }
        if (!(flags & 0x400000)) {
            return 1;
        }
    }
    return 0;
}
