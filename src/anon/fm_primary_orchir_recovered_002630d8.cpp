#include "../common/types.h"
extern "C" u32 func_00139d78(...);
extern "C" u32 func_00257770(...);
extern "C" u32 func_0027e920(...);
extern "C" u32 func_0028acc8(...);
extern "C" s32 D_0035f020;
extern "C" s32 D_0035f024;

s32 func_002630d8(void) {
    s32 result;
    s32 buffer;
    buffer = func_00257770();
    result = func_00139d78(buffer + 0x198);
    if (result == 0) {
        result = func_00139d78(buffer + 0x814);
        if ((((result == 0) && (result = func_00139d78(buffer + 0x4c8), result == 0)) && (result = func_0028acc8(D_0035f020), result == 0)) && (result = func_0028acc8(D_0035f024), result == 0)) {
            result = func_0027e920();
        }
    }
    return result;
}
