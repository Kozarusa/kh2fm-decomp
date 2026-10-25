#include "../common/types.h"
extern "C" u32 D_0035f5f4;
extern "C" u32 func_00139d78(u32);
// why: the result of this call is discarded by the original (no v0 use after the jal)
extern "C" void func_00276a18();
extern "C" u32 func_00276b10();

// why: the only exit is a tail call into func_00276b10 whose accepted definition returns u32

u32 func_002a73d0() {
    for (s32 group = 0; group < 4; group++) {
        s32 offset = group * 872;
        for (s32 count = 1; count >= 0; count--) {
            if (func_00139d78(offset + D_0035f5f4) != 0) {
                u32 object = offset + D_0035f5f4;
                u32 table = *(u32*)object;
                ((void (*)(u32))*(u32*)(table + 20))(object);
            }
            offset += 436;
        }
    }
    func_00276a18();
    return func_00276b10();
}
