#include "../common/types.h"
extern "C" f32 D_0036b3f8;
extern "C" u8 D_00340eb0;

s32 func_0015cc80(u32* object) {
    if (((f32*)object)[3] == 0.0f) {
        f32* limit = &D_0036b3f8;
        asm("" : "+r"(limit)); // why: original materializes the address with addiu and loads at offset 0
        register f32 value asm("$f1") = ((f32*)object)[4]; // why: original keeps the field in f1 and the bound in f0
        if (value == *limit && (object[0] & 0xffffff) == 0x808080) {
            D_00340eb0 = 0;
            return 1;
        }
    }
    D_00340eb0 = 1;
    return 0;
}
