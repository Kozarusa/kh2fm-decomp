#include "../common/types.h"
struct Pool {
    u8 entries[0x400];
    s32 table[32];
    s32 count;
};
extern "C" Pool D_01e2a5f8;
extern "C" s32 func_002bac78(void*, s32, s32, s32, s32, s32, s32);

s32 func_002baf48(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f) {
    Pool* pool = &D_01e2a5f8;
    pool->count = pool->count - 1;
    return func_002bac78(pool->entries + pool->table[pool->count] * 0x20, a, b, c, d, e, f);
}
