#include "../common/types.h"
extern "C" s32 func_002859a0(void);
// why: matches the accepted CmTop::GetPartyInfo definition (no arguments, pointer result); extern "C" because the probe linker script defines only the plain symbol
extern "C" void* func_00258108(void);
extern "C" s32 func_002811b0(s32,s32);
extern "C" s32 func_001b7818(s32);

void func_00287358(s32 member, u32 bit) {
    s32 sram = func_002859a0();
    void* party = func_00258108();
    if (member == 0) {
        u32* word = (u32*)((bit >> 5) * 4 + (sram + 0x50));
        u32 mask = 1 << (bit & 31);
        u32 value = *word;
        if ((value & mask) == 0) {
            *word = value | mask;
        }
    } else {
        s32 slot = func_001b7818(func_002811b0((s32)party, member)) - 2;
        u32 index = slot * 48 + bit;
        u32* word = (u32*)((index >> 5) * 4 + (sram + 0x5c));
        u32 mask = 1 << (index & 31);
        u32 value = *word;
        if ((value & mask) == 0) {
            *word = value | mask;
        }
    }
}
