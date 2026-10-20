#include "../common/types.h"
extern "C" u8 D_0035f580;
extern "C" u8 D_0035f581;
extern "C" u32 D_0035f57c;
extern "C" u32 func_00103570();
extern "C" u32 func_001063c0(u32, u32);
extern "C" u32 func_0023f800(u32);
u32 func_002944f8() {
    D_0035f580 = 0;
    D_0035f581 = 0;
    u32 system = func_00103570();
    u32 pointer = func_001063c0(28, system);
    u32 result = func_0023f800(pointer);
    D_0035f57c = pointer;
    return result;
}

