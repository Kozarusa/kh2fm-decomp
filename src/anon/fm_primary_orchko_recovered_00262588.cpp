#include "../common/types.h"
extern "C" u32 func_00257770(void);
extern "C" s32 func_00139d78(u32);
extern "C" void func_00139510(u32);

typedef void (*LeaveMethod)(u32);

// why: void per DEVIATIONS #36; exits are a tail into 00139510 (writes no v0/$f0: stale-b) and a jr ra holding the direct 00139d78 result

// Preserve original registry aliases.
void func_00262588(void) asm("_ZN2Tz6CmItem10LeaveStockEv");

void func_00262588(void) {
    u32 base = func_00257770();
    if (func_00139d78(base + 2504) != 0) {
        func_00139510(base + 2504);
    }
    u32 cursor = base;
    s32 count = 4;
    do {
        u32 object = cursor + 3376;
        if (func_00139d78(object) != 0) {
            (*(LeaveMethod*)(*(u32*)object + 20))(object);
        }
        count--;
        cursor += 436;
    } while (count >= 0);
    if (func_00139d78(base + 816) != 0) {
        func_00139510(base + 816);
    }
}
