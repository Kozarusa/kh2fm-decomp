#include "../common/types.h"
struct Pierrot {
    void* table;
    u8 pad0[0x3b0 - 4];
    s32 state;
    u8 pad1[0x588 - 0x3b4];
    u32 flags_a;
    u8 pad2[0x600 - 0x58c];
    u32 flags_b;
    u8 pad3[0xabc - 0x604];
    u32 flags_c;
};
extern "C" u8 D_00350910[];
extern "C" void func_001b3b70(Pierrot*, void*, s32, void*);

void func_001a6bc8(Pierrot* object, void* entry, void* position) {
    func_001b3b70(object, entry, 4, position);
    u32 value_b = object->flags_b;
    u32 value_a = object->flags_a;
    u32 value_c = object->flags_c;
    object->table = D_00350910;
    object->flags_c = value_c | 4;
    object->flags_a = value_a | 0x100;
    object->state = 3;
    object->flags_b = (value_b & 0xffffff87) | 8;
}
