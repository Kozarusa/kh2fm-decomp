#include "../common/types.h"
extern "C" u8 D_0035ecd8[];
extern "C" u32 func_001058e8(void);
extern "C" u32 func_002fde18(...);

struct SaveFlags {
    u32 enabled : 1;
    u32 mode : 2;
    u32 shown : 1;
    u32 flag4 : 1;
    u32 flag5 : 1;
    u32 flag6 : 1;
    u32 flag7 : 1;
    u32 flag8 : 1;
    u32 level : 2;
};

struct SaveBlock {
    u16 first;
    u16 second;
    SaveFlags flags;
};

u32 func_00242880(void) {
    u32 pointer = func_001058e8();
    *(u16*)(pointer + 0x41a0) = 0;
    SaveBlock* block = (SaveBlock*)(pointer + 0x41a0);
    block->second = 0;
    block->flags.enabled = 1;
    block->flags.mode = 1;
    block->flags.shown = 1;
    block->flags.flag4 = 0;
    block->flags.flag5 = 0;
    block->flags.flag6 = 0;
    block->flags.flag7 = 0;
    block->flags.flag8 = 0;
    block->flags.level = 2;
    return func_002fde18(D_0035ecd8, 0, 4);
}
