#include "../common/types.h"
// why: copied from the recovered call site in fm_primary_orchky_recovered_0024e158.cpp (eight word arguments a0-a3, t0-t3 and one stack word)
extern "C" void func_0028d980(u8*, u32, u32, u32, u32, s32, s32, s32, s32);
// why: the only recovered declarations are varargs; derived from registers (a0 the cursor object), its result is never read here
extern "C" u32 func_00139620(u8*);
// why: the only recovered declarations are varargs; derived from registers (a0 the cursor object); its original is store-only (lw/and/sw) and writes no v0
extern "C" void func_001395f8(u8*);
extern "C" u32 func_00192048(u64);
extern "C" u32 func_002fde18(void*,u8,u32);
// why: word type as in fm_primary_orchce_recovered_002803e0.cpp; the original reloads it after each word store, so the stores may alias it
extern "C" u32 D_0035f264;
extern "C" u32 D_0035f250;

// why: the single exit leaves v0 from the final func_001395f8 call, whose original writes neither v0 nor f0 (stale-b, ruling #36)

void func_00280148(void) {
    u8* cursor = (u8*)(D_0035f264 + 24);
    func_0028d980(cursor, 0x755d, 0, 0, D_0035f250, 7, 8, -1, 0);
    func_00139620(cursor);
    func_001395f8(cursor);
    *(s32*)(cursor + 432) = 2;
    *(u32*)(cursor + 408) = func_00192048(0x4903);
    cursor = (u8*)(D_0035f264 + 460);
    func_0028d980(cursor, 0x755e, 0, 0, D_0035f250, 10, 11, -1, 0);
    func_002fde18((void*)(D_0035f264 + 1304), 0, 8);
    func_00139620(cursor);
    func_001395f8(cursor);
    *(s32*)(cursor + 432) = 2;
    *(u32*)(cursor + 408) = D_0035f264 + 1304;
}
