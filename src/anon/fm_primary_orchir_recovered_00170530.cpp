#include "../common/types.h"

extern "C" u8 *func_00170400(u32, u32, u32);

u8 *func_00170530(u32 first, u32 second, u32 value, u32 fourth)
{
    u8 *object = func_00170400(first, second, fourth);
    *object = 1;
    *(u16 *)(object + 0x38) = value;
    *(u16 *)(object + 0x3a) = 0xffff;
    return object;
}
