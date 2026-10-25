#include "../common/types.h"
extern "C" u32 D_00372308[];
extern "C" u8* D_0035ee18[];
extern "C" s32 D_0035ee08;
// why: copied from fm_primary_oneword_recovered_00246968.cpp, which calls it
extern "C" bool func_001a6d08(u32);
// why: no recovered source calls it (fm_primary_conditionfinish_recovered.cpp only declares it with this form); six word arguments derived from a0-a3, t0, t1
extern "C" int func_0028c198(u64, u64, u64, u64, u64, u64);
// why: no recovered source calls it; derived from registers (a0 in, v0 stored)
extern "C" s32 func_0024efc0(s32);
// why: no recovered source calls it; its original body (4 words) only sets bit 0x800 at +12 and writes no v0
extern "C" void func_001396b0(u8*);
// why: no recovered source calls it; derived from registers (a0 object, a1 flag), result unused here
extern "C" void func_0031ac78(u8*, u32);

// why: void per DEVIATIONS #36: the three exits after func_001396b0 / func_0031ac78 are stale-a/stale-b
// (v0 is func_0024efc0's result that crossed later calls, and the final callees write no v0);
// the remaining exit is direct (func_001a6d08 false on the last index)

void func_0024e9c0() {
    s32 index;
    for (index = 0; index < 5; index++) {
        u32 entry = D_00372308[index];
        if (entry != 0) {
            if (!func_001a6d08(entry)) {
                continue;
            }
        }
        // why: the original reloads the slot after storing through the new object (volatile keeps that reload)
        u8* volatile* slot = (u8* volatile*)&D_0035ee18[index];
        u8* created = (u8*)func_0028c198(0, 2, 2, D_0035ee08, -1, 0);
        *slot = created;
        *(s32*)(created + 0x188) = 1;
        u8* object = *slot;
        *(s32*)(object + 0x190) = func_0024efc0(index);
        func_001396b0(object);
        if (*(s32*)(object + 0x190) != 0) {
            *(s32*)(object + 0x18c) = 0;
            func_001396b0(object);
            if (*(s32*)(object + 0x18c) != 0) {
                func_0031ac78(object, 0);
            }
        }
    }
}
