#include "../common/types.h"
extern "C" u32 func_00139510(...);
extern "C" u32 func_00139d78(...);
extern "C" u32 D_0035f20c;

u32 func_00275e08() {
    if (func_00139d78(D_0035f20c)) func_00139510(D_0035f20c);
    u32 result = func_00139d78(D_0035f20c + 436);
    if (result) return func_00139510(D_0035f20c + 436);
    return result;
}
