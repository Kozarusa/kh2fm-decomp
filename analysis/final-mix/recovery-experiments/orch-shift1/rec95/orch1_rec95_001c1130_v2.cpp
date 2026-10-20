#include "../common/types.h"
struct Block { u64 words[8]; } __attribute__((packed));
extern "C" u8 D_01d49388[];
extern "C" u8* func_001c10f8();

Block* func_001c1130() {
    u8* source = func_001c10f8();
    *(Block*)(D_01d49388 + (u32)source[0x24] * 64) = *(Block*)source;
    return (Block*)(D_01d49388 + (u32)source[0x24] * 64);
}
