#include "../common/types.h"
struct Manager;
struct ManagerTable {
    void* slot0;
    void (*release)(Manager*, s32);
};
struct Manager {
    ManagerTable* table;
};
struct Node {
    u8 pad00[0x14];
    s32 handle14;
    s32 handle18;
    u8 pad1c[0x8];
    s32 program24;
    Node* next28;
    Node* child2c;
    s32 pad30;
    s32 extra34;
};
extern "C" u8 D_0034dbf8[];
extern "C" Manager* D_004f6288;
extern "C" u32 func_0016c7d8(u32);
extern "C" u64 func_0016ce90(...);
extern "C" u64 func_001da458(...);
extern "C" s32 func_001da558(Node*, u8*, s32, s32);
extern "C" void func_0016d1f0(s32);

u64 func_0016cab8(Node* object) {
    if (object->program24 != 0) {
        func_001da458(object, object->program24, 0, 0);
        func_001da558(object, D_0034dbf8, 0, 0);
    }
    Node* child = object->child2c;
    while (child != 0) {
        Node* next = child->next28;
        if (child != 0) {
            func_0016cab8(child);
            func_0016c7d8((u32)child);
        }
        child = next;
    }
    D_004f6288->table->release(D_004f6288, object->handle14);
    D_004f6288->table->release(D_004f6288, object->handle18);
    if (object->extra34 != 0) {
        func_0016d1f0(object->extra34);
    }
    return func_0016ce90(object);
}
