#include "../common/types.h"
extern "C" u32 func_00103570();
extern "C" u32 func_001063c0(u32,u32);
extern "C" u32 func_00324448(u32);
extern "C" u32 D_0035f600;
extern "C" u32 D_0035f604;
u32 func_002a7678() {
    D_0035f600 = func_001063c0(260, func_00103570());
    u32 pointer = func_001063c0(9040, func_00103570());
    u32 result = func_00324448(pointer);
    D_0035f604 = pointer;
    return result;
}
