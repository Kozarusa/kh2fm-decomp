#include "../common/types.h"
extern "C" u32 func_002891e8(...);
extern "C" u32 func_002469a0(...);
extern "C" u32 func_00139d78(...);
extern "C" void func_00138c10(u8*, u64);
// why: src/tozawa/smenu_heco.cpp declares u32 func_00246840(u32) and uses the u32 result; here the original sets no a0 before the jal, so the argument is left out to keep the bytes exact
extern "C" u32 func_00246840(void);
extern "C" u8* func_00243230(u32 value, u32 index);
extern "C" s32 D_0035ed20;
extern "C" u8* D_0035ed34;
extern "C" s8 D_0035ed44;

u8* func_00247c20(void) {
    u32 select = func_002891e8(D_0035ed20);
    u32 slot = func_002469a0(select);
    if (((D_0035ed44 >> slot) ^ 1) & 1)
        // why: this exit returns the func_002469a0 value untouched in v0; the return type follows the tail func_00243230 (accepted u8*)
        return (u8*)slot;
    if (func_00139d78(D_0035ed34 + select * 408)) {
        u8* entry = D_0035ed34 + select * 408;
        if (*(s32*)(entry + 388) != 82)
            func_00138c10(entry, 82);
    }
    if (func_00246840())
        slot += 4;
    return func_00243230(4, slot);
}
