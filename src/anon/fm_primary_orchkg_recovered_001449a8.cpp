#include "../common/types.h"
#include "../kn/fvector.hpp"
struct __attribute__((aligned(16))) Vector { f32 x; f32 y; f32 z; f32 w; };
extern "C" void func_00144b38(u32, u8*);
extern "C" void func_001447e0(u8*, Vector*, Vector*);

void func_001449a8(u8* box, kn::FVector* rows) {
    register kn::FVector* matrix asm("$16") = rows; // why: original keeps the matrix pointer in s0
    kn::FVector minimum;
    kn::FVector maximum;
    kn::FVector point;
    kn::FVector corners[8];
    kn::FVector temp;
    func_00144b38((u32)box, (u8*)corners);
    for (s32 index = 0; index < 8; index++) {
        // why: VU0 macro vector times matrix, same sequence as accepted 001835f8 / 00140500; noreorder keeps the sqc2 out of the branch delay slot (as in 001835f8)
        asm volatile(".set noreorder; lqc2 $vf5,0(%1); lqc2 $vf1,0(%2); lqc2 $vf2,16(%2); lqc2 $vf3,32(%2); lqc2 $vf4,48(%2); vmulax.xyzw ACC,$vf1,$vf5x; vmadday.xyzw ACC,$vf2,$vf5y; vmaddaz.xyzw ACC,$vf3,$vf5z; vmaddw.xyzw $vf5,$vf4,$vf5w; sqc2 $vf5,0(%0); .set reorder"
                     : : "r"(&temp), "r"(&corners[index]), "r"(matrix) : "memory");
        corners[index] = temp;
        point = corners[index];
        if (index == 0) {
            minimum = maximum = point;
        } else {
            f32 value = *(f32*)&point.x;
            if (value < *(f32*)&minimum.x) {
                *(f32*)&minimum.x = value;
            } else if (*(f32*)&maximum.x < value) {
                *(f32*)&maximum.x = value;
            }
            value = *(f32*)&point.y;
            if (value < *(f32*)&minimum.y) {
                *(f32*)&minimum.y = value;
            } else if (*(f32*)&maximum.y < value) {
                *(f32*)&maximum.y = value;
            }
            value = *(f32*)&point.z;
            if (value < *(f32*)&minimum.z) {
                *(f32*)&minimum.z = value;
            } else if (*(f32*)&maximum.z < value) {
                *(f32*)&maximum.z = value;
            }
        }
    }
    func_001447e0(box, (Vector*)&minimum, (Vector*)&maximum);
    kn::FVector* cursor = corners + 8;
    while (1) {
        // why: original array cleanup loop body is five nop words, same construct as accepted func_00146730
        asm volatile("nop\n\tnop\n\tnop\n\tnop\n\tnop");
        if (corners == cursor) break;
        cursor -= 1;
    }
}
