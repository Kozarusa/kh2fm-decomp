#include "../common/types.h"
#include "../kn/fvector.hpp"
extern "C" f32 D_0036e7a4;

bool func_001db298(u8* object, const kn::FVector* point) {
    kn::FVector local;
    local = *point;
    u8* matrix = object + 16;
    register const f32* source asm("$12") = &D_0036e7a4; // why: original keeps the constant address in t4; unbound it takes t6 (v3)
    asm("" : "+r"(source)); // why: original forms the full address before the lwc1
    f32* lanes = (f32*)&local;
    lanes[3] = *source;
    kn::FVector temp;
    // why: VU0 macro vector times matrix, same sequence as accepted 0017cf00/00140500
    asm volatile("lqc2 $vf5,0(%1); lqc2 $vf1,0(%2); lqc2 $vf2,16(%2); lqc2 $vf3,32(%2); lqc2 $vf4,48(%2); vmulax.xyzw ACC,$vf1,$vf5x; vmadday.xyzw ACC,$vf2,$vf5y; vmaddaz.xyzw ACC,$vf3,$vf5z; vmaddw.xyzw $vf5,$vf4,$vf5w; sqc2 $vf5,0(%0)"
                 : : "r"(&temp), "r"(&local), "r"(matrix) : "memory");
    local = temp;
    return -*(f32*)(object + 0x50) <= lanes[0] && lanes[0] <= *(f32*)(object + 0x50)
        && -*(f32*)(object + 0x54) <= lanes[1] && lanes[1] <= *(f32*)(object + 0x54)
        && -*(f32*)(object + 0x58) <= lanes[2] && lanes[2] <= *(f32*)(object + 0x58);
}
