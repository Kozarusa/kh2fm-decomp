#include "../common/types.h"
// Object/VTable and func_002edfd8 copied from accepted caller 0031e520.
struct Object;
struct VTable {
    void* slot0;
    void (*slot1)(Object*);
};
struct Object {
    VTable* vtable;
    u8 data[32];
};
extern "C" void func_002edfd8(Object*, void*);
namespace worldmap {
    class Libretto;
}
// why: this is worldmap::Libretto::isExistObj (accepted definition returns u32); extern "C" plain name because the probe linker script defines only func_002be5b8 (the member form failed to link in v1); the original passes the object in a0 (move a0,s0 before jal 002be5b8)
extern "C" u32 func_002be5b8(worldmap::Libretto* libretto);
// why: extern "C" because the probe linker script defines only the plain symbol; accepted definitions 0015f548 / 002be9b0 return s32
extern "C" s32 func_0015f548();
// why: no recovered use; nothing is passed and no result is read
extern "C" void func_001c8e90();
// why: extern "C" for the same isolated-link reason as func_0015f548
extern "C" s32 func_002be9b0();

// why: s32 because both exits leave a callee v0 (isExistObj's nonzero result, or the tail of func_002be9b0); accepted caller Libretto::leaveAllObj discards it

s32 func_002be0b0(worldmap::Libretto* libretto, s32 index) {
    // the four object slots start at word 11 (offset 44), as cleared by the constructor 002bd8f8 and scanned by isExistObj
    Object** slots = (Object**)libretto;
    if (slots[index + 11] != 0) {
        func_002edfd8((Object*)((u8*)libretto + 8), slots[index + 11]);
        if (slots[index + 11] != 0) {
            slots[index + 11]->vtable->slot1(slots[index + 11]);
        }
        slots[index + 11] = 0;
    }
    u32 exists = func_002be5b8(libretto);
    if (exists != 0) {
        return exists;
    }
    func_0015f548();
    func_001c8e90();
    return func_002be9b0();
}
