#include "../common/types.h"
extern "C" u32 func_001058e8(void);
extern "C" u64 func_0014ca80(s32, u64, u64, u64, u64);

void func_0014cc40(u64 a, u64 b, u64 c, u64 d, s32 index) {
    s32* base = (s32*)(func_001058e8() + 0x2444);
    s32* entry = base + index;
    func_0014ca80(entry[2], a, b, c, d);
}