#include "../common/types.h"

extern "C" s32 D_0034ece8;
extern "C" u8 D_0032e020[];
extern "C" int func_00188fe0(...);
extern "C" u32 func_001ada38(s64);
// why: extern "C" because the accepted C++ declaration from fm_primary_resume_recovered_00.cpp fails the isolated link (v1); first parameter u8* because the u64 form schedules the address add before li a2 (v3, 2 words)
extern "C" void func_00189028(u8*, u64, u64, u64);
// why: only placeholder sources declare func_00188bf8; it is a store-only leaf (no v0), parameters derived from a0/a1 set before the tail call
extern "C" void func_00188bf8(u32, u32);
// why: only placeholder sources declare func_002bea20; it reads no argument registers and its result is not used here
extern "C" void func_002bea20();

// why: void per DEVIATIONS #36; default ids leave entry v0, the 50-52 path leaves own stores, the 188bf8 tail leaves a stale 188fe0 result (stale-a), the 189028 tail goes into an accepted void definition (stale-b)

void func_001d7098(s32 id) {
    switch (id) {
    case 12:
        func_001ada38(1);
        D_0034ece8 = 4;
        func_002bea20();
        return;
    case 50:
    case 51:
    case 52:
        D_0034ece8 = 3;
        return;
    case 176:
    case 179:
    case 184:
        func_00188bf8(func_00188fe0(D_0032e020, 1), 41);
        return;
    case 182:
    case 183:
    case 186:
    case 296:
    case 297:
    case 298:
        func_00188bf8(func_00188fe0(D_0032e020, 1), 384);
        return;
    case 189:
        func_00188bf8(func_00188fe0(D_0032e020, 1), 43);
        return;
    case 187:
        func_00189028(D_0032e020, 1, 41, 0);
        return;
    }
}
