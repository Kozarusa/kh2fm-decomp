#include "../common/types.h"
extern "C" u32 D_0035f610;
extern "C" u32 func_00103570();
extern "C" u32 func_001063c0(u32, u32);
extern "C" u32 func_00319a60(...);
u32 func_002a9ce8() {
    u32 system = func_00103570();
    u32 object = func_001063c0(2408, system);
    u32 result = func_00319a60(object);
    D_0035f610 = object;
    return result;
}
