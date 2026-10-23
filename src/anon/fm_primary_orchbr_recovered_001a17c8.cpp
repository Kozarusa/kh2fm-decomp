#include "../common/types.h"
extern "C" u64 func_001a1840(...);

struct Pool {
    u8 pad[0x9a00];
    s32 table[64];
    s32 count;
};
extern "C" Pool D_01c62fb8;

void func_001a17c8(u8* object) {
    func_001a1840();
    s32 count = *(s32*)(object + 600) - 1;
    *(s32*)(object + 600) = count;
    if (count < 1) {
        s32 index = D_01c62fb8.count;
        D_01c62fb8.count = index + 1;
        D_01c62fb8.table[index] = (((s32)object - (s32)&D_01c62fb8) >> 3) * 0x3f2b3885;
    }
}
