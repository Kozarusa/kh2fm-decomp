#include "../common/types.h"
extern "C" u32 func_001058e8(void);
extern "C" u64 func_0014ca80(s32, u64, u64, u64, u64);

void func_0014cc40(u64 a, u64 b, u64 c, u64 d, s32 index) {
    u8* save = (u8*)func_001058e8();
    func_0014ca80(*(s32*)(save + index * 4 + 0x244c), a, b, c, d);
}