#include "../common/types.h"
extern "C" u8 D_0032bb30[];
extern "C" u64 func_00188e08(...);
extern "C" u64 func_001e0868(...);
extern "C" u64 func_002e7768(...);
extern "C" u64 func_002e77a0(...);
extern "C" u64 func_00319870(...);
extern "C" u64 func_00319930(...);
extern "C" u64 func_003199d0(...);
extern "C" u64 func_00319a60(...);
extern "C" u64 func_00319bd0(...);
extern "C" u64 func_00319d20(...);
extern "C" u64 func_00319d30(...);
extern "C" u64 func_00319d58(...);

// Preserve original registry aliases.
void func_001058f8(s32 initialize, s32 priority) asm("_Z13func_001058f8ii");

void func_001058f8(s32 initialize, s32 priority) {
    if (priority == 0xffff && initialize == 1) {
        u8* base = D_0032bb30;
        asm("" : "+r"(base)); // why: keeps the D_0032bb30 base in one register for all member offsets
        func_00319bd0(base + 12);
        func_00188e08(base + 9456);
        func_00319870(base + 16364);
        func_00319930(base + 16808);
        func_00319d20(base + 18904);
        func_00319d30(base + 18912);
        func_00319d58(base + 18928);
        func_003199d0(base + 18932);
        func_00319a60(base + 19512);
        func_002e7768(base + 21920);
        func_001e0868(base + 65760);
    }
    if (priority == 0xffff && initialize == 0) {
        u8* base = D_0032bb30;
        asm("" : "+r"(base)); // why: keeps the D_0032bb30 base separate from the member offset
        func_002e77a0(base + 21920);
        asm volatile("" ::: "memory"); // why: original calls with jal and returns itself, not a tail call
    }
}
