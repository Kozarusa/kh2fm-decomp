#include "../common/types.h"
extern "C" s32 func_002ff3fc(...);
extern "C" u32 func_002ff2e8(...);
struct Node {
    Node* next;
    Node* prev;
    s32 body[10];
    s32 field30;
    s32 pad34[4];
    s32 field44;
    s16 pad48;
    s16 field4a;
};
extern "C" Node* D_0034d840[2];

void func_00168958(Node* object, s32 value, u32 arg) {
    object->field30 = value;
    object->prev = 0;
    object->field44 = 0;
    object->field4a = 0;
    func_002ff3fc(arg);
    func_002ff2e8(&object->body, arg);
    if (D_0034d840[0] == 0) {
        D_0034d840[1] = object;
        D_0034d840[0] = object;
        object->next = 0;
    } else {
        object->next = D_0034d840[0];
        D_0034d840[0] = object;
    }
}
