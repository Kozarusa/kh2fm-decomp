#include "../common/types.h"
extern "C" f32 D_0036cedc;
extern "C" f32 D_0036cee0;
extern "C" void func_00194218(u8*, s32, f32);

void func_00194120(u8* object, f32 value) {
    f32 clamped = 0.0f;
    if (!(value < clamped)) {
        f32* limit = &D_0036cedc;
        asm("" : "+r"(limit)); // why: original forms the address before the zero-offset load
        clamped = *limit;
        if (!(clamped < value)) {
            clamped = value;
        }
    }
    f32* scale = &D_0036cee0;
    asm("" : "+r"(scale)); // why: original forms the address before the zero-offset load
    object[0x6a0] = (s32)(clamped * *scale);
    u16 kind = *(u16*)(*(u8**)(object + 8) + 0x4c);
    if (kind != 5000) {
        if (kind == 5002) {
            f32* maximum = &D_0036cedc;
            asm("" : "+r"(maximum)); // why: original forms the address before the zero-offset load
            func_00194218(object, 0, *maximum - clamped);
            func_00194218(object, 1, clamped);
        }
    } else {
        for (s32 index = 0; index < 10; index++) {
            func_00194218(object, index, clamped);
        }
    }
}
