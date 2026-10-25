#include "../common/types.h"
extern "C" u8 D_00347f98[];
extern "C" u8 D_0035eb98[];
extern "C" u8* D_0035eea4;
extern "C" s16* D_0035ee9c;
// why: no recovered source calls or defines this function; no argument registers are set before the call and its result is not used
extern "C" void func_002529a8(void);
extern "C" u8* func_0023ee30(s32);
extern "C" void func_0031a838(u32);
extern "C" void func_002369a0(u8*);
extern "C" void func_0023c008(u8*);
// why: no recovered source calls or defines this function; eight register arguments (a0-a3, t0-t3) plus one word stored at 0(sp), result not used
extern "C" void func_0028d7f0(u8*, s32, s32, s32, s32, s32, s32, s32, s32);
// why: signature of the accepted definition fm_primary_orchdx_recovered_0023ef50.cpp
extern "C" void func_0023ef50(u8*);
// why: no recovered source defines this function; one exit leaves the v0 of func_00287bc0 directly, which recovered call sites use as a u32 result; extern "C" because the isolated probe linker script defines only the plain symbol
extern "C" u32 func_00252d88(void);

u32 func_00252900(void) {
    func_002529a8();
    u8* object = func_0023ee30(160);
    *(u8**)(object + 0) = D_00347f98;
    func_0031a838((u32)(object + 12));
    *(u8**)(object + 0) = D_0035eb98;
    func_002369a0(object + 24);
    func_0023c008(object + 48);
    D_0035eea4 = object;
    func_0028d7f0(object, 30002, 0, 0, D_0035ee9c[0], D_0035ee9c[1], 0, 0, 0);
    func_0023ef50(D_0035eea4);
    return func_00252d88();
}
