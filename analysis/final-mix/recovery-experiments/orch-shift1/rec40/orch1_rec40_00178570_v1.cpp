#include "../common/types.h"
extern "C" f32 D_0036c4cc;

void func_00178570(u8* object) {
    // why: VU macro zero-fill of a 16-byte vector, copied from accepted sibling func_0017fdf8
    asm volatile(
        "vsub.xyzw $vf1,$vf0,$vf0;"
        "sqc2 $vf1,0(%0)" : : "r"(object + 0x10) : "memory");
    u8* owner = *(u8**)(object + 0xb44);
    if (0.0f < *(f32*)(owner + 0xa3c)) {
        if (*(f32*)(owner + 0xa34) < 0.0f) {
            *(f32*)(object + 0x14) = D_0036c4cc;
        }
    }
}
