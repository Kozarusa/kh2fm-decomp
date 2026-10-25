#include "../common/types.h"
extern "C" u8 D_003628f0[];
extern "C" void func_0017f540(u8*, s32, f32, f32);          // copied from accepted caller fm_primary_orchbd_recovered_0017c108.cpp
extern "C" s32* func_001c0d38(u8*, u8*, u32, u32);           // parameter types copied from the accepted definition fm_primary_orchkg_recovered_001c0d38.cpp
extern "C" u32 func_002d1260(void);                         // copied from accepted caller fm_primary_orchkl_recovered_001cad60.cpp
extern "C" s32 func_002e7568(u32, u32, u8*, f32);           // copied from accepted caller fm_primary_orchjo_recovered_002d4868.cpp
// why: no accepted definition or caller; the original loads a1 = 1 and the callee masks its a1 with andi 0xff (flag byte), and the callee writes no v0
extern "C" void func_002db968(u8*, u8);

// Return contract (DEVIATIONS #36): the only exit is the tail call into func_002db968, whose original instructions write no v0 and end in a tail call into
// accepted-void func_002e7340: stale-b (clarification iii).

void func_002dbca0(u8* object, u8 flag) {
    func_0017f540(object + 0x140, 0, 0.0f, 0.0f);
    func_001c0d38(object, (u8*)func_002d1260(), 0x43, 0);
    if (flag != 0) {
        func_002e7568((u32)object, 2, D_003628f0, 1.0f);
    }
    func_002db968(object, 1);
}
