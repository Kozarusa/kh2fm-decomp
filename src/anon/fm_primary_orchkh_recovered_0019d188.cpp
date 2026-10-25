#include "../common/types.h"
struct Info {
    u32 pad[2];
    u32 flags;
};
struct Node;
typedef s32 (*NodeMethod)(Node*);
struct Node {
    NodeMethod* table;
    u32 pad[2];
    Info* info;
};
struct Object {
    u8 pad[40];
    Node* node;
};
extern "C" u32 D_0034f240;
extern "C" u32 func_001c8ab0(void);
// why: accepted C++ definition void func_0019cc20(u32) fails the isolated probe link; extern "C" resolves the plain symbol
extern "C" void func_0019cc20(u32);
extern "C" void func_0019cd40(Object*);
extern "C" void func_0019ce48(Object*);
// why: accepted C++ declaration void func_0019d260(u32) fails the isolated probe link; extern "C" resolves the plain symbol
extern "C" void func_0019d260(u32);

void func_0019d188(Object* object) {
    Node* node;
    if (func_001c8ab0() == 1 || (D_0034f240 & 0x4000) != 0 || (node = object->node) == 0 ||
        (node->info->flags & 0x20000) != 0) {
        func_0019cc20((u32)object);
        return;
    }
    if (node->table[16](node) != 0) {
        func_0019cd40(object);
        func_0019ce48(object);
    }
    func_0019d260((u32)object);
}
