#include "../common/types.h"
extern "C" u8 D_00340eb0;

s32 func_0015cc80(u32* object) {
    if (((f32*)object)[3] == 0.0f) {

                 register f32 value asm("$f1") = ((f32*)object)[4];         if (value == 255.0f && (object[0] & 0xffffff) == 0x808080) {
            D_00340eb0 = 0;
            return 1;
        }
    }
    D_00340eb0 = 1;
    return 0;
}
