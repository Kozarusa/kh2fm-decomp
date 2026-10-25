#include "../common/types.h"

extern "C" u8 D_0032e020[];
extern "C" int func_00188fe0(...);
// why: no accepted non-placeholder source declares func_00188c10; it is a store-only leaf, parameters derived from a0/a1 set before the tail call
extern "C" void func_00188c10(u32, u32);
extern "C" void func_002beb28();

// why: void per DEVIATIONS #36; default ids leave entry v0, both tail calls go into callees that leave only stale values

void func_001d7380(s32 id) {
    switch (id) {
    case 12:
        func_002beb28();
        return;
    case 176:
    case 181:
    case 182:
    case 183:
    case 185:
    case 186:
    case 189:
    case 296:
    case 297:
    case 298:
        func_00188c10(func_00188fe0(D_0032e020, 1), 2);
        return;
    }
}
