#include "../common/types.h"

extern "C" u32 func_002b78ec(u32);

void func_002b8a70(u8* base)
{
    volatile u8* input = base;
    func_002b78ec((u32)(input + 0x8000));
    *(u32*)(input + 0x48000) = 0;
}
