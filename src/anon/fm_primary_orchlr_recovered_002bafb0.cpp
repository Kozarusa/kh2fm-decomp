#include "../common/types.h"
struct FmInitPair { u32 first, second; };
extern "C" FmInitPair D_01e2a5e8;
extern "C" FmInitPair D_01e2a5f0;
extern "C" u8 D_01e2a5f8[];

// Preserve original registry aliases.
void func_002bafb0(u32 phase, u32 priority) asm("_Z16wtarget_002bafb0jjjj");

void func_002bafb0(u32 phase, u32 priority)
{
    if (priority == 0xffffu && phase == 1) { D_01e2a5e8.first = 0; D_01e2a5e8.second = 0; }
    if (priority == 0xffffu && phase == 1) { D_01e2a5f0.first = 0; D_01e2a5f0.second = 0; }
    if (priority == 0xffffu && phase == 1) {
        u8* base = D_01e2a5f8;
        u32* target = (u32*)(base + 0x400);
        s32 index;
        for (index = 0; index < 32; ++index) *target++ = index;
        *(u32*)(base + 0x480) = 32;
    }
}
