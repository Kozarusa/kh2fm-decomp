#include "../common/types.h"
extern "C" u8 D_01e2a410[];
extern "C" u32 func_002bc9a8(void*, s32, s32);
extern "C" u32 func_002bce10(void*, s32);

u32 func_002b9b78() {
    func_002bc9a8(D_01e2a410, 2, 0);
    func_002bce10(D_01e2a410, 2);
    func_002bc9a8(D_01e2a410, 3, 999);
    return func_002bce10(D_01e2a410, 3);
}
