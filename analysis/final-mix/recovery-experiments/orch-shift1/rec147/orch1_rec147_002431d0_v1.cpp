#include "../common/types.h"
extern "C" u32 func_001058e8(void);
bool func_002431d0(s32 value, s32 offset) {
    u32 pointer = func_001058e8();
    u32 index = value * 8 + offset;
    return (*(u32*)(pointer + (index >> 5) * 4 + 0x49d8) & (1u << (index & 31))) != 0;
}
