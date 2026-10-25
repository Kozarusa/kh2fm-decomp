#include "../common/types.h"
extern "C" bool func_001a6d08(u32);
// why: no recovered source calls this; derived from registers (eight word arguments a0-a3, t0-t3 and one stack word)
extern "C" void func_0028d980(u8*, u32, u32, u32, u32, s32, s32, s32, s32);
extern "C" u64 func_00139620(...);
extern "C" u64 func_001395f8(...);
extern "C" u32 func_002fde18(...);
// why: no recovered source calls this; derived from registers (no arguments; every exit of its original leaves a callee v0, like the accepted same-shape func_00244b38)
extern "C" s32 func_0024e228(void);
// why: original reloads the object pointer before every store
extern "C" u8* volatile D_0035ede4;
extern "C" u32 D_0035edd4;
extern "C" u32 D_0035edf8;

// why: every exit is a direct callee result (func_001a6d08 zero, or the tail func_0024e228 result)

s32 func_0024e158(void) {
    s32 flag = func_001a6d08(7);
    if (flag == 0) return flag;
    func_0028d980(D_0035ede4, 0x753b, 0, 0, D_0035edd4, 39, 41, -1, 0);
    func_00139620(D_0035ede4);
    func_001395f8(D_0035ede4);
    *(s32*)(D_0035ede4 + 432) = 2;
    *(u8*)(D_0035ede4 + 405) = 1;
    u8* part = D_0035ede4 + 24;
    *(u32*)(part + 184) |= 8;
    func_002fde18(D_0035edf8, 0, 32);
    *(u32*)(D_0035ede4 + 408) = D_0035edf8;
    return func_0024e228();
}
