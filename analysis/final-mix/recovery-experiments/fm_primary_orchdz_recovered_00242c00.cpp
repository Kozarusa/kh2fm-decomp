#include "../common/types.h"
extern "C" u32 func_001058e8(void);
extern "C" u32 func_00242b58(void);
extern "C" u32 func_00242b88(s8);
extern "C" u32 func_00242bd0(void);

void func_00242c00(u8 value) {
    u32 pointer = func_001058e8() + 0x41a0;
    u32 result = value == 0;
    *(u32*)(pointer + 4) = (*(u32*)(pointer + 4) & ~32u) | (result << 5);
    if (func_00242bd0() == 0 && func_00242b58() == 0) func_00242b88(1);
}
