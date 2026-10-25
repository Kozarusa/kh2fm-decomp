#include "../common/types.h"
extern "C" u32 D_0035eea4;
extern "C" u8* D_0035ee90[];
// why: copied from the call site in fm_primary_orcheg_recovered_0026e5b8.cpp
extern "C" u32 func_00287bc0(void);
// why: Tz::Layout::getNextNum from tozawa layout.cpp returns s32; object parameter derived from a0; extern "C" plain symbol because the isolated probe linker script defines only the plain symbol
extern "C" s32 func_0023f100(u32 object);
// why: no accepted source calls it; no arguments are set before the jal
extern "C" void func_00252ce0(void);
// why: no accepted source calls it; no arguments are set before the jal
extern "C" void func_00252d88(void);
// why: no accepted source calls it; no arguments are set before the jal
extern "C" void func_00252e50(void);
// why: copied from the call site in fm_primary_orchiq_recovered_0024d4a0.cpp
extern "C" u32 func_0023f0c0(...);
// why: copied from the call site in fm_primary_orchei_recovered_0027db58.cpp
extern "C" u32 func_00167f18(...);
// why: copied from the call site in fm_primary_orchei_recovered_0027db58.cpp
extern "C" u64 func_00242618(u64, s8);
// why: no accepted source calls or defines it; object derived from a0; returns the v0 of its final call Tz::Layout::setNum (accepted definition fm_primary_orchji_recovered_0023f070.cpp returns u32)
extern "C" u32 func_0023f108(u32 object);

// why: every exit is a direct callee result (getNum v0, GetInputState v0, tail ChgNextNum v0), so the result is typed per R4.3

u32 func_00252c20(void) {
    u32 mode = func_00287bc0();
    s16 target = *(s16*)(D_0035ee90[mode - 1] + 4);
    if (func_0023f100(D_0035eea4) == -1) {
        func_00252ce0();
        func_00252d88();
        func_00252e50();
    }
    u32 result = func_0023f0c0(D_0035eea4);
    if (result == (u32)target) {
        result = func_00167f18(0);
        if ((*(u64*)(result + 8) & 4) != 0) {
            func_00242618(2, 1);
            return func_0023f108(D_0035eea4);
        }
    }
    return result;
}
