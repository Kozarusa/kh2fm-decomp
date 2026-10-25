#include "../common/types.h"
extern "C" u32 D_0035f634;
extern "C" s32 func_00139d78(u32);
extern "C" void func_00139510(u32);

void func_002b2c80(void) {
    s32 offset = 0;
    s32 count = 1;
    do {
        if (func_00139d78(D_0035f634 + offset + 0x4e18) != 0) {
            u32 object = offset + D_0035f634 + 0x4e18;
            (*(void (**)(u32))(*(u32*)object + 20))(object);
        }
        count--;
        offset += 408;
    } while (count >= 0);
    if (func_00139d78(D_0035f634 + 0x4c80) != 0) {
        func_00139510(D_0035f634 + 0x4c80);
    }
    if (func_00139d78(D_0035f634 + 0x5148) != 0) {
        func_00139510(D_0035f634 + 0x5148);
    }
}
