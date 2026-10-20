#include "../common/types.h"
struct Pool {
    u8 entries[160];
    s32 freeList[8];
    s32 count;
};
extern "C" Pool D_01d48cc8;
extern "C" void func_001b8450(u8*, s32, s32);

u8* func_001b8680(s32 a, s32 b) {
    D_01d48cc8.count = D_01d48cc8.count - 1;
    s32 index = D_01d48cc8.freeList[D_01d48cc8.count];
    u8* entry = D_01d48cc8.entries + index * 20;
    func_001b8450(entry, a, b);
    return entry;
}
