#include "../common/types.h"
extern "C" f32 D_0036dd58;
extern "C" u32 func_001c0298(...);
// why: accepted definition (auto80_199_queue.cpp) adds six unnamed unused u32 placeholders; the original call sets only a0/a1
extern "C" u8* func_0019fee8(u8* a0, s32 a1);
// why: accepted C++ definition fm_primary_orchdm_recovered_001c0410.cpp fails the isolated probe link (v1), exact types kept
extern "C" void func_001c0410(u8* target, u8* source, u8* extra);

u8* func_001c0320(u8* object, u8* source, u8* flag) {
    u32 found = func_001c0298(object, source, flag);
    *flag = found;
    if (found != 0) {
        s32 key = *(s32*)(source + 0x20);
        if (key != *(s32*)(object + 0x24)) {
            *(s32*)(object + 0x24) = key;
            *(s32*)(object + 0x28) = 0;
        } else {
            *(s32*)(object + 0x28) = *(s32*)(object + 0x28) + 1;
        }
        u8* owner = *(u8**)object;
        if (owner != 0 && (*(u32*)(owner + 0x588) & 4) != 0) {
            f32* scale = &D_0036dd58;
            asm("" : "+r"(scale)); // why: original materializes the full address with lui/addiu before the load
            *(f32*)(object + 0x2c) = *scale;
        }
    }
    u8* entry = func_0019fee8(*(u8**)(source + 0x28), *(s32*)(object + 0x28));
    if (*(u16*)(entry + 0x26) != 0) {
        func_001c0410(object, source, entry);
    }
    u32 bit = *(u32*)(source + 0x1c);
    u32* words = (u32*)(object + 4);
    u32* slot = words + (bit >> 5);
    *slot = *slot | (1 << (bit & 0x1f));
    return entry;
}
