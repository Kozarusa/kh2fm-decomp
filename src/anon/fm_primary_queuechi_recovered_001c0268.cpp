#include "../common/types.h"
bool func_001c0268(u32 object, u32 other) {
    u32 index = *(u32*)(other + 28);
    u32 offset = (index >> 5) * 4;
    u32 mask = 1u << (index & 31);
    return (*(u32*)(object + offset + 4) & mask) == 0;
}
