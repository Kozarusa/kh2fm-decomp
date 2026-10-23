#include "../common/types.h"

extern "C" u32 func_001dc818(...);

void func_002d0cf0(s32 object)
{
    if (*(s32 *)(object + 0xb0c))
    {
        func_001dc818(*(s32 *)(object + 0xb0c));
        *(u32 *)(object + 0xb0c) = 0;
    }
    *(u32 *)(object + 0xb10) = 0;
    u32 flags = *(u32 *)(object + 0x10c);
    *(u32 *)(object + 0x108) = *(u32 *)(object + 0x108) | 0x403;
    *(u32 *)(object + 0x10c) = flags | 0x80;
}
