#include "../common/types.h"
struct Head {
    u64 word[4];
} __attribute__((packed));
struct Block {
    Head head;
    u32 last;
};
extern "C" Block D_00363630;

// Preserve original registry aliases.
void func_002ed268(Block* source) asm("_Z16wtarget_002ed268jjjj");

void func_002ed268(Block* source) {
    D_00363630 = *source;
}
