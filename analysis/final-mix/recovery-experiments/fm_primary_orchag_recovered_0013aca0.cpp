#include "../common/types.h"
struct Pool {
    u8 pad0[0x6e40];
    s32 slots[36];
    s32 count;
};
extern "C" Pool* D_00348058;
extern "C" void func_0013aa78(s32, s32, s32, s32, s32, s32, s32);

s32 func_0013aca0(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f) {
    Pool* pool = D_00348058;
    s32 index = pool->count - 1;
    pool->count = index;
    s32 result = (s32)pool + pool->slots[index] * 0x310;
    func_0013aa78(result, a, b, c + 0x20, d, e, f);
    return result;
}
