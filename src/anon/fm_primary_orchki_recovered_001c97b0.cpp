#include "../common/types.h"
struct FlagWord {
    u32 low : 4;
    u32 flag : 1;
};
extern "C" f32 D_0036e0a4;
extern "C" s32 D_00351f30;
extern "C" s32 D_01d49980[];
extern "C" s32 func_0017e668(...);
extern "C" bool func_0019ba60(...);
extern "C" u32 func_001ad990(f32, f32, f32, void*);
// why: exact types of the accepted definition fm_primary_orchca_recovered_001a8f10.cpp, with C linkage for the probe link
extern "C" s32 func_001a8f10(s32);

// Preserve original registry aliases.
s32 func_001c97b0(s32 part, f32 value) asm("_Z13func_001c97b0Pvf");

s32 func_001c97b0(s32 part, f32 value) {
    s32 handle = func_0017e668(part);
    u8* object = (u8*)handle;
    if (func_0019ba60(handle)) {
        FlagWord* flags = (FlagWord*)(object + 0x7f8);
        if (flags->flag == 0) {
            f32* scale = &D_0036e0a4;
            // why: discarded float-to-unsigned round trip of the scale; its branchy expansion (removed later as dead) keeps the flag word in t7 with the bnezl reload of 2040(s0); without it 8 words differ (pfix3 v2-v7)
            f32 unused = (f32)(u32)*scale;
            // why: the original forms the full address of D_0036e0a4 (lui+addiu) and then loads at offset 0
            asm("" : "+r"(scale));
            func_001ad990(*scale, 0.0f, value, object + 0x82c);
        }
        flags->flag = 1;
    }
    s32* slot = &D_01d49980[D_00351f30++];
    s32 result = func_001a8f10(part);
    *slot = result;
    return result;
}
