#include "../common/types.h"
extern "C" u32 func_001058e8(void);

void func_00242a90(s32 value) {
    u32 pointer = func_001058e8() + 0x41a0;
    s32 result = 0;
    if (value != 0 && (result = 2, value != 2)) result = 1;
    *(u32*)(pointer + 4) = (*(u32*)(pointer + 4) & ~6u) | (result << 1);
}
