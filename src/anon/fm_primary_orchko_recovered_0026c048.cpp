#include "../common/types.h"
// why: no recovered source uses this callee; a0/a1 are word arguments and only a zero test of its v0 is used.
extern "C" u32 func_00281180(s32, s32);
// why: no recovered source uses this callee; a0/a1 are word arguments and its v0 is passed on as a word.
extern "C" u32 func_002891b8(u32, s32);
// why: no recovered source calls this callee (only extern lists); a0-a2 are words, a3 and t0 carry the same pointer.
extern "C" u32 func_00288ce0(u32, u32, s32, u8*, u8*);
// why: the accepted C++ declaration fails the isolated probe link (v1: unresolved mangled reference), the probe linker script defines only the plain symbol.
extern "C" void func_0028af90(u16* object, s32 count);
// why: no recovered source uses this callee; its original stores a1 as a byte and writes no v0.
extern "C" void func_0028b1e8(u32, u8);
extern "C" u64 func_00257708(...);
extern "C" s32 D_0035f010;
extern "C" u32 D_0035f01c;
extern "C" u32 D_0035f024;
extern "C" u32 D_0035f0f4;

// why: both exits are stale-b (ruling #36): the tail into func_00257708 and the fall-through after func_0028b1e8, whose originals write no v0.

void func_0026c048() {
    s32 index = 0;
    s32 slot = 0;
    do {
        if (func_00281180(D_0035f010, index++) != 0) {
            u32 item = func_002891b8(D_0035f01c, slot);
            u32 menu = D_0035f024;
            u8* pointer = (u8*)(D_0035f0f4 + slot * 8 + 0xec8);
            func_00288ce0(menu, item, slot++, pointer, pointer);
        }
    } while (index < 4);
    func_0028af90((u16*)D_0035f024, slot);
    func_0028b1e8(D_0035f024, 1);
    if (slot < 3) {
        func_00257708(1);
    }
}
