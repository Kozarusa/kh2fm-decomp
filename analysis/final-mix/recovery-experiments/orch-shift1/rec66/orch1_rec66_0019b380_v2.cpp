#include "../common/types.h"
struct Block { u8 pad0[2]; u16 size; u8 pad1; u8 key; };
struct Header { u8 pad[8]; u16 count; };
struct Owner { u8 pad0[8]; Header* header; u8 pad1[0x20]; Block* first; };

Block* func_0019b380(Owner* owner, s32 key) {
    s32 index = 0;
    Block* block = owner->first;
    if (owner->header->count != 0) {
        do {
            if (block->key == key) {
                return block;
            }
            index++;
            block = (Block*)((u8*)block + block->size * 12 + 8);
        } while (index < owner->header->count);
    }
    return 0;
}