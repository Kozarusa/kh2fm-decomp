#include "../common/types.h"
extern "C" u32 func_00139d78(...);
extern "C" u32 func_00281be0(void);
extern "C" u32 D_0035f634;

u32 func_002b1660() {
    u32 result = func_00139d78(D_0035f634 + 0x5478u);
    if (result == 0u) {
        result = func_00139d78(D_0035f634 + 0x5978u);
        if (result == 0u) {
            result = func_00139d78(D_0035f634 + 0x5b2cu);
            if (result == 0u) {
                result = func_00139d78(D_0035f634 + 0x5ce0u);
                if (result == 0u) {
                    result = func_00281be0();
                }
            }
        }
    }
    return result;
}
