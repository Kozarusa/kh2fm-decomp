#include "../common/types.h"
extern "C" u32 func_001dca30(s32, u32, u32);
// why: the accepted definition (fm_primary_callbackaddress_recovered_001e0128.cpp) is void, but this function uses the v0 it leaves as a 32-bit pointer, so the return type is taken from the registers; C linkage for the isolated link
extern "C" u32 func_001e0128(u32);
// why: parameter and return types of the accepted definition (misc_1.cpp); C linkage because the C++ name fails the isolated link
extern "C" void func_001e0370(void*);

struct Setting {
    u32 header[4]; // why: word members put u32 in the struct alias set so the bitfield read stays after the u32 stores (lg305 v2 hoisted it)
    u32 enabled : 1;
    u32 unused : 16;
    u32 shared : 1;
    u32 rest : 14;
};

// why: the rate is stored through a word/float union so the store aliases the later word loads and stays third (a plain f32 store was scheduled last, rcfix28 v1)
union Word {
    u32 bits;
    f32 real;
};

// why: void per DEVIATIONS #36: the flag-clear exit leaves entry v0 (entry); the call exit ends in store-only func_001dca30 (stale-b), whose v0 is func_001e0128's result after two later calls (stale-a)

void func_001de9a8(u8* object, u32 owner, Setting* setting, u32 extra, f32 rate) {
    *(u32*)(object + 0x40) = owner;
    *(u32*)(object + 0x48) = extra;
    ((Word*)(object + 0x50))->real = rate;
    *(s32*)(object + 0x54) = -1;
    *(u32*)(object + 0x5c) = 0;
    // why: stored as a word so it may alias the flag word and stays before the flag load
    *(u32*)(object + 0x44) = (u32)setting;
    *(u32*)(object + 0x4c) = 0;
    *(u32*)(object + 0x58) = 0;
    if ((u8)setting->enabled) { // why: the u8 cast reproduces the original's second andi 0xff
        *(u32*)(object + 0x5c) = 1;
    }
    if (setting->shared) {
        *(u32*)(object + 0x5c) |= 2;
    }
    if (*(u32*)((u8*)setting + 0x10) & 0x10000) {
        u32 entry = func_001e0128(0x40);
        func_001e0370((void*)entry);
        *(u32*)(object + 0x58) = entry;
        func_001dca30(*(u32*)(object + 0x40), entry + 0x20, 2);
        *(u32*)(object + 0x5c) |= 4;
    }
}
