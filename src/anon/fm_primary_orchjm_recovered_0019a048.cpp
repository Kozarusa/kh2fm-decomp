#include "../common/types.h"
struct Node;
struct NodeTable {
    u32 pad0;
    u32 pad4;
    s32 (*test)(Node*, s32);
};
struct NodeInfo {
    u8 pad[0x2c];
    u16 kind;
};
struct Node {
    NodeTable* table;
    u8 pad04[0x5c];
    Node* next;
    u8 pad64[0x8];
    NodeInfo* info;
};
struct Flags {
    u32 skip : 1;
    u32 pad1 : 2;
    u32 hit : 1;
    u32 clear4 : 1;
    u32 rest : 27;
};
struct Owner {
    u32 pad0;
    Flags flags;
    u8* mode;
    Node* first;
    u32 pad10;
    f32 timer;
};
extern "C" f32 D_00349e10;
extern "C" s32 func_00191a50();
extern "C" u32 func_0019a1a0(s32,s64);
extern "C" void func_0019b180(Owner*, s32);

void func_0019a048(Owner* owner, s32 value) {
    owner->flags.hit = 0;
    owner->flags.clear4 = 0;
    if ((u8)owner->flags.skip != 0) {
        return;
    }
    if (*owner->mode == 4) {
        func_0019b180(owner, value);
        return;
    }
    if (func_00191a50() != 0) {
        return;
    }
    if (0.0f < owner->timer) {
        owner->timer = owner->timer - D_00349e10;
    }
    Node* previous = 0;
    register u32 six asm("$20") = 6; // why: original sets the mode constant 6 in s4 before the kind constant
    register u32 one asm("$19") = 1; // why: original keeps the kind constant 1 in s3 and mode 6 in s4
    Node* node;
    while ((node = (previous == 0 ? owner->first : previous->next)), (previous = node), node != 0) {
        if (*owner->mode == six && node->info->kind != one) {
            continue;
        }
        if (node->table->test(node, value) == 0) {
            continue;
        }
        owner->flags.hit = 1;
        if (func_0019a1a0((s32)owner, (s64)node) != 0) {
            return;
        }
    }
}
