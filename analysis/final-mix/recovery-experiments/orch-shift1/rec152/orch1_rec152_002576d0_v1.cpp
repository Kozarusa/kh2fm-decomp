#include "../common/types.h"
extern "C" u32 D_0035f034;
extern "C" u32 D_0035f024;
extern "C" u32 func_00139d78(...);
extern "C" u32 func_0028acc8(u32);
u32 func_002576d0() {
    u32 result = func_00139d78(D_0035f034);
    if (result == 0) result = func_0028acc8(D_0035f024);
    return result;
}
