#include "../common/types.h"
extern "C" u32 D_0035f654;
extern "C" u32 D_0035f650;
extern "C" u8 D_0035f6d0;
extern "C" u32 func_00139d78(...);
extern "C" u32 func_0028acc8(u32);
extern "C" u32 func_0028abe0(u32);
u32 func_002b4f50() {
    if (func_00139d78(D_0035f654) != 0) {
        u32 object = D_0035f654;
        // why: the original indirect call target occupies t5 ($13).
        register u32 (*callback)(u32) asm("$13") = (u32 (*)(u32))(*(u32*)(*(u32*)object + 20));
        callback(object);
    }
    u32 result = func_0028acc8(D_0035f650);
    if (result != 0) result = func_0028abe0(D_0035f650);
    D_0035f6d0 = 0;
    return result;
}


